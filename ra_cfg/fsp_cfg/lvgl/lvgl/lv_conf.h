/* generated configuration header file - do not edit */
#ifndef LV_CONF_H_
#define LV_CONF_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "lv_conf_user.h"

#ifndef LV_CONF_SUPPRESS_DEFINE_CHECK
#define LV_CONF_SUPPRESS_DEFINE_CHECK
#endif

#ifndef LV_CONF_INCLUDE_SIMPLE
#define LV_CONF_INCLUDE_SIMPLE
#endif

#ifndef LV_KCONFIG_IGNORE
#define LV_KCONFIG_IGNORE
#endif

#ifndef LV_COLOR_DEPTH
#define LV_COLOR_DEPTH (16)
#endif

#ifndef LV_USE_STDLIB_MALLOC
#define LV_USE_STDLIB_MALLOC LV_STDLIB_BUILTIN
#endif

#if LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN
#ifndef LV_MEM_SIZE
#define LV_MEM_SIZE (0x20000)
#endif
#endif

#ifndef LV_USE_OS
#define LV_USE_OS (LV_OS_FREERTOS)
#endif

#ifndef LV_DRAW_LAYER_MAX_MEMORY
#define LV_DRAW_LAYER_MAX_MEMORY (0)
#endif

#ifndef LV_DRAW_LAYER_SIMPLE_BUF_SIZE
#define LV_DRAW_LAYER_SIMPLE_BUF_SIZE (0x6000)
#endif

#ifndef LV_DRAW_THREAD_STACK_SIZE
#define LV_DRAW_THREAD_STACK_SIZE (0x2000)
#endif

#ifndef LV_DRAW_THREAD_PRIO
#define LV_DRAW_THREAD_PRIO (LV_THREAD_PRIO_HIGH)
#endif

#ifndef LV_USE_DRAW_SW
#define LV_USE_DRAW_SW (1)
#endif

#if LV_USE_DRAW_SW == 1
#ifndef LV_DRAW_SW_SUPPORT_RGB565
#define LV_DRAW_SW_SUPPORT_RGB565 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_RGB565_SWAPPED
#define LV_DRAW_SW_SUPPORT_RGB565_SWAPPED (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_RGB565A8
#define LV_DRAW_SW_SUPPORT_RGB565A8 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_RGB888
#define LV_DRAW_SW_SUPPORT_RGB888 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_XRGB8888
#define LV_DRAW_SW_SUPPORT_XRGB8888 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_ARGB8888
#define LV_DRAW_SW_SUPPORT_ARGB8888 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_ARGB8888_PREMULTIPLIED
#define LV_DRAW_SW_SUPPORT_ARGB8888_PREMULTIPLIED (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_L8
#define LV_DRAW_SW_SUPPORT_L8 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_AL88
#define LV_DRAW_SW_SUPPORT_AL88 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_A8
#define LV_DRAW_SW_SUPPORT_A8 (1)
#endif

#ifndef LV_DRAW_SW_SUPPORT_I1
#define LV_DRAW_SW_SUPPORT_I1 (1)
#endif
#endif

#ifndef LV_USE_DRAW_DAVE2D
#define LV_USE_DRAW_DAVE2D (1)
#endif

#ifndef LV_ASSERT_HANDLER_INCLUDE
#define LV_ASSERT_HANDLER_INCLUDE <stdint.h>
#endif

#ifndef LV_ASSERT_HANDLER
#define LV_ASSERT_HANDLER 
#endif

#ifndef LV_USE_OBJ_NAME
#define LV_USE_OBJ_NAME (1)
#endif

#ifndef LV_USE_GESTURE_RECOGNITION
#define LV_USE_GESTURE_RECOGNITION (0)
#endif

#ifndef LV_FONT_MONTSERRAT_8
#define LV_FONT_MONTSERRAT_8 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_10
#define LV_FONT_MONTSERRAT_10 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_12
#define LV_FONT_MONTSERRAT_12 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_16
#define LV_FONT_MONTSERRAT_16 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_18
#define LV_FONT_MONTSERRAT_18 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_20
#define LV_FONT_MONTSERRAT_20 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_22
#define LV_FONT_MONTSERRAT_22 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_24
#define LV_FONT_MONTSERRAT_24 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_26
#define LV_FONT_MONTSERRAT_26 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_28
#define LV_FONT_MONTSERRAT_28 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_30
#define LV_FONT_MONTSERRAT_30 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_32
#define LV_FONT_MONTSERRAT_32 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_34
#define LV_FONT_MONTSERRAT_34 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_36
#define LV_FONT_MONTSERRAT_36 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_38
#define LV_FONT_MONTSERRAT_38 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_40
#define LV_FONT_MONTSERRAT_40 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_42
#define LV_FONT_MONTSERRAT_42 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_44
#define LV_FONT_MONTSERRAT_44 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_46
#define LV_FONT_MONTSERRAT_46 (1)
#endif
#ifndef LV_FONT_MONTSERRAT_48
#define LV_FONT_MONTSERRAT_48 (1)
#endif

#ifndef LV_FONT_DEJAVU_16_PERSIAN_HEBREW
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW (1)
#endif

#ifndef LV_FONT_SOURCE_HAN_SANS_SC_14_CJK
#define LV_FONT_SOURCE_HAN_SANS_SC_14_CJK (1)
#endif
#ifndef LV_FONT_SOURCE_HAN_SANS_SC_16_CJK
#define LV_FONT_SOURCE_HAN_SANS_SC_16_CJK (1)
#endif

#ifndef LV_FONT_UNSCII_8
#define LV_FONT_UNSCII_8 (1)
#endif
#ifndef LV_FONT_UNSCII_16
#define LV_FONT_UNSCII_16 (1)
#endif

#ifndef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &lv_font_montserrat_14
#endif

#ifndef LV_USE_FONT_PLACEHOLDER
#define LV_USE_FONT_PLACEHOLDER (1)
#endif

#ifndef LV_USE_BIDI
#define LV_USE_BIDI (0)
#endif

#ifndef LV_USE_ARABIC_PERSIAN_CHARS
#define LV_USE_ARABIC_PERSIAN_CHARS (0)
#endif

#ifndef LV_USE_IME_PINYIN
#define LV_USE_IME_PINYIN (0)
#endif

#if LV_USE_IME_PINYIN
    #ifndef LV_IME_PINYIN_USE_DEFAULT_DICT
        #define LV_IME_PINYIN_USE_DEFAULT_DICT (1)
    #endif

    #ifndef LV_IME_PINYIN_CAND_TEXT_NUM
        #define LV_IME_PINYIN_CAND_TEXT_NUM (6)
    #endif

    #ifndef LV_IME_PINYIN_USE_K9_MODE
        #define LV_IME_PINYIN_USE_K9_MODE (1)
    #endif

    #if LV_IME_PINYIN_USE_K9_MODE == 1
        #ifndef LV_IME_PINYIN_K9_CAND_TEXT_NUM
            #define LV_IME_PINYIN_K9_CAND_TEXT_NUM (3)
        #endif
    #endif
#endif

#ifndef LV_USE_FONT_MANAGER
#define LV_USE_FONT_MANAGER (0)
#endif

#if LV_USE_FONT_MANAGER
    #ifndef LV_FONT_MANAGER_NAME_MAX_LEN
        #define LV_FONT_MANAGER_NAME_MAX_LEN (32)
    #endif
#endif

#ifndef LV_BUILD_EXAMPLES
#define LV_BUILD_EXAMPLES (0)
#endif

#ifndef LV_BUILD_DEMOS
#define LV_BUILD_DEMOS (0)
#endif

#ifdef __cplusplus
}
#endif
#endif /* LV_CONF_H_ */
