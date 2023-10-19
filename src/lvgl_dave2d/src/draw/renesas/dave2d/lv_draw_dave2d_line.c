#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D


void lv_draw_dave2d_line(lv_draw_unit_t * draw_unit, const lv_draw_line_dsc_t * dsc)
{

    lv_draw_dave2d_unit_t * draw_dave2d_unit = (lv_draw_dave2d_unit_t *)draw_unit;
    lv_area_t clip_line;
    d2_u32     mode;

    //LV_LOG_USER("db = 0x%x FB = 0x%lx\r\n",  (unsigned int)draw_unit->target_layer->buf, R_GLCDC->GR[0].FLM2);



    clip_line.x1 = LV_MIN(dsc->p1.x, dsc->p2.x) - dsc->width / 2;
    clip_line.x2 = LV_MAX(dsc->p1.x, dsc->p2.x) + dsc->width / 2;
    clip_line.y1 = LV_MIN(dsc->p1.y, dsc->p2.y) - dsc->width / 2;
    clip_line.y2 = LV_MAX(dsc->p1.y, dsc->p2.y) + dsc->width / 2;

    bool is_common;
    is_common = _lv_area_intersect(&clip_line, &clip_line, draw_unit->clip_area);
    if(!is_common) return;

#if LV_USE_OS
    lv_result_t  status;
    status = lv_mutex_lock(draw_dave2d_unit->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

    if ((R_GLCDC->GR[0].FLM2 == (uint32_t)draw_unit->target_layer->buf))
    {
       __BKPT(0); //Are we copying into the visable framebuffer?
    }

    bool dashed = dsc->dash_gap && dsc->dash_width;

    if (dashed)
    {
       /* TODO */
       __NOP();
    }

    d2_u32 dest_stride = draw_unit->target_layer->buf_stride;
    //
    // Generate render operations
    //
    d2_framebuffer(draw_dave2d_unit->d2_handle,
                   draw_unit->target_layer->buf,
                   lv_area_get_width(&draw_unit->target_layer->buf_area),
                   lv_area_get_width(&draw_unit->target_layer->buf_area),
                   (d2_u32)lv_area_get_height(&draw_unit->target_layer->buf_area),
                   lv_draw_dave2d_cf_fb_get());
    d2_selectrenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer);
    d2_setcolor(draw_dave2d_unit->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(dsc->color));


    d2_setalpha( draw_dave2d_unit->d2_handle, dsc->opa  );


    d2_cliprect(draw_dave2d_unit->d2_handle, clip_line.x1, clip_line.y1, clip_line.x2, clip_line.y2);

    if ((dsc->round_end == 1) || (dsc->round_start == 1))
    {
       mode = d2_lc_round;
    }
    else
    {
       mode = d2_lc_butt; // lines end directly at endpoints
    }

    d2_setlinecap( draw_dave2d_unit->d2_handle, mode);


    d2_renderline(draw_dave2d_unit->d2_handle, D2_FIX4(dsc->p1.x), D2_FIX4 (dsc->p1.y),D2_FIX4 (dsc->p2.x),
                     D2_FIX4 (dsc->p2.y), D2_FIX4 (dsc->width), d2_le_exclude_none);

    //
    // Execute render operations
    //
    d2_executerenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer, 0);
    d2_flushframe(draw_dave2d_unit->d2_handle);

#if LV_USE_OS
    status = lv_mutex_unlock(draw_dave2d_unit->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif
}

#endif /*LV_USE_DRAW_DAVE2D*/
