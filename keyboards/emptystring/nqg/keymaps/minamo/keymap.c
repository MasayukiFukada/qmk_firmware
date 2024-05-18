#include QMK_KEYBOARD_H

#define _BASE    0
#define _LOWER   1
#define _RAISE   2
#define _PLAY    3
#define _SUPPORT 4

tap_dance_action_t tap_dance_actions[] = {};

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

#define KC_L1 DF(_BASE)
#define KC_L2 DF(_CUSTOM)

#define MY_Q LSFT_T(KC_Q)
#define MY_W LCTL_T(KC_W)
#define MY_F LGUI_T(KC_F)
#define MY_P LALT_T(KC_P)
#define MY_L RALT_T(KC_L)
#define MY_U RGUI_T(KC_U)
#define MY_Y RCTL_T(KC_Y)
#define MY_MINS RSFT_T(KC_MINS)

#define MY_R LT(_RAISE, KC_R)
#define MY_T LT(_LOWER, KC_T)
#define MY_E LT(_LOWER, KC_E)
#define MY_I LT(_RAISE, KC_I)
#define MY_O LT(_SUPPORT, KC_O)

#define KC_LCMM LT(_LOWER, KC_COMM)
#define KC_LDOT LT(_RAISE, KC_DOT)
#define KC_LSLS LT(_SUPPORT, KC_SLSH)
#define KC_LENT LT(_ADJUST, KC_ENTER)
#define KC_LLOW LT(_LOWER, KC_ESC)
#define KC_LRAI LT(_RAISE, KC_BSPC)

#define KC_HENK KC_INT4
#define KC_MHEN KC_INT5
#define RESET QK_BOOT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
               MY_Q    , MY_W    , MY_F    , MY_P    , KC_B    , KC_J    , MY_L    , MY_U    , MY_Y    , MY_MINS , \
               KC_A    , MY_R    , KC_S    , MY_T    , KC_G    , KC_M    , KC_N    , MY_E    , MY_I    , MY_O    , \
               KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_K    , KC_H    , KC_COMM , KC_ENT  , KC_SLSH , \
     KC_ESC  ,                     XXXXXXX , XXXXXXX , KC_SPC  , KC_ENT  , XXXXXXX , XXXXXXX
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
  ),
  [_LOWER] = LAYOUT(
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
               KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ , _______ , _______ , _______ , _______ , \
               KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_EQL  , KC_SCLN , KC_COMM , KC_DOT  , KC_SLSH , \
               KC_GRV  , KC_QUOT , KC_LBRC , KC_RBRC , KC_BSLS , KC_PSCR , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
     XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
  ),
  [_RAISE] = LAYOUT(
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
               KC_PGUP , KC_HOME , KC_UP   , KC_END  , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , \
               KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , \
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F13  , KC_F14  , KC_F15  , KC_F16  , KC_F17  , KC_F18  , \
     XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
  ),
  [_PLAY] = LAYOUT(
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
               KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , \
               KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , XXXXXXX , \
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
     XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
  ),
  [_SUPPORT] = LAYOUT(
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
               KC_ESC  , KC_INS  , KC_INT4 , KC_INT5 , XXXXXXX , XXXXXXX , XXXXXXX , _BASE   , _PLAY   , QK_BOOT , \
               KC_TAB  , KC_DEL  , KC_BSPC , KC_SPC  , XXXXXXX , XXXXXXX , KC_ENT  , XXXXXXX , KC_LNG5 , XXXXXXX , \
               XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MUTE , KC_VOLU , KC_VOLD , XXXXXXX , XXXXXXX , \
     XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
// ,---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------.
  ),
};

