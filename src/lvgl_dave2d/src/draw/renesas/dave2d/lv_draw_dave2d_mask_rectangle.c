#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D

void lv_draw_dave2d_mask_rect(lv_draw_dave2d_unit_t * draw_dave2d_unit, const lv_draw_mask_rect_dsc_t * dsc, const lv_area_t * coords)
{
    lv_area_t clipped_area;
    d2_u32      flags = 0;

    if(!_lv_area_intersect(&clipped_area, coords, draw_dave2d_unit->base_unit.clip_area)) return;

#if LV_USE_OS
    lv_result_t  status;
    status = lv_mutex_lock(draw_dave2d_unit->pd2Mutex );
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

#ifdef D2_RENDER_EACH_OPERATION
    d2_selectrenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer);
#endif

    d2_framebuffer(draw_dave2d_unit->d2_handle,
            draw_dave2d_unit->base_unit.target_layer->buf,
                   lv_area_get_width(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   (d2_u32)lv_area_get_width(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   (d2_u32)lv_area_get_height(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   lv_draw_dave2d_cf_fb_get());


    d2_cliprect(draw_dave2d_unit->d2_handle, clipped_area.x1, clipped_area.y1, clipped_area.x2, clipped_area.y2);

//    d2_s32 d2_renderbox(    draw_dave2d_unit->d2_handle,
//    d2_point        x1,
//    d2_point        y1,
//    d2_width        w,
//    d2_width        h   );

//
// Execute render operations
//
#ifdef D2_RENDER_EACH_OPERATION
    d2_executerenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer, 0);
    d2_flushframe(draw_dave2d_unit->d2_handle);
#endif

#if LV_USE_OS
    status = lv_mutex_unlock(draw_dave2d_unit->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif
}
#endif //LV_USE_DRAW_DAVE2D
