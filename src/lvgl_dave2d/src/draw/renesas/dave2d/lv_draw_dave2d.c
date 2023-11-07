/**
 * @file lv_draw_dave2d.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D

/*********************
 *      DEFINES
 *********************/
#define DRAW_UNIT_ID_DAVE2D     4

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
#if LV_USE_OS
    static void _dave2d_render_thread_cb(void * ptr);
#endif

static void execute_drawing(lv_draw_dave2d_unit_t * u);

static void _dave2d_buf_invalidate_cache_cb(void * buf, uint32_t stride, lv_color_format_t color_format,
        const lv_area_t * area);

static  void _dave2d_buf_copy(void * dest_buf, uint32_t dest_w, uint32_t dest_h, const lv_area_t * dest_area,
        void * src_buf,  uint32_t src_w, uint32_t src_h, const lv_area_t * src_area, lv_color_format_t color_format);

static int32_t _dave2d_evaluate(lv_draw_unit_t * draw_unit, lv_draw_task_t * task);

static int32_t lv_draw_dave2d_dispatch(lv_draw_unit_t * draw_unit, lv_layer_t * layer);

static d2_s32 lv_dave2d_init(void);

static void lv_draw_buf_dave2d_init_handlers(void);

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

d2_device * _d2_handle;
d2_renderbuffer * _renderbuffer;

#if LV_USE_OS
lv_mutex_t xd2Semaphore;
#endif


/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_draw_dave2d_init(void)
{
    d2_s32 result = D2_OK;

    lv_draw_buf_dave2d_init_handlers();



    lv_draw_dave2d_unit_t * draw_dave2d_unit = lv_draw_create_unit(sizeof(lv_draw_dave2d_unit_t));
    draw_dave2d_unit->base_unit.dispatch_cb = lv_draw_dave2d_dispatch;
    draw_dave2d_unit->base_unit.evaluate_cb = _dave2d_evaluate;
    draw_dave2d_unit->idx = DRAW_UNIT_ID_DAVE2D;

    result = lv_dave2d_init();
    if (D2_OK != result)
    {
        __BKPT(0);
    }

#if LV_USE_OS
    lv_result_t res;
    res =  lv_mutex_init( &xd2Semaphore );
    if (LV_RESULT_OK != res)
    {
        __BKPT(0);
    }

    draw_dave2d_unit->pd2Mutex    = &xd2Semaphore;
#endif


    draw_dave2d_unit->d2_handle = _d2_handle;
    draw_dave2d_unit->renderbuffer = _renderbuffer;


#if LV_USE_OS
    lv_thread_init(&draw_dave2d_unit->thread, LV_THREAD_PRIO_HIGH, _dave2d_render_thread_cb, 8 * 1024, draw_dave2d_unit);
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_draw_buf_dave2d_init_handlers(void)
{
    lv_draw_buf_handlers_t * handlers = lv_draw_buf_get_handlers();

#if defined(RENESAS_CORTEX_M85)
#if (BSP_CFG_DCACHE_ENABLED)
    handlers->invalidate_cache_cb = _dave2d_buf_invalidate_cache_cb;
#endif
#endif
    handlers->buf_copy_cb = _dave2d_buf_copy;
}

#if defined(RENESAS_CORTEX_M85)
static void _dave2d_buf_invalidate_cache_cb(void * buf, uint32_t stride, lv_color_format_t color_format,
                                                const lv_area_t * area)
{


#if !(BSP_CFG_DCACHE_ENABLED)
    /* TODO */
    FSP_PARAMETER_NOT_USED(buf);
    FSP_PARAMETER_NOT_USED(stride);
    FSP_PARAMETER_NOT_USED(color_format);
    FSP_PARAMETER_NOT_USED(area);

#else
    uint8_t * address = buf;
    int32_t size = 0;

    uint8_t bytes_per_pixel = lv_color_format_get_size(color_format);


    address = address + (area->x1 * bytes_per_pixel) + (stride * (uint32_t)area->y1 * bytes_per_pixel);
    size    = ((stride - area->x1) * bytes_per_pixel) + ((area->y2 - area->y1) * stride * bytes_per_pixel) + (area->x2 * bytes_per_pixel);

    SCB_CleanInvalidateDCache_by_Addr(address, size);
#endif
}
#endif

static void _dave2d_buf_copy(void * dest_buf, uint32_t dest_w, uint32_t dest_h, const lv_area_t * dest_area,
                 void * src_buf,  uint32_t src_w, uint32_t src_h, const lv_area_t * src_area, lv_color_format_t color_format)
{
    lv_area_t  screen;
    d2_s32     result;

#if LV_USE_OS
    lv_result_t  status;

    status = lv_mutex_lock( &xd2Semaphore );
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

#if CHECK_RENDERING_TO_VISIBLE_FB
    if (R_GLCDC->GR[0].FLM2 == (uint32_t)dest_buf)
    {
        __BKPT(0); //Are we copying into the visible framebuffer?
    }
#endif

    screen.x1 = 0;
    screen.y1 = 0;
    screen.x2 = DISPLAY_HSIZE_INPUT0;
    screen.y2 = DISPLAY_VSIZE_INPUT0;

    result = d2_selectrenderbuffer(_d2_handle, _renderbuffer);
    if (D2_OK != result)
    {
        __BKPT(0);
    }

    // Generate render operations
    result = d2_framebuffer(_d2_handle, (uint16_t *)dest_buf, DISPLAY_HSIZE_INPUT0, DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0,
                            DISPLAY_VSIZE_INPUT0, lv_draw_dave2d_cf_fb_get());
    if (D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_cliprect(_d2_handle, screen.x1, screen.y1, screen.x2, screen.y2);
    if (D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_setblitsrc(_d2_handle, (void *) src_buf, (d2_s32)src_w,  DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0, (d2_s32)src_h, lv_draw_dave2d_lv_colour_fmt_to_d2_fmt(color_format));
    if (D2_OK != result)
    {
        __BKPT(0);
    }

    result = d2_blitcopy(_d2_handle, (d2_s32)src_w, (d2_s32)src_h, (d2_blitpos)src_area->x1, (d2_blitpos)src_area->y1, D2_FIX4(dest_w), D2_FIX4(dest_h),
                D2_FIX4(dest_area->x1), D2_FIX4(dest_area->y1), 0);
    if (D2_OK != result)
    {
        __BKPT(0);
    }

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

#if LV_USE_OS
    status = lv_mutex_unlock( &xd2Semaphore );
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

}

static int32_t _dave2d_evaluate(lv_draw_unit_t * u, lv_draw_task_t * t)
{
    LV_UNUSED(u);

    switch(t->type) {
        case LV_DRAW_TASK_TYPE_FILL: {

                return 0;
            }

        case LV_DRAW_TASK_TYPE_BG_IMG: {

                return 0;
            }

        case LV_DRAW_TASK_TYPE_LAYER: {

                return 0;
            }

        case LV_DRAW_TASK_TYPE_IMAGE: {
            return 0;
        }

        case LV_DRAW_TASK_TYPE_BORDER: {
            return 0;
        }

        case  LV_DRAW_TASK_TYPE_BOX_SHADOW: {
            return 0;
        }

        case  LV_DRAW_TASK_TYPE_LABEL: {
            return 0;
        }

        case LV_DRAW_TASK_TYPE_LINE: {
#if 1
            t->preferred_draw_unit_id = DRAW_UNIT_ID_DAVE2D;
            return 1;
#else
            return 0;
#endif
        }

        case  LV_DRAW_TASK_TYPE_ARC: {
#if 1
            t->preferred_draw_unit_id = DRAW_UNIT_ID_DAVE2D;
            return 1;
#else
            return 0;
#endif
        }

        case LV_DRAW_TASK_TYPE_TRIANGLE: {
#if 1
            t->preferred_draw_unit_id = DRAW_UNIT_ID_DAVE2D;
            return 1;
#else
            return 0;
#endif
        }

        case  LV_DRAW_TASK_TYPE_MASK_RECTANGLE: {
            return 0;
        }

        case LV_DRAW_TASK_TYPE_MASK_BITMAP: {
            return 0;
        }

        default:
            return 0;
    }

    return 0;
}

static int32_t lv_draw_dave2d_dispatch(lv_draw_unit_t * draw_unit, lv_layer_t * layer)
{
    lv_draw_dave2d_unit_t * draw_dave2d_unit = (lv_draw_dave2d_unit_t *) draw_unit;

    /*Return immediately if it's busy with draw task*/
    if(draw_dave2d_unit->task_act) return 0;

    lv_draw_task_t * t = NULL;
    t = lv_draw_get_next_available_task(layer, NULL, DRAW_UNIT_ID_DAVE2D);

    /* Return 0 is no selection, some tasks can be supported by other units. */
    if(t == NULL || t->preferred_draw_unit_id != DRAW_UNIT_ID_DAVE2D)
        return 0;

    t->state = LV_DRAW_TASK_STATE_IN_PROGRESS;
    draw_dave2d_unit->base_unit.target_layer = layer;
    draw_dave2d_unit->base_unit.clip_area = &t->clip_area;
    draw_dave2d_unit->task_act = t;

#if LV_USE_OS
    /*Let the render thread work*/
    lv_thread_sync_signal(&draw_dave2d_unit->sync);
#else
    execute_drawing(draw_dave2d_unit);

    draw_dave2d_unit->task_act->state = LV_DRAW_TASK_STATE_READY;
    draw_dave2d_unit->task_act = NULL;

    /*The draw unit is free now. Request a new dispatching as it can get a new task*/
    lv_draw_dispatch_request();

#endif
    return 1;
}

#if LV_USE_OS
static void _dave2d_render_thread_cb(void * ptr)
{
    lv_draw_dave2d_unit_t * u = ptr;

    lv_thread_sync_init(&u->sync);

    while(1) {
        while(u->task_act == NULL) {
            lv_thread_sync_wait(&u->sync);
        }

        execute_drawing(u);

        /*Cleanup*/
        u->task_act->state = LV_DRAW_TASK_STATE_READY;
        u->task_act = NULL;

        /*The draw unit is free now. Request a new dispatching as it can get a new task*/
        lv_draw_dispatch_request();
    }
}
#endif

static void execute_drawing(lv_draw_dave2d_unit_t * u)
{
    /*Render the draw task*/
    lv_draw_task_t * t = u->task_act;
    lv_layer_t* layer = u->base_unit.target_layer;

    /* Invalidate cache */
    lv_draw_buf_invalidate_cache(layer->buf, layer->buf_stride, layer->color_format, &t->area);

    switch(t->type) {
        case LV_DRAW_TASK_TYPE_FILL:
            //lv_draw_dave2d_fill(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_BORDER:
            //lv_draw_dave2d_border(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_BOX_SHADOW:
            //lv_draw_dave2d_box_shadow(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_BG_IMG:
            //lv_draw_dave2d_bg_image(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_LABEL:
            //lv_draw_dave2d_label(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_IMAGE:
            //lv_draw_dave2d_image(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_LINE:
            lv_draw_dave2d_line(u, t->draw_dsc);
            break;
        case LV_DRAW_TASK_TYPE_ARC:
            lv_draw_dave2d_arc(u, t->draw_dsc, &t->area);
            break;

        case LV_DRAW_TASK_TYPE_TRIANGLE:
            lv_draw_dave2d_triangle(u, t->draw_dsc);
            break;
        case LV_DRAW_TASK_TYPE_LAYER:
            //lv_draw_dave2d_layer(u, t->draw_dsc, &t->area);
            break;
        case LV_DRAW_TASK_TYPE_MASK_RECTANGLE:
            //lv_draw_dave2d_mask_rect(u, t->draw_dsc, &t->area);
            break;
        default:
            break;
    }

}

static d2_s32 lv_dave2d_init(void)
{
    d2_s32 result = D2_OK;

    if(_d2_handle != NULL)
    {
        return D2_NOMEMORY;
    }

    _d2_handle = d2_opendevice(0);
    if(_d2_handle == NULL)
    {
        return D2_NOMEMORY;
    }

    /* bind the hardware */
    result = d2_inithw(_d2_handle, 0);
    if (result != D2_OK)
    {
        LV_LOG_ERROR("Could NOT d2_inithw\n");
        d2_closedevice(_d2_handle);
        return result;
    }

    //
    // Set various D2 parameters
    //
    result = d2_setblendmode(_d2_handle, d2_bm_alpha, d2_bm_one_minus_alpha);
    result = d2_setalphamode(_d2_handle, d2_am_constant);
    result = d2_setalpha(_d2_handle, UINT8_MAX);
    result = d2_setantialiasing(_d2_handle, 1);
    result = d2_setlinecap(_d2_handle, d2_lc_butt);
    result = d2_setlinejoin(_d2_handle, d2_lj_miter);

    /* set blocksize for default displaylist */
    result = d2_setdlistblocksize(_d2_handle, 25);
    if(D2_OK != result)
    {
        LV_LOG_ERROR("Could NOT d2_setdlistblocksize\n");
        d2_closedevice(_d2_handle);
        return result;
    }

    _renderbuffer = d2_newrenderbuffer(_d2_handle, 20, 20);
    if(!_renderbuffer) {
        LV_LOG_ERROR("NO renderbuffer\n");
        d2_closedevice(_d2_handle);

        return D2_NOMEMORY;
    }

    result = d2_selectrenderbuffer(_d2_handle, _renderbuffer);
    if(D2_OK != result)
    {
        LV_LOG_ERROR("Could NOT d2_setdlistblocksize\n");
        d2_closedevice(_d2_handle);
    }

    return result;
}

#endif /*LV_USE_DRAW_DAVE2D*/
