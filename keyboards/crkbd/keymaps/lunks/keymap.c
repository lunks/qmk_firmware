/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
  TM_ADV = SAFE_RANGE,
  TM_PREV,
  NXT_WIN,
  PRV_WIN
};

enum layers {
    BASE,       // Base
    NAVG,      // Navigation
    SYMB,     // Symbols
    NUMPAD,  // Numpad and Mouse
    DANGER, // Not really
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------.              ,---------------------------------------------------.
                KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|-----------------+--------+--------+--------+--------+--------|              |-----+--------+--------+--------+------------------|
      LT(NAVG, KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  //|-----------------+--------+--------+--------+--------+--------|              |-----+--------+--------+--------+------------------|
               KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RCTL,
  //|-----------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                          KC_LGUI,MO(NUMPAD),KC_ENT,   KC_SPC,MO(SYMB), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [NAVG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,  CL_WIN, _______, _______, NEW_TAB,                      C(KC_6), _______, _______, _______,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, TM_PREV,  TM_ADV, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, PRV_WIN, NXT_WIN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,   CMD_C,   CMD_V, KC_LPRN,                      KC_RPRN, SWIPRO,  _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       MO(NUMPAD),  CH_WIN, KC_LPRN,     KC_RPRN, RUN_NE, RUN_FI
                                   //`--------------------------'    `------------------------------'
  ),

  [SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, KC_MS_U, KC_BTN1, _______, _______,                         KC_7,    KC_8,    KC_9, _______, KC_MPLY, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                         KC_4,    KC_5,    KC_6, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_1,    KC_2,    KC_3,    _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+----------|  |------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, MO(DANGER),      KC_0,  _______, _______
                                      //`----------------------------'  `--------------------------'
  ),

  [DANGER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,--------------------------------------------------------.
      _______, _______, _______, _______, QK_BOOT, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,    _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-----------|
                                         _______, _______,  _______,   _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
/*
 * Copy and paste for a new layer
 *
  [LAYER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,   _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
*/

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_NAVG 2
#define L_SYMB 4
#define L_NUMPAD 8
#define L_DANGER 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case L_NAVG:
            oled_write_ln_P(PSTR("NAVG"), false);
            break;
        case L_SYMB:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_NUMPAD:
        case L_NUMPAD|L_NAVG:
            oled_write_ln_P(PSTR("NUMBERS!"), false);
            break;
        case L_DANGER:
        case L_DANGER|L_NUMPAD|L_NAVG:
        case L_DANGER|L_NUMPAD:
            oled_write_ln_P(PSTR("!!!DANGER!!!"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
    }
    return false;
}

#endif // OLED_ENABLE

bool cmd_related_action = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  #endif // OLED_ENABLE

  switch (keycode) {
    case TM_ADV:
      if (record->event.pressed) {
        if (!cmd_related_action) {
          cmd_related_action = true;
          register_code(KC_LGUI);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case TM_PREV:
      if (record->event.pressed) {
        if (!cmd_related_action) {
          cmd_related_action = true;
          register_code(KC_LGUI);
        }
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      break;
    case NXT_WIN:
      if (record->event.pressed) {
        if (!cmd_related_action) {
          cmd_related_action = true;
          register_code(KC_LGUI);
        }
        register_code(KC_LSFT);
        register_code(KC_RBRC);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_RBRC);
      }
      break;
    case PRV_WIN:
      if (record->event.pressed) {
        if (!cmd_related_action) {
          cmd_related_action = true;
          register_code(KC_LGUI);
        }
        register_code(KC_LSFT);
        register_code(KC_LBRC);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_LBRC);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (cmd_related_action) {
    if (IS_LAYER_OFF(NAVG)) {
      unregister_code(KC_LGUI);
      cmd_related_action = false;
    }
  }
}
