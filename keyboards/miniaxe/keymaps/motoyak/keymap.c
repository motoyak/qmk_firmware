 /* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
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

#define TAPPING_TERM 100
#define PERMISSIVE_HOLD

// layers
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | MHEN | BKSP |           | Spc  | KANA | Esc  |
 *               | L-Alt| LOWER|L-Ctrl|           | R-Sft| RAISE| R-Gui|
 *               `--------------------'           `--------------------'
 */
[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    MT(MOD_LALT, KC_ESC), LT(_LOWER, KC_MHEN), MT(MOD_LCTL, KC_BSPC),
                                                    MT(MOD_RSFT, KC_SPC), LT(_RAISE, KC_KANA), MT(MOD_RGUI, KC_ESC)
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   _  |   +  |  |   |  ~   |           |   :  |   "  |   >  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ins |   -  |   =  |  \   |  `   |           |   ;  |   '  |   <  |   [  |   ]  |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | MHEN | BKSP |           | Spc  | KANA | Esc  |
 *               | L-Alt| LOWER|L-Ctrl|           | R-Sft| RAISE| R-Gui|
 *               `--------------------'           `--------------------'
 */
[_RAISE] = LAYOUT(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_TAB,  KC_UNDS, KC_PLUS, KC_PIPE, KC_TILD,      KC_COLN, KC_DQUO, KC_GT,   KC_LCBR, KC_RCBR,
  KC_INS,  KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,       KC_SCLN, KC_QUOT, KC_LT,   KC_LBRC, KC_RBRC,
                    _______, _______, _______,      _______,  _______, _______
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   R  |   E  |   I  | SRq  |           | Left | Down |  Up  | Right| Enter|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Del |   S  |   U  |   B  | PSc  |           | Home | PgUp | PgUp | End  | R-ALT|
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | MHEN | BKSP |           | Spc  | KANA | Esc  |
 *               | L-Alt| LOWER|L-Ctrl|           | R-Sft| RAISE| R-Gui|
 *               `--------------------'           `--------------------'
 */
[_LOWER] = LAYOUT(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,  KC_R,    KC_E,    KC_I,    KC_SYSREQ,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
  KC_DEL,  KC_S,    KC_U,    KC_B,    KC_PSCR,      KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_RALT,
                    _______, _______, _______,      _______,  _______, _______
),


/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |   R  |   E  |   I  | SRq  |           | MPlay| MSTOP| Bri+ | Bri- | Enter|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | L-Sft|   S  |   U  |   B  | PSc  |           | Prev | Next | Vol- | Vol+ | Mute |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      | MHEN | BKSP |           | Spc  | KANA | Esc  |
 *               | L-Alt| LOWER|L-Ctrl|           | R-Sft| RAISE| R-Gui|
 *               `--------------------'           `--------------------'
 */
[_ADJUST] =  LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_TAB,  KC_R,    KC_E,    KC_I,    KC_SYSREQ,    KC_MPLY, KC_MSTP, KC_BRIU, KC_BRID, KC_ENT,
  KC_LSFT, KC_S,    KC_U,    KC_B,    KC_PSCR,      KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,
                    _______, _______, _______,      _______,  _______, _______
)
};

 uint32_t layer_state_set_user(uint32_t state) {
     return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
 }
