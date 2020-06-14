#include QMK_KEYBOARD_H

#include "custom_share.h"
#include "custom_keys.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

// -----------------------------------------------------------------------------

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,

    UNKNOWN_TAPS      = 7,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)  return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    }
    return UNKNOWN_TAPS;
}

// -- A

static tap atap_state = {
  .is_press_action = true,
  .state = 0
};

void a_finished (qk_tap_dance_state_t *state, void *user_data) {
  atap_state.state = cur_dance(state);
  switch(atap_state.state) {
    case SINGLE_TAP:  register_code(KC_A);    break;
    case DOUBLE_HOLD: register_code(KC_LSFT); break;
    case TRIPLE_TAP: register_code(KC_TAB); break;
  }
}

void a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(atap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_A); break;
    case DOUBLE_HOLD: unregister_code(KC_LSFT); break;
    case TRIPLE_TAP: unregister_code(KC_TAB); break;
  }
}

// -- E

static tap etap_state = {
  .is_press_action = true,
  .state = 0
};

void e_finished (qk_tap_dance_state_t *state, void *user_data) {
  etap_state.state = cur_dance(state);
  switch(etap_state.state) {
    case SINGLE_TAP: register_code(KC_E); break;
    case DOUBLE_HOLD: layer_on(LOWER); break;
  }
}

void e_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(etap_state.state) {
    case SINGLE_TAP: unregister_code(KC_E); break;
    case DOUBLE_HOLD: layer_off(LOWER); break;
  }
}

// -- F

static tap ftap_state = {
  .is_press_action = true,
  .state = 0
};

void f_finished (qk_tap_dance_state_t *state, void *user_data) {
  ftap_state.state = cur_dance(state);
  switch(ftap_state.state) {
    case SINGLE_TAP: register_code(KC_F); break;
    case DOUBLE_HOLD: register_code(KC_LGUI); break;
  }
}

void f_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(ftap_state.state) {
    case SINGLE_TAP: unregister_code(KC_F); break;
    case DOUBLE_HOLD: unregister_code(KC_LGUI); break;
  }
}

// -- I

static tap itap_state = {
  .is_press_action = true,
  .state = 0
};

void i_finished (qk_tap_dance_state_t *state, void *user_data) {
  itap_state.state = cur_dance(state);
  switch(itap_state.state) {
    case SINGLE_TAP:  register_code(KC_I);    break;
    case DOUBLE_HOLD: layer_on(CURSOR); break;
  }
}

void i_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(itap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_I); break;
    case DOUBLE_HOLD: layer_off(CURSOR); break;
  }
}

// -- L

static tap ltap_state = {
  .is_press_action = true,
  .state = 0
};

void l_finished (qk_tap_dance_state_t *state, void *user_data) {
  ltap_state.state = cur_dance(state);
  switch(ltap_state.state) {
    case SINGLE_TAP:  register_code(KC_L);    break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
  }
}

void l_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(ltap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_L); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT); break;
  }
}

// -- N

static tap ntap_state = {
  .is_press_action = true,
  .state = 0
};

void n_finished (qk_tap_dance_state_t *state, void *user_data) {
  ntap_state.state = cur_dance(state);
  switch(ntap_state.state) {
    case SINGLE_TAP:  register_code(KC_N);    break;
    case DOUBLE_HOLD: layer_on(RAISE); break;
  }
}

void n_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(ntap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_N); break;
    case DOUBLE_HOLD: layer_off(RAISE); break;
  }
}

// -- O

static tap otap_state = {
  .is_press_action = true,
  .state = 0
};

void o_finished (qk_tap_dance_state_t *state, void *user_data) {
  otap_state.state = cur_dance(state);
  switch(otap_state.state) {
    case SINGLE_TAP:  register_code(KC_O);    break;
    case DOUBLE_HOLD: register_code(KC_LSFT); break;
  }
}

void o_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(otap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_O); break;
    case DOUBLE_HOLD: unregister_code(KC_LSFT); break;
  }
}

// -- P

static tap ptap_state = {
  .is_press_action = true,
  .state = 0
};

void p_finished (qk_tap_dance_state_t *state, void *user_data) {
  ptap_state.state = cur_dance(state);
  switch(ptap_state.state) {
    case SINGLE_TAP:  register_code(KC_P);    break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
  }
}

void p_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(ptap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_P); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT); break;
  }
}

// -- Q

static tap qtap_state = {
  .is_press_action = true,
  .state = 0
};

void q_finished (qk_tap_dance_state_t *state, void *user_data) {
  qtap_state.state = cur_dance(state);
  switch(qtap_state.state) {
    case SINGLE_TAP: register_code(KC_Q); break;
    case DOUBLE_TAP: register_code(KC_ESC); break;
  }
}

void q_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(qtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_Q); break;
    case DOUBLE_TAP: unregister_code(KC_ESC); break;
  }
}

// -- U

static tap utap_state = {
  .is_press_action = true,
  .state = 0
};

void u_finished (qk_tap_dance_state_t *state, void *user_data) {
  utap_state.state = cur_dance(state);
  switch(utap_state.state) {
    case SINGLE_TAP: register_code(KC_U); break;
    case DOUBLE_HOLD: register_code(KC_LGUI); break;
  }
}

void u_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(utap_state.state) {
    case SINGLE_TAP: unregister_code(KC_U); break;
    case DOUBLE_HOLD: unregister_code(KC_LGUI); break;
  }
}

// -- W

static tap wtap_state = {
  .is_press_action = true,
  .state = 0
};

void w_finished (qk_tap_dance_state_t *state, void *user_data) {
  wtap_state.state = cur_dance(state);
  switch(wtap_state.state) {
    case SINGLE_TAP:  register_code(KC_W);    break;
    case DOUBLE_HOLD: register_code(KC_LCTL); break;
  }
}

void w_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(wtap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_W); break;
    case DOUBLE_HOLD: unregister_code(KC_LCTL); break;
  }
}

// -- X

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch(xtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case TRIPLE_TAP: reset_keyboard(); break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case TRIPLE_TAP: break;
  }
}

// -- Y

static tap ytap_state = {
  .is_press_action = true,
  .state = 0
};

void y_finished (qk_tap_dance_state_t *state, void *user_data) {
  ytap_state.state = cur_dance(state);
  switch(ytap_state.state) {
    case SINGLE_TAP:  register_code(KC_Y);    break;
    case DOUBLE_HOLD: register_code(KC_LCTL); break;
  }
}

void y_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(ytap_state.state) {
    case SINGLE_TAP:  unregister_code(KC_Y); break;
    case DOUBLE_HOLD: unregister_code(KC_LCTL); break;
  }
}

// -- comma

static tap commatap_state = {
  .is_press_action = true,
  .state = 0
};

void comma_finished (qk_tap_dance_state_t *state, void *user_data) {
  commatap_state.state = cur_dance(state);
  switch(commatap_state.state) {
    case SINGLE_TAP: register_code(KC_COMM); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_COMM); break;
  }
}

void comma_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(commatap_state.state) {
    case SINGLE_TAP: unregister_code(KC_COMM); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_COMM); break;
  }
}

// -- dot

static tap dottap_state = {
  .is_press_action = true,
  .state = 0
};

void dot_finished (qk_tap_dance_state_t *state, void *user_data) {
  dottap_state.state = cur_dance(state);
  switch(dottap_state.state) {
    case SINGLE_TAP: register_code(KC_DOT); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_DOT); break;
  }
}

void dot_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(dottap_state.state) {
    case SINGLE_TAP: unregister_code(KC_DOT); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_DOT); break;
  }
}

// -- slash

static tap slashtap_state = {
  .is_press_action = true,
  .state = 0
};

void slash_finished (qk_tap_dance_state_t *state, void *user_data) {
  slashtap_state.state = cur_dance(state);
  switch(slashtap_state.state) {
    case SINGLE_TAP: register_code(KC_SLSH); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_SLSH); break;
  }
}

void slash_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(slashtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SLSH); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_SLSH); break;
  }
}

// -- minus

static tap minustap_state = {
  .is_press_action = true,
  .state = 0
};

void minus_finished (qk_tap_dance_state_t *state, void *user_data) {
  minustap_state.state = cur_dance(state);
  switch(minustap_state.state) {
    case SINGLE_TAP: register_code(KC_MINS); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_MINS); break;
  }
}

void minus_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(minustap_state.state) {
    case SINGLE_TAP: unregister_code(KC_MINS); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_MINS); break;
  }
}

// -- quot

static tap quottap_state = {
  .is_press_action = true,
  .state = 0
};

void quot_finished (qk_tap_dance_state_t *state, void *user_data) {
  quottap_state.state = cur_dance(state);
  switch(quottap_state.state) {
    case SINGLE_TAP: register_code(KC_QUOT); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_QUOT); break;
  }
}

void quot_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(quottap_state.state) {
    case SINGLE_TAP: unregister_code(KC_QUOT); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_QUOT); break;
  }
}

// -- semicolon

static tap semicolontap_state = {
  .is_press_action = true,
  .state = 0
};

void semicolon_finished (qk_tap_dance_state_t *state, void *user_data) {
  semicolontap_state.state = cur_dance(state);
  switch(semicolontap_state.state) {
    case SINGLE_TAP: register_code(KC_SCLN); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_SCLN); break;
  }
}

void semicolon_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(semicolontap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SCLN); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_SCLN); break;
  }
}

// -- space

static tap spacetap_state = {
  .is_press_action = true,
  .state = 0
};

void space_finished (qk_tap_dance_state_t *state, void *user_data) {
  spacetap_state.state = cur_dance(state);
  switch(spacetap_state.state) {
    case SINGLE_TAP: register_code(KC_SPC); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_BSPC); break;
    case DOUBLE_HOLD: register_code(KC_BSPC); break;
  }
}

void space_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(spacetap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SPC); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case DOUBLE_HOLD: unregister_code(KC_BSPC); break;
  }
}

// -- enter

static tap entertap_state = {
  .is_press_action = true,
  .state = 0
};

void enter_finished (qk_tap_dance_state_t *state, void *user_data) {
  entertap_state.state = cur_dance(state);
  switch(entertap_state.state) {
    case SINGLE_TAP: register_code(KC_ENT); break;
    case DOUBLE_TAP: register_code(KC_BSPC); break;
    case DOUBLE_HOLD: register_code(KC_BSPC); break;
  }
}

void enter_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(entertap_state.state) {
    case SINGLE_TAP: unregister_code(KC_ENT); break;
    case DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case DOUBLE_HOLD: unregister_code(KC_BSPC); break;
  }
}

// -- 1

static tap n1tap_state = {
  .is_press_action = true,
  .state = 0
};

void n1_finished (qk_tap_dance_state_t *state, void *user_data) {
  n1tap_state.state = cur_dance(state);
  switch(n1tap_state.state) {
    case SINGLE_TAP: register_code(KC_1); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_1); break;
  }
}

void n1_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n1tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_1); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_1); break;
  }
}

// -- 2

static tap n2tap_state = {
  .is_press_action = true,
  .state = 0
};

void n2_finished (qk_tap_dance_state_t *state, void *user_data) {
  n2tap_state.state = cur_dance(state);
  switch(n2tap_state.state) {
    case SINGLE_TAP: register_code(KC_2); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_2); break;
  }
}

void n2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n2tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_2); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_2); break;
  }
}

// -- 3

static tap n3tap_state = {
  .is_press_action = true,
  .state = 0
};

void n3_finished (qk_tap_dance_state_t *state, void *user_data) {
  n3tap_state.state = cur_dance(state);
  switch(n3tap_state.state) {
    case SINGLE_TAP: register_code(KC_3); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_3); break;
  }
}

void n3_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n3tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_3); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_3); break;
  }
}

// -- 4

static tap n4tap_state = {
  .is_press_action = true,
  .state = 0
};

void n4_finished (qk_tap_dance_state_t *state, void *user_data) {
  n4tap_state.state = cur_dance(state);
  switch(n4tap_state.state) {
    case SINGLE_TAP: register_code(KC_4); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_4); break;
  }
}

void n4_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n4tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_4); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_4); break;
  }
}

// -- 5

static tap n5tap_state = {
  .is_press_action = true,
  .state = 0
};

void n5_finished (qk_tap_dance_state_t *state, void *user_data) {
  n5tap_state.state = cur_dance(state);
  switch(n5tap_state.state) {
    case SINGLE_TAP: register_code(KC_5); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_5); break;
  }
}

void n5_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n5tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_5); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_5); break;
  }
}

// -- 6

static tap n6tap_state = {
  .is_press_action = true,
  .state = 0
};

void n6_finished (qk_tap_dance_state_t *state, void *user_data) {
  n6tap_state.state = cur_dance(state);
  switch(n6tap_state.state) {
    case SINGLE_TAP: register_code(KC_6); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_6); break;
  }
}

void n6_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n6tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_6); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_6); break;
  }
}

// -- 7

static tap n7tap_state = {
  .is_press_action = true,
  .state = 0
};

void n7_finished (qk_tap_dance_state_t *state, void *user_data) {
  n7tap_state.state = cur_dance(state);
  switch(n7tap_state.state) {
    case SINGLE_TAP: register_code(KC_7); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_7); break;
  }
}

void n7_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n7tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_7); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_7); break;
  }
}

// -- 8

static tap n8tap_state = {
  .is_press_action = true,
  .state = 0
};

void n8_finished (qk_tap_dance_state_t *state, void *user_data) {
  n8tap_state.state = cur_dance(state);
  switch(n8tap_state.state) {
    case SINGLE_TAP: register_code(KC_8); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_8); break;
  }
}

void n8_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n8tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_8); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_8); break;
  }
}

// -- 9

static tap n9tap_state = {
  .is_press_action = true,
  .state = 0
};

void n9_finished (qk_tap_dance_state_t *state, void *user_data) {
  n9tap_state.state = cur_dance(state);
  switch(n9tap_state.state) {
    case SINGLE_TAP: register_code(KC_9); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_9); break;
  }
}

void n9_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n9tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_9); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_9); break;
  }
}

// -- 0

static tap n0tap_state = {
  .is_press_action = true,
  .state = 0
};

void n0_finished (qk_tap_dance_state_t *state, void *user_data) {
  n0tap_state.state = cur_dance(state);
  switch(n0tap_state.state) {
    case SINGLE_TAP: register_code(KC_0); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_0); break;
  }
}

void n0_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch(n0tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_0); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_0); break;
  }
}

// -----------------------------------------------------------------------------

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    [TD_KEY_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, e_reset),
    [TD_KEY_F] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f_finished, f_reset),
    [TD_KEY_I] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, i_finished, i_reset),
    [TD_KEY_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_finished, l_reset),
    [TD_KEY_N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n_finished, n_reset),
    [TD_KEY_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_finished, o_reset),
    [TD_KEY_P] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, p_finished, p_reset),
    [TD_KEY_Q] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    [TD_KEY_U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    [TD_KEY_W] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
    [TD_KEY_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
    [TD_KEY_Y] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset),
    [TD_KEY_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset),
    [TD_KEY_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, enter_finished, enter_reset),
    [TD_KEY_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comma_finished, comma_reset),
    [TD_KEY_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, dot_reset),
    [TD_KEY_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slash_finished, slash_reset),
    [TD_KEY_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, minus_finished, minus_reset),
    [TD_KEY_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quot_finished, quot_reset),
    [TD_KEY_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semicolon_finished, semicolon_reset),
    [TD_KEY_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n1_finished, n1_reset),
    [TD_KEY_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n2_finished, n2_reset),
    [TD_KEY_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n3_finished, n3_reset),
    [TD_KEY_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n4_finished, n4_reset),
    [TD_KEY_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n5_finished, n5_reset),
    [TD_KEY_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n6_finished, n6_reset),
    [TD_KEY_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n7_finished, n7_reset),
    [TD_KEY_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n8_finished, n8_reset),
    [TD_KEY_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n9_finished, n9_reset),
    [TD_KEY_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n0_finished, n0_reset),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
