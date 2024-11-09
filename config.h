/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
// #define RGBLIGHT_DEFAULT_HUE 43
// #define RGBLIGHT_DEFAULT_ON true
// #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_EFFECT_BREATHING

// #ifndef RGBLIGHT_LIMIT_VAL
// #define RGBLIGHT_LIMIT_VAL 150
// #endif

// #ifdef RGBLIGHT_ENABLE
// #define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
// #define RGB_SLEEP
// #define RGBLIGHT_DISABLE_KEYCODES
// #define RGBLIGHT_LIMIT_VAL 128
// #endif

// #define ENABLE_RGB_MATRIX_SOLID_REACTIVEddcacx
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #define ENABLE_RGB_MATRIX_RIVERFLOW
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE


#define PERMISSIVE_HOLD
#define TAPPING_TERM 165
#define RETRO_TAPPING
//#define HOLD_ON_OTHER_KEY_PRESS

// #undef WS2812_DI_PIN
// #define WS2812_DI_PIN 25
// #undef RGBLED_NUM
// #define RGBLED_NUM 2
// #undef RGBLED_SPLIT
// #define RGBLED_SPLIT {1, 1}
// #undef WS2812_DI_PIN
// #define WS2812_DI_PIN 25
// #undef RGBLIGHT_LED_COUNT
// #define RGBLIGHT_LED_COUNT 2
// #undef RGBLED_SPLIT
// #define RGBLED_SPLIT {1, 1}
// #define SPLIT_LED_STATE_ENABLE

// #define SPLIT_USB_DETECT
// #undef RGB_MATRIX_DEFAULT_HUE 
// #define RGB_MATRIX_DEFAULT_HUE 48
// #undef RGB_MATRIX_DEFAULT_SAT
// #define RGB_MATRIX_DEFAULT_SAT 87
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 30
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

