/* Copyright 2019 Takuya Urakawa, Dm9Recoreds.com
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
#include "leds.h"

#define KC_LLOW LT(LOWER, KC_NO)
#define KC_LRAI LT(RAISE, KC_NO)
#define KC_LCUR LT(CURSOR, KC_HENK)
#define KC_LFUN LT(FUNCTION, KC_MHEN)
#define KC_LSUP LT(SUPPORT, KC_NO)
#define KC_LADJ MO(ADJUST)
#define KC_LDOT LT(CURSOR, KC_DOT)
#define KC_LSLS LT(SUPPORT, KC_SLSH)

#define KC_MENT LSFT_T(KC_ENT)
#define KC_MSPC LCTL_T(KC_SPC)

enum layers {
    BASE,
    LOWER,
    RAISE,
    CURSOR,
    FUNCTION,
    SUPPORT,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        KC_ESC , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_LBRC,   KC_J   , KC_L   , KC_U   , KC_Y   , KC_MINS, KC_BSPC, \
        KC_TAB , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_RBRC,   KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_DEL,  \
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,            KC_PSCR, KC_K   , KC_H   , KC_COMM, KC_LDOT, KC_LSLS, \
        KC_LADJ,                   KC_LALT, KC_LGUI, KC_LLOW, KC_MSPC,   KC_MENT, KC_LRAI, KC_RALT, KC_LSUP, KC_LFUN, KC_LCUR  \
    ),
    [LOWER] = LAYOUT(
        XXXXXXX, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    ),
    [RAISE] = LAYOUT(
        XXXXXXX, KC_GRV , KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_EQL , KC_MINS, KC_BSLS, KC_SCLN, XXXXXXX, \
        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    ),
    [CURSOR] = LAYOUT(
        XXXXXXX, KC_PGUP, KC_HOME, KC_UP  , KC_END , XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    ),
    // RESET に失敗するとネジを全て緩める必要があるので複数用意しておく。
    [FUNCTION] = LAYOUT(
        RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    ),
    [SUPPORT] = LAYOUT(
        RESET  , KC_ESC , KC_INS , KC_HENK, KC_MHEN, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_TAB , KC_DEL , KC_BSPC, KC_SPC , XXXXXXX, XXXXXXX,   KC_ENT , KC_ENT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    ),
    [ADJUST] = LAYOUT(
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, \
        _______,                   _______, _______, _______, _______,   _______, XXXXXXX, _______, _______, _______, _______ \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

uint32_t layer_state_set_user(uint32_t state) {
    uint32_t computed = update_tri_layer_state(state, LOWER, RAISE, ADJUST);
    switch (biton32(computed)) {
    case LOWER:
        set_led(0,0);
        set_led(1,1);
        set_led(2,0);
        break;
    case RAISE:
        set_led(0,0);
        set_led(1,0);
        set_led(2,1);
        break;
    case ADJUST:
        set_led(0,1);
        set_led(1,1);
        set_led(2,1);
        break;
    default:
        set_led(0,0);
        set_led(1,0);
        set_led(2,0);
        break;
    }
  return computed;
}

void led_set_user(uint8_t usb_led) {
}
