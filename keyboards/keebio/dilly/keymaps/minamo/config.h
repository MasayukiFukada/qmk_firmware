#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLED_NUM 10
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define PERMISSIVE_HOLD
#define TAPPING_TERM 170
#define IGNORE_MOD_TAP_INTERRUPT

#define PREVENT_STUCK_MODIFIERS

#define MOUSEKEY_DELAY             150
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         8
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
