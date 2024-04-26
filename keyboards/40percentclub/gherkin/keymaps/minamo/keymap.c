#include QMK_KEYBOARD_H

#include "custom_share.h"
#include "custom_keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ortho_3x10(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     MY_Q   ,MY_W   ,MY_F   ,MY_P   ,MY_B   ,  MY_J   ,MY_L   ,MY_U   ,MY_Y   ,MY_MINS,
     MY_A   ,MY_R   ,MY_S   ,MY_T   ,MY_G   ,  MY_M   ,MY_N   ,MY_E   ,MY_I   ,MY_O   ,
     MY_Z   ,MY_X   ,MY_C   ,MY_D   ,MY_SPC ,  MY_K   ,MY_H   ,MY_V   ,MY_ENT ,MY_SLSH
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [LOWER] = LAYOUT_ortho_3x10(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     MY_6   ,MY_7   ,MY_8   ,MY_9   ,MY_0   ,  _______,_______,_______,_______,_______,
     MY_1   ,MY_2   ,MY_3   ,MY_4   ,MY_5   ,  MY_EQL ,MY_SCLN,MY_CMM ,MY_DOT ,MY_SLSH,
     MY_GRV ,MY_QUOT,MY_LBRC,MY_RBRC,MY_BSLS,  KC_PSCR,_______,_______,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [RAISE] = LAYOUT_ortho_3x10(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_PGUP,KC_HOME,KC_UP  ,KC_END ,KC_F7  ,  KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_F1  ,  KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,
     _______,_______,_______,_______,KC_F13 ,  KC_F14 ,KC_F15 ,KC_F16 ,KC_F17 ,KC_F18
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [PLAY] = LAYOUT_ortho_3x10(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,  KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_ESC ,
     KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,  KC_M   ,KC_N   ,KC_E   ,KC_I   ,_______,
     KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_SPC ,  KC_K   ,KC_H   ,KC_V   ,KC_ENT ,KC_SLSH
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
  [SUPPORT] = LAYOUT_ortho_3x10(
  //,-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------.
     KC_ESC ,KC_INS ,KC_INT4,KC_INT5,_______,  _______,_______,NORMAL ,GAME   ,QK_BOOT,
     KC_TAB ,KC_DEL ,KC_BSPC,KC_SPC ,_______,  _______,KC_ENT ,_______,KC_LNG5,_______,
     RGB_TOG,RGB_MOD,RGB_RMOD,RGB_HUI,RGB_HUD, KC_MUTE,KC_VOLU,KC_VOLD,_______,_______
  //`-------+-------+-------+-------+-------+  -------+-------+-------+-------+-------'
  ),
};

