/* Copyright 2021 nekomimist
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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

#define M_LOWER LT(_LOWER, KC_F20)
#define M_RAISE LT(_RAISE, KC_F21)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Default Layer
	 *  Main Side (USB Cable Connected Side)
	 *  ,-----------------------------------------
	 *  |    `    1    2    3    4    5
	 *  |  TAB    Q    W    E    R    T
	 *  | CTRL    A    S    D    F    G
	 *  | SHFT    Z    X    C    V    B HOME
	 *  |  ADJ  ESC  WIN  ALT  F20  LWR  SPC BSPC
	 *  `-----------------------------------------
	 *  Sub Side (USB Cable Not Connected Side)
	 *  ,-----------------------------------------
	 *  |              6    7    8    9    0    =
	 *  |              Y    U    I    O    P BKSP
	 *  |              H    J    K    L    ;    '
	 *  |      MUTE    N    M    ,    .    /  ENT
	 *  |  ENT  SPC  RSE  F21 LEFT DOWN   UP RGHT
	 *  `-----------------------------------------
	 */
	[_QWERTY] = LAYOUT( /* Base */
		KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______,
		KC_TAB ,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, _______, _______,
		KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, _______, _______,
		KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_HOME, _______,
		ADJUST ,  KC_ESC, KC_LGUI, KC_LALT, KC_LALT, M_LOWER,  KC_SPC, KC_BSPC,

		_______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
		_______, _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
		_______, _______,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
		_______, KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
		 KC_ENT,  KC_SPC, M_RAISE, M_RAISE, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT
		),

	/* Lower
	 *  Main Side (USB Cable Connected Side)
	 *  ,-----------------------------------------
	 *  |    ~    !    @    #    $    %
	 *  |    ~    !    @    #    $    %
	 *  |        F1   F2   F3   F4   F5
	 *  |        F7   F8   F9  F10  F11  END
	 *  | CAPS  ESC  WIN  ALT  F20       SPC BSPC
	 *  `-----------------------------------------
	 *  Sub Side (USB Cable Not Connected Side)
	 *  ,-----------------------------------------
	 *  |              ^    &    *    (    )  DEL
	 *  |              ^    &    *    (    )  DEL
	 *  |             F6    _    +    {    }    |
	 *  |      MUTE  F12           HOME  END  ENT
	 *  |  ENT  SPC       F21 HOME  PDN  PUP  END
	 *  `-----------------------------------------
	 */
	[_LOWER] = LAYOUT(
		KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______,
		KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______, _______,
		_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______,
		_______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_END, _______,
		KC_CAPS,  KC_ESC, KC_LGUI, KC_LALT, KC_LALT,  KC_F20,  KC_SPC, KC_BSPC,

		_______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
		_______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
		_______, _______,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
		_______, KC_MUTE,  KC_F12, _______, _______, KC_HOME,  KC_END,  KC_ENT,
		 KC_ENT,  KC_SPC,  KC_F21, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END
		),

	/* Raise
	 *  Main Side (USB Cable Connected Side)
	 *  ,-----------------------------------------
	 *  |    `    1    2    3    4    5
	 *  |    `    1    2    3    4    5
	 *  |        F1   F2   F3   F4   F5
	 *  |        F7   F8   F9  F10  F11  END
	 *  | CAPS  ESC  WIN  LWR  ALT  F20  SPC BSPC
	 *  `-----------------------------------------
	 *  Sub Side (USB Cable Not Connected Side)
	 *  ,-----------------------------------------
	 *  |              6    7    8    9    0    =
	 *  |              6    7    8    9    0    =
	 *  |             F6    -    =    [    ]    \
	 *  |      MUTE  F12            PDN  PUP  ENT
	 *  |  Ent  SPC       F21 HOME  PDN  PUP  END
	 *  `-----------------------------------------
	 */
	[_RAISE] = LAYOUT(
		KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______,
		KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, _______,
		_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______,
		_______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_END, _______,
		KC_CAPS,  KC_ESC, KC_LGUI, KC_LALT, _______,  KC_F20,  KC_SPC, KC_BSPC,

		_______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
		_______, _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
		_______, _______,   KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
		_______, KC_MUTE,  KC_F12, _______, _______, KC_PGDN, KC_PGUP,  KC_ENT,
		 KC_ENT,  KC_SPC,  KC_F21, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END
		),

	/* Adjust
	 *  Main Side (USB Cable Connected Side)
	 *  ,------------------------------------------
	 *  | RTOG RMOD             RST
	 *  | RHUI RSAI RVAI        ERST
	 *  | RHUD RSAD RVAD
	 *  |
	 *  |
	 *  `------------------------------------------
	 *  Sub Side (USB Cable Not Connected Side)
	 *  ,------------------------------------------
	 *  |                MUTE VOL- VOL+
	 *  |                STOP MPRV MNXT PLAY
	 *  |
	 *  |
	 *  |
	 *  `------------------------------------------
	 */
	[_ADJUST] = LAYOUT(
		RGB_TOG, RGB_MOD, _______, _______, _______,   RESET, _______, _______,
		RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, EEP_RST, _______, _______,
		RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,

		_______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
		_______, _______, KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______
		),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
    case QWERTY:
		if (record->event.pressed) {
			// 他のレイヤはpersistentではないのでいらない?
			// Dvorakとかcolemakとかあるなら別だが……
			set_single_persistent_default_layer(_QWERTY);
		}
		return false;
		break;
    case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
    case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
    case ADJUST:
		if (record->event.pressed) {
			layer_on(_ADJUST);
		} else {
			layer_off(_ADJUST);
		}
		return false;
		break;
	}
	return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
