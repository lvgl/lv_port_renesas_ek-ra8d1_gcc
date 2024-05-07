/* generated thread source file - do not edit */
#include "LVGL_thread.h"

#if 1
static StaticTask_t LVGL_thread_memory;
#if defined(__ARMCC_VERSION)           /* AC6 compiler */
                static uint8_t LVGL_thread_stack[32768] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".stack.thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
                #else
static uint8_t LVGL_thread_stack[32768] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".bss.dtcm_bss") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
#endif
#endif
TaskHandle_t LVGL_thread;
void LVGL_thread_create(void);
static void LVGL_thread_func(void *pvParameters);
void rtos_startup_err_callback(void *p_instance, void *p_data);
void rtos_startup_common_init(void);
dmac_instance_ctrl_t g_transfer2_ctrl;
transfer_info_t g_transfer2_info =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_1_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_BLOCK,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 1,
  .length = 64, };
const dmac_extended_cfg_t g_transfer2_extend =
{ .offset = 0, .src_buffer_size = 0,
#if defined(VECTOR_NUMBER_DMAC0_INT)
    .irq                 = VECTOR_NUMBER_DMAC0_INT,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (BSP_IRQ_DISABLED),
  .channel = 0, .p_callback = NULL, .p_context = NULL, .activation_source = ELC_EVENT_NONE, };
const transfer_cfg_t g_transfer2_cfg =
{ .p_info = &g_transfer2_info, .p_extend = &g_transfer2_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer2 =
{ .p_ctrl = &g_transfer2_ctrl, .p_cfg = &g_transfer2_cfg, .p_api = &g_transfer_on_dmac };
ospi_b_instance_ctrl_t g_ospi0_ctrl;

static const spi_flash_erase_command_t g_ospi0_erase_command_list[] =
{
#if ((0x21 > 0) && (4096 > 0))
  { .command = 0x21, .size = 4096 },
#endif
#if ((0xDC > 0) && (262144 > 0))
  { .command = 0xDC, .size = 262144 },
#endif
#if (0x60 > 0)
  { .command = 0x60, .size = SPI_FLASH_ERASE_SIZE_CHIP_ERASE },
#endif
        };

static ospi_b_timing_setting_t g_ospi0_timing_settings =
{ .command_to_command_interval = OSPI_B_COMMAND_INTERVAL_CLOCKS_2, .cs_pullup_lag =
          OSPI_B_COMMAND_CS_PULLUP_CLOCKS_NO_EXTENSION,
  .cs_pulldown_lead = OSPI_B_COMMAND_CS_PULLDOWN_CLOCKS_NO_EXTENSION };

#if !(0)

#if (0)
            static const spi_flash_erase_command_t g_ospi0_high_speed_erase_command_list[] =
            {
              #if ((0 > 0) && (4096 > 0))
                {.command = 0,     .size = 4096 },
              #endif
              #if ((0 > 0) && (4096 > 0))
                {.command = 0,      .size = 262144  },
              #endif
              #if (0 > 0)
                {.command = 0,       .size  = SPI_FLASH_ERASE_SIZE_CHIP_ERASE        },
              #endif
            };
             #endif

const ospi_b_xspi_command_set_t g_ospi0_high_speed_command_set =
        { .protocol = SPI_FLASH_PROTOCOL_8D_8D_8D,
          .command_bytes = OSPI_B_COMMAND_BYTES_2,
          .read_command = 0xEEEE,
          .page_program_command = 0x1212,
          .write_enable_command = 0x0606,
          .status_command = 0x0505,
          .read_dummy_cycles = 10,
          .program_dummy_cycles = 0, /* Unused by OSPI Flash */
          .status_dummy_cycles = 5,
#if (0)
                .p_erase_command_list      = g_ospi0_high_speed_erase_command_list,
                .erase_command_list_length = sizeof(g_ospi0_high_speed_erase_command_list)/sizeof(g_ospi0_high_speed_erase_command_list[0]),
            #else
          .p_erase_command_list = NULL, /* Use the erase commands specified in spi_flash_cfg_t */
#endif
        };
#endif

#if OSPI_B_CFG_DOTF_SUPPORT_ENABLE
            extern uint32_t g_ospi_dotf_iv[];
            extern uint32_t g_ospi_dotf_key[];

            static ospi_b_dotf_cfg_t g_ospi_dotf_cfg=
            {
                .key_type       = OSPI_B_DOTF_AES_KEY_TYPE_128,
                .p_start_addr   = (uint32_t *)0x90000000,
                .p_end_addr     = (uint32_t *)0x90001FFF,
                .p_key          = (uint32_t *)g_ospi_dotf_key,
                .p_iv           = (uint32_t *)g_ospi_dotf_iv,
            };
            #endif

static const ospi_b_extended_cfg_t g_ospi0_extended_cfg =
{ .channel = (ospi_b_device_number_t) 1, .data_latch_delay_clocks = 0x00, .p_timing_settings = &g_ospi0_timing_settings,
#if (0)
                .p_xspi_command_set_list                 = ,
                .xspi_command_set_list_length            = 0,
            #else
  .p_xspi_command_set_list = &g_ospi0_high_speed_command_set,
  .xspi_command_set_list_length = 1U,
#endif
  .p_autocalibration_preamble_pattern_addr = (uint8_t*) 0x90000000,
#if OSPI_B_CFG_DMAC_SUPPORT_ENABLE
                .p_lower_lvl_transfer                    = &g_transfer2,
            #endif
#if OSPI_B_CFG_DOTF_SUPPORT_ENABLE
                .p_dotf_cfg                              = &g_ospi_dotf_cfg,
            #endif
  .read_dummy_cycles = 0,
  .program_dummy_cycles = 0, /* Unused by OSPI Flash */
  .status_dummy_cycles = 0, };
const spi_flash_cfg_t g_ospi0_cfg =
{ .spi_protocol = SPI_FLASH_PROTOCOL_EXTENDED_SPI,
  .read_mode = SPI_FLASH_READ_MODE_STANDARD, /* Unused by OSPI Flash */
  .address_bytes = SPI_FLASH_ADDRESS_BYTES_4,
  .dummy_clocks = SPI_FLASH_DUMMY_CLOCKS_DEFAULT, /* Unused by OSPI Flash */
  .page_program_address_lines = (spi_flash_data_lines_t) 0U, /* Unused by OSPI Flash */
  .page_size_bytes = 64,
  .write_status_bit = 0,
  .write_enable_bit = 1,
  .page_program_command = 0x12,
  .write_enable_command = 0x06,
  .status_command = 0x05,
  .read_command = 0x13,
#if OSPI_B_CFG_XIP_SUPPORT_ENABLE
                .xip_enter_command           = 0,
                .xip_exit_command            = 0,
            #else
  .xip_enter_command = 0U,
  .xip_exit_command = 0U,
#endif
  .erase_command_list_length = sizeof(g_ospi0_erase_command_list) / sizeof(g_ospi0_erase_command_list[0]),
  .p_erase_command_list = &g_ospi0_erase_command_list[0],
  .p_extend = &g_ospi0_extended_cfg, };
/** This structure encompasses everything that is needed to use an instance of this interface. */
const spi_flash_instance_t g_ospi0 =
{ .p_ctrl = &g_ospi0_ctrl, .p_cfg = &g_ospi0_cfg, .p_api = &g_ospi_b_on_spi_flash, };
gpt_instance_ctrl_t g_timer0_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer0_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT0_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer0_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT0_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
          .capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer0_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };

const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.001 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x1d4c0,
  .duty_cycle_counts = 0xea60, .source_div = (timer_source_div_t) 0, .channel = 0, .p_callback = timer_tick_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &g_timer0_extend,
  .cycle_end_ipl = (8),
#if defined(VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_gpt };
iic_master_instance_ctrl_t g_i2c_master1_ctrl;
const iic_master_extended_cfg_t g_i2c_master1_extend =
{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_LONG, .timeout_scl_low = IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
/* Actual calculated bitrate: 398936. Actual calculated duty cycle: 50%. */.clock_settings.brl_value = 31,
  .clock_settings.brh_value = 31, .clock_settings.cks_value = 1, };
const i2c_master_cfg_t g_i2c_master1_cfg =
{ .channel = 1, .rate = I2C_MASTER_RATE_FAST, .slave = 0x5D, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .p_callback = g_i2c_master1_cb,
  .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC1_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC1_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC1_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC1_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC1_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (12),
  .p_extend = &g_i2c_master1_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master1 =
{ .p_ctrl = &g_i2c_master1_ctrl, .p_cfg = &g_i2c_master1_cfg, .p_api = &g_i2c_master_on_iic };
dtc_instance_ctrl_t g_transfer0_ctrl;

#if (1 == 1)
transfer_info_t g_transfer0_info =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_1_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 0,
  .length = 0, };

#elif (1 > 1)
/* User is responsible to initialize the array. */
transfer_info_t g_transfer0_info[1];
#else
/* User must call api::reconfigure before enable DTC transfer. */
#endif

const dtc_extended_cfg_t g_transfer0_cfg_extend =
{ .activation_source = VECTOR_NUMBER_SCI9_TXI, };

const transfer_cfg_t g_transfer0_cfg =
{
#if (1 == 1)
  .p_info = &g_transfer0_info,
#elif (1 > 1)
    .p_info              = g_transfer0_info,
#else
    .p_info = NULL,
#endif
  .p_extend = &g_transfer0_cfg_extend, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 =
{ .p_ctrl = &g_transfer0_ctrl, .p_cfg = &g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
sci_b_uart_instance_ctrl_t g_uart0_ctrl;

sci_b_baud_setting_t g_uart0_baud_setting =
        {
        /* Baud rate calculated with 0.091% error. */.baudrate_bits_b.abcse = 0,
          .baudrate_bits_b.abcs = 0, .baudrate_bits_b.bgdm = 1, .baudrate_bits_b.cks = 0, .baudrate_bits_b.brr = 6, .baudrate_bits_b.mddr =
                  (uint8_t) 220,
          .baudrate_bits_b.brme = true };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_b_uart_extended_cfg_t g_uart0_cfg_extend =
{ .clock = SCI_B_UART_CLOCK_INT, .rx_edge_start = SCI_B_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_B_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_B_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart0_baud_setting, .flow_control =
          SCI_B_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_B_UART_RS485_DISABLE,
    .polarity = SCI_B_UART_RS485_DE_POLARITY_HIGH,
    .assertion_time = 1,
    .negation_time = 1, } };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 9, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          uart_callback,
  .p_context = NULL, .p_extend = &g_uart0_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == g_transfer0)
                .p_transfer_tx       = NULL,
#else
  .p_transfer_tx = &g_transfer0,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI9_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI9_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI9_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI9_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI9_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci_b };
extern uint32_t g_fsp_common_thread_count;

const rm_freertos_port_parameters_t LVGL_thread_parameters =
{ .p_context = (void*) NULL, };

void LVGL_thread_create(void)
{
    /* Increment count so we will know the number of threads created in the RA Configuration editor. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

#if 1
    LVGL_thread = xTaskCreateStatic (
#else
                    BaseType_t LVGL_thread_create_err = xTaskCreate(
                    #endif
                                     LVGL_thread_func,
                                     (const char*) "LVGL Thread", 32768 / 4, // In words, not bytes
                                     (void*) &LVGL_thread_parameters, //pvParameters
                                     1,
#if 1
                                     (StackType_t*) &LVGL_thread_stack,
                                     (StaticTask_t*) &LVGL_thread_memory
#else
                        & LVGL_thread
                        #endif
                                     );

#if 1
    if (NULL == LVGL_thread)
    {
        rtos_startup_err_callback (LVGL_thread, 0);
    }
#else
                    if (pdPASS != LVGL_thread_create_err)
                    {
                        rtos_startup_err_callback(LVGL_thread, 0);
                    }
                    #endif
}
static void LVGL_thread_func(void *pvParameters)
{
    /* Initialize common components */
    rtos_startup_common_init ();

    /* Initialize each module instance. */

#if (1 == BSP_TZ_NONSECURE_BUILD) && (1 == 1)
                    /* When FreeRTOS is used in a non-secure TrustZone application, portALLOCATE_SECURE_CONTEXT must be called prior
                     * to calling any non-secure callable function in a thread. The parameter is unused in the FSP implementation.
                     * If no slots are available then configASSERT() will be called from vPortSVCHandler_C(). If this occurs, the
                     * application will need to either increase the value of the "Process Stack Slots" Property in the rm_tz_context
                     * module in the secure project or decrease the number of threads in the non-secure project that are allocating
                     * a secure context. Users can control which threads allocate a secure context via the Properties tab when
                     * selecting each thread. Note that the idle thread in FreeRTOS requires a secure context so the application
                     * will need at least 1 secure context even if no user threads make secure calls. */
                     portALLOCATE_SECURE_CONTEXT(0);
                    #endif

    /* Enter user code for this thread. Pass task handle. */
    LVGL_thread_entry (pvParameters);
}
