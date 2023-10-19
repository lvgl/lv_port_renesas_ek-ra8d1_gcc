#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D

void lv_draw_dave2d_arc(lv_draw_unit_t * draw_unit, const lv_draw_arc_dsc_t * dsc, const lv_area_t * coords)
{

    uint32_t                flags = 0;
    int32_t sin_start;
    int32_t cos_start;
    int32_t sin_end;
    int32_t cos_end;
    lv_draw_dave2d_unit_t * draw_dave2d_unit = (lv_draw_dave2d_unit_t *)draw_unit;

#if CHECK_RENDERING_TO_VISABLE_FB
    if ((R_GLCDC->GR[0].FLM2 == (uint32_t)draw_unit->target_layer->buf))
    {
        __BKPT(0); //Are we copying into the visable framebuffer?
    }
#endif

    lv_area_t clipped_area;

    if(!_lv_area_intersect(&clipped_area, coords, draw_unit->clip_area)) return;

    //
    // If both angles are equal (e.g. 0 and 0 or 180 and 180) nothing has to be done
    //
    if (dsc->start_angle == dsc->end_angle )
    {
        return;                      // Nothing to do, no angle - no arc
    }

#if LV_USE_OS
    lv_result_t  status;
    status = lv_mutex_lock(draw_dave2d_unit->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

    //
    // Generate render operations
    //
    d2_framebuffer(draw_dave2d_unit->d2_handle,
                   draw_unit->target_layer->buf,
                   lv_area_get_width(&draw_unit->target_layer->buf_area),
                   (d2_u32)lv_area_get_width(&draw_unit->target_layer->buf_area),
                   (d2_u32)lv_area_get_height(&draw_unit->target_layer->buf_area),
                   lv_draw_dave2d_cf_fb_get());

    d2_selectrenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer);
    d2_setalpha( draw_dave2d_unit->d2_handle, dsc->opa  );

    d2_setcolor(draw_dave2d_unit->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(dsc->color));

    d2_cliprect(draw_dave2d_unit->d2_handle, clipped_area.x1, clipped_area.y1, clipped_area.x2, clipped_area.y2);

    if (360 <= LV_ABS(dsc->start_angle - dsc->end_angle))
    {
        d2_rendercircle(draw_dave2d_unit->d2_handle,
                              (d2_point)D2_FIX4(dsc->center.x),
                              (d2_point) D2_FIX4 (dsc->center.y),
                              (d2_width) D2_FIX4(dsc->radius - dsc->width/2 ),
                              (d2_width) D2_FIX4 (dsc->width));
    }
    else //An ARC, not a full circle
    {
        //
        // If the difference between both is larger than 180 degrees we must use the concave flag
        //
        /** Set d2_wf_concave flag if the pie object to draw is concave shape. */
        if ((LV_ABS(dsc->start_angle - dsc->end_angle) > 180) || ((dsc->end_angle < dsc->start_angle) && (LV_ABS(dsc->start_angle - (dsc->end_angle + 360)) > 180)))
        {
            flags = d2_wf_concave;
        }
        else
        {
             flags = 0;
        }

        sin_start = lv_trigo_sin((int16_t)dsc->start_angle);
        cos_start = lv_trigo_cos((int16_t)dsc->start_angle);

        sin_end   = lv_trigo_sin((int16_t)dsc->end_angle);
        cos_end   = lv_trigo_cos((int16_t)dsc->end_angle);

        d2_renderwedge(draw_dave2d_unit->d2_handle,
                        (d2_point)D2_FIX4(dsc->center.x),
                        (d2_point) D2_FIX4 (dsc->center.y),
                        (d2_width) D2_FIX4(dsc->radius - dsc->width/2 ),
                        (d2_width) D2_FIX4 (dsc->width),
                        -(d2_s32) (sin_start << 1),
                        (d2_s32)  (cos_start << 1),
                        (d2_s32)  (sin_end << 1),
                        -(d2_s32) (cos_end << 1),
                          flags);

        if(dsc->rounded)
        {
            lv_point_t start_coord;
            lv_point_t end_coord;

            start_coord.x = dsc->center.x + (int16_t)(((dsc->radius - dsc->width/2) * cos_start) >> LV_TRIGO_SHIFT);
            start_coord.y = dsc->center.y + (int16_t)(((dsc->radius - dsc->width/2) * sin_start) >> LV_TRIGO_SHIFT);


            /** Render a circle. */
            d2_rendercircle(draw_dave2d_unit->d2_handle,
                                              (d2_point) D2_FIX4((uint16_t) (start_coord.x)),
                                              (d2_point) D2_FIX4((uint16_t) (start_coord.y)),
                                              (d2_width) D2_FIX4(dsc->width/2), 0);

            end_coord.x = dsc->center.x + (int16_t)(((dsc->radius - dsc->width/2) * cos_end) >> LV_TRIGO_SHIFT);
            end_coord.y = dsc->center.y + (int16_t)(((dsc->radius - dsc->width/2) * sin_end) >> LV_TRIGO_SHIFT);

            /** Render a circle. */
            d2_rendercircle(draw_dave2d_unit->d2_handle,
                                              (d2_point) D2_FIX4((uint16_t) (end_coord.x)),
                                              (d2_point) D2_FIX4((uint16_t) (end_coord.y)),
                                              (d2_width) D2_FIX4(dsc->width/2), 0);
        }
    }

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
