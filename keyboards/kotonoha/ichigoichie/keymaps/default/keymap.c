/* Copyright 2020 MasayukiFukada
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
#include "keytable.h"

extern rgblight_config_t rgblight_config;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
  // ,-------+------+------+------+------.
        BIT7 , BIT4 , BIT3 , BIT2 , BIT1 ,
        BIT5 , BIT6 ,        BIT8 , BIT9
  // ,-------+------+------+------+------.
  ),
};

// LED 初期化
void led_init(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_setrgb_at(  0,   0,   0, 0);
  rgblight_setrgb_at(  0,   0,   0, 1);
  rgblight_setrgb_at(  0,   0,   0, 2);
#endif
}

// 入力に対する LED アクション
uint16_t hue = 0;
bool isFirstBoot = true;
void input_action_led(keyrecord_t *record) {
  if (isFirstBoot) {
    isFirstBoot = false;
    led_init();
  }
  if (record->event.pressed) {
    return;
  }
  hue = (hue + 5) % 360;
  rgblight_sethsv_at(hue, rgblight_config.sat, rgblight_config.val, 1);
  // 下はとりあえず GUI のワンショット状態のインジケーターに使用する
  if (isGuiOneshot) {
    return;
  }
  rgblight_sethsv_at(hue, rgblight_config.sat, rgblight_config.val, 0);
}

// キーに対する反応
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  input_action_led(record);

  switch (keycode) {
    case BIT1: update_code_by(KEYBIT1, record); break;
    case BIT2: update_code_by(KEYBIT2, record); break;
    case BIT3: update_code_by(KEYBIT3, record); break;
    case BIT4: update_code_by(KEYBIT4, record); break;
    case BIT5: update_code_by(KEYBIT5, record); break;
    case BIT6: update_code_by(KEYBIT6, record); break;
    case BIT7: update_code_by(KEYBIT7, record); break;
    case BIT8: update_code_by(KEYBIT8, record); break;
    case BIT9: update_code_by(KEYBIT9, record); break;
    default:
      break;
  }
  return true;
}

void matrix_init_user(void) {
/*
  debug_enable = true;
  debug_matrix = true;
  debug_mouse  = true;
*/
}

void led_set_user(uint8_t usb_led) {
  led_init();
}
