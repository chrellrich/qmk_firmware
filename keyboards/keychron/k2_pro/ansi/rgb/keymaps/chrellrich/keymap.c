/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off
enum layers{
  WIN_BASE,
  WIN_FN,
  WIN_FN2
};


// Tap Dance declarations
enum {
    TD_CAPS_ESC,
    TD_RGB_KEYLOCK,
    TD_F1_F13,
    TD_F2_F14,
    TD_F3_F15,
    TD_F4_F16,
    TD_F5_F17,
    TD_F6_F18,
    TD_F7_F19,
    TD_F8_F20,
    TD_F9_F21,
    TD_F10_F22,
    TD_F11_F23,
    TD_F12_F24,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Caps Lock, twice for Escape
    [TD_CAPS_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS, KC_ESC),
    [TD_F1_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F13),
    [TD_F2_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F14),
    [TD_F3_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F15),
    [TD_F4_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F16),
    [TD_F5_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F17),
    [TD_F6_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F18),
    [TD_F7_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F19),
    [TD_F8_F20] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F20),
    [TD_F9_F21] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F21),
    [TD_F10_F22] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F22),
    [TD_F11_F23] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F23),
    [TD_F12_F24] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_F24),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[WIN_BASE] = LAYOUT_ansi_84(
     KC_ESC,   TD(TD_F1_F13),    TD(TD_F2_F14),    TD(TD_F3_F15),    TD(TD_F4_F16),    TD(TD_F5_F17),    TD(TD_F6_F18),    TD(TD_F7_F19),    TD(TD_F8_F20),    TD(TD_F9_F21),    TD(TD_F10_F22),   TD(TD_F11_F23),   TD(TD_F12_F24),   KC_PSCR,  KC_DEL,   QK_LOCK,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            DM_REC1,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            DM_PLY1,
     TD(TD_CAPS_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_BTN1,  KC_MS_U,  KC_BTN2,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  MO(WIN_FN2),  KC_MS_L,  KC_MS_D,  KC_MS_R),

[WIN_FN2] = LAYOUT_ansi_84(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_WH_U,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_L,  KC_WH_D,  KC_WH_R)
};
