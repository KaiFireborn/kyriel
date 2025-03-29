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
// #include "features/achordion.h"
// #if __has_include("keymap.h")
// #    include "keymap.h"
// #endif

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
#define CKC_LEFTA ALGR(KC_J)      // � (leftarrow)
#define CKC_RIGHTA ALGR(KC_SCLN)  // →
#define CKC_LEFTDA ALGR(KC_LBRC)  // � (Leftdoublearrow)
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
#define CKC_MU ALGR(KC_9)         // μ
#define CKC_EMPTY ALGR(KC_0)      // ⌀
#define CKC_BR_C_UP LSA(KC_UP)
#define CKC_BR_C_DOWN LSA(KC_DOWN)
#define CKC_BR_R_UP MEH(KC_UP)
#define CKC_BR_R_DOWN MEH(KC_DOWN)
#define CKC_EQUIV ALGR(KC_SLSH)     // ⇔
#define CKC_MATH_AND ALGR(KC_QUOT)  // ∧
#define CKC_MATH_OR ALGR(KC_NUHS)   // ∨
#define CKC_DQUOT S(KC_QUOT)        //"
#define CKC_SH_SP LSFT_T(KC_SPC)    // mod-tap
#define CKC_C_ESC LCTL_T(KC_ESC)    // mod-tap
#define CKC_A_DEL LALT_T(KC_DEL)    // mod-tap
#define CKC_A_TAB LALT_T(KC_TAB)    // mod-tap
#define CKC_NAV_ENT LT(NAV, KC_ENT) // mod-tap

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

// const key_override_t spacedel_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &dot_key_override, &comm_key_override,

    &p1_key_override,  &p2_key_override,   &p3_key_override, &p4_key_override, &p5_key_override, &p6_key_override, &p7_key_override, &p8_key_override, &p9_key_override, &p0_key_override,
};
// TODO: redo mouse layer
enum layers { ALPHAS, NUM, SYM, NAV, COSM, MOUSE, LM, RM, GI, GI2, FN, KB };

// START FORMAT
//  MO(MOUSE) removed for now, so is
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHAS] = LAYOUT_split_3x6_5(
		XXXXXXX,     KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,                                                                         KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_MUTE,     

		KC_TAB,      KC_A,        KC_R,        KC_S,        KC_T,        KC_G,                                                                         KC_M,        KC_N,        KC_E,        KC_I,        KC_O,        KC_MINS,     

		KC_LCTL,     KC_Z,        KC_X,        KC_C,        KC_D,        KC_V,        MO(COSM),    KC_ESC,                   MO(FN),      MO(NUM),     KC_K,        KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_ENT,      

		                                       TG(GI),      MO(LM),      KC_LSFT,     KC_SPC,      MO(NAV),                  MO(SYM),     KC_SPC,      KC_BSPC,     MO(RM),      TO(ALPHAS)                                          

	),

	[SYM] = LAYOUT_split_3x6_5(
		_______,     CKC_DQUOT,   KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,                                                                      KC_CIRC,     KC_AMPR,     KC_ASTR,     CKC_GRV,     KC_QUOT,     _______,     

		_______,     KC_EXLM,     KC_LBRC,     KC_LPRN,     KC_LCBR,     KC_PLUS,                                                                      KC_LT,       KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     KC_MINS,     

		_______,     KC_QUES,     KC_RBRC,     KC_RPRN,     KC_RCBR,     KC_EQL,      XXXXXXX,     _______,                  XXXXXXX,     XXXXXXX,     KC_GT,       CKC_TILD,    KC_PIPE,     KC_BSLS,     KC_SLSH,     _______,     

		                                       QK_LLCK,     XXXXXXX,     XXXXXXX,     KC_UNDS,     _______,                  _______,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[COSM] = LAYOUT_split_3x6_5(
		_______,     CKC_ENT,     CKC_EUR,     CKC_DEG,     CKC_DELT,    CKC_INF,                                                                      CKC_MDOT,    CKC_MU,      CKC_UUML,    CKC_SECT,    CKC_EMPTY,   _______,     

		_______,     CKC_AUML,    CKC_NO,      CKC_SUML,    CKC_YES,     CKC_PLSMNS,                                                                   CKC_GTOET,   CKC_LEFTA,   CKC_UPA,     CKC_RIGHTA,  CKC_OUML,    CKC_NOT,     

		_______,     CKC_EQUIV,   CKC_RIGHTDA, CKC_LEFTDA,  CKC_ERR,     CKC_NEQL,    _______,     _______,                  XXXXXXX,     XXXXXXX,     CKC_LTOET,   CKC_ALMEQ,   CKC_DOWNA,   CKC_MATH_OR, CKC_MATH_AND,_______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     KC_RSFT,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[NUM] = LAYOUT_split_3x6_5(
		RGB_TOG,     KC_LPRN,     KC_6,        KC_3,        KC_2,        KC_RPRN,                                                                      XXXXXXX,     XXXXXXX,     KC_PAST,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     KC_9,        KC_7,        KC_0,        KC_1,        KC_PPLS,                                                                      KC_LT,       KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     KC_PMNS,     

		_______,     XXXXXXX,     KC_8,        KC_5,        KC_4,        KC_EQL,      KC_CALC,     XXXXXXX,                  _______,     _______,     KC_GT,       XXXXXXX,     KC_PCMM,     KC_PDOT,     KC_SLSH,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     _______,     _______,                  _______,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[FN] = LAYOUT_split_3x6_5(
		RGB_MOD,     KC_F12,      KC_F6,       KC_F3,       KC_F2,       KC_F15,                                                                       KC_FIND,     XXXXXXX,     KC_EJCT,     RGB_TOG,     KC_MUTE,     _______,     

		_______,     KC_F9,       KC_F7,       KC_F10,      KC_F1,       KC_F13,                                                                       XXXXXXX,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     KC_F11,      KC_F8,       KC_F5,       KC_F4,       KC_F14,      XXXXXXX,     XXXXXXX,                  _______,     _______,     XXXXXXX,     KC_MPRV,     KC_MPLY,     KC_MNXT,     XXXXXXX,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[NAV] = LAYOUT_split_3x6_5(
		_______,     XXXXXXX,     KC_HOME,     KC_END,      CKC_SCRSV,   S(KC_PSCR),                                                                   XXXXXXX,     KC_HOME,     KC_END,      KC_INS,      XXXXXXX,     _______,     

		A(KC_TAB),   KC_LGUI,     KC_LCTL,     KC_LSFT,     KC_LALT,     KC_PSCR,                                                                      CW_TOGG,     KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_UP,       _______,     

		_______,     XXXXXXX,     KC_LEFT,     KC_RGHT,     LGUI(KC_D),  A(KC_PSCR),  XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     KC_CAPS,     KC_PGUP,     KC_PGDN,     KC_TAB,      XXXXXXX,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     _______,     XXXXXXX,                  _______,     KC_DEL,      KC_BSPC,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[MOUSE] = LAYOUT_split_3x6_5(
		_______,     KC_BTN4,     KC_BTN5,     KC_BTN2,     KC_BTN1,     KC_BTN3,                                                                      KC_ACL0,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     KC_MS_L,     KC_MS_U,     KC_MS_D,     KC_MS_R,     LSA(KC_PSCR),                                                                 KC_ACL1,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     KC_WH_L,     KC_WH_U,     KC_WH_D,     KC_WH_R,     KC_LSCR,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     KC_ACL2,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		                                       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[LM] = LAYOUT_split_3x6_5(
		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     KC_LGUI,     KC_LCTL,     KC_LSFT,     KC_LALT,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,                  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     

		                                       _______,     _______,     _______,     KC_LSFT,     _______,                  _______,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[RM] = LAYOUT_split_3x6_5(
		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,                  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     

		                                       _______,     _______,     _______,     KC_LSFT,     _______,                  _______,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[GI] = LAYOUT_split_3x6_5(
		_______,     KC_LCTL,     KC_2,        KC_5,        KC_3,        KC_4,                                                                         KC_BTN3,     KC_WH_L,     KC_WH_D,     KC_WH_U,     KC_WH_R,     _______,     

		KC_1,        KC_LSFT,     KC_Q,        KC_W,        KC_E,        KC_F,                                                                         XXXXXXX,     KC_BTN1,     KC_BTN1,     KC_BTN2,     XXXXXXX,     _______,     

		KC_ESC,      KC_X,        KC_A,        KC_S,        KC_D,        KC_T,        KC_LALT,     KC_ENT,                   XXXXXXX,     XXXXXXX,     XXXXXXX,     KC_MS_L,     KC_MS_D,     KC_MS_U,     KC_MS_R,     _______,     

		                                       TO(ALPHAS),  KC_Z,        MO(FN),      KC_SPC,      MO(GI2),                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[GI2] = LAYOUT_split_3x6_5(
		KC_LGUI,     KC_J,        KC_M,        KC_U,        KC_B,        KC_C,                                                                         _______,     _______,     _______,     _______,     _______,     _______,     

		A(KC_TAB),   KC_V,        KC_Q,        KC_W,        KC_E,        C(KC_G),                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		KC_P,        KC_O,        KC_R,        KC_TAB,      KC_L,        KC_G,        KC_BSLS,     KC_BTN3,                  XXXXXXX,     XXXXXXX,     RGB_TOG,     RGB_TOG,     RGB_TOG,     RGB_TOG,     RGB_TOG,     _______,     

		                                       LGUI(KC_D),  KC_Y,        _______,     _______,     _______,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[KB] = LAYOUT_split_3x6_5(
		_______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                                                      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     XXXXXXX,     RGB_TOG,     QK_BOOT,     XXXXXXX,     TO(KB),                                                                       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		                                       _______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	)
};

char PROGMEM alphas_preview_l[] = "  Q W F P B    \nt A R S T G    \nc Z X C D V c e\n      g m s _ v";
char PROGMEM alphas_preview_r[] = "    J L U Y ' m\n    M N E I O -\nf n K H , . / r\ns _ b m r      ";
char PROGMEM sym_preview_l[] = "  C @ # $ %    \n  E [ ( { +    \n  ? ] ) } =    \n      Q     _  ";
char PROGMEM sym_preview_r[] = "    ^ & * C '  \n    < a s c g -\n    > C | \\ /  \n        r      ";
char PROGMEM cosm_preview_l[] = "  C C C C C    \n  C C C C C    \n  C C C C C    \n      Q        ";
char PROGMEM cosm_preview_r[] = "    C C C C C  \n    C C C C C C\n    C C C C C  \n    s   r      ";
char PROGMEM num_preview_l[] = "R ( 6 3 2 )    \n  9 7 0 1 +    \n    8 5 4 = C  \n      Q        ";
char PROGMEM num_preview_r[] = "        *      \n    < a s c g -\n    >   P . /  \n        r      ";
char PROGMEM fn_preview_l[] = "R f f f f f    \n  f f f f f    \n  f f f f f    \n      Q        ";
char PROGMEM fn_preview_r[] = "    f   j R m  \n      a s c g  \n      M M M    \n        r      ";
char PROGMEM nav_preview_l[] = "    h e C S    \nA g c s a P    \n    l R d A    \n      Q        ";
char PROGMEM nav_preview_r[] = "      h e i    \n    W l d R u  \n    P p p t    \n  D b   r      ";
char PROGMEM mouse_preview_l[] = "  B B B B B    \n  M M M M L    \n  W W W W L    \n               ";
char PROGMEM mouse_preview_r[] = "    A          \n    A a s c g  \n    A          \n        r      ";
char PROGMEM lm_preview_l[] = "               \n  g c s a      \n               \n            s  ";
char PROGMEM lm_preview_r[] = "               \n               \n               \n        r      ";
char PROGMEM rm_preview_l[] = "               \n               \n               \n            s  ";
char PROGMEM rm_preview_r[] = "               \n      a s c g  \n               \n        r      ";
char PROGMEM gi_preview_l[] = "  c 2 5 3 4    \n1 s Q W E F    \ne X A S D T a r\n      r Z f _ M";
char PROGMEM gi_preview_r[] = "    B W W W W  \n      B B B    \n      M M M M  \n        r      ";
char PROGMEM gi2_preview_l[] = "g J M U B C    \nA V Q W E C    \nP O R t L G \\ B\n      d Y      ";
char PROGMEM gi2_preview_r[] = "               \n               \n    R R R R R  \n        r      ";
char PROGMEM kb_preview_l[] = "               \n    R Q   T    \n               \n               ";
char PROGMEM kb_preview_r[] = "               \n               \n               \n        r      ";
// END FORMAT

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

void keyboard_pre_init_user(void) {
    setPinOutput(24);
    writePinHigh(24);
}

void print_oled_right(char s[]) {
    if (!is_keyboard_master()) {
        oled_write_P("kfls21\n\n", false);
        oled_write_P(PSTR(s), false);
    }
}

void turn_off_right_oled(void) {
    if (!is_keyboard_master()) {
        oled_off();
    }
}

void print_oled_left(char s[]) {
    if (is_keyboard_master()) {
        oled_write_P("Hello, World! ~Kyriel\n\n", false);
        oled_write_P(PSTR(s), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    // if (layer == GI || layer == GI2) {
    //    turn_off_right_oled();
    // }
    switch (layer) {
        case ALPHAS:

            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;

        case LM:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
        case RM:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
        case SYM:
            print_oled_left(sym_preview_l);
            print_oled_right(sym_preview_r);
            break;
        case NUM:
            print_oled_left(num_preview_l);
            print_oled_right(num_preview_r);
            break;
        case FN:
            print_oled_left(fn_preview_l);
            print_oled_right(fn_preview_r);
            break;
        case COSM:
            print_oled_left(cosm_preview_l);
            print_oled_right(cosm_preview_r);
            break;
        case NAV:
            print_oled_left(nav_preview_l);
            print_oled_right(nav_preview_r);
            break;
        case MOUSE:
            print_oled_left(mouse_preview_l);
            print_oled_right(mouse_preview_r);
            break;
        case GI:
            print_oled_left(gi_preview_l);
            if (!is_keyboard_master()) {
                oled_clear();
            }
            break;
        case GI2:
            print_oled_left(gi2_preview_l);
            break;
        case KB:
            print_oled_left(kb_preview_l);
            print_oled_right(kb_preview_r);
            break;
        default:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
    }
    return false;
}
// TODO: implement caps/cw indicators

// LED MATRIX
int default_rgb_brightness   = 110;
int default_ug_brightness    = 220;
int increased_rgb_brightness = 145;
// source: https://coolors.co/fed222-a7221a-e14232-f3f0f4-f79e6c
#define C_RGB_GOLD 254, 210, 32              // ##FED222
#define C_RGB_CORNELL_RED 167, 34, 26        // ##A7221A
#define C_RGB_vermilion 225, 66, 50          // ##E74D42
#define C_RGB_GHOST_WHITE 243, 240, 244      // ##F3F0F4
#define C_RGB_ATOMIC_TANGERINE 247, 158, 108 // ##F79E6C

HSV c_hsv_gold             = {.h = 34, .s = 221, .v = 254};
HSV c_hsv_cornell_red      = {.h = 2, .s = 215, .v = 167};
HSV c_hsv_vermilion        = {.h = 3, .s = 182, .v = 231};
HSV c_hsv_ghost_white      = {.h = 202, .s = 4, .v = 244};
HSV c_hsv_atomic_tangerine = {.h = 15, .s = 144, .v = 247};

// GI layer colors
HSV c_hsv_pyro    = {.h = 128, .s = 41, .v = 250};
HSV c_hsv_hydro   = {.h = 139, .s = 245, .v = 194};
HSV c_hsv_anemo   = {.h = 106, .s = 82, .v = 245};
HSV c_hsv_electro = {.h = 196, .s = 163, .v = 209};
HSV c_hsv_cryo    = {.h = 139, .s = 245, .v = 194};
HSV c_hsv_dendro  = {.h = 55, .s = 212, .v = 232};
HSV c_hsv_geo     = {.h = 34, .s = 153, .v = 242};

HSV  ug_color          = {.h = 34, .s = 221, .v = 254};
bool right_half_ug_off = false;
bool all_ug_off        = false;

// void unpack_rgb_to_rgb_array(RGB rgb, uint8_t array[3])
// {
//     array[0] = rgb.r;
//     array[1] = rgb.g;
//     array[2] = rgb.b;
// }
RGB color_to_dimmer_rgb(HSV hsv, int brightness) {
    hsv.v = brightness;
    return hsv_to_rgb(hsv);
}

void set_matrix_color_to_dimmed_hsv(uint8_t index, HSV hsv, int brightness) {
    RGB dimmer_rgb = color_to_dimmer_rgb(hsv, brightness);
    rgb_matrix_set_color(index, dimmer_rgb.r, dimmer_rgb.g, dimmer_rgb.b);
}

void copy_array(uint8_t dest[], uint8_t src[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CUSTOM_REACTIVE);
}

void set_underglow_color_hsv(HSV hsv) {
    ug_color = hsv;
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
bool keycode_is_shifted(uint8_t keycode) {
    // also if any of the custom keys defined above between CKC_SCRV and CKC_MATH_OR but one by one
    return (keycode >= KC_TILDE && keycode <= KC_QUESTION) || (keycode == CKC_SCRSV) || (keycode == CKC_ENT) || (keycode == CKC_EUR) || (keycode == CKC_DEG) || (keycode == CKC_DELT) || (keycode == CKC_INF) || (keycode == CKC_MDOT) || (keycode == CKC_UUML) || (keycode == CKC_NOT) || (keycode == CKC_NEQL) || (keycode == CKC_AUML) || (keycode == CKC_SUML) || (keycode == CKC_LTOET) || (keycode == CKC_GTOET) || (keycode == CKC_UPA) || (keycode == CKC_DOWNA) || (keycode == CKC_LEFTA) || (keycode == CKC_RIGHTA) || (keycode == CKC_LEFTDA) || (keycode == CKC_RIGHTDA) || (keycode == CKC_YES) || (keycode == CKC_NO) || (keycode == CKC_OUML) || (keycode == CKC_ALMEQ) || (keycode == CKC_PLSMNS) || (keycode == CKC_ERR) || (keycode == CKC_SECT) || (keycode == CKC_GRV) || (keycode == CKC_TILD) || (keycode == CKC_MU) || (keycode == CKC_BR_C_UP) || (keycode == CKC_BR_C_DOWN) || (keycode == CKC_BR_R_UP) || (keycode == CKC_BR_R_DOWN) || (keycode == CKC_EQUIV) || (keycode == CKC_MATH_AND) ||
           (keycode == CKC_MATH_OR);
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
bool keycode_is_arrow(uint8_t keycode) {
    return keycode >= KC_INSERT && keycode <= KC_UP;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            if (!all_ug_off && (!right_half_ug_off || i <= 6)) {
                set_matrix_color_to_dimmed_hsv(i, ug_color, default_ug_brightness);
            }
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index   = g_led_config.matrix_co[row][col];
            uint8_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (index >= led_min && index < led_max && index != NO_LED && keycode > KC_TRNS) {
                uint8_t highest_layer = get_highest_layer(layer_state | default_layer_state);
                if (highest_layer != FN) { // don't turn underglow back on if function (trnasition from GI)
                    right_half_ug_off = false;
                }
                switch (highest_layer) {
                    case ALPHAS:
                        set_underglow_color_hsv(c_hsv_gold);
                        break;
                    case SYM: // highlight all keys on SYM
                        set_matrix_color_to_dimmed_hsv(index, c_hsv_vermilion, default_rgb_brightness);
                        if (keycode_is_shifted(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        }
                        break;
                    case COSM: // highlight all keys on COSM
                        set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        break;

                    case NAV: // highlight keys on NAV depending on grouping
                        if (keycode_is_navigation(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_media(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        } else if (keycode_is_arrow(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        }
                        break;

                    case GI:                                 // highlight keys on GI depending on element + wasd + eq
                        set_underglow_color_hsv(c_hsv_gold); // maybe greener?

                        right_half_ug_off = true;

                        if (keycode == KC_1) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_electro, increased_rgb_brightness);
                        }
                        if (keycode == KC_2) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_electro, increased_rgb_brightness);
                        }
                        if (keycode == KC_3) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_hydro, increased_rgb_brightness);
                        }
                        if (keycode == KC_4) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_dendro, increased_rgb_brightness);
                        }
                        if (keycode == KC_W || keycode == KC_A || keycode == KC_S || keycode == KC_D) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_YELLOW}, increased_rgb_brightness);
                        }
                        if (keycode == KC_Q || keycode == KC_E) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_F) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_T) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_BLUE}, increased_rgb_brightness);
                        }

                        break;
                    case GI2: // highlight wasd on GI2
                        right_half_ug_off = true;

                        if (keycode == KC_W) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_YELLOW}, increased_rgb_brightness);
                        }
                        if (keycode == KC_Q || keycode == KC_E) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        // d white, printscr azure
                        if (keycode == KC_D) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_G) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_AZURE}, increased_rgb_brightness);
                        }
                        // set_underglow_color_hsv(c_hsv_ghost_white);

                        break;

                    default:
                        set_underglow_color_hsv(c_hsv_gold);

                        if (keycode_is_number(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_arrow(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_function(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, default_rgb_brightness);
                        } else if (keycode_is_symbol(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_vermilion, default_rgb_brightness);
                        } else if (keycode_is_navigation(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else if (keycode_is_media(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        } else if (keycode_is_keypad(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else if (keycode_is_mouse(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_hardware(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, default_rgb_brightness);
                        }
                }
            }
            if (keycode_is_modifier(keycode) && (get_highest_layer(layer_state | default_layer_state) != ALPHAS && get_highest_layer(layer_state | default_layer_state) != GI && get_highest_layer(layer_state | default_layer_state) != GI2)) {
                set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, increased_rgb_brightness);
            }
        }
    }
    return false;
}
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
// #include "features/achordion.h"
// #if __has_include("keymap.h")
// #    include "keymap.h"
// #endif

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
#define CKC_LEFTA ALGR(KC_J)      // � (leftarrow)
#define CKC_RIGHTA ALGR(KC_SCLN)  // →
#define CKC_LEFTDA ALGR(KC_LBRC)  // � (Leftdoublearrow)
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
#define CKC_MU ALGR(KC_9)         // μ
#define CKC_EMPTY ALGR(KC_0)      // ⌀
#define CKC_BR_C_UP LSA(KC_UP)
#define CKC_BR_C_DOWN LSA(KC_DOWN)
#define CKC_BR_R_UP MEH(KC_UP)
#define CKC_BR_R_DOWN MEH(KC_DOWN)
#define CKC_EQUIV ALGR(KC_SLSH)     // ⇔
#define CKC_MATH_AND ALGR(KC_QUOT)  // ∧
#define CKC_MATH_OR ALGR(KC_NUHS)   // ∨
#define CKC_DQUOT S(KC_QUOT)        //"
#define CKC_SH_SP LSFT_T(KC_SPC)    // mod-tap
#define CKC_C_ESC LCTL_T(KC_ESC)    // mod-tap
#define CKC_A_DEL LALT_T(KC_DEL)    // mod-tap
#define CKC_A_TAB LALT_T(KC_TAB)    // mod-tap
#define CKC_NAV_ENT LT(NAV, KC_ENT) // mod-tap

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

// const key_override_t spacedel_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &dot_key_override, &comm_key_override,

    &p1_key_override,  &p2_key_override,   &p3_key_override, &p4_key_override, &p5_key_override, &p6_key_override, &p7_key_override, &p8_key_override, &p9_key_override, &p0_key_override,
};
// TODO: redo mouse layer
enum layers { ALPHAS, NUM, SYM, NAV, COSM, MOUSE, LM, RM, GI, GI2, FN, KB };

// START FORMAT
//  MO(MOUSE) removed for now, so is
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[ALPHAS] = LAYOUT_split_3x6_5(
		XXXXXXX,     KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,                                                                         KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_MUTE,     

		KC_TAB,      KC_A,        KC_R,        KC_S,        KC_T,        KC_G,                                                                         KC_M,        KC_N,        KC_E,        KC_I,        KC_O,        KC_MINS,     

		KC_LCTL,     KC_Z,        KC_X,        KC_C,        KC_D,        KC_V,        MO(COSM),    KC_ESC,                   MO(FN),      MO(NUM),     KC_K,        KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_ENT,      

		                                       TG(GI),      MO(LM),      KC_LSFT,     KC_SPC,      MO(NAV),                  MO(SYM),     KC_SPC,      KC_BSPC,     MO(RM),      TO(ALPHAS)                                          

	),

	[SYM] = LAYOUT_split_3x6_5(
		_______,     CKC_DQUOT,   KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,                                                                      KC_CIRC,     KC_AMPR,     KC_ASTR,     CKC_GRV,     KC_QUOT,     _______,     

		_______,     KC_EXLM,     KC_LBRC,     KC_LPRN,     KC_LCBR,     KC_PLUS,                                                                      KC_LT,       KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     KC_MINS,     

		_______,     KC_QUES,     KC_RBRC,     KC_RPRN,     KC_RCBR,     KC_EQL,      XXXXXXX,     _______,                  XXXXXXX,     XXXXXXX,     KC_GT,       CKC_TILD,    KC_PIPE,     KC_BSLS,     KC_SLSH,     _______,     

		                                       QK_LLCK,     XXXXXXX,     XXXXXXX,     KC_UNDS,     _______,                  _______,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[COSM] = LAYOUT_split_3x6_5(
		_______,     CKC_ENT,     CKC_EUR,     CKC_DEG,     CKC_DELT,    CKC_INF,                                                                      CKC_MDOT,    CKC_MU,      CKC_UUML,    CKC_SECT,    CKC_EMPTY,   _______,     

		_______,     CKC_AUML,    CKC_NO,      CKC_SUML,    CKC_YES,     CKC_PLSMNS,                                                                   CKC_GTOET,   CKC_LEFTA,   CKC_UPA,     CKC_RIGHTA,  CKC_OUML,    CKC_NOT,     

		_______,     CKC_EQUIV,   CKC_RIGHTDA, CKC_LEFTDA,  CKC_ERR,     CKC_NEQL,    _______,     _______,                  XXXXXXX,     XXXXXXX,     CKC_LTOET,   CKC_ALMEQ,   CKC_DOWNA,   CKC_MATH_OR, CKC_MATH_AND,_______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     KC_RSFT,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[NUM] = LAYOUT_split_3x6_5(
		RGB_TOG,     KC_LPRN,     KC_6,        KC_3,        KC_2,        KC_RPRN,                                                                      XXXXXXX,     XXXXXXX,     KC_PAST,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     KC_9,        KC_7,        KC_0,        KC_1,        KC_PPLS,                                                                      KC_LT,       KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     KC_PMNS,     

		_______,     XXXXXXX,     KC_8,        KC_5,        KC_4,        KC_EQL,      KC_CALC,     XXXXXXX,                  _______,     _______,     KC_GT,       XXXXXXX,     KC_PCMM,     KC_PDOT,     KC_SLSH,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     _______,     _______,                  _______,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[FN] = LAYOUT_split_3x6_5(
		RGB_MOD,     KC_F12,      KC_F6,       KC_F3,       KC_F2,       KC_F15,                                                                       KC_FIND,     XXXXXXX,     KC_EJCT,     RGB_TOG,     KC_MUTE,     _______,     

		_______,     KC_F9,       KC_F7,       KC_F10,      KC_F1,       KC_F13,                                                                       XXXXXXX,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     KC_F11,      KC_F8,       KC_F5,       KC_F4,       KC_F14,      XXXXXXX,     XXXXXXX,                  _______,     _______,     XXXXXXX,     KC_MPRV,     KC_MPLY,     KC_MNXT,     XXXXXXX,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     _______,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[NAV] = LAYOUT_split_3x6_5(
		_______,     XXXXXXX,     KC_HOME,     KC_END,      CKC_SCRSV,   S(KC_PSCR),                                                                   XXXXXXX,     KC_HOME,     KC_END,      KC_INS,      XXXXXXX,     _______,     

		A(KC_TAB),   KC_LGUI,     KC_LCTL,     KC_LSFT,     KC_LALT,     KC_PSCR,                                                                      CW_TOGG,     KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_UP,       _______,     

		_______,     XXXXXXX,     KC_LEFT,     KC_RGHT,     LGUI(KC_D),  A(KC_PSCR),  XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     KC_CAPS,     KC_PGUP,     KC_PGDN,     KC_TAB,      XXXXXXX,     _______,     

		                                       QK_LLCK,     XXXXXXX,     _______,     _______,     XXXXXXX,                  _______,     KC_DEL,      KC_BSPC,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[MOUSE] = LAYOUT_split_3x6_5(
		_______,     KC_BTN4,     KC_BTN5,     KC_BTN2,     KC_BTN1,     KC_BTN3,                                                                      KC_ACL0,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     KC_MS_L,     KC_MS_U,     KC_MS_D,     KC_MS_R,     LSA(KC_PSCR),                                                                 KC_ACL1,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     KC_WH_L,     KC_WH_U,     KC_WH_D,     KC_WH_R,     KC_LSCR,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     KC_ACL2,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		                                       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[LM] = LAYOUT_split_3x6_5(
		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     KC_LGUI,     KC_LCTL,     KC_LSFT,     KC_LALT,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,                  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     

		                                       _______,     _______,     _______,     KC_LSFT,     _______,                  _______,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[RM] = LAYOUT_split_3x6_5(
		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,                                                                      _______,     KC_RALT,     KC_RSFT,     KC_RCTL,     KC_RGUI,     _______,     

		_______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,                  _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     

		                                       _______,     _______,     _______,     KC_LSFT,     _______,                  _______,     _______,     _______,     _______,     TO(ALPHAS)                                          

	),

	[GI] = LAYOUT_split_3x6_5(
		_______,     KC_LCTL,     KC_2,        KC_5,        KC_3,        KC_4,                                                                         KC_BTN3,     KC_WH_L,     KC_WH_D,     KC_WH_U,     KC_WH_R,     _______,     

		KC_1,        KC_LSFT,     KC_Q,        KC_W,        KC_E,        KC_F,                                                                         XXXXXXX,     KC_BTN1,     KC_BTN1,     KC_BTN2,     XXXXXXX,     _______,     

		KC_ESC,      KC_X,        KC_A,        KC_S,        KC_D,        KC_T,        KC_LALT,     KC_ENT,                   XXXXXXX,     XXXXXXX,     XXXXXXX,     KC_MS_L,     KC_MS_D,     KC_MS_U,     KC_MS_R,     _______,     

		                                       TO(ALPHAS),  KC_Z,        MO(FN),      KC_SPC,      MO(GI2),                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[GI2] = LAYOUT_split_3x6_5(
		KC_LGUI,     KC_J,        KC_M,        KC_U,        KC_B,        KC_C,                                                                         _______,     _______,     _______,     _______,     _______,     _______,     

		A(KC_TAB),   KC_V,        KC_Q,        KC_W,        KC_E,        C(KC_G),                                                                      _______,     _______,     _______,     _______,     _______,     _______,     

		KC_P,        KC_O,        KC_R,        KC_TAB,      KC_L,        KC_G,        KC_BSLS,     KC_BTN3,                  XXXXXXX,     XXXXXXX,     RGB_TOG,     RGB_TOG,     RGB_TOG,     RGB_TOG,     RGB_TOG,     _______,     

		                                       LGUI(KC_D),  KC_Y,        _______,     _______,     _______,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	),

	[KB] = LAYOUT_split_3x6_5(
		_______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                                                      XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     XXXXXXX,     RGB_TOG,     QK_BOOT,     XXXXXXX,     TO(KB),                                                                       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		_______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     

		                                       _______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TO(ALPHAS)                                          

	)
};

char PROGMEM alphas_preview_l[] = "  Q W F P B    \nt A R S T G    \nc Z X C D V c e\n      g m s _ v";
char PROGMEM alphas_preview_r[] = "    J L U Y ' m\n    M N E I O -\nf n K H , . / r\ns _ b m r      ";
char PROGMEM sym_preview_l[] = "  C @ # $ %    \n  E [ ( { +    \n  ? ] ) } =    \n      Q     _  ";
char PROGMEM sym_preview_r[] = "    ^ & * C '  \n    < a s c g -\n    > C | \\ /  \n        r      ";
char PROGMEM cosm_preview_l[] = "  C C C C C    \n  C C C C C    \n  C C C C C    \n      Q        ";
char PROGMEM cosm_preview_r[] = "    C C C C C  \n    C C C C C C\n    C C C C C  \n    s   r      ";
char PROGMEM num_preview_l[] = "R ( 6 3 2 )    \n  9 7 0 1 +    \n    8 5 4 = C  \n      Q        ";
char PROGMEM num_preview_r[] = "        *      \n    < a s c g -\n    >   P . /  \n        r      ";
char PROGMEM fn_preview_l[] = "R f f f f f    \n  f f f f f    \n  f f f f f    \n      Q        ";
char PROGMEM fn_preview_r[] = "    f   j R m  \n      a s c g  \n      M M M    \n        r      ";
char PROGMEM nav_preview_l[] = "    h e C S    \nA g c s a P    \n    l R d A    \n      Q        ";
char PROGMEM nav_preview_r[] = "      h e i    \n    W l d R u  \n    P p p t    \n  D b   r      ";
char PROGMEM mouse_preview_l[] = "  B B B B B    \n  M M M M L    \n  W W W W L    \n               ";
char PROGMEM mouse_preview_r[] = "    A          \n    A a s c g  \n    A          \n        r      ";
char PROGMEM lm_preview_l[] = "               \n  g c s a      \n               \n            s  ";
char PROGMEM lm_preview_r[] = "               \n               \n               \n        r      ";
char PROGMEM rm_preview_l[] = "               \n               \n               \n            s  ";
char PROGMEM rm_preview_r[] = "               \n      a s c g  \n               \n        r      ";
char PROGMEM gi_preview_l[] = "  c 2 5 3 4    \n1 s Q W E F    \ne X A S D T a r\n      r Z f _ M";
char PROGMEM gi_preview_r[] = "    B W W W W  \n      B B B    \n      M M M M  \n        r      ";
char PROGMEM gi2_preview_l[] = "g J M U B C    \nA V Q W E C    \nP O R t L G \\ B\n      d Y      ";
char PROGMEM gi2_preview_r[] = "               \n               \n    R R R R R  \n        r      ";
char PROGMEM kb_preview_l[] = "               \n    R Q   T    \n               \n               ";
char PROGMEM kb_preview_r[] = "               \n               \n               \n        r      ";
// END FORMAT

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

void keyboard_pre_init_user(void) {
    setPinOutput(24);
    writePinHigh(24);
}

void print_oled_right(char s[]) {
    if (!is_keyboard_master()) {
        oled_write_P("kfls21\n\n", false);
        oled_write_P(PSTR(s), false);
    }
}

void turn_off_right_oled(void) {
    if (!is_keyboard_master()) {
        oled_off();
    }
}

void print_oled_left(char s[]) {
    if (is_keyboard_master()) {
        oled_write_P("Hello, World! ~Kyriel\n\n", false);
        oled_write_P(PSTR(s), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    // if (layer == GI || layer == GI2) {
    //    turn_off_right_oled();
    // }
    switch (layer) {
        case ALPHAS:

            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;

        case LM:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
        case RM:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
        case SYM:
            print_oled_left(sym_preview_l);
            print_oled_right(sym_preview_r);
            break;
        case NUM:
            print_oled_left(num_preview_l);
            print_oled_right(num_preview_r);
            break;
        case FN:
            print_oled_left(fn_preview_l);
            print_oled_right(fn_preview_r);
            break;
        case COSM:
            print_oled_left(cosm_preview_l);
            print_oled_right(cosm_preview_r);
            break;
        case NAV:
            print_oled_left(nav_preview_l);
            print_oled_right(nav_preview_r);
            break;
        case MOUSE:
            print_oled_left(mouse_preview_l);
            print_oled_right(mouse_preview_r);
            break;
        case GI:
            print_oled_left(gi_preview_l);
            if (!is_keyboard_master()) {
                oled_clear();
            }
            break;
        case GI2:
            print_oled_left(gi2_preview_l);
            break;
        case KB:
            print_oled_left(kb_preview_l);
            print_oled_right(kb_preview_r);
            break;
        default:
            print_oled_left(alphas_preview_l);
            print_oled_right(alphas_preview_r);
            break;
    }
    return false;
}
// TODO: implement caps/cw indicators

// LED MATRIX
int default_rgb_brightness   = 110;
int default_ug_brightness    = 220;
int increased_rgb_brightness = 145;
// source: https://coolors.co/fed222-a7221a-e14232-f3f0f4-f79e6c
#define C_RGB_GOLD 254, 210, 32              // ##FED222
#define C_RGB_CORNELL_RED 167, 34, 26        // ##A7221A
#define C_RGB_vermilion 225, 66, 50          // ##E74D42
#define C_RGB_GHOST_WHITE 243, 240, 244      // ##F3F0F4
#define C_RGB_ATOMIC_TANGERINE 247, 158, 108 // ##F79E6C

HSV c_hsv_gold             = {.h = 34, .s = 221, .v = 254};
HSV c_hsv_cornell_red      = {.h = 2, .s = 215, .v = 167};
HSV c_hsv_vermilion        = {.h = 3, .s = 182, .v = 231};
HSV c_hsv_ghost_white      = {.h = 202, .s = 4, .v = 244};
HSV c_hsv_atomic_tangerine = {.h = 15, .s = 144, .v = 247};

// GI layer colors
HSV c_hsv_pyro    = {.h = 128, .s = 41, .v = 250};
HSV c_hsv_hydro   = {.h = 139, .s = 245, .v = 194};
HSV c_hsv_anemo   = {.h = 106, .s = 82, .v = 245};
HSV c_hsv_electro = {.h = 196, .s = 163, .v = 209};
HSV c_hsv_cryo    = {.h = 139, .s = 245, .v = 194};
HSV c_hsv_dendro  = {.h = 55, .s = 212, .v = 232};
HSV c_hsv_geo     = {.h = 34, .s = 153, .v = 242};

HSV  ug_color          = {.h = 34, .s = 221, .v = 254};
bool right_half_ug_off = false;
bool all_ug_off        = false;

// void unpack_rgb_to_rgb_array(RGB rgb, uint8_t array[3])
// {
//     array[0] = rgb.r;
//     array[1] = rgb.g;
//     array[2] = rgb.b;
// }
RGB color_to_dimmer_rgb(HSV hsv, int brightness) {
    hsv.v = brightness;
    return hsv_to_rgb(hsv);
}

void set_matrix_color_to_dimmed_hsv(uint8_t index, HSV hsv, int brightness) {
    RGB dimmer_rgb = color_to_dimmer_rgb(hsv, brightness);
    rgb_matrix_set_color(index, dimmer_rgb.r, dimmer_rgb.g, dimmer_rgb.b);
}

void copy_array(uint8_t dest[], uint8_t src[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CUSTOM_REACTIVE);
}

void set_underglow_color_hsv(HSV hsv) {
    ug_color = hsv;
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
bool keycode_is_shifted(uint8_t keycode) {
    // also if any of the custom keys defined above between CKC_SCRV and CKC_MATH_OR but one by one
    return (keycode >= KC_TILDE && keycode <= KC_QUESTION) || (keycode == CKC_SCRSV) || (keycode == CKC_ENT) || (keycode == CKC_EUR) || (keycode == CKC_DEG) || (keycode == CKC_DELT) || (keycode == CKC_INF) || (keycode == CKC_MDOT) || (keycode == CKC_UUML) || (keycode == CKC_NOT) || (keycode == CKC_NEQL) || (keycode == CKC_AUML) || (keycode == CKC_SUML) || (keycode == CKC_LTOET) || (keycode == CKC_GTOET) || (keycode == CKC_UPA) || (keycode == CKC_DOWNA) || (keycode == CKC_LEFTA) || (keycode == CKC_RIGHTA) || (keycode == CKC_LEFTDA) || (keycode == CKC_RIGHTDA) || (keycode == CKC_YES) || (keycode == CKC_NO) || (keycode == CKC_OUML) || (keycode == CKC_ALMEQ) || (keycode == CKC_PLSMNS) || (keycode == CKC_ERR) || (keycode == CKC_SECT) || (keycode == CKC_GRV) || (keycode == CKC_TILD) || (keycode == CKC_MU) || (keycode == CKC_BR_C_UP) || (keycode == CKC_BR_C_DOWN) || (keycode == CKC_BR_R_UP) || (keycode == CKC_BR_R_DOWN) || (keycode == CKC_EQUIV) || (keycode == CKC_MATH_AND) ||
           (keycode == CKC_MATH_OR);
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
bool keycode_is_arrow(uint8_t keycode) {
    return keycode >= KC_INSERT && keycode <= KC_UP;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            if (!all_ug_off && (!right_half_ug_off || i <= 6)) {
                set_matrix_color_to_dimmed_hsv(i, ug_color, default_ug_brightness);
            }
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index   = g_led_config.matrix_co[row][col];
            uint8_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (index >= led_min && index < led_max && index != NO_LED && keycode > KC_TRNS) {
                uint8_t highest_layer = get_highest_layer(layer_state | default_layer_state);
                if (highest_layer != FN) { // don't turn underglow back on if function (trnasition from GI)
                    right_half_ug_off = false;
                }
                switch (highest_layer) {
                    case ALPHAS:
                        set_underglow_color_hsv(c_hsv_gold);
                        break;
                    case SYM: // highlight all keys on SYM
                        set_matrix_color_to_dimmed_hsv(index, c_hsv_vermilion, default_rgb_brightness);
                        if (keycode_is_shifted(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        }
                        break;
                    case COSM: // highlight all keys on COSM
                        set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        break;

                    case NAV: // highlight keys on NAV depending on grouping
                        if (keycode_is_navigation(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_media(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        } else if (keycode_is_arrow(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        }
                        break;

                    case GI:                                 // highlight keys on GI depending on element + wasd + eq
                        set_underglow_color_hsv(c_hsv_gold); // maybe greener?

                        right_half_ug_off = true;

                        if (keycode == KC_1) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_electro, increased_rgb_brightness);
                        }
                        if (keycode == KC_2) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_electro, increased_rgb_brightness);
                        }
                        if (keycode == KC_3) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_hydro, increased_rgb_brightness);
                        }
                        if (keycode == KC_4) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_dendro, increased_rgb_brightness);
                        }
                        if (keycode == KC_W || keycode == KC_A || keycode == KC_S || keycode == KC_D) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_YELLOW}, increased_rgb_brightness);
                        }
                        if (keycode == KC_Q || keycode == KC_E) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_F) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_T) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_BLUE}, increased_rgb_brightness);
                        }

                        break;
                    case GI2: // highlight wasd on GI2
                        right_half_ug_off = true;

                        if (keycode == KC_W) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_YELLOW}, increased_rgb_brightness);
                        }
                        if (keycode == KC_Q || keycode == KC_E) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        // d white, printscr azure
                        if (keycode == KC_D) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_WHITE}, increased_rgb_brightness);
                        }
                        if (keycode == KC_G) {
                            set_matrix_color_to_dimmed_hsv(index, (HSV){HSV_AZURE}, increased_rgb_brightness);
                        }
                        // set_underglow_color_hsv(c_hsv_ghost_white);

                        break;

                    default:
                        set_underglow_color_hsv(c_hsv_gold);

                        if (keycode_is_number(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_arrow(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_function(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, default_rgb_brightness);
                        } else if (keycode_is_symbol(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_vermilion, default_rgb_brightness);
                        } else if (keycode_is_navigation(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else if (keycode_is_media(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_atomic_tangerine, default_rgb_brightness);
                        } else if (keycode_is_keypad(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else if (keycode_is_mouse(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_ghost_white, default_rgb_brightness);
                        } else if (keycode_is_hardware(keycode)) {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_cornell_red, default_rgb_brightness);
                        } else {
                            set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, default_rgb_brightness);
                        }
                }
            }
            if (keycode_is_modifier(keycode) && (get_highest_layer(layer_state | default_layer_state) != ALPHAS && get_highest_layer(layer_state | default_layer_state) != GI && get_highest_layer(layer_state | default_layer_state) != GI2)) {
                set_matrix_color_to_dimmed_hsv(index, c_hsv_gold, increased_rgb_brightness);
            }
        }
    }
    return false;
}