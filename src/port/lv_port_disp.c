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
#include "lvgl/src/display/lv_display_private.h"

/*********************
 *      DEFINES
 *********************/


#define RGB_565_BLACK  (0)
#define RGB_565_REG    (0x1F << 11)
#define RGB_565_GREEN  (0x3F << 5)
#define RGB_565_BLUE   (0x1F << 0)


#define USE_RENDER_MODE_PARTIAL    (0)  //LV_DISPLAY_RENDER_MODE_PARTIAL
#define USE_RENDER_MODE_FULL       (1)  //LV_DISPLAY_RENDER_MODE_FULL
#define USE_RENDER_MODE_DIRECT     (0)  //LV_DISPLAY_RENDER_MODE_DIRECT

#define PARTIAL_MODE_VSIZE         (100)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);
static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);
static void vsync_wait(struct _lv_display_t * disp);
#if (USE_RENDER_MODE_PARTIAL)
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
#if  ((USE_RENDER_MODE_DIRECT) || (USE_RENDER_MODE_FULL))
    lv_display_set_flush_wait_cb(disp, vsync_wait);
#endif
#if (USE_RENDER_MODE_PARTIAL)
    /* Example 1
     * One buffer for partial rendering*/
    static lv_color_t buf_1_1[DISPLAY_HSIZE_INPUT0 * PARTIAL_MODE_VSIZE];
    lv_display_set_draw_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
#endif

#if  (USE_RENDER_MODE_DIRECT)
    /* Example 2
     * Two buffers for partial rendering
     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
    lv_display_set_draw_buffers(disp, &fb_background[0][0], &fb_background[1][0], sizeof(fb_background[0]), LV_DISPLAY_RENDER_MODE_DIRECT);
#endif

#if (USE_RENDER_MODE_FULL)
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
    uint8_t * p_fb = &fb_background[1][0];

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

#if (1 == USE_RENDER_MODE_PARTIAL)
    p_fb = &fb_background[0][0];
#endif

    do
    {
        err =
            R_GLCDC_BufferChange(&g_display0_ctrl,
                                 (uint8_t *) p_fb,
                                 (display_frame_layer_t) 0);
    } while (FSP_ERR_INVALID_UPDATE_TIMING == err);

    /* Enable the backlight */
    R_IOPORT_PinWrite(&g_ioport_ctrl, DISP_BLEN, BSP_IO_LEVEL_HIGH);
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

#if (USE_RENDER_MODE_FULL || USE_RENDER_MODE_DIRECT)
static void vsync_wait(struct _lv_display_t * disp)
{
    FSP_PARAMETER_NOT_USED(disp);
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

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    if(disp_flush_enabled)
    {
#if defined(RENESAS_CORTEX_M85)
#if (BSP_CFG_DCACHE_ENABLED)
        int32_t size;
        /* Invalidate cache - so the HW can access any data written by the CPU */
        if(disp_drv->render_mode == LV_DISPLAY_RENDER_MODE_PARTIAL)
        {
            size = lv_area_get_width(area) * lv_area_get_height(area) * lv_color_format_get_size(disp_drv->color_format);
        }
        else
        {
            size = sizeof(fb_background[0]);
        }
        SCB_CleanInvalidateDCache_by_Addr(px_map, size);
#endif
#endif

#if (0 == D2_RENDER_EACH_OPERATION)
        dave2d_end_of_frame();

        dave2d_wait_for_finish();
#endif

#if ((USE_RENDER_MODE_FULL) || (USE_RENDER_MODE_DIRECT))

        FSP_PARAMETER_NOT_USED(area);
        //Display the frame buffer pointed by px_map
        fsp_err_t err;

        if(disp_drv->render_mode == LV_DISPLAY_RENDER_MODE_DIRECT) {
            if(lv_display_flush_is_last(disp_drv)) {
                do
                {
                    err =
                        R_GLCDC_BufferChange(&g_display0_ctrl,
                                             (uint8_t *) px_map,
                                             (display_frame_layer_t) 0);
                    if (err)
                    {
                        vsync_wait(disp_drv);
                    }
                } while (FSP_ERR_INVALID_UPDATE_TIMING == err);
            }
        }
        else if(disp_drv->render_mode == LV_DISPLAY_RENDER_MODE_FULL)
        {
               do
               {
                   err =
                       R_GLCDC_BufferChange(&g_display0_ctrl,
                                            (uint8_t *) px_map,
                                            (display_frame_layer_t) 0);
                   if (err)
                   {
                       vsync_wait(disp_drv);
                   }
               } while (FSP_ERR_INVALID_UPDATE_TIMING == err);
        }

#endif
#if (USE_RENDER_MODE_PARTIAL) //LV_DISPLAY_RENDER_MODE_PARTIAL
#if 0
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
#else
            lv_area_t area_1;

            area_1.x1 = 0;
            area_1.y1 = 0;
            area_1.x2 = lv_area_get_width(area) - 1;
            area_1.y2 = lv_area_get_height(area) - 1;
            __NOP();
            lv_draw_buf_copy( &fb_background[0][0], DISPLAY_HSIZE_INPUT0, DISPLAY_VSIZE_INPUT0, area, px_map, (uint32_t)lv_area_get_width(area), (uint32_t)lv_area_get_height(area)*5, &area_1, disp_drv->color_format);
#endif
#endif

#if  (0 == D2_RENDER_EACH_OPERATION)
            dave2d_start_of_frame();
#endif
    }


    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    if (disp_drv->flush_wait_cb == NULL)
    {
        //lv_display_flush_ready(disp_drv);
    }
}

#if (USE_RENDER_MODE_PARTIAL)
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
