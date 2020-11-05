/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
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
 
This file was made by GuestJim of Overclockers Club based on the original files the above covers.
While it works for him, there is no warranty or guarantee it will for anyone else
His article creating such custom keymap files:
	http://www.overclockersclub.com/reviews/cmk_qmk_via
 */
#include QMK_KEYBOARD_H

#define OBS_REC RALT(KC_F9)
//	Alt + F9	OBS Studio start and stop recording hotkey
#define OBS_BUF RALT(KC_F10)
//	Alt + F10	OBS Studio replay buffer save

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Qwerty
	* ,-----------------------------------------------------------------------------------------.
	* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
	* |-----------------------------------------------------------------------------------------+
	* |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
	* |-----------------------------------------------------------------------------------------+
	* |  Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      Shift      |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl  |  GUI  |  Alt  |              Space              |  Alt  |  T(1) |LT1,Menu| Ctrl |
	* `-----------------------------------------------------------------------------------------'
	*/
	[0] = LAYOUT_60_ansi(
		KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLS,
		KC_CAPS,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,				KC_ENT,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,							KC_RSFT,
		KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC,								KC_RALT,	TT(1),		LT(1, KC_APP),			KC_RCTL
	),

	/* Function
	* ,-----------------------------------------------------------------------------------------.
	* |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
	* |-----------------------------------------------------------------------------------------+
	* |        |     | Up  |     |     |     |     |     |     |     |PrtSc|ScrLk|Pause|        |
	* |-----------------------------------------------------------------------------------------+
	* |         |Left |Down |Right|     |     |     |     |     | Ins |Home |PgUp |             |
	* |-----------------------------------------------------------------------------------------+
	* |           |VolUp|VolDn|VolMu|     |     |     |     | Del | End |PgDn |                 |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 | TG L3 |       |  L2   |       |
	* `-----------------------------------------------------------------------------------------'
	*/
	[1] = LAYOUT_60_ansi(
		KC_GRV,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_DEL,
		KC_TRNS,	KC_TRNS,	KC_UP,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_PSCR,	KC_SLCK,	KC_PAUS,	KC_TRNS,
		KC_TRNS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_INS,		KC_HOME,	KC_PGUP,				KC_TRNS,
		KC_TRNS,	KC_VOLU,	KC_VOLD,	KC_MUTE,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_DEL,		KC_END,		KC_PGDN,							KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,										KC_TRNS,												TG(3),	KC_TRNS,	MO(2),	KC_TRNS
	),

	/* RGB
	* ,-----------------------------------------------------------------------------------------.
	* |     |     |     |     |     |     |     |     |     |     |     |     |     |   Reset   |
	* |-----------------------------------------------------------------------------------------+
	* | BL Tog |BLInc|BLDec|BLStp|     |     |     |     |     |     |     |     |     |        |
	* |-----------------------------------------------------------------------------------------+
	* | RGB Tog |Mode |Hue I|Sat I|Val I|Spd I|Plain|Breat|     |     |     |     |             |
	* |-----------------------------------------------------------------------------------------+
	* |           |RMode|Hue D|Sat D|Val D|Spd D|     |Knigh|     |Gradi|     |                 |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 |       |       |       |       |
	* `-----------------------------------------------------------------------------------------'
	*/
	[2] = LAYOUT_60_ansi(
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RESET,
		BL_TOGG,	BL_INC,		BL_DEC,		BL_STEP,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_SAI,	RGB_VAI,	RGB_SPI,	RGB_M_P,	RGB_M_B,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,
		KC_TRNS,	RGB_RMOD,	RGB_HUD,	RGB_SAD,	RGB_VAD,	RGB_SPD,	KC_TRNS,	RGB_M_K,	KC_TRNS,	RGB_M_G,	KC_TRNS,							KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,										KC_TRNS											KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	),
	/* Review
	* ,-----------------------------------------------------------------------------------------.
	* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
	* |-----------------------------------------------------------------------------------------+
	* |        |     |     |     |     |     |     |     |     |     |     |PSRC |OBS_BUF|  F12   |
	* |-----------------------------------------------------------------------------------------+
	* |         |     |     |     |     |     |     |     |     |     |     |OBS_REC|             |
	* |-----------------------------------------------------------------------------------------+
	* |           |     |     |     |     |     |     |     |     |     |     |       LOCK      |
	* |-----------------------------------------------------------------------------------------+
	* |       |       |       |                                 | TG L3 |       |       |       |
	* `-----------------------------------------------------------------------------------------'
	*/
	[3] = LAYOUT_60_ansi(/* Review */
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_PSCR,	OBS_BUF,	KC_F12,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	OBS_REC,				KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,							KC_LOCK,
		KC_TRNS,	KC_TRNS,	KC_TRNS,										KC_TRNS,											TG(3),	KC_TRNS,	KC_TRNS,	KC_TRNS
	),
};
