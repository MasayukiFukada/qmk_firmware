<<<<<<< HEAD
// Copyright 2022 Takuya Urakawa @hsgw (dm9records.com, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lain.h"

keyboard_config_t lain_config;

static const pin_t leds[LED_NUM]       = LED_PINS;
bool               led_states[LED_NUM] = {0};

void lain_eeconfig_update_kb(void) { eeconfig_update_kb(lain_config.raw); }

void lain_set_led(uint8_t no, bool flag) {
    led_states[no] = flag;
    writePin(leds[no], lain_config.led_enabled ? flag : false);
}

void lain_enable_leds(bool flag) {
    lain_config.led_enabled = flag;
    lain_eeconfig_update_kb();

    for (int i = 0; i < LED_NUM; i++) {
        writePin(leds[i], lain_config.led_enabled ? led_states[i] : false);
    }
}

void lain_enable_leds_toggle(void) { lain_enable_leds(!lain_config.led_enabled); }

void led_init_ports(void) {
    for (uint8_t i = 0; i < LED_NUM; i++) {
        setPinOutput(leds[i]);
        lain_set_led(leds[i], 0);
    }
}

void eeconfig_init_kb(void) {
    // set default config
    lain_config.led_enabled = true;
    lain_eeconfig_update_kb();

    eeconfig_init_user();
}

void keyboard_post_init_kb(void) {
    // read stored config
    lain_config.raw = eeconfig_read_kb();

    keyboard_post_init_user();
=======
/* Copyright 2019 Takuya Urakawa(hsgw), dm9records.com, 5z6p.com
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
#include "lain.h"
#include "leds.h"
#include "matrix.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    init_leds();
    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    led_set_user(usb_led);
>>>>>>> 6d823e373f (lain 追加！)
}
