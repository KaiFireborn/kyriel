/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// #define ENCODERS_PAD_A { leftEncoderA }
// #define ENCODERS_PAD_B { lefEEncoderB }
// #define ENCODER_RESOLUTION 4

// #define ENCODERS_PAD_A_RIGHT { rightEncoderA }
// #define ENCODERS_PAD_B_RIGHT { rightEncoderB }
// #define ENCODER_RESOLUTION_RIGHT 4

// LAYOUT

#define CKC_SCRSV MEH(KC_PSCR)    // screensaver
#define CKC_ENT ALGR(KC_1)        // ↵
#define CKC_EUR ALGR(KC_2)        // €
#define CKC_DEG ALGR(KC_3)        // °
#define CKC_DELT ALGR(KC_4)       // Δ
#define CKC_INF ALGR(KC_5)        // ∞
#define CKC_MDOT ALGR(KC_6)       // ·
#define CKC_UUML ALGR(KC_U)       // ü
#define CKC_NOT ALGR(KC_MINS)     // ¬
#define CKC_NEQL ALGR(KC_EQL)     // ≠
#define CKC_AUML ALGR(KC_A)       // ä
#define CKC_SUML ALGR(KC_S)       // ß
#define CKC_LTOET ALGR(KC_COMM)   // ≤
#define CKC_GTOET ALGR(KC_DOT)    // ≥
#define CKC_UPA ALGR(KC_L)        // ↑
#define CKC_DOWNA ALGR(KC_K)      // ↓
#define CKC_LEFTA ALGR(KC_J)      // ←
#define CKC_RIGHTA ALGR(KC_SCLN)  // →
#define CKC_LEFTDA ALGR(KC_LBRC)  // ⇐
#define CKC_RIGHTDA ALGR(KC_RBRC) // ⇒
#define CKC_YES ALGR(KC_7)        // ✓
#define CKC_NO ALGR(KC_8)         // ✕
#define CKC_OUML ALGR(KC_O)       // ö
#define CKC_ALMEQ ALGR(KC_NUBS)   // ≈
#define CKC_PLSMNS S(KC_GRV)      // ±
#define CKC_ERR ALGR(KC_GRV)      // ↯
#define CKC_SECT KC_GRV           // §
#define CKC_GRV KC_NUBS           //`
#define CKC_TILD S(KC_NUBS)       //~
#define CKC_MU ALGR(KC_9)         //
#define CKC_BR_C_UP LSA(KC_UP)
#define CKC_BR_C_DOWN LSA(KC_DOWN)
#define CKC_BR_R_UP MEH(KC_UP)
#define CKC_BR_R_DOWN MEH(KC_DOWN)
#define CKC_EQUIV ALGR(KC_SLSH)    // ⇔
#define CKC_MATH_AND ALGR(KC_QUOT) // ∧
#define CKC_MATH_OR ALGR(KC_NUHS)  // ∨

const key_override_t dot_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);

// numpad
const key_override_t p1_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_P1);
const key_override_t p2_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_P2);
const key_override_t p3_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_P3);
const key_override_t p4_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_P4);
const key_override_t p5_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_P5);
const key_override_t p6_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_P6);
const key_override_t p7_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_P7);
const key_override_t p8_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_P8);
const key_override_t p9_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_P9);
const key_override_t p0_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_P0);

const key_override_t *key_overrides[] = {
    &dot_key_override, &comm_key_override,

    &p1_key_override,  &p2_key_override,   &p3_key_override, &p4_key_override, &p5_key_override, &p6_key_override, &p7_key_override, &p8_key_override, &p9_key_override, &p0_key_override,
};

enum layers {
    ALPHAS,
    NUM,
    SYM,
    NAV,
    COSM,
    MOUSE,
    LM,
    RM,
    GI,
    GI2,
    FN,

    KB
};

// MO(MOUSE) removed for now
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHAS] = LAYOUT_split_3x6_5(
		QK_LOCK,       KC_Q,          KC_W,          KC_F,          KC_P,          KC_B,                                                                                     KC_J,          KC_L,          KC_U,          KC_Y,          KC_QUOT,       KC_MUTE,       

		KC_ESC,        KC_A,          KC_R,          KC_S,          KC_T,          KC_G,                                                                                     KC_M,          KC_N,          KC_E,          KC_I,          KC_O,          KC_ENT,        

		KC_LCTL,       KC_Z,          KC_X,          KC_C,          KC_D,          KC_V,          KC_LGUI,       MO(COSM),                     MO(FN),        MO(MOUSE),     KC_K,          KC_H,          KC_COMM,       KC_DOT,        KC_SLSH,       KC_LALT,       

		                                             TG(GI),        MO(LM),        LSFT_T(KC_SPC),MO(NAV),       MO(SYM),                      MO(NUM),       KC_BSPC,       KC_SPC,        MO(RM),        TO(ALPHAS)                                                  

	),

    [SYM] = LAYOUT_split_3x6_5(
		RGB_VAI,       KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,                                                                                  KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_UNDS,       KC_EQL,        _______,       

		_______,       KC_LGUI,       KC_LCTL,       KC_LSFT,       KC_LALT,       KC_PIPE,                                                                                  KC_GT,         KC_LCBR,       KC_LPRN,       KC_LBRC,       KC_PLUS,       _______,       

		_______,       CKC_TILD,      CKC_GRV,       KC_BSLS,       KC_SLSH,       KC_QUES,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       XXXXXXX,       KC_LT,         KC_RCBR,       KC_RPRN,       KC_RBRC,       KC_MINS,       _______,       

		                                             XXXXXXX,       XXXXXXX,       _______,       XXXXXXX,       _______,                      XXXXXXX,       _______,       _______,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[NUM] = LAYOUT_split_3x6_5(
		RGB_TOG,       KC_LPRN,       KC_7,          KC_8,          KC_9,          KC_RPRN,                                                                                  KC_CIRC,       KC_DLR,        KC_PAST,       KC_HASH,       KC_LNUM,       _______,       

		_______,       KC_PERC,       KC_4,          KC_5,          KC_6,          KC_PPLS,                                                                                  KC_PPLS,       KC_RALT,       KC_RSFT,       KC_RCTL,       KC_RGUI,       _______,       

		_______,       _______,       KC_1,          KC_2,          KC_3,          KC_PMNS,       KC_PAST,       KC_PSLS,                      XXXXXXX,       XXXXXXX,       KC_PMNS,       KC_PAST,       KC_PSLS,       KC_LT,         KC_GT,         _______,       

		                                             XXXXXXX,       KC_0,          KC_PDOT,       KC_PEQL,       XXXXXXX,                      _______,       _______,       _______,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[FN] = LAYOUT_split_3x6_5(
		RGB_MOD,       KC_F12,        KC_F7,         KC_F8,         KC_F9,         KC_F15,                                                                                   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		_______,       KC_F11,        KC_F4,         KC_F5,         KC_F6,         KC_F14,                                                                                   XXXXXXX,       KC_RALT,       KC_RSFT,       KC_RCTL,       KC_RGUI,       _______,       

		_______,       KC_F10,        KC_F1,         KC_F2,         KC_F3,         KC_F13,        XXXXXXX,       XXXXXXX,                      _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		                                             XXXXXXX,       XXXXXXX,       _______,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       _______,       _______,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	

	[COSM] = LAYOUT_split_3x6_5(
        RGB_VAD,       CKC_ENT,       CKC_EUR,       CKC_DEG,       CKC_DELT,      CKC_INF,                                                                                  CKC_MDOT,      CKC_MU,        CKC_UUML,      CKC_NOT,       CKC_NEQL,      _______,       

		_______,       CKC_AUML,      CKC_MATH_AND,  CKC_SUML,      CKC_MATH_OR,   CKC_YES,                                                                                  CKC_GTOET,     CKC_LEFTA,     CKC_LEFTDA,    CKC_UPA,       CKC_OUML,      _______,       

		_______,       CKC_ALMEQ,     CKC_PLSMNS,    CKC_SECT,      CKC_ERR,       CKC_NO,        XXXXXXX,       _______,                      XXXXXXX,       XXXXXXX,       CKC_LTOET,     CKC_RIGHTA,    CKC_RIGHTDA,   CKC_DOWNA,     CKC_EQUIV,     _______,       

		                                             XXXXXXX,       XXXXXXX,       _______,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       _______,       _______,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[NAV] = LAYOUT_split_3x6_5(
		QK_CLEAR_EEPROM,       KC_SLEP,       KC_EJCT,       KC_FIND,       CKC_SCRSV,     S(KC_PSCR),                                                                               XXXXXXX,       KC_HOME,       KC_END,        KC_DEL,        KC_INS,        _______,       

		_______,       KC_LGUI,       KC_LCTL,       KC_LSFT,       KC_LALT,       KC_PSCR,                                                                                  CW_TOGG,       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       _______,       

		_______,       KC_MNXT,       KC_MPLY,       KC_MPRV,       LGUI(KC_D),    A(KC_PSCR),    XXXXXXX,       XXXXXXX,                      XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_PGDN,       KC_PGUP,       KC_TAB,        KC_CAPS,       _______,       

		                                             XXXXXXX,       XXXXXXX,       _______,       _______,       XXXXXXX,                      XXXXXXX,       _______,       _______,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[MOUSE] = LAYOUT_split_3x6_5(
		_______,       KC_BTN4,       KC_BTN5,       KC_BTN2,       KC_BTN1,       KC_BTN3,                                                                                  KC_ACL0,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		_______,       KC_MS_L,       KC_MS_U,       KC_MS_D,       KC_MS_R,       LSA(KC_PSCR),                                                                             KC_ACL1,       KC_RALT,       KC_RSFT,       KC_RCTL,       KC_RGUI,       _______,       

		_______,       KC_WH_L,       KC_WH_U,       KC_WH_D,       KC_WH_R,       KC_LSCR,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       XXXXXXX,       KC_ACL2,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		                                             XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       _______,       _______,       _______,       TO(ALPHAS)                                                  

	),

	[LM] = LAYOUT_split_3x6_5(
		_______,       _______,       _______,       _______,       _______,       _______,                                                                                  _______,       _______,       _______,       _______,       _______,       _______,       

		_______,       KC_LGUI,       KC_LCTL,       KC_LSFT,       KC_LALT,       _______,                                                                                  _______,       _______,       _______,       _______,       _______,       _______,       

		_______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,                      _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       

		                                             _______,       _______,       _______,       KC_LSFT,       _______,                      _______,       _______,       _______,       _______,       TO(ALPHAS)                                                  

	),

	[RM] = LAYOUT_split_3x6_5(
		_______,       _______,       _______,       _______,       _______,       _______,                                                                                  _______,       _______,       _______,       _______,       _______,       _______,       

		_______,       _______,       _______,       _______,       _______,       _______,                                                                                  _______,       KC_RALT,       KC_RSFT,       KC_RCTL,       KC_RGUI,       _______,       

		_______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,                      _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       

		                                             _______,       _______,       _______,       KC_LSFT,       _______,                      _______,       _______,       _______,       _______,       TO(ALPHAS)                                                  

	),

	[GI] = LAYOUT_split_3x6_5(
		_______,       KC_1,          KC_2,          KC_5,          KC_3,          KC_4,                                                                                     KC_BTN3,       KC_WH_L,       KC_WH_D,       KC_WH_U,       KC_WH_R,       _______,       

		KC_TAB,        KC_LSFT,       KC_Q,          KC_W,          KC_E,          KC_F,                                                                                     KC_F,          KC_BTN1,       KC_BTN1,       KC_BTN2,       KC_T,          _______,       

		KC_ESC,        KC_V,          KC_A,          KC_S,          KC_D,          KC_T,          KC_LALT,       KC_ENT,                       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_MS_L,       KC_MS_D,       KC_MS_U,       KC_MS_R,       _______,       

		                                             TO(ALPHAS),    KC_Z,          MO(FN),        KC_SPC,        MO(GI2),                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[GI2] = LAYOUT_split_3x6_5(
		KC_LGUI,       KC_J,          KC_M,          KC_U,          KC_C,          KC_B,                                                                                     _______,       _______,       _______,       _______,       _______,       _______,       

		KC_O,          KC_LCTL,       _______,       _______,       _______,       C(KC_G),                                                                                  _______,       _______,       _______,       _______,       _______,       _______,       

		KC_Y,          KC_P,          KC_R,          KC_X,          KC_L,          KC_G,          KC_BSLS,       KC_BTN3,                      XXXXXXX,       XXXXXXX,       RGB_TOG,       RGB_TOG,       RGB_TOG,       RGB_TOG,       RGB_TOG,       _______,       

		                                             LGUI(KC_D),    _______,       _______,       _______,       _______,                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       TO(ALPHAS)                                                  

	),

	[KB] = LAYOUT_split_3x6_5(
		_______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                                                                  XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		_______,       XXXXXXX,       RGB_TOG,       QK_BOOT,       XXXXXXX,       TO(KB),                                                                                   XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		_______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,       

		                                             _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       TO(ALPHAS)                                                  

	)
};

// ENCODERS

bool encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder R
    if (index == 0) {
        // Clockwise
        if (clockwise) {
            if (IS_LAYER_ON(FN)) {
                tap_code16(CKC_BR_R_UP);
            } else if (IS_LAYER_ON(NUM)) {
                tap_code16(RGB_VAI);
            } else {
                tap_code16(CKC_BR_C_UP);
            }
            // Anticlockwise
        } else {
            if (IS_LAYER_ON(FN)) {
                tap_code16(CKC_BR_R_DOWN);
            } else if (IS_LAYER_ON(NUM)) {
                tap_code16(RGB_VAD);
            } else {
                tap_code16(CKC_BR_C_DOWN);
            }
        }
        // Encoder L
    } else if (index == 1) {
        // Clockwise
        if (clockwise) {
            if (IS_LAYER_ON(NAV)) {
                tap_code16(C(KC_RGHT));
            } else if (IS_LAYER_ON(SYM)) {
                tap_code(KC_WH_R);
            } else if (IS_LAYER_ON(COSM)) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_VOLU);
            } // AntiClockwise
        } else {
            if (IS_LAYER_ON(NAV)) {
                tap_code16(C(KC_LEFT));
            } else if (IS_LAYER_ON(SYM)) {
                tap_code(KC_WH_L);
            } else if (IS_LAYER_ON(COSM)) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}

// OLEDS

// static void render_logo(void) {

// }

void keyboard_pre_init_user(void) {
    setPinOutput(24);
    writePinHigh(24);
}

//

void print_oled_left(void) {
    oled_write_P(PSTR("kfls21"), false);

    // static const char PROGMEM kyria_logo[] = {
    //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
    //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    // };

    // oled_write_P(kyria_logo, false);
}

char alphas_preview = "f('🔒 Q W F P B    \n⎋ A R S T G    \n^ Z X C D V ⌘ M\n      T M L M M', '    J L U Y " 🔇\n    M N E I O ↩\nM M K H , . / ⌥\nM ⌫ ␣ M T      ')";
char sym_preview = "f('R E @ # $ %    \n_ ⌘ ^ ⇧ ⌥ |    \n_ C C \\ / ? X X\n      X X _ X _', '    ^ & * _ = _\n    > { ( [ + _\nX X < } ) ] - _\nX _ _ X T      ')";
char num_preview = "f('R ( 7 8 9 )    \n_ % 4 5 6 +    \n_ _ 1 2 3 - * /\n      X 0 . P X', '    ^ $ * # L _\n    + ⌥ ⇧ ^ ⌘ _\nX X - * / < > _\n_ _ _ X T      ')";
char fn_preview = "f('R ¹ ⁷ ⁸ ⁹ ¹    \n_ ¹ ⁴ ⁵ ⁶ ¹    \n_ ¹ ¹ ² ³ ¹ X X\n      X X _ X X', '    X X X X X _\n    X ⌥ ⇧ ^ ⌘ _\n_ X X X X X X _\nX _ _ X T      ')";
char cosm_preview = "f('R C C C C C    \n_ C C C C C    \n_ C C C C C X _\n      X X _ X X', '    C C C C C _\n    C C C C C _\nX X C C C C C _\nX _ _ X T      ')";
char nav_preview = "f('Q 💤 ⏏ 🔍 C S    \n_ ⌘ ^ ⇧ ⌥ P    \n_ M M M Ð A X X\n      X X _ _ X', '    X ⌂ ≡ D ⇱ _\n    ↻ ← ↓ ↑ R _\nX X X ⇟ ⇞ ⇥ ⇪ _\nX _ _ X T      ')";
char mouse_preview = "f('_ B B B B B    \n_ M M M M L    \n_ W W W W L X X\n      X X X X X', '    A X X X X _\n    A ⌥ ⇧ ^ ⌘ _\nX X A X X X X _\nX _ _ _ T      ')";
char lm_preview = "f('_ _ _ _ _ _    \n_ ⌘ ^ ⇧ ⌥ _    \n_ _ _ _ _ _ _ _\n      _ _ _ ⇧ _', '    _ _ _ _ _ _\n    _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ T      ')";
char rm_preview = "f('_ _ _ _ _ _    \n_ _ _ _ _ _    \n_ _ _ _ _ _ _ _\n      _ _ _ ⇧ _', '    _ _ _ _ _ _\n    _ ⌥ ⇧ ^ ⌘ _\n_ _ _ _ _ _ _ _\n_ _ _ _ T      ')";
char gi_preview = "f('_ 1 2 5 3 4    \n⇥ ⇧ Q W E F    \n⎋ V A S D T ⌥ ↩\n      T Z M ␣ M', '    B W W W W _\n    F B B B T _\nX X X M M M M _\nX X X X T      ')";
char gi2_preview = "f('⌘ J M U C B    \nO ^ _ _ _ C    \nY P R X L G \\ B\n      Ð _ _ _ _', '    _ _ _ _ _ _\n    _ _ _ _ _ _\nX X R R R R R _\nX X X X T      ')";
char kb_preview = "f('_ X X X X X    \n_ X R Q X T    \n_ X X X X X X X\n      _ X X X X', '    X X X X X _\n    X X X X X _\nX X X X X X X _\nX X X X T      ')";



void print_oled_right(void) {
    oled_write_P(PSTR("Hello, World! ~Kyriel"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_oled_right();
    } else {
        print_oled_left();
    }
    return false;
}

// LED MATRIX
int default_rgb_brightness = 50;
int default_ug_brightness = 50;
#define C_RGB_GOLD 254, 210, 32              // ##FED222
#define C_RGB_CORNELL_RED 167, 34, 26        // ##A7221A
#define C_RGB_VERMILLION 225, 66, 50         // ##E74D42
#define C_RGB_GHOST_WHITE 243, 240, 244      // ##F3F0F4
#define C_RGB_ATOMIC_TANGERINE 247, 158, 108 // ##F79E6C

HSV c_hsv_gold =  {.h = 48, .s = 221, .v = 254}; 

RGB rgb_gold = {C_RGB_GOLD};
RGB rgb_cornell_red = {C_RGB_CORNELL_RED};
RGB rgb_vermillion = {C_RGB_VERMILLION};
RGB rgb_ghost_white = {C_RGB_GHOST_WHITE};
RGB rgb_atomic_tangerine = {C_RGB_ATOMIC_TANGERINE};

// uint8_t c_rgb_gold[3]             = {C_RGB_GOLD};
// uint8_t c_rgb_cornell_red[3]      = {C_RGB_CORNELL_RED};
// uint8_t c_rgb_vermillion[3]       = {C_RGB_VERMILLION};
// uint8_t c_rgb_ghost_white[3]      = {C_RGB_GHOST_WHITE};
// uint8_t c_rgb_atomic_tangerine[3] = {C_RGB_ATOMIC_TANGERINE};

void unpack_rgb_to_array(RGB rgb, uint8_t array[3]) {
    array[0] = rgb.r;
    array[1] = rgb.g;
    array[2] = rgb.b;
}

// HSV rgb_to_hsv(RGB rgb) {
//     HSV hsv;
//     uint8_t rgb_min, rgb_max;

//     rgb_min = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
//     rgb_max = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

//     hsv.v = rgb_max;
//     if (hsv.v == 0) {
//         hsv.h = 0;
//         hsv.s = 0;
//         return hsv;
//     }

//     hsv.s = 255 * (rgb_max - rgb_min) / hsv.v;
//     if (hsv.s == 0) {
//         hsv.h = 0;
//         return hsv;
//     }

//     if (rgb_max == rgb.r) {
//         hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgb_max - rgb_min);
//     } else if (rgb_max == rgb.g) {
//         hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgb_max - rgb_min);
//     } else {
//         hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgb_max - rgb_min);
//     }

//     return hsv;
// }

// RGB change_color_brightness(rgb_led_t rgb, int brightness) {
//     HSV hsv = rgb_to_hsv(rgb);
//     hsv.v = brightness;
//     return hsv_to_rgb(hsv);
// }

RGB color_to_dimmer_rgb(HSV hsv, int brightness) {
    hsv.v = brightness;
    return hsv_to_rgb(hsv);
}



void copy_array(uint8_t dest[], uint8_t src[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
// #define C_RGB_

void keyboard_post_init_user(void) {
    //     // Initialize RGB to static black
    //     rgblight_enable_noeeprom();
    //     rgblight_sethsv_noeeprom(HSV_RED);
    //     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    // rgb_matrix_set_color_all(C_RGB_GOLD);
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CUSTOM_REACTIVE);
}

uint8_t ug_color[3] = {C_RGB_GOLD};
void    set_underglow_color(rgb_led_t color) {
    // copy_array(ug_color, color, 3);
    unpack_rgb_to_array(color, ug_color);
}

bool keycode_is_number(uint8_t keycode) {
    return keycode >= KC_1 && keycode <= KC_0;
}

bool keycode_is_function(uint8_t keycode) {
    return (keycode >= KC_F1 && keycode <= KC_F12) || (keycode >= KC_F13 && keycode <= KC_F24);
}

bool keycode_is_alpha(uint8_t keycode) {
    return keycode >= KC_A && keycode <= KC_Z;
}

bool keycode_is_modifier(uint8_t keycode) {
    return keycode >= KC_LCTL && keycode <= KC_RGUI;
}

// bool keycode_is_layer(uint8_t keycode) {
//     return keycode >= DF() && keycode <= TT();
// }

bool keycode_is_action(uint8_t keycode) {
    return (keycode >= KC_ENTER && keycode <= KC_SPC) || keycode == KC_CAPS_LOCK || (keycode >= KC_PRINT_SCREEN && keycode <= KC_PAUSE) || keycode == QK_CAPS_WORD_TOGGLE || keycode == QK_LOCK;
}

bool keycode_is_mouse(uint8_t keycode) {
    return keycode >= QK_MOUSE_CURSOR_UP && keycode <= QK_MOUSE_ACCELERATION_2;
}

bool keycode_is_symbol(uint8_t keycode) {
    return (keycode >= KC_MINUS && keycode <= KC_SLASH) || (keycode == KC_NONUS_BACKSLASH);
}

bool keycode_is_navigation(uint8_t keycode) {
    return keycode >= KC_INSERT && keycode <= KC_UP;
}

bool keycode_is_keypad(uint8_t keycode) {
    return (keycode >= KC_NUM_LOCK && keycode <= KC_KP_DOT) || keycode == KC_KP_EQUAL || keycode == KC_KP_COMMA || keycode == KC_KP_EQUAL_AS400;
}

bool keycode_is_media(uint8_t keycode) {
    return (keycode >= KC_APPLICATION && keycode <= KC_KB_POWER) || (keycode >= KC_EXECUTE && keycode <= KC_LOCKING_SCROLL_LOCK) || (keycode >= KC_SYSTEM_POWER && keycode <= KC_LAUNCHPAD);
}

bool keycode_is_hardware(uint8_t keycode) {
    return (keycode >= RGB_TOG && keycode <= RGB_SPD) || (keycode >= QK_BOOTLOADER && keycode <= QK_REBOOT);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            rgb_matrix_set_color(i, ug_color[0], ug_color[1], ug_color[2]);
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index   = g_led_config.matrix_co[row][col];
            uint8_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (index >= led_min && index < led_max && index != NO_LED && keycode > KC_TRNS) {
                // underglow
                switch (get_highest_layer(layer_state | default_layer_state)) {
                    case ALPHAS:
                        set_underglow_color((RGB){C_RGB_GOLD});
                        break;

                        // case NUM:
                        //     break;

                        // case FN:
                        //     break;

                    case SYM:
                        rgb_matrix_set_color(index, C_RGB_CORNELL_RED);
                        break;

                    case NAV:
                        if (keycode_is_navigation(keycode)) {
                            rgb_matrix_set_color(index, RGB_TEAL);
                        } else if (keycode_is_media(keycode)) {
                            rgb_matrix_set_color(index, RGB_MAGENTA);
                        } else {
                            rgb_matrix_set_color(index, C_RGB_VERMILLION);
                        }

                    case COSM:
                        rgb_matrix_set_color(index, RGB_BLUE);
                        break;

                    // case MOUSE:
                    //     break;

                    // case LM:
                    //     break;
                    // case RM:
                    //     break;
                    case GI:
                        set_underglow_color((RGB){C_RGB_ATOMIC_TANGERINE});

                        if (keycode == KC_1) {
                            rgb_matrix_set_color(0, RGB_WHITE);
                        }
                        else if(keycode == KC_2) {
                            rgb_matrix_set_color(1, RGB_WHITE);
                        }
                        if (keycode == KC_3) {
                            rgb_matrix_set_color(2, RGB_WHITE);
                        } else if (keycode == KC_4) {
                            rgb_matrix_set_color(3, RGB_WHITE);
                        }
                        // else if(keycode == KC_5) {
                        //     rgb_matrix_set_color(4, RGB_WHITE);
                        // }
                        // else if(keycode == KC_Q) {
                        //     rgb_matrix_set_color(5, RGB_WHITE);
                        // }
                        // else if(keycode == KC_W) {
                        //     rgb_matrix_set_color(6, RGB_WHITE);
                        // }
                        // else if (keycode == KC_E) {
                        //     rgb_matrix_set_color(7, RGB_WHITE);
                        // }
                        // else if (keycode == KC_F) {
                        //     rgb_matrix_set_color(8, RGB_WHITE);
                        // }
                        // else if (keycode == KC_V) {
                        //     rgb_matrix_set_color(9, RGB_WHITE);
                        // }
                        // else if (keycode == KC_A) {
                        //     rgb_matrix_set_color(10, RGB_WHITE);
                        // }
                        // else if (keycode == KC_S) {
                        //     rgb_matrix_set_color(11, RGB_WHITE);
                        // }
                        // else if (keycode == KC_D) {
                        //     rgb_matrix_set_color(12, RGB_WHITE);
                        // }
                        // else if (keycode == KC_G) {
                        //     rgb_matrix_set_color(13, RGB_WHITE);
                        // }
                        // else if (keycode == KC_Z) {
                        //     rgb_matrix_set_color(14, RGB_WHITE);
                        // }
                        // else if (keycode == KC_LSFT) {
                        //     rgb_matrix_set_color(15, RGB_WHITE);
                        // }
                        // else if (keycode == KC_TAB) {
                        //     rgb_matrix_set_color(16, RGB_WHITE);
                        // }
                        // else if (keycode == KC_ESC) {
                        //     rgb_matrix_set_color(17, RGB_WHITE);
                        // }
                        // else if (keycode == KC_ENT) {
                        //     rgb_matrix_set_color(18, RGB_WHITE);
                        // }

                        break;
                    case GI2:
                        set_underglow_color((RGB){C_RGB_GHOST_WHITE});
                          
                        // if (keycode == KC_J) {
                        //     rgb_matrix_set_color(0, RGB_TURQUOISE);
                        // }
                        // else if(keycode == KC_M) {
                        //     rgb_matrix_set_color(1, RGB_TURQUOISE);
                        // }
                        // else if(keycode == KC_U) {
                        //     rgb_matrix_set_color(2, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_C) {
                        //     rgb_matrix_set_color(3, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_B) {
                        //     rgb_matrix_set_color(4, RGB_TURQUOISE);
                        // }
                        // else if(keycode == KC_P) {
                        //     rgb_matrix_set_color(5, RGB_TURQUOISE);
                        // }
                        // else if(keycode == KC_R) {
                        //     rgb_matrix_set_color(6, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_O) {
                        //     rgb_matrix_set_color(7, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_Y) {
                        //     rgb_matrix_set_color(8, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_X) {
                        //     rgb_matrix_set_color(9, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_C) {
                        //     rgb_matrix_set_color(10, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_L) {
                        //     rgb_matrix_set_color(11, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_G) {
                        //     rgb_matrix_set_color(12, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_D) {
                        //     rgb_matrix_set_color(13, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_E) {
                        //     rgb_matrix_set_color(14, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_W) {
                        //     rgb_matrix_set_color(15, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_Q) {
                        //     rgb_matrix_set_color(16, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_BSLS) {
                        //     rgb_matrix_set_color(17, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_LGUI) {
                        //     rgb_matrix_set_color(18, RGB_TURQUOISE);
                        // }
                        // else if (keycode == KC_BTN3) {
                        //     rgb_matrix_set_color(19, RGB_TURQUOISE);
                        // }

                        break;
                    // case KB:
                    //     break;
                    default:
                        set_underglow_color((RGB){C_RGB_GOLD});

                        if (keycode_is_number(keycode)) {
                            rgb_matrix_set_color(index, color_to_dimmer_rgb((HSV){HSV_BLUE}, 100).r, color_to_dimmer_rgb((HSV){HSV_BLUE}, 100).g, color_to_dimmer_rgb((HSV){HSV_BLUE}, 100).b);
                        } else if (keycode_is_function(keycode)) {
                            rgb_matrix_set_color(index, RGB_ORANGE);
                        } else if (keycode_is_symbol(keycode)) {
                            rgb_matrix_set_color(index, RGB_CYAN);
                        } else if (keycode_is_navigation(keycode)) {
                            rgb_matrix_set_color(index, RGB_TEAL);
                        } else if (keycode_is_media(keycode)) {
                            rgb_matrix_set_color(index, RGB_MAGENTA);
                        } else if (keycode_is_keypad(keycode)) {
                            rgb_matrix_set_color(index, RGB_CYAN);
                        } else if (keycode_is_mouse(keycode)) {
                            rgb_matrix_set_color(index, RGB_WHITE);
                        } else if (keycode_is_hardware(keycode)) {
                            rgb_matrix_set_color(index, RGB_MAGENTA);
                        } else {
                            rgb_matrix_set_color(index, RGB_RED);
                        }
                }
            }
            if (keycode_is_modifier(keycode) && (get_highest_layer(layer_state | default_layer_state) != ALPHAS && get_highest_layer(layer_state | default_layer_state) != GI && get_highest_layer(layer_state | default_layer_state) != GI2)) {
                rgb_matrix_set_color(index, C_RGB_GOLD);
            }
        }
    }
    // if (get_highest_layer(layer_state) > 0) {
    //     uint8_t layer = get_highest_layer(layer_state);

    //     for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    //         for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
    //             uint8_t index = g_led_config.matrix_co[row][col];

    //             if (index >= led_min && index < led_max && index != NO_LED &&
    //             keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {

    //                 copy_array(ug_color, c_rgb_gold, 3);

    //                 switch(get_highest_layer(layer_state|default_layer_state)) {
    //                     case ALPHAS:
    //                         set_underglow_color(C_RGB_GOLD);
    //                         break;

    //                     case NUM:
    //                         rgb_matrix_set_color(index, RGB_GREEN);

    //                         break;

    //                     case FN:
    //                         rgb_matrix_set_color(index, RGB_ORANGE);
    //                         break;

    //                     case SYM:
    //                         rgb_matrix_set_color(index, RGB_CYAN);
    //                         break;
    //                     case NAV:
    //                         rgb_matrix_set_color(index, RGB_TEAL);
    //                         break;

    //                     case COSM:
    //                         rgb_matrix_set_color(index, RGB_MAGENTA);
    //                         break;

    //                     case MOUSE:
    //                         rgb_matrix_set_color(index, RGB_WHITE);
    //                         break;

    //                     case LM:
    //                         rgb_matrix_set_color(index, RGB_YELLOW);
    //                         break;
    //                     case RM:
    //                         rgb_matrix_set_color(index, RGB_YELLOW);
    //                         break;
    //                     case GI:
    //                         // rgb_matrix_set_color(index, RGB_GOLD);
    //                         set_underglow_color(C_RGB_ATOMIC_TANGERINE);

    //                         break;
    //                     case GI2:
    //                         // rgb_matrix_set_color(index, RGB_GOLDENROD);
    //                         set_underglow_color(C_RGB_GHOST_WHITE);
    //                         break;
    //                     case KB:
    //                         rgb_matrix_set_color(index, RGB_PURPLE);
    //                         break;
    //                     default:
    //                         set_underglow_color(C_RGB_GOLD);
    //                         break;
    //                 }

    //                 // if (g_led_config.flags[index] & LED_FLAG_UNDERGLOW) {
    //                 //     rgb_matrix_set_color(index, C_RGB_VERMILLION);
    //                 // }
    //             }
    //         }
    //     }
    // }
    return false;
}