/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
            [1] = glcdc_underflow_1_isr, /* GLCDC UNDERFLOW 1 (Graphic 1 underflow) */
            [2] = mipi_dsi_seq0, /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
            [3] = mipi_dsi_seq1, /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
            [4] = mipi_dsi_vin1, /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
            [5] = mipi_dsi_rcv, /* MIPIDSI RCV (DSI packet receive interrupt) */
            [6] = mipi_dsi_ferr, /* MIPIDSI FERR (DSI fatal error interrupt) */
            [7] = mipi_dsi_ppi, /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
            [8] = drw_int_isr, /* DRW INT (DRW interrupt) */
            [9] = sci_b_uart_rxi_isr, /* SCI9 RXI (Receive data full) */
            [10] = sci_b_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [11] = sci_b_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [12] = sci_b_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [13] = iic_master_rxi_isr, /* IIC1 RXI (Receive data full) */
            [14] = iic_master_txi_isr, /* IIC1 TXI (Transmit data empty) */
            [15] = iic_master_tei_isr, /* IIC1 TEI (Transmit end) */
            [16] = iic_master_eri_isr, /* IIC1 ERI (Transfer error) */
            [17] = r_icu_isr, /* ICU IRQ3 (External pin interrupt 3) */
            [18] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_LINE_DETECT,GROUP0), /* GLCDC LINE DETECT (Specified line) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_UNDERFLOW_1,GROUP1), /* GLCDC UNDERFLOW 1 (Graphic 1 underflow) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_SEQ0,GROUP2), /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_SEQ1,GROUP3), /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_VIN1,GROUP4), /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_RCV,GROUP5), /* MIPIDSI RCV (DSI packet receive interrupt) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_FERR,GROUP6), /* MIPIDSI FERR (DSI fatal error interrupt) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_PPI,GROUP7), /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_DRW_INT,GROUP0), /* DRW INT (DRW interrupt) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_SCI9_RXI,GROUP1), /* SCI9 RXI (Receive data full) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TXI,GROUP2), /* SCI9 TXI (Transmit data empty) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TEI,GROUP3), /* SCI9 TEI (Transmit end) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_SCI9_ERI,GROUP4), /* SCI9 ERI (Receive error) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_IIC1_RXI,GROUP5), /* IIC1 RXI (Receive data full) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_IIC1_TXI,GROUP6), /* IIC1 TXI (Transmit data empty) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_IIC1_TEI,GROUP7), /* IIC1 TEI (Transmit end) */
            [16] = BSP_PRV_VECT_ENUM(EVENT_IIC1_ERI,GROUP0), /* IIC1 ERI (Transfer error) */
            [17] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ3,GROUP1), /* ICU IRQ3 (External pin interrupt 3) */
            [18] = BSP_PRV_VECT_ENUM(EVENT_GPT0_COUNTER_OVERFLOW,GROUP2), /* GPT0 COUNTER OVERFLOW (Overflow) */
        };
        #endif
        #endif
