/* Copyright 2019 e3w2q
 * * This program is free software: you can redistribute it and/or modify
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

#define BASE     0
#define LOWER    1
#define RAISE    2
#define CURSOR   3
#define FUNCTION 4
#define SUPPORT  5
#define ADJUST   6

// Fillers to make layering more clear
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RRMD RGB_RMOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_LLOW LT(LOWER, KC_ESC)
#define KC_LRAI LT(RAISE, KC_BSPC)
#define KC_LADJ LT(ADJUST, KC_HENK)
#define KC_LCUR LT(CURSOR, KC_HENK)
#define KC_LFUN LT(FUNCTION, KC_MHEN)
#define KC_LSUP LT(SUPPORT, KC_NO)
#define KC_LDOT LT(CURSOR, KC_DOT)
#define KC_LSLS LT(SUPPORT, KC_SLSH)
#define KC_LDEL LT(ADJUST, KC_DEL)
#define KC_MGUI LGUI_T(KC_ENT)
#define KC_MALT LALT_T(KC_ENT)
#define KC_MENT LSFT_T(KC_ENT)
#define KC_MSPC LCTL_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,---------------------------------------------------
   *  |    =    (    )   BS  Esc   F1   F2   F3   F4   F5
   *  | NmLk  KP/  KP*  Tab Hank    1    2    3    4    5
   *  |  KP7  KP8  KP9  KP-  Tab    Q    W    E    R    T
   *  |  KP4  KP5  KP6  KP+ Caps    A    S    D    F    G
   *  |  KP1  KP2  KP3 Entr Shft    Z    W    C    V    B
   *  |  KP0   00    .    , Ctrl  GUI  Alt MHEN Spce Spce
   *  `---------------------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,---------------------------------------------------
   *  |   F6   F7   F8   F9  F10  F11  F12 PtSc  Del  Ins
   *  |    6    7    8    9    0    -    =   BS   BS Home
   *  |    Y    U    I    O    P    [    ]    \ Entr  End
   *  |    H    J    K    L    ;    ' Entr Entr Entr  PgUp
   *  |    N    M    ,    .    / Shft Shft Shft   Up  PgDn
   *  | Spce  HEN KANA  Alt  App Ctrl MO(1)Left Down Rght
   *  `---------------------------------------------------
   */

  [BASE] = LAYOUT(
    // 左手
    KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , KC_MUTE ,
    KC_A    , KC_R    , KC_S    , KC_T    , KC_G    , KC_LADJ ,
    KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_MGUI ,
              KC_LDEL , KC_TAB  , KC_LLOW , KC_MSPC ,

    // 右手
    XXXXXXX , KC_J    , KC_L    , KC_U    , KC_Y    , KC_MINS ,
    KC_LFUN , KC_M    , KC_N    , KC_E    , KC_I    , KC_O    ,
    KC_MALT , KC_K    , KC_H    , KC_COMM , KC_LDOT , KC_LSLS ,
              KC_MENT , KC_LRAI , KC_LSUP , KC_LCUR
  ),

  [LOWER] = LAYOUT(
    // 左手
    KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , XXXXXXX ,
    KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              XXXXXXX , XXXXXXX , _______ , _______ ,

    // 右手
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              _______ , _______ , XXXXXXX , XXXXXXX
  ),

  [RAISE] = LAYOUT(
    // 左手
    KC_GRV  , KC_QUOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_LBRC , KC_RBRC , XXXXXXX , XXXXXXX , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              XXXXXXX , XXXXXXX , _______ , _______ ,

    // 右手
    XXXXXXX , XXXXXXX , KC_EQL  , KC_MINS , KC_BSLS , KC_SCLN ,
    _______ , XXXXXXX , XXXXXXX , KC_COMM , KC_DOT  , KC_SLSH ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              _______ , _______ , XXXXXXX , XXXXXXX
  ),

  [CURSOR] = LAYOUT(
    // 左手
    KC_PGUP , KC_HOME , KC_UP   , KC_END  , XXXXXXX , XXXXXXX ,
    KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              XXXXXXX , XXXXXXX , _______ , _______ ,

    // 右手
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              _______ , _______ , XXXXXXX , XXXXXXX
  ),

  [FUNCTION] = LAYOUT(
    // 左手
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX ,
    KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              XXXXXXX , XXXXXXX , _______ , _______ ,

    // 右手
    XXXXXXX , KC_F6   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , KC_F12  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              _______ , _______ , XXXXXXX , XXXXXXX
  ),

  [SUPPORT] = LAYOUT(
    // 左手
    KC_ESC  , XXXXXXX , KC_HENK , KC_MHEN , XXXXXXX , XXXXXXX ,
    KC_TAB  , KC_DEL  , KC_BSPC , KC_SPC  , XXXXXXX , _______ ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,
              XXXXXXX , XXXXXXX , _______ , _______ ,

    // 右手
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    _______ , KC_ENT  , KC_ENT  , XXXXXXX , XXXXXXX , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              _______ , _______ , XXXXXXX , XXXXXXX
  ),

  [ADJUST] = LAYOUT(
    // 左手
    RESET   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

    // 右手
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
  ),
};

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
            tap_code(KC_TAB);
        } else {
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
    }
}

void led_set_user(uint8_t usb_led) {
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

