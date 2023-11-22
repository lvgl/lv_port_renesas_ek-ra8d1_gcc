/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/


#include "LVGL_thread.h"
#include "touch_GT911.h"
#include "arducam.h"
#include <stdbool.h>
#include "lv_port_disp.h"
#include <renesas/dave2d/lv_draw_dave2d.h>

/*********************
 *      DEFINES
 *********************/


#define RGB_565_BLACK  (0)
#define RGB_565_REG    (0x1F << 11)
#define RGB_565_GREEN  (0x3F << 5)
#define RGB_565_BLUE   (0x1F << 0)


#define USE_PARTIAL       (0)
#define USE_DOUBLE_BUFFER (1)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
#if (USE_PARTIAL)
static void put_px(int32_t x, int32_t y, uint16_t px_map);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    lv_display_t * disp = lv_display_create(DISPLAY_HSIZE_INPUT0, DISPLAY_VSIZE_INPUT0);
    lv_display_set_flush_cb(disp, disp_flush);
#if (USE_PARTIAL)
    /* Example 1
     * One buffer for partial rendering*/
    static lv_color_t buf_1_1[DISPLAY_HSIZE_INPUT0 * 10];                          /*A buffer for 10 rows*/
    lv_display_set_draw_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
#endif

#if 0
    /* Example 2
     * Two buffers for partial rendering
     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
    static lv_color_t buf_2_1[DISPLAY_HSIZE_INPUT0 * 10];
    static lv_color_t buf_2_2[DISPLAY_HSIZE_INPUT0 * 10];
    lv_display_set_draw_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
#endif

#if (USE_DOUBLE_BUFFER)
    /* Example 3
     * Two buffers screen sized buffer for double buffering.
     * Both LV_DISPLAY_RENDER_MODE_DIRECT and LV_DISPLAY_RENDER_MODE_FULL works, see their comments*/

    lv_display_set_draw_buffers(disp, &fb_background[0][0], &fb_background[1][0], sizeof(fb_background[0]), LV_DISPLAY_RENDER_MODE_FULL);
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    fsp_err_t err;
    uint8_t * p_fb;

    /* Need to initialise the Touch Controller before the LCD, as only a Single Reset line shared between them */
    err = R_IIC_MASTER_Open(&g_i2c_master1_ctrl, &g_i2c_master1_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }

    err = R_ICU_ExternalIrqOpen(&g_external_irq3_ctrl, &g_external_irq3_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }

    err = init_ts(&g_i2c_master1_ctrl);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }

    err = enable_ts(&g_i2c_master1_ctrl, &g_external_irq3_ctrl);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }

    //R_BSP_SoftwareDelay(150, BSP_DELAY_UNITS_MILLISECONDS);

    /* Fill the Frame buffer with a colour, to zero out info from previous execution runs */
    uint32_t count;
    uint16_t * p = (uint16_t *)&fb_background[0][0];

    for (count = 0; count < sizeof(fb_background)/2; count++)
    {
        *p++ = RGB_565_BLACK;
    }


    err = R_GLCDC_Open(&g_display0_ctrl, &g_display0_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }

    err = R_GLCDC_Start(&g_display0_ctrl);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0); //TODO: Better error handling
    }


#if (1 == USE_PARTIAL)
    p_fb = &fb_background[0][0];
#else
    p_fb = &fb_background[1][0];
#endif

    do
    {
        err =
            R_GLCDC_BufferChange(&g_display0_ctrl,
                                 (uint8_t *) p_fb,
                                 (display_frame_layer_t) 0);
    } while (FSP_ERR_INVALID_UPDATE_TIMING == err);


}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

void glcdc_callback(display_callback_args_t *p_args)
{
    if (DISPLAY_EVENT_LINE_DETECTION == p_args->event)
    {
#if BSP_CFG_RTOS == 2               // FreeRTOS
       BaseType_t context_switch;

       //
       // Set Vsync semaphore
       //
       xSemaphoreGiveFromISR(_SemaphoreVsync, &context_switch);

       //
       // Return to the highest priority available task
       //
       portYIELD_FROM_ISR(context_switch);
#else
#endif
    }
    else if (DISPLAY_EVENT_GR1_UNDERFLOW == p_args->event)
    {
        __BKPT(0); //Layer 1 Underrun
    }
    else if (DISPLAY_EVENT_GR2_UNDERFLOW == p_args->event)
    {
        __BKPT(0); //Layer 2 Underrun
    }
    else //DISPLAY_EVENT_FRAME_END
    {
        __BKPT(0);
    }

}

#if (USE_DOUBLE_BUFFER)
static void vsync_wait (void)
{
  #if BSP_CFG_RTOS == 2              // FreeRTOS
    //
    // If Vsync semaphore has already been set, clear it then wait to avoid tearing
    //
    if (uxSemaphoreGetCount(_SemaphoreVsync))
    {
        xSemaphoreTake(_SemaphoreVsync, 10);
    }

    xSemaphoreTake(_SemaphoreVsync, portMAX_DELAY);
  #else
  #endif

}
#endif



 extern d2_device * _d2_handle;
 extern d2_renderbuffer * _renderbuffer;

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    if(disp_flush_enabled) {
        /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    static bool enable_backlight = true;
    static  uint8_t * p_color_last = NULL;

    if (true == enable_backlight)
    {
        /* Enable the backlight */
        R_IOPORT_PinWrite(&g_ioport_ctrl, DISP_BLEN, BSP_IO_LEVEL_HIGH);
        enable_backlight = false;

    }


#if (USE_DOUBLE_BUFFER) //LV_DISPLAY_RENDER_MODE_FULL or LV_DISPLAY_RENDER_MODE_DIRECT
        {
            FSP_PARAMETER_NOT_USED(area);
                //Display the frame buffer pointed by color_p
                fsp_err_t err;

                //LV_LOG_USER("to 0x%x\r\n", (unsigned int)px_map);


                if (p_color_last != px_map)
                {
#if defined(RENESAS_CORTEX_M85)
#if (BSP_CFG_DCACHE_ENABLED)
                    /* Invalidate cache - so GLCDC can access any data written by the CPU */
                    SCB_CleanInvalidateDCache_by_Addr(px_map, sizeof(fb_background[0]));
#endif
#endif

#ifndef D2_RENDER_EACH_OPERATION
                    d2_s32     result;

                    // Execute render operations
                    result = d2_executerenderbuffer(_d2_handle, _renderbuffer, 0);
                    if (D2_OK != result)
                    {
                        __BKPT(0);
                    }

                    result = d2_flushframe(_d2_handle);
                    if (D2_OK != result)
                    {
                        __BKPT(0);
                    }

                    result = d2_selectrenderbuffer(_d2_handle, _renderbuffer);
                    if (D2_OK != result)
                    {
                        __BKPT(0);
                    }
#endif
                    do
                    {
                        err =
                            R_GLCDC_BufferChange(&g_display0_ctrl,
                                                 (uint8_t *) px_map,
                                                 (display_frame_layer_t) 0);
                        if (err)
                        {
                            vsync_wait();
                        }
                    } while (FSP_ERR_INVALID_UPDATE_TIMING == err);

                    vsync_wait();//wait for the GLCDC registers to actually be updated
                }
                else
                {
#if CHECK_RENDERING_TO_VISIBLE_FB
                    if (R_GLCDC->GR[0].FLM2 == (uint32_t)px_map)
                    {
                        __BKPT(0); //Are we copying into the visible framebuffer?
                    }
#endif
                }
                p_color_last = px_map;
        }
#else //LV_DISPLAY_RENDER_MODE_PARTIAL

        int32_t x;
        int32_t y;
        uint16_t *p = (uint16_t *)px_map;
        for(y = area->y1; y <= area->y2; y++) {
            for(x = area->x1; x <= area->x2; x++) {
                /*Put a pixel to the display. For example:*/
                put_px(x, y, *p);
                p++;
            }
        }
#endif
    }


    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_display_flush_ready(disp_drv);
}

#if (USE_PARTIAL)
static void put_px(int32_t x, int32_t y, uint16_t px_map)
{
    uint16_t *p = (uint16_t *)&fb_background[0][0]; //RGB565 format framebuffer


    p = p + (y * DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0);
    p = p + (x );

    *p = px_map;
}
#endif


#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
