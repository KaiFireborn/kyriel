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

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE

// #define PERMISSIVE_HOLD
#define TAPPING_TERM 175
// #define RETRO_TAPPING
//#define HOLD_ON_OTHER_KEY_PRESS

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 30
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#define RGB_MATRIX_SLEEP
#define RGB_TRIGGER_ON_KEYDOWN

#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_OLED_ENABLE
#define OLED_TIMEOUT 40000
#define RGB_MATRIX_TIMEOUT 40000

// #define LED_CAPS_LOCK_PIN 24  
// #define LED_PIN_ON_STATE 0