<<<<<<< HEAD
// Copyright 2022 Takuya Urakawa @hsgw (dm9records.com, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later
=======
/*
Copyright 2019 Takuya Urakawa(hsgw), dm9records.com, 5z6p.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
>>>>>>> 6d823e373f (lain 追加！)

#pragma once

<<<<<<< HEAD
=======
#include "config_common.h"
<<<<<<< HEAD

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

/*
 * Keyboard Matrix Assignments
 */
#define MATRIX_ROW_PINS \
    { C6, D7, D6, D4 }
#define MATRIX_COL_PINS \
    { C7, F7, F6, F5, F4, F1, F0, B3, B2, B1, D2, D3, D5 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

>>>>>>> 11ee6780ac (lain 追加！)
/* LED Settings */
#define LED_NUM 3
#define LED_PINS \
    { B6, B5, B4 }

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
<<<<<<< HEAD
=======

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
=======
>>>>>>> 6d823e373f (lain 追加！)
>>>>>>> 11ee6780ac (lain 追加！)
