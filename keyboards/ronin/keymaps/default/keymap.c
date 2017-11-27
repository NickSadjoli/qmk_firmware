/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "ronin.h"

#define _ML 0
#define _U1 1
#define _U2 2

#define _____ KC_TRNS


#define MACRO_GUI           99
#define BACK_TAB            0

#define M_GUI  M(MACRO_GUI)
#define B_TAB  M(BACK_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WL: Windows Layer (Layer for use in Windows OS, Default Layer when first flashed)
   * ,------------------------------------------------------------.
   * | 00| 01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 0e|
   * |-----------------------------------------------------------|
   * |   10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|   1e|
   * |-----------------------------------------------------------|
   * |   20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b|   2c| 2e|
   * |-----------------------------------------------------------|
   * |   30| 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a|   3c| 3d| 3e|
   * |-----------------------------------------------------------|
   * | 40| 41| 42|   43    | 45| 46|   48    | 4a| 4b| 4c| 4d| 4e|
   * `-----------------------------------------------------------'
   */
[_ML] = KEYMAP(
  KC_GESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,    KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,  KC_BSLS,    KC_GRV ,\
    KC_TAB  ,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_DEL,     KC_BSPC , \
    KC_LCTL ,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,     KC_L,    KC_SCLN,  KC_QUOT,    KC_ENT ,  KC_INS , \
    KC_LSFT ,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,    KC_RSFT  ,  KC_UP,  KC_PSCR, \
  KC_CAPS,  KC_LGUI,  KC_LALT,   KC_SPACE ,  MO(_U1),  MO(_U2),   KC_BSPC,  KC_RCTRL, KC_RALT,   KC_LEFT,  KC_DOWN,  KC_RGHT) ,

[_U1] = KEYMAP(
  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,    KC_PSLS,  KC_PAST,  _____,  _____,  _____,  _____,    _____ ,\
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  KC_7,  KC_8,  KC_9,    KC_PMNS,     KC_RBRC,  _____,     _____ , \
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  KC_4,  KC_5,  KC_6,    KC_ENTER,  _____,    _____ ,  _____ , \
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  KC_1,  KC_2,  KC_3,  KC_PPLS,    _____  ,  _____,  _____, \
  _____,  _____,  _____,   _____ ,  MO(_U1),  MO(_U2),   KC_0,  KC_DOT, _____,   _____,  _____,  _____) ,

[_U2] = KEYMAP(
  _____,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,    KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  _____,    KC_HOME ,\
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  KC_UP,     _____,    _____,     KC_RBRC,  _____,     _____ , \
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  KC_LEFT,  KC_DOWN,     KC_RGHT,    _____,  _____,    _____ ,  _____ , \
    _____ ,  _____,  _____,  _____,  _____,  _____,  _____,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _____,    _____  ,  _____,  _____, \
  _____,  _____,  _____,   _____ ,  MO(_U1),  MO(_U2),   _____,  _____, _____,   _____,  _____,  _____) ,

};

/*
const uint16_t PROGMEM fn_actions[] = {

};
*/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MACRO_GUI:{
          if (record->event.pressed){
            //when key is PRESSED
            return MACRO(D(LGUI), END);
          }
          else {
            return MACRO(U(LGUI), END);
          }

          break;
        }

        case BACK_TAB:{
          if (record->event.pressed){
            //when key is PRESSED
            return MACRO(D(LSHIFT), D(TAB), END);
          }
          else {
            return MACRO(U(LSHIFT), U(TAB), END);
          }

          break;
        }
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
