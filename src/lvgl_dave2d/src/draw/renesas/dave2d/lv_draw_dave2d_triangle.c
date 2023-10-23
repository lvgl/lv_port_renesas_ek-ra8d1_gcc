#include <renesas/dave2d/lv_draw_dave2d.h>
#if LV_USE_DRAW_DAVE2D


void lv_draw_dave2d_triangle(lv_draw_unit_t * draw_unit, const lv_draw_triangle_dsc_t * dsc)
{
    FSP_PARAMETER_NOT_USED(draw_unit);
    FSP_PARAMETER_NOT_USED(dsc);
    lv_area_t clipped_area;
    d2_u32      flags = 0;
    lv_color_t  colour;
    lv_grad_t * grad = NULL;
    d2_color * p_texture_buf = NULL;
    lv_draw_dave2d_unit_t * draw_dave2d_unit = (lv_draw_dave2d_unit_t *)draw_unit;

    d2_color lv_tex_colour;
    lv_opa_t lv_tex_opa;

#if CHECK_RENDERING_TO_VISIBLE_FB
    if ((R_GLCDC->GR[0].FLM2 == (uint32_t)draw_unit->target_layer->buf))
    {
        __BKPT(0); //Are we copying into the visable framebuffer?
    }
#endif
    lv_area_t tri_area;
    tri_area.x1 = LV_MIN3(dsc->p[0].x, dsc->p[1].x, dsc->p[2].x);
    tri_area.y1 = LV_MIN3(dsc->p[0].y, dsc->p[1].y, dsc->p[2].y);
    tri_area.x2 = LV_MAX3(dsc->p[0].x, dsc->p[1].x, dsc->p[2].x);
    tri_area.y2 = LV_MAX3(dsc->p[0].y, dsc->p[1].y, dsc->p[2].y);


    if(!_lv_area_intersect(&clipped_area, &tri_area, draw_unit->clip_area)) return;

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
     * [0]: left bottom
     * [1]: top
     * [2]: right bottom*/


    if(dsc->p[0].y <= dsc->p[1].y && dsc->p[0].y <= dsc->p[2].y) {
        p[1] = dsc->p[0];
        if(dsc->p[1].x < dsc->p[2].x) {
            p[0] = dsc->p[1];
            p[2] = dsc->p[2];
        }
        else {
            p[0] = dsc->p[2];
            p[2] = dsc->p[1];
        }
    }
    else if(dsc->p[1].y <= dsc->p[0].y && dsc->p[1].y <= dsc->p[2].y) {
        p[1] = dsc->p[1];
        if(dsc->p[0].x < dsc->p[2].x) {
            p[0] = dsc->p[0];
            p[2] = dsc->p[2];
        }
        else {
            p[0] = dsc->p[2];
            p[2] = dsc->p[0];
        }
    }
    else {
        p[1] = dsc->p[2];
        if(dsc->p[0].x < dsc->p[1].x) {
            p[0] = dsc->p[0];
            p[2] = dsc->p[1];
        }
        else {
            p[0] = dsc->p[1];
            p[2] = dsc->p[0];
        }
    }

    if (LV_GRAD_DIR_NONE != dsc->bg_grad.dir)
    {
        grad = lv_gradient_get(&dsc->bg_grad, lv_area_get_width(&tri_area), lv_area_get_height(&tri_area));


        lv_coord_t area_w = lv_area_get_width(&clipped_area);
        lv_coord_t area_h = lv_area_get_height(&clipped_area);
        p_texture_buf = lv_malloc(area_w * area_h * sizeof(d2_color));

        if ( LV_GRAD_DIR_VER == dsc->bg_grad.dir)
        {
            int32_t x = 0;
            int32_t y = 0;
            lv_coord_t width = lv_area_get_width(&clipped_area);
            lv_coord_t height = lv_area_get_height(&clipped_area);


            for (y = 0; y < height; y++ )
            {
                lv_tex_colour = lv_draw_dave2d_lv_colour_to_d2_colour(grad->color_map[y]);
                lv_tex_opa = grad->opa_map[y];
                d2_color tex_col = (lv_tex_opa << 24) | lv_tex_colour;
                //d2_color tex_col = (y * 3) << 24 | (y * 4) << 16 | (y * 1) << 8 | (y * 2) << 16;

                for(x = 0; x < width; x++)
                {
                    p_texture_buf[(y * width) + x] = (tex_col);
                }
            }
        }
        else if (LV_GRAD_DIR_HOR == dsc->bg_grad.dir)
        {
            int32_t x = 0;
            int32_t y = 0;
            lv_coord_t width = lv_area_get_width(&clipped_area);
            lv_coord_t height = lv_area_get_height(&clipped_area);

             for(x = 0; x < width; x++)
             {
                 lv_tex_colour = lv_draw_dave2d_lv_colour_to_d2_colour(grad->color_map[x]);
                  lv_tex_opa = grad->opa_map[x];
                  d2_color tex_col = (lv_tex_opa << 24) | lv_tex_colour;
                 p_texture_buf[x] = (tex_col);
             }

            for (y = 1; y < height; y++ )
            {
                lv_memcpy(&p_texture_buf[y * width], &p_texture_buf[0], width * sizeof(int));
            }
        }
        d2_setfillmode(  draw_dave2d_unit->d2_handle, d2_fm_texture);
        d2_settexture(  draw_dave2d_unit->d2_handle,
                        p_texture_buf,
                        area_w,
                        area_w,
                        area_h,
                        d2_mode_argb8888  );

        d2_settextureoperation( draw_dave2d_unit->d2_handle,
                d2_to_copy, d2_to_copy, d2_to_copy, d2_to_copy );

        d2_setblendmode(    draw_dave2d_unit->d2_handle,
                d2_bm_alpha , d2_bm_one_minus_alpha   );


        d2_setalphablendmode(   draw_dave2d_unit->d2_handle,
                d2_bm_one, d2_bm_one_minus_alpha  ); //Alpha blending

    }
    else
    {
        colour = dsc->bg_color;
        d2_setfillmode(  draw_dave2d_unit->d2_handle, d2_fm_color ); //default
        d2_setalpha( draw_dave2d_unit->d2_handle, dsc->bg_opa  );

        d2_setcolor(draw_dave2d_unit->d2_handle, 0, lv_draw_dave2d_lv_colour_to_d2_colour(colour));

    }

    d2_framebuffer(draw_dave2d_unit->d2_handle,
                   draw_unit->target_layer->buf,
                   lv_area_get_width(&draw_unit->target_layer->buf_area),
                   (d2_u32)lv_area_get_width(&draw_unit->target_layer->buf_area),
                   (d2_u32)lv_area_get_height(&draw_unit->target_layer->buf_area),
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
