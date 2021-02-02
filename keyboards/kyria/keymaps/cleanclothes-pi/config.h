/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// Turn off on slave
//#define WAIT_FOR_USB

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK


/* -------------- OLED DISPLAY ------------------------------------- */
#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

/* -------------- TAPPING ------------------------------------*/
#define TAPPING_TERM 205
#define TAPPING_TERM_PER_KEY

/* -------------- ROTARY ENCODER ----------------------------------*/
#ifdef ENCODER_ENABLE
  #define ENCODER_DIRECTION_FLIP
  #define ENCODER_RESOLUTION 2
#endif

/* -------------- ONESHOT MOD----------------------------------*/
/* #define ONESHOT_TAP_TOGGLE 2 */
#define ONESHOT_TIMEOUT 5000

/* -------------- COMBO ----------------------------------*/
#define COMBO_COUNT 10
#define COMBO_TERM 175

/* -------------- HOLD ----------------------------------*/
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD
// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

/* -------------- MOUSEKEYS ----------------------------------*/
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10
#undef MOUSEKEY_TIME_TO_MAX 
#define MOUSEKEY_TIME_TO_MAX 40
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100
