#include "foobar.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE       0
#define _LOWER      1
#define _RAISE      2
#define _EXTEND     3
#define _FNC        4
#define _CURSOR     5
#define _SUPPORT    6
#define _MOUSE      7
#define _ADJ        8

#define _______ KC_TRNS

// Tap-Hold keys
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

#define KC_WCTL LCTL_T(KC_W)
#define KC_YCTL LCTL_T(KC_Y)
#define KC_PSFT LSFT_T(KC_P)
#define KC_LLSF LSFT_T(KC_L)
#define KC_BALT LALT_T(KC_B)
#define KC_JALT LALT_T(KC_J)
#define KC_FGUI GUI_T(KC_F)
#define KC_UGUI GUI_T(KC_U)

#define KC_ZADJ LT(_ADJ, KC_Z)
#define KC_SFNC LT(_FNC, KC_S)
#define KC_GMOU LT(_MOUSE, KC_G)
#define KC_TEXT LT(_EXTEND, KC_T)
#define KC_DCUR LT(_CURSOR, KC_DOT)
#define KC_LSLS LT(_SUPPORT, KC_SLSH)
#define KC_LOW  MO(_LOWER)
#define KC_RAI  MO(_RAISE)
#define KC_DLOW LT(_LOWER, KC_D)
#define KC_HRAI LT(_RAISE, KC_H)

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_Q   ,KC_WCTL,KC_FGUI,KC_PSFT,KC_BALT,  KC_JALT,KC_LLSF,KC_UGUI,KC_YCTL,KC_MINS,
     KC_A   ,KC_R   ,KC_SFNC,KC_TEXT,KC_GMOU,  KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,
     KC_ZADJ,KC_X   ,KC_C   ,KC_DLOW,KC_V   ,  KC_K   ,KC_HRAI,KC_COMM,KC_DCUR,KC_LSLS
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_LOWER] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,  _______,_______,_______,_______,_______,
     KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,  _______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_RAISE] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_GRV ,KC_QUOT,_______,_______,_______,  _______,_______,_______,_______,_______,
     _______,KC_LBRC,KC_RBRC,_______,_______,  _______,KC_EQL ,KC_MINS,KC_BSLS,KC_SCLN,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_EXTEND] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     _______,_______,KC_ESC ,_______,_______,  KC_COLN,KC_SCLN,KC_LABK,KC_RABK,KC_QUES,
     _______,_______,KC_BSPC,_______,_______,  KC_ENT ,KC_SPC ,KC_COMM,KC_DOT ,KC_SLSH,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_FNC] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,  KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,
     KC_F11 ,KC_F12 ,_______,KC_F3  ,_______,  _______,KC_F2  ,_______,KC_MENU,KC_PSCR,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_CURSOR] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_PGUP,KC_HOME,KC_UP  ,KC_END ,KC_INS ,  _______,_______,_______,_______,_______,
     KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL ,  _______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_SUPPORT] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_ESC ,KC_INS ,KC_HENK,KC_MHEN,_______,  _______,_______,_______,_______,_______,
     KC_TAB ,KC_DEL ,KC_BSPC,KC_SPC ,_______,  KC_ENT ,KC_ENT ,_______,_______,_______,
     _______,_______,_______,_______,_______,  _______,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_MOUSE] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     _______,_______,KC_ESC ,_______,_______,  KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5,
     _______,_______,KC_BSPC,_______,_______,  KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,
     _______,_______,_______,_______,_______,  KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [_ADJ] = LAYOUT_split(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_RST ,KC_LCTL,KC_LALT,KC_DEL ,KC_RMOD,  KC_RHUI,KC_RSAI,KC_RVAI,KC_RTOG,KC_RST ,
     _______,_______,KC_RTOG,RGB_RST,KC_RRMD,  KC_RHUD,KC_RSAD,KC_RVAD,KC_DBUG,_______,
     _______,_______,_______,_______,_______,  _______,_______,KC_MUTE,KC_VOLU,KC_VOLD
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

