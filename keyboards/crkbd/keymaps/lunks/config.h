/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define HOLD_ON_OTHER_KEY_PRESS
#define COMBO_COUNT 1
#define COMBO_TERM 60

#define NEW_TAB LGUI(KC_T)
#define CL_WIN LGUI(KC_W)
#define CMD_C LGUI(KC_C)
#define CMD_V LGUI(KC_V)
#define CH_WIN KC_F8
#define RUN_NE KC_F5
#define RUN_FI KC_F6
#define SWIPRO LGUI(S(KC_M))
