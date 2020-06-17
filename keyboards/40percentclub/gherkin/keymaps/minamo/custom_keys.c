#include QMK_KEYBOARD_H

#include "custom_share.h"
#include "custom_keys.h"

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

// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
};

// -----------------------------------------------------------------------------

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};

