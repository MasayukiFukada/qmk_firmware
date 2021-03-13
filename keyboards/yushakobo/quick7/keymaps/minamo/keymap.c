/* Copyright 2020 yushakobo
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SUB
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    YUSHAURL = SAFE_RANGE
};

#define KC_LLAY LT(_SUB, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
//       '--------+--------+--------'
           KC_MUTE, KC_LLAY, RGB_MOD,
           KC_ESC , KC_UP  , KC_BSPC,
           KC_LEFT, KC_DOWN, KC_RGHT
//       '--------+--------+--------'
    ),
    [_SUB] = LAYOUT(
//       '--------+--------+--------'
           RESET  , _______, RGB_TOG,
           KC_1   , KC_LEAD, KC_2   ,
           KC_3   , KC_4   , KC_5
//       '--------+--------+--------'
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) { // Right encoder
        if (clockwise) {
            rgblight_decrease_hue_noeeprom();
        } else {
            rgblight_increase_hue_noeeprom();
        }
    }
}

bool did_leader_succeed;

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        did_leader_succeed = leading = false;

        SEQ_ONE_KEY(KC_1) {
            // feedly の 一度 j を押してアクティブになってからのマクロ
            // 「Read Later の解除」「別タブで開く」「2 番目のタブに戻る」「削除」
            SEND_STRING("sv" SS_LCTL("2") "x");
            did_leader_succeed = true;
        }
        SEQ_ONE_KEY(KC_2) {
            did_leader_succeed = true;
        }
        SEQ_ONE_KEY(KC_3) {
            did_leader_succeed = true;
        }
        SEQ_ONE_KEY(KC_4) {
            register_code(KC_LSFT);
            register_code(KC_LGUI);
            tap_code(KC_C);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            did_leader_succeed = true;
        }
        SEQ_ONE_KEY(KC_5) {
            did_leader_succeed = true;
        }
        else {
            did_leader_succeed = true;
        }

        leader_end();
    }
}

void leader_start(void) {
}

void leader_end(void) {
    if (did_leader_succeed) {
    } else {
    }
}
