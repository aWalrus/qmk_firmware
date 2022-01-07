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

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_SPC, KC_ENT, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_APP, MO(3), KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_RALT, MO(3), KC_MUTE),
	[1] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_LCTL, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_BSPC, KC_SPC, KC_ENT, KC_DEL, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_RSFT, KC_TRNS, KC_NO, KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, MO(4), KC_RALT, KC_NO, KC_TRNS),
	[2] = LAYOUT(KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_LCTL, KC_NO, KC_LCBR, KC_RCBR, KC_MINS, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, KC_LSFT, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_BSPC, KC_SPC, KC_ENT, KC_DEL, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_RSFT, KC_TRNS, KC_NO, KC_NO, MO(4), KC_SPC, KC_ENT, KC_TRNS, KC_NO, KC_NO, KC_TRNS),
	[3] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC, KC_LCTL, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_SPC, KC_ENT, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_TRNS, KC_TRNS, KC_LGUI, KC_NO, KC_SPC, KC_ENT, KC_NO, KC_RALT, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCG_SWP, KC_NO, DEBUG, KC_NO, RESET, RESET, KC_NO, DEBUG, KC_NO, LCG_SWP, KC_NO, KC_NO, LCG_NRM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCG_NRM, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS)
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_DOWN);
        } else {
            tap_code(KC_BRIGHTNESS_UP);
        }
    }
    return false;
}
#endif
