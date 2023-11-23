#include <LVGL_thread.h>
#include "math.h"
#include "dsi_layer.h"
#include "port/lv_port_disp.h"
#include "port/lv_port_indev.h"
#include "lvgl/demos/lv_demos.h"
#include "touch_GT911.h"
#include "arducam.h"
#include "stdlib.h"

//https://github.com/dialog-semiconductor/BLE_SDK10_DA1470x_examples/tree/main/features/watch_demo_lvgl/lvgl/lvgl

#define REGION_0_ATTR_IDX 0U
#define REGION_1_ATTR_IDX 1U
#define READ_WRITE 0U
#define READ_ONLY 1U
#define PRIVILEGED_ONLY 0U
#define ANY_PRVILEGE 1U
#define EXECUTION_PERMITTED 0U
#define NO_EXECUTION 1U

#define NON_TRANSIENT 1U
#define TRANSIENT     0U

#define WRITE_BACK    1U
#define WRITE_THROUGH 0U

#define READ_ALLOCATE  1U
#define WRITE_ALLOCATE 1U


#define RGB_565_REG    (0x1F << 11)
#define RGB_565_GREEN  (0x3F << 5)
#define RGB_565_BLUE   (0x1F << 0)

#define RGB_565_BLACK  (0)

void lv_draw_dave2d_init(void);

void timer_tick_callback(timer_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    lv_tick_inc(1);
}

#define D2D_TEST (0)

#if D2D_TEST
static void disp_init(void);

static d2_device * _d2_handle;
static d2_renderbuffer * _renderbuffer;

#define     PI    3.14159265358979323846

double          nx0;
double          ny0;
double          nx1;
double          ny1;

int16_t start_angle = 0;
int16_t end_angle = 45;
#endif

/* New Thread entry function */
/* pvParameters contains TaskHandle_t */
void LVGL_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    fsp_err_t err;
#if D2D_TEST
    uint32_t flags = 0;
    d2_s32 result;


    /** Set d2_wf_concave flag if the pie object to draw is concave shape. */
    if (abs(start_angle - end_angle) > 180)
    {
        flags = d2_wf_concave;
        __NOP();
    }
    else
    {
        flags = 0;
        __NOP();
    }


    double d_start_angle = ((start_angle - 0) * PI)/180;
    double d_end_angle = ((end_angle + 0) * PI)/180;

    nx0 = -sin (d_start_angle);
    ny0 = cos (d_start_angle);

    nx1 = sin (d_end_angle);
    ny1 = -cos (d_end_angle);

    d2_s32 x0 = (d2_s32)(nx0 * 65536);
    d2_s32 x1 = (d2_s32)(nx1 * 65536);
    d2_s32 y0 = (d2_s32)(ny0 * 65536);
    d2_s32 y1 = (d2_s32)(ny1 * 65536);

    disp_init();

    /* Enable the backlight */
    R_IOPORT_PinWrite(&g_ioport_ctrl, DISP_BLEN, BSP_IO_LEVEL_HIGH);

    if(_d2_handle != NULL)
    {
        __BKPT(0);
    }

    _d2_handle = d2_opendevice(0);
    if(_d2_handle == NULL)
    {
        __BKPT(0);
    }

    /* bind the hardware */
    result = d2_inithw(_d2_handle, 0);
    if (result != D2_OK)
    {

        d2_closedevice(_d2_handle);
        __BKPT(0);
    }

    //
    // Set various D2 parameters
    //


    /* set blocksize for default displaylist */
    result = d2_setdlistblocksize(_d2_handle, 25);
    if(D2_OK != result)
    {

        d2_closedevice(_d2_handle);
        __BKPT(0);
    }

    _renderbuffer = d2_newrenderbuffer(_d2_handle, 20, 20);
    if(!_renderbuffer) {

        d2_closedevice(_d2_handle);

        __BKPT(0);
    }

    result = d2_selectrenderbuffer(_d2_handle, _renderbuffer);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_framebuffer(_d2_handle,
                  &fb_background[0][0],
                  480,
                   480,
                   854,
                   d2_mode_rgb565);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_selectrenderbuffer(_d2_handle, _renderbuffer);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_setfillmode( _d2_handle, d2_fm_twocolor  );
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_setcolor(_d2_handle, 0, 0x000000ff);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_setcolor(_d2_handle, 1, 0x0000ff00);
    if(D2_OK != result)
    {
        __BKPT(0);
    }



    result = d2_rendertri(    _d2_handle,
    (d2_point)      D2_FIX4( 100),
    (d2_point)      D2_FIX4( 100),
    (d2_point)      D2_FIX4( 200),
    (d2_point)      D2_FIX4( 200),
    (d2_point)      D2_FIX4( 100),
    (d2_point)      D2_FIX4( 200),
    flags   );
    if(D2_OK != result)
    {
        __BKPT(0);
    }


    //
    // Execute render operations
    //
    result = d2_executerenderbuffer(_d2_handle, _renderbuffer, 0);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_flushframe(_d2_handle);
    if(D2_OK != result)
    {
        __BKPT(0);
    }

    while (1)
    {
        vTaskDelay (5);
    }
#else
    lv_init();

#if LV_USE_DRAW_DAVE2D
    lv_draw_dave2d_init();
#endif

    lv_port_disp_init();

    lv_port_indev_init();

#if (1 == LV_USE_DEMO_BENCHMARK)
    //disp_disable_update();

    lv_demo_benchmark_set_finished_cb(&on_benchmark_finished);
    lv_demo_benchmark_set_max_speed(true);

    lv_demo_benchmark();
#endif

#if (1 == LV_USE_DEMO_MUSIC)
    lv_demo_music();
#endif

#if (1 == LV_USE_DEMO_KEYPAD_AND_ENCODER)
    lv_demo_keypad_encoder();

#endif

#if (1 == LV_USE_DEMO_STRESS)
    lv_demo_stress();
#endif

#if (1 == LV_USE_DEMO_WIDGETS)
    lv_demo_widgets();
#endif

#if 1
    err = R_GPT_Open(&g_timer0_ctrl, &g_timer0_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0);
    }

    err = R_GPT_Start(&g_timer0_ctrl);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0);
    }

#endif
    /* TODO: add your own code here */
    while (1)
    {
        lv_timer_handler();
        vTaskDelay (100);
    }
#endif
}

#if D2D_TEST
static void disp_init(void)
{
    fsp_err_t err;

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

    R_BSP_SoftwareDelay(150, BSP_DELAY_UNITS_MILLISECONDS);

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

    uint8_t * p_fb;
    p_fb = &fb_background[0][0];


    do
    {
        err =
            R_GLCDC_BufferChange(&g_display0_ctrl,
                                 (uint8_t *) p_fb,
                                 (display_frame_layer_t) 0);
    } while (FSP_ERR_INVALID_UPDATE_TIMING == err);


}
#endif

void vApplicationMallocFailedHook( void )
{
    __BKPT(0);
}
