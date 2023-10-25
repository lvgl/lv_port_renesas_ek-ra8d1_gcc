#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D

void lv_draw_dave2d_triangle(lv_draw_dave2d_unit_t * draw_dave2d_unit, const lv_draw_triangle_dsc_t * dsc)
{
    lv_area_t clipped_area;
    d2_u32      flags = 0;
    lv_color_t  colour;
    lv_grad_t * grad = NULL;
    d2_color * p_texture_buf = NULL;

    d2_u8 current_alpha_mode = 0;
    d2_alpha current_alpha_value = 0;

#if CHECK_RENDERING_TO_VISIBLE_FB
    if ((R_GLCDC->GR[0].FLM2 == (uint32_t)draw_dave2d_unit->base_unit.target_layer->buf))
    {
        __BKPT(0); //Are we copying into the visible framebuffer?
    }
#endif
    lv_area_t tri_area;
    tri_area.x1 = LV_MIN3(dsc->p[0].x, dsc->p[1].x, dsc->p[2].x);
    tri_area.y1 = LV_MIN3(dsc->p[0].y, dsc->p[1].y, dsc->p[2].y);
    tri_area.x2 = LV_MAX3(dsc->p[0].x, dsc->p[1].x, dsc->p[2].x);
    tri_area.y2 = LV_MAX3(dsc->p[0].y, dsc->p[1].y, dsc->p[2].y);


    if(!_lv_area_intersect(&clipped_area, &tri_area, draw_dave2d_unit->base_unit.clip_area)) return;

#if LV_USE_OS
    lv_result_t  status;
    status = lv_mutex_lock(draw_dave2d_unit->pd2Mutex );
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }
#endif

    lv_point_t p[3];
    p[0] = dsc->p[0];
    p[1] = dsc->p[1];
    p[2] = dsc->p[2];

    /*Order the points like this:
     * [0]: top
     * [1]: right bottom
     * [2]: left bottom */


    if(dsc->p[0].y <= dsc->p[1].y && dsc->p[0].y <= dsc->p[2].y) {
        p[0] = dsc->p[0];
        if(dsc->p[1].x < dsc->p[2].x) {
            p[2] = dsc->p[1];
            p[1] = dsc->p[2];
        }
        else {
            p[2] = dsc->p[2];
            p[1] = dsc->p[1];
        }
    }
    else if(dsc->p[1].y <= dsc->p[0].y && dsc->p[1].y <= dsc->p[2].y) {
        p[0] = dsc->p[1];
        if(dsc->p[0].x < dsc->p[2].x) {
            p[2] = dsc->p[0];
            p[1] = dsc->p[2];
        }
        else {
            p[2] = dsc->p[2];
            p[1] = dsc->p[0];
        }
    }
    else {
        p[0] = dsc->p[2];
        if(dsc->p[0].x < dsc->p[1].x) {
            p[2] = dsc->p[0];
            p[1] = dsc->p[1];
        }
        else {
            p[2] = dsc->p[1];
            p[1] = dsc->p[0];
        }
    }

    if (LV_GRAD_DIR_NONE != dsc->bg_grad.dir)
    {
        grad = lv_gradient_get(&dsc->bg_grad, lv_area_get_width(&tri_area), lv_area_get_height(&tri_area));


        lv_coord_t area_w = lv_area_get_width(&clipped_area);
        lv_coord_t area_h = lv_area_get_height(&clipped_area);
        float a1;
        float a2;

        float y1;
        float y2;

        float y3;
        float y0;
        int16_t y0_i ;
        int16_t y3_i ;

        if ( LV_GRAD_DIR_VER == dsc->bg_grad.dir)
        {
             a1 = dsc->bg_grad.stops[0].opa;
             a2 = dsc->bg_grad.stops[dsc->bg_grad.stops_count - 1].opa;

             y1 = clipped_area.y1;
             y2 = clipped_area.y2;

             if (a1 < a2)
             {
                 /* TODO */
                 __BKPT(0);
                 y0 = 0.0f;//silence the compiler warning
                 y3 = 0.0f;

             }
             else
             {
                 y0 = y2 - ((y2 - y1)/(a2 - a1) * (a2)); //point where alpha is 0
                 y3 = y1 + ((y2 - y1)/(a2 - a1) * (255 - a1)); //point where alpha is 255

             }

              y0_i = (int16_t)y0;
              y3_i = (int16_t)y3;

              d2_setalphagradient(draw_dave2d_unit->d2_handle, 0, D2_FIX4(clipped_area.x1),  D2_FIX4(y0_i), D2_FIX4(0), D2_FIX4(y3_i - y0_i) );
        }
        else if (LV_GRAD_DIR_HOR == dsc->bg_grad.dir)
        {
            /* TODO */
            __BKPT(0);
        }

        current_alpha_mode = d2_getalphamode( draw_dave2d_unit->d2_handle  );
        current_alpha_value = d2_getalpha(draw_dave2d_unit->d2_handle );
        d2_setfillmode(draw_dave2d_unit->d2_handle, d2_fm_color);
        d2_setcolor(draw_dave2d_unit->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(dsc->bg_grad.stops[0].color));
        d2_setalphamode(draw_dave2d_unit->d2_handle, d2_am_gradient1 );




    }
    else
    {
        colour = dsc->bg_color;
        d2_setfillmode(  draw_dave2d_unit->d2_handle, d2_fm_color ); //default
        d2_setalpha( draw_dave2d_unit->d2_handle, dsc->bg_opa  );

        d2_setcolor(draw_dave2d_unit->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(colour));

    }

    d2_framebuffer(draw_dave2d_unit->d2_handle,
            draw_dave2d_unit->base_unit.target_layer->buf,
                   lv_area_get_width(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   (d2_u32)lv_area_get_width(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   (d2_u32)lv_area_get_height(&draw_dave2d_unit->base_unit.target_layer->buf_area),
                   lv_draw_dave2d_cf_fb_get());

    d2_selectrenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer);


    d2_cliprect(draw_dave2d_unit->d2_handle, clipped_area.x1, clipped_area.y1, clipped_area.x2, clipped_area.y2);

    d2_rendertri(    draw_dave2d_unit->d2_handle,
    (d2_point)      D2_FIX4( p[0].x),
    (d2_point)      D2_FIX4( p[0].y),
    (d2_point)      D2_FIX4( p[1].x),
    (d2_point)      D2_FIX4( p[1].y),
    (d2_point)      D2_FIX4( p[2].x),
    (d2_point)      D2_FIX4( p[2].y),
    flags   );

    //
    // Execute render operations
    //
    d2_executerenderbuffer(draw_dave2d_unit->d2_handle, draw_dave2d_unit->renderbuffer, 0);
    d2_flushframe(draw_dave2d_unit->d2_handle);

    if(grad) {
        lv_gradient_cleanup(grad);
    }

    if (p_texture_buf)
    {
        lv_free(p_texture_buf);
    }

    if (LV_GRAD_DIR_NONE != dsc->bg_grad.dir)
    {
        d2_setfillmode(  draw_dave2d_unit->d2_handle, d2_fm_color ); //default
        d2_settextureoperation( draw_dave2d_unit->d2_handle,
                d2_to_one, d2_to_copy, d2_to_copy, d2_to_copy ); //Defaults
        d2_setalphablendmode(   draw_dave2d_unit->d2_handle,
                d2_bm_one, d2_bm_zero  ); //Defaults
        d2_setblendmode(    draw_dave2d_unit->d2_handle,
                d2_bm_alpha , d2_bm_one_minus_alpha  ); //Defaults
        d2_setalphamode(draw_dave2d_unit->d2_handle, current_alpha_mode);
        d2_setalpha(draw_dave2d_unit->d2_handle, current_alpha_value);
    }

#if LV_USE_OS
    status = lv_mutex_unlock(draw_dave2d_unit->pd2Mutex);
    if (LV_RESULT_OK != status)
    {
        __BKPT(0);
    }


#endif

}


#endif /*LV_USE_DRAW_DAVE2D*/
