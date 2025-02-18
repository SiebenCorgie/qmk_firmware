/* Copyright 2020 Paul James
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

#include "lumberjack.h"

enum layers {
    _QWERTY = 0,
    _LEVEL4,
    _FUNCTION,
};

#define FN MO(_FUNCTION)
#define LF MO(_LEVEL4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------.           ,-----------------------------------------.
     * |  Esc |  1   |  2   |  3   |  4   |  5   |           |  6   |  7   |  8   |  9   |  0   |  -   |
     * |------+------+------+------+------+------|           |------+------+------+------+------+------|
     * | Tab  |  Q   |  W   |  E   |  R   |  T   |           |  Y   |  U   |  I   |  O   |  P   |  [   |
     * |------+------+------+------+------+------|           |------+------+------+------+------+------|
     * | Caps |  A   |  S   |  D   |  F   |  G   |           |  H   |  J   |  K   |  L   |  ;   |  '   |
     * |------+------+------+------+------+------|           |------+------+------+------+------+------|
     * | Shft |  Z   |  X   |  C   |  V   |  B   |           |  N   |  M   |  ,   |  .   |  /   |  ESC |
     * |------+------+------+------+------+------|           |------+------+------+------+------+------|
     * | Ctrl | ---- | ---  | GUI  | LALT | Spac |           | Entr |  L5  | bcsp |      |      |      |
     * `-----------------------------------------'           `-----------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x12(
        KC_ESC,  KC_1, KC_2, KC_3,    KC_4,    KC_5,   KC_6,   KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,   KC_Y,   KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC,
        KC_CAPS, KC_A, KC_S, KC_D,    KC_F,    KC_G,   KC_H,   KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,    KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC ,
        KC_LCTL, ____, ____, KC_LGUI, KC_LALT, KC_SPC, KC_ENT, LF,   KC_BSPC, _______, ______, _______),

    /* HardCoded level 4
     * ,------------------------------------------. ,-----------------------------------------.
     * |   -  |   f1 |   f2 |  f3  |   f4 |  f5  | |  f6  | f7   |  f8  |  f9  |  f10 |  f11 |
     * |------+------+------+------+------+------| |------+------+------+------+------+------|
     * |      | pgup | bgsp |  up  |  del | pgdw | |      |   7  |   8  |   9  |   0  | PRTSC|
     * |------+------+------+------+------+------| |------+------+------+------+------+------|
     * |      | start| left | down |right | end  | |      |   4  |   5  |   6  |      |VOLHI |
     * |------+------+------+------+------+------| |------+------+------+------+------+------|
     * |      |      |      |      |      |      | |      |   1  |   2  |   3  |      |VOLLO |
     * |------+------+------+------+------+------| |------+------+------+------+------+------|
     * |      |      |      |      |      |      | |      |      |      |      | PP   | MUTE |
     * `-----------------------------------------' `-----------------------------------------'
     */
    [_LEVEL4] = LAYOUT_ortho_5x12(

        _______, KC_F1,      KC_F2,   KC_F3,   KC_F4,    KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_PAGE_UP, KC_BSPC, KC_UP,   KC_DEL,   KC_PAGE_DOWN, _____,   KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
        _______, _______,    KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,       _______, KC_4,    KC_5,    KC_6,    ______,  KC_VOLU,
        _______, _______,    _______, _______, _______,  _______,      _______, KC_1,    KC_2,    KC_3,    ______,  KC_VOLD,
        _______, _______,    _______, _______, _______,  _______,      _______, _______, _____,   _____,   KC_MPLY, KC_MUTE)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {[_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [_LEVEL4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}};
#endif // ENCODER_MAP_ENABLE
