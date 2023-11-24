#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D


void lv_draw_dave2d_fill(lv_draw_dave2d_unit_t * u, const lv_draw_fill_dsc_t * dsc, const lv_area_t * coords)
{
    d2_u32     mode;

    lv_area_t draw_area;
    lv_area_t buffer_area;
    uint32_t res;
    bool is_common;
    int32_t x;
    int32_t y;

    is_common = _lv_area_intersect(&draw_area, coords, u->base_unit.clip_area);
    if(!is_common) return;

#if LV_USE_OS
    lv_result_t  status;
    status = lv_mutex_lock(u->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

    buffer_area = u->base_unit.target_layer->buf_area;

    x = 0 - u->base_unit.target_layer->buf_area.x1;
    y = 0 - u->base_unit.target_layer->buf_area.y1;


    lv_area_move(&draw_area, x, y);
    lv_area_move(&buffer_area, x, y);

    d2_u32 dest_stride = u->base_unit.target_layer->buf_stride;

    //
    // Generate render operations
    //
#if D2_RENDER_EACH_OPERATION
    d2_selectrenderbuffer(u->d2_handle, u->renderbuffer);
#endif

    d2_framebuffer(u->d2_handle,
            u->base_unit.target_layer->buf,
            (d2_s32)u->base_unit.target_layer->buf_stride/lv_color_format_get_size(u->base_unit.target_layer->color_format),
            (d2_u32)lv_area_get_width(&buffer_area),
                   (d2_u32)lv_area_get_height(&buffer_area),
                   lv_draw_dave2d_cf_fb_get());


    d2_setcolor(u->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(dsc->color));
    d2_setalpha( u->d2_handle, dsc->opa);


    d2_cliprect(u->d2_handle, draw_area.x1, draw_area.y1, draw_area.x2, draw_area.y2);

    d2_renderbox(u->d2_handle, D2_FIX4(draw_area.x1),
                               D2_FIX4(draw_area.y1),
                               D2_FIX4(lv_area_get_width(&draw_area)),
                               D2_FIX4(lv_area_get_height(&draw_area)));

    //
    // Execute render operations
    //
#if D2_RENDER_EACH_OPERATION
    d2_executerenderbuffer(u->d2_handle, u->renderbuffer, 0);
    d2_flushframe(u->d2_handle);
#endif

#if LV_USE_OS
    status = lv_mutex_unlock(u->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif
}

#endif /*LV_USE_DRAW_DAVE2D*/
