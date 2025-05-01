#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE    0
#define _LOWER   1
#define _RAISE   2
#define _SUPPORT 3
#define _ADJUST  4

enum custom_keycodes {
  ONESHOT_CLEAR = SAFE_RANGE,
  ONESHOT_SHIFT,
  ONESHOT_CTRL,
  ONESHOT_ALT,
  ONESHOT_GUI,
  RGB_RST,
  TAP_ANM
};

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

#define KC_LCMM LT(_LOWER, KC_COMM)
#define KC_LDOT LT(_RAISE, KC_DOT)
#define KC_LSLS LT(_SUPPORT, KC_SLSH)
#define KC_LMIN LT(_ADJUST, KC_MINS)
#define KC_LLOW LT(_LOWER, KC_BSPC)
#define KC_LRAI LT(_RAISE, KC_LNG5)
#define KC_MALT LALT_T(KC_ESC)
#define KC_MGUI LGUI_T(KC_DEL)
#define KC_MENT LSFT_T(KC_ENT)
#define KC_MSPC LCTL_T(KC_SPC)

#define KC_1CLR ONESHOT_CLEAR
#define KC_1SFT ONESHOT_SHIFT
#define KC_1CTL ONESHOT_CTRL
#define KC_1ALT ONESHOT_ALT
#define KC_1GUI ONESHOT_GUI

#define KC_JPN  LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( \
// ,---------+---------+---------+---------+---------.  ,---------+---------+---------+---------+---------.
     KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,    KC_J    , KC_L    , KC_U    , KC_Y    , KC_LMIN , \
     KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,    KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , \
     KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    ,    KC_K    , KC_H    , KC_LCMM , KC_LDOT , KC_LSLS , \
// `---------+---------+---------+---------+---------/  `---------+---------+---------+---------+---------/
                         KC_MALT , KC_MGUI , KC_MSPC ,    KC_MENT , KC_LLOW , KC_LRAI \
),
[_LOWER] = LAYOUT( \
// ,---------+---------+---------+---------+---------.  ,---------+---------+---------+---------+---------.
     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
     KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,    KC_EQL  , KC_SCLN , KC_COMM , KC_DOT  , KC_SLSH , \
     KC_GRV  , KC_QUOT , KC_LBRC , KC_RBRC , KC_BSLS ,    KC_PSCR , KC_APP  , KC_MUTE , XXXXXXX , XXXXXXX , \
// `---------+---------+---------+---------+---------/  `---------+---------+---------+---------+---------/
                         _______ , _______ , _______ ,    _______ , _______ , _______ \
),
[_RAISE] = LAYOUT( \
// ,---------+---------+---------+---------+---------.  ,---------+---------+---------+---------+---------.
     KC_PGUP , KC_HOME , KC_UP   , KC_END  , KC_F7   ,    KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , \
     KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , KC_F1   ,    KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , \
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F13  ,    KC_F14  , KC_F15  , KC_F16  , KC_F17  , KC_F18  , \
// `---------+---------+---------+---------+---------/  `---------+---------+---------+---------+---------/
                         _______ , _______ , _______ ,    _______ , _______ , _______ \
),
[_SUPPORT] = LAYOUT( \
// ,---------+---------+---------+---------+---------.  ,---------+---------+---------+---------+---------.
     KC_ESC  , KC_LNG5 , KC_INT4 , KC_INT5 , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
     KC_TAB  , XXXXXXX , KC_BSPC , KC_SPC  , XXXXXXX ,    XXXXXXX , KC_JPN  , KC_LCTL , KC_LSFT , KC_BSPC , \
     KC_CAPS , XXXXXXX , XXXXXXX , KC_SPC  , KC_SPC  ,    KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , \
// `---------+---------+---------+---------+---------/  `---------+---------+---------+---------+---------/
                         _______ , _______ , _______ ,    _______ , _______ , _______ \
),
[_ADJUST] = LAYOUT( \
// ,---------+---------+---------+---------+---------.  ,---------+---------+---------+---------+---------.
     QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , \
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , \
     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , \
// `---------+---------+---------+---------+---------/  `---------+---------+---------+---------+---------/
                         XXXXXXX , XXXXXXX , XXXXXXX ,    XXXXXXX , XXXXXXX , XXXXXXX \
),
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// ワンショットモディファイアの追加
// ※ 各モディファイアは合成、保持される
void append_onshot_modifier(uint8_t newkey) {
  uint8_t modkeys = get_oneshot_mods() | newkey;
  set_oneshot_mods(modkeys);
}
void set_oneshot_shift(void) { append_onshot_modifier(MOD_LSFT); }
void set_oneshot_ctrl(void)  { append_onshot_modifier(MOD_LCTL); }
void set_oneshot_alt(void)   { append_onshot_modifier(MOD_LALT); }
void set_oneshot_gui(void)   { append_onshot_modifier(MOD_LGUI); }
void set_oneshot_clear(void) {
  clear_oneshot_mods();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ONESHOT_CLEAR: set_oneshot_clear(); break;
    case ONESHOT_SHIFT: set_oneshot_shift(); break;
    case ONESHOT_CTRL:  set_oneshot_ctrl(); break;
    case ONESHOT_ALT:   set_oneshot_alt(); break;
    case ONESHOT_GUI:   set_oneshot_gui(); break;
  }
  return true;
}
