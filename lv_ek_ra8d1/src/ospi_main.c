#include "hal_data.h"
#include "LVGL_thread.h"
#include "board_cfg.h"
#include "stdio.h"
#include "ospi_main.h"


/* CHange to 1 to enable easier to debug asserts. */
#if 0
 #undef assert
 #define assert(pred)    do { if (!(pred)) __BKPT(0); } while (0)
#endif

/* These commands and registers are for the Infineon S28HS256 and may not match other targets. */
#define READ_SFDP_COMMAND          (0x5AU)
#define READ_SFDP_COMMAND_OPI      (0x5A5AU)
#define READ_REGISTER_COMMAND      (0x65U)
#define READ_REGISTER_COMMAND_OPI  (0x6565U)
#define WRITE_REGISTER_COMMAND     (0x71U)
#define WRITE_REGISTER_COMMAND_OPI (0x7171U)
#define WRITE_ENABLE_COMMAND       (0x06U)
#define WRITE_ENABLE_COMMAND_OPI   (0x0606U)
#define READ_STATUS_COMMAND        (0x05U)
#define READ_STATUS_COMMAND_OPI    (0x0505U)

#define CFR2V_REGISTER_ADDRESS (0x800003U)
#define CFR3V_REGISTER_ADDRESS (0x800004U)
#define CFR5V_REGISTER_ADDRESS (0x800006U)

#define CFR3N_REGISTER_ADDRESS (0x04U)

#define CFR2V_MEMLAT_Pos       (0U)
#define CFR2V_MEMLAT_Msk       (0x0FU)

#define CFR3V_VRGLAT_Pos       (6U)
#define CFR3V_VRGLAT_Msk       (0xC0U)
#define CFR3V_UNHYSA_Pos       (3U)
#define CFR3V_UNHYSA_Msk       (0x08U)

#define CFR5V_SDRDDR_Pos       (1U)
#define CFR5V_SDRDDR_Msk       (0x02U)
#define CFR5V_OPIIT_Pos        (0U)
#define CFR5V_OPIIT_Msk        (0x01U)

#define CFR2V_WRITE_Msk        (0x00U)
#define CFR3V_WRITE_Msk        (0x00U)
#define CFR5V_WRITE_Msk        (0x40U)

#define REG_LATENCY_CODE_SPI   (0x00U)
#define REG_LATENCY_CODE_OPI   (0x02U)

#define MEM_LATENCY_CODE_SPI   (0x08U)
#define MEM_LATENCY_CODE_OPI   (0x03U)

#define REG_DUMMY_CYCLES_SPI   (0U)
#define REG_DUMMY_CYCLES_OPI   (3U)
//#define REG_DUMMY_CYCLES_OPI   (6U)

#define WRITE_ENABLE_MASK      (0x02U)

#define READ_SFDP_DUMMY_CYCLES (8U)
#define SFDP_SIGNATURE         (0x50444653U)

#define OSPI_TEST_DATA_LENGTH  (0x40U)
#define OSPI_SECTOR_SIZE       (4096U)
#define OSPI_BLOCK_SIZE        (262144U)

#define OSPI_MODE_SPI          (CFR5V_WRITE_Msk)
#define OSPI_MODE_DOPI         (CFR5V_WRITE_Msk | CFR5V_OPIIT_Msk | CFR5V_SDRDDR_Msk)

#define OSPI_RESET_PIN         BSP_IO_PORT_01_PIN_06
#define OSPI_RESET_DELAY       (40U)

#ifdef USE_OSPI


FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

static void reset_ospi_device(void);
static void write_en(bool is_dopi, uint8_t dummy_cycles);
static void oclk_change(bsp_clocks_octaclk_div_t divider);
static void transition_to_dopi(void);


const uint32_t g_autocalibration_data [4]BSP_PLACE_IN_SECTION(".ospi_device_1") =
{
		0xFFFF0000U,
		0x000800FFU,
		0x00FFF700U,
		0xF700F708U
};


const uint8_t g_ddr_register_dummy_cycles_cfr3[4] = {//RDARG_4_0 use these dummy cycles for reading volatile registers
3,4,5,6
};

const uint8_t g_sdr_register_dummy_cycles_cfr3[4] = { //RDARG_C_0 RDDYB_4_0 use these dummy cycles for reading volatile registers

0,1,1,2
};


static void reset_ospi_device(void)
{
    R_IOPORT_PinWrite(&g_ioport_ctrl, OSPI_RES, BSP_IO_LEVEL_HIGH);
    vTaskDelay(OSPI_RESET_DELAY);
    R_IOPORT_PinWrite(&g_ioport_ctrl, OSPI_RES, BSP_IO_LEVEL_LOW);
    vTaskDelay(OSPI_RESET_DELAY);
    R_IOPORT_PinWrite(&g_ioport_ctrl, OSPI_RES, BSP_IO_LEVEL_HIGH);
    vTaskDelay(OSPI_RESET_DELAY);

}

static void write_en(bool is_dopi, uint8_t dummycycles)
{
    spi_flash_direct_transfer_t tfr =
    {
        .command = is_dopi ? WRITE_ENABLE_COMMAND_OPI : WRITE_ENABLE_COMMAND,
        .command_length = is_dopi ? 2U : 1U,
        .address_length = 0U,
        .data_length = 0U,
        .dummy_cycles = 0U
    };
    fsp_err_t err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
    assert(FSP_SUCCESS == err);

    tfr = (spi_flash_direct_transfer_t) {
        .command = is_dopi ? READ_STATUS_COMMAND_OPI : READ_STATUS_COMMAND,
        .command_length = is_dopi ? 2U : 1U,
        .address_length = is_dopi ? 4U : 0U,    // Address is always sent for any kind of read in DOPI
        .data_length = 1U,
        .dummy_cycles = dummycycles //is_dopi ? REG_DUMMY_CYCLES_OPI : REG_DUMMY_CYCLES_SPI,
    };
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
    assert(FSP_SUCCESS == err);

    if ((tfr.data & WRITE_ENABLE_MASK) == 0)
    {
        __BKPT(0);
    }
}
static void oclk_change(bsp_clocks_octaclk_div_t divider)
{
    /* Now update the octaclk divider. */
    bsp_octaclk_settings_t octaclk_settings;
    octaclk_settings.source_clock = BSP_CLOCKS_SOURCE_CLOCK_PLL2P;
    octaclk_settings.divider      = divider;
    R_BSP_OctaclkUpdate(&octaclk_settings);
}


uint8_t cfr2v;
uint8_t cfr3v;
uint8_t cfr3n;

static void transition_to_dopi(void)
{
    fsp_err_t err = FSP_SUCCESS;
    uint8_t dopi_dummy_cycles = 3; //Factory default for latency code in CFR3N is 0, so 3 latency cycles in 8D-8D-8D DDR mode
    uint8_t spi_dummy_cycles = 0;  //Factory default for latency code in CFR3N is 0, so 0 latency cycles in 1S-1S-1S SDR mode


    spi_flash_direct_transfer_t tfr =
    {
        .command = READ_REGISTER_COMMAND,
        .command_length = 1U,
        .address_length = 3U,
        .data_length = 1U,
        .dummy_cycles = spi_dummy_cycles
    };

    /*Read CFR2V*/
    tfr.address = CFR2V_REGISTER_ADDRESS;
    tfr.data = 0x0;
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
    assert(FSP_SUCCESS == err);
    cfr2v = (0x000000FF & tfr.data);

    /*Read CFR3V*/
    tfr.address = CFR3V_REGISTER_ADDRESS;
    tfr.data = 0x0;
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
    assert(FSP_SUCCESS == err);
    cfr3v = (0x000000FF & tfr.data);

    tfr.command = WRITE_REGISTER_COMMAND;

    write_en(false, spi_dummy_cycles);

    /* Modify the registers for the new clock speed. */
    tfr.address = CFR2V_REGISTER_ADDRESS;
    tfr.data = (cfr2v & ~CFR2V_MEMLAT_Msk) | CFR2V_WRITE_Msk | ((MEM_LATENCY_CODE_OPI << CFR2V_MEMLAT_Pos) & CFR2V_MEMLAT_Msk);
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
    assert(FSP_SUCCESS == err);

    write_en(false, spi_dummy_cycles);

    tfr.address = CFR3V_REGISTER_ADDRESS;
    tfr.data = (cfr3v & ~CFR3V_VRGLAT_Msk) | CFR3V_WRITE_Msk | ((REG_LATENCY_CODE_OPI << CFR3V_VRGLAT_Pos) & CFR3V_VRGLAT_Msk);
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
    assert(FSP_SUCCESS == err);

    spi_dummy_cycles = g_sdr_register_dummy_cycles_cfr3[REG_LATENCY_CODE_OPI];
    dopi_dummy_cycles = g_ddr_register_dummy_cycles_cfr3[REG_LATENCY_CODE_OPI];

    write_en(false, spi_dummy_cycles);

    /* Transition to DOPI. */
    tfr.dummy_cycles = 0;//NO dummy cycles for a register write
    tfr.address = CFR5V_REGISTER_ADDRESS;
    tfr.data = OSPI_MODE_DOPI;
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);
    assert(FSP_SUCCESS == err);

    /* Change the protocol mode of the driver. */
    /* DS will auto-calibrate in this call. */
    err = R_OSPI_B_SpiProtocolSet(&g_ospi0_ctrl, SPI_FLASH_PROTOCOL_8D_8D_8D);
    assert(FSP_SUCCESS == err);

    /* Change clock speed. */
    oclk_change(BSP_CLOCKS_OCTACLK_DIV_1);

    /* auto-calibrate after changing the speed of OM_SCLK */
    err = R_OSPI_B_AutoCalibrate(&g_ospi0_ctrl);
    assert(FSP_SUCCESS == err);

    tfr.command = READ_REGISTER_COMMAND_OPI;
    tfr.command_length = 2U;
    tfr.address = CFR5V_REGISTER_ADDRESS;
    tfr.address_length = 4U;
    tfr.data = 0U;
    tfr.data_length = 1U;
    tfr.dummy_cycles = dopi_dummy_cycles;

    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
    assert(FSP_SUCCESS == err);
    assert(OSPI_MODE_DOPI == (tfr.data & 0xFF));   // Need to mask here because DOPI always reads 2 bytes at a time.
}

spi_flash_cfg_t g_ram_ospi_cfg;
ospi_b_extended_cfg_t g_ram_ospi_extended_cfg;
ospi_b_xspi_command_set_t g_ram_ospi_high_speed_command_set;

static const spi_flash_erase_command_t g_ospi0_dopi_erase_command_list[] = {
		{ .command = 0x2121, .size = 4096 },
		{ .command = 0xDCDC, .size = 262144 },
		{ .command = 0x6060, .size = SPI_FLASH_ERASE_SIZE_CHIP_ERASE },
};

/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void init_ospi(void)
{
    fsp_err_t err = FSP_SUCCESS;

    reset_ospi_device();

    memcpy(&g_ram_ospi_cfg, &g_ospi0_cfg, sizeof(spi_flash_cfg_t));
    memcpy(&g_ram_ospi_extended_cfg, g_ospi0_cfg.p_extend, sizeof(ospi_b_extended_cfg_t));
    memcpy(&g_ram_ospi_high_speed_command_set, g_ram_ospi_extended_cfg.p_xspi_command_set_list, sizeof(ospi_b_xspi_command_set_t));

    /* Set the erase commands for High Speed mode for 8D-8D-8D */
    g_ram_ospi_cfg.p_extend = &g_ram_ospi_extended_cfg;
    g_ram_ospi_extended_cfg.p_xspi_command_set_list = &g_ram_ospi_high_speed_command_set;
    g_ram_ospi_high_speed_command_set.p_erase_command_list = g_ospi0_dopi_erase_command_list;
    g_ram_ospi_high_speed_command_set.erase_command_list_length = sizeof(g_ospi0_dopi_erase_command_list)/sizeof(spi_flash_erase_command_t);

    g_ram_ospi_extended_cfg.p_autocalibration_preamble_pattern_addr = (uint8_t*)&g_autocalibration_data[0];

    err = R_OSPI_B_Open(&g_ospi0_ctrl, &g_ram_ospi_cfg);
    assert(FSP_SUCCESS == err);

    spi_flash_direct_transfer_t test_tfr =
    {
         .command = READ_SFDP_COMMAND,
         .command_length = 1,
         .address = 0,
         .address_length = 3,
         .data = 0,
         .data_length = 4,
         .dummy_cycles = READ_SFDP_DUMMY_CYCLES
    };
    err = R_OSPI_B_DirectTransfer(&g_ospi0_ctrl, &test_tfr, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);
    assert(FSP_SUCCESS == err);

    if (SFDP_SIGNATURE != test_tfr.data)
    {
        while (true)
        {
            __BKPT(0);
        }
    }

    transition_to_dopi();
}
#endif
