#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE   0
#define _LOWER 1
#define _RAISE 2
#define _CURSOR 3
#define _FUNC  4
#define _MOUSE 5
#define _ADJUST 6

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
  //RGB_RST,
  //TAP_ANM,
};

#define KC_ KC_TRNS
#define KC________ KC_TRNS
#define KC_XXXXXXX KC_NO

#define KC_MSPC CTL_T(KC_SPC)
#define KC_MENT SFT_T(KC_ENT)
#define KC_LOWR LT(_LOWER, KC_ESC)
#define KC_RASE LT(_RAISE, KC_BSPC)
#define KC_LDOT LT(_CURSOR, KC_DOT)
#define KC_MALT ALT_T(KC_BSPC)

#define KC_ADJ  ADJUST
#define KC_MOSE MOUSE
#define KC_FUNC FUNC
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG

#ifdef RGBLIGHT_ENABLE

#define KC_RRST RGB_RST
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RRMD RGB_RMOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_ANIME TAP_ANM

extern rgblight_config_t rgblight_config;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     KC_ESC ,XXXXXXX,XXXXXXX,XXXXXXX,KC_INS ,KC_DEL ,                 KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,KC_BSPC,
     KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                 KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,XXXXXXX,
     KC_LSFT,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                 KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_MHEN,
     KC_ADJ ,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,KC_MOSE, KC_MOSE,KC_K   ,KC_H   ,KC_COMM,KC_LDOT,KC_SLSH,KC_HENK,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     KC_LGUI,KC_LOWR,KC_MSPC, KC_MENT,KC_RASE,KC_MALT
  ),

  [_LOWER] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
     KC_EQL ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,                 KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
     _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                 KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______, _______,_______,_______,KC_COMM,KC_DOT ,KC_SLSH,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  ),

  [_RAISE] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                 KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     _______,KC_GRV ,KC_QUOT,XXXXXXX,XXXXXXX,XXXXXXX,                 XXXXXXX,KC_EQL ,KC_MINS,KC_BSLS,KC_SCLN,_______,
     _______,XXXXXXX,KC_LBRC,KC_RBRC,XXXXXXX,XXXXXXX,                 XXXXXXX,XXXXXXX,KC_COMM,KC_DOT ,KC_SLSH,_______,
     _______,_______,_______,_______,_______,_______,_______, _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  ),

  [_CURSOR] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
     _______,KC_PGUP,KC_HOME,KC_UP  ,KC_END ,_______,                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,_______,                 XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  ),

  [_FUNC] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                 KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
     _______,_______,_______,_______,_______,_______,_______, _______,KC_HOME,KC_END ,_______,_______,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  ),

  [_MOUSE] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,                 KC_ACL0,KC_ACL1,KC_ACL2,_______,_______,_______,
     _______,_______,_______,KC_ESC ,_______,_______,                 KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5,_______,
     _______,_______,_______,KC_BSPC,_______,_______,                 KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
     _______,_______,_______,_______,_______,_______,_______, _______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  ),

  [_ADJUST] = LAYOUT(
  //.-------+-------+-------+-------+-------+-------.                .-------+-------+-------+-------+-------+-------.
     RESET  ,_______,_______,_______,_______,_______,                 KC_ACL0,KC_ACL1,KC_ACL2,_______,_______,RESET  ,
     _______,_______,_______,_______,_______,_______,                 KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5,_______,
     _______,_______,_______,_______,_______,_______,                 KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
     _______,_______,_______,_______,_______,_______,_______, _______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______,_______,
  //`-------+-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______, _______,_______,_______
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

//bool isTapAnimation = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
//  case RGB_RST:
//    #ifdef RGBLIGHT_ENABLE
//      if (record->event.pressed) {
//        eeconfig_update_rgblight_default();
//        rgblight_enable();
//      }
//    #endif
//    break;
//  case TAP_ANM:
//    if (record->event.pressed) {
//      isTapAnimation = !isTapAnimation;
//    }
//    break;
  }

//if (isTapAnimation) {
//  rgblight_mode_noeeprom(1);
//  uint16_t hue = (rgblight_config.hue + 5) % 360;
//  rgblight_sethsv_noeeprom(hue, rgblight_config.sat, rgblight_config.val);
//}

  return true;
}
