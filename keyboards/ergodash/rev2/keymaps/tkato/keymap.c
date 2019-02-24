#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define EISU LALT(KC_GRV)

// PyCharm
#define PC_LTAB LGUI(LSFT(KC_LBRC))
#define PC_RTAB LGUI(LSFT(KC_RBRC))

// Cmd + Space
#define LANG LGUI(KC_SPC)

#define ALFRED LALT(KC_SPC)
#define DASH LALT(LGUI(LCTL(KC_D)))

// Mission Control
#define MC LCTL(KC_UP)
// move to Left workspace
#define MC_L LCTL(KC_LEFT)
// move to Right workspace
#define MC_R LCTL(KC_RIGHT)

// PrintScreen to clipboard
#define PS1 LGUI(LSFT(LCTL(KC_4)))
// PrintScreen to file
#define PS2 LGUI(LSFT(KC_4))

//Tap Dance Declarations
enum {
  TD_LANG2_LANG1 = 0,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LANG2_LANG1]  = ACTION_TAP_DANCE_DOUBLE(KC_LANG2, KC_LANG1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |                    |   7  |   8  |   9  |   0  |   -  |   =  |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  MC  |                    |      |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | MC_L |                    | MC_R |   H  |   J  |   K  |   L  |   ;  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |Alfred|                    | DASH |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  PS1 |  PS2 |  ALt | GUI  |||||||| Lower| Enter| LANG |||||||| Bksp | Space| Raise||||||||  F7  |  F8  |  F9  |  F10 |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MC,                             _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MC_L,                           MC_R,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALFRED,                         DASH,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    PS1,     PS2,     KC_LALT, KC_LGUI, LOWER,   KC_ENT , LANG,                           KC_BSPC, KC_SPC , RAISE,   KC_F7,   KC_F8,   KC_F9,   KC_F10   \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   7  |   8  |   9  |   R  |   T  |  MC  |                    |      |   Y  |   U  |   I  |   O  |   [  |   ]  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   4  |   5  |   6  |   F  |   G  | MC_L |                    | MC_R |   H  |   J  |  Up  |   L  |   ;  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   1  |   2  |   3  |   0  |   B  |Alfred|                    | DASH |   N  | Left | Down | Right|   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | PS1  | PS2  |  ALt | GUI  |||||||| Lower| Enter| LANG |||||||| Bksp | Space| Raise|||||||| Home | End  | Pgup | Pgdn |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, \
    KC_TAB,  KC_7,    KC_8,    KC_9,    KC_R,    KC_T,    MC,                             _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_LBRC, KC_RBRC,  \
    KC_LCTL, KC_4,    KC_5,    KC_6,    KC_F,    KC_G,    MC_L,                           MC_R,    KC_H,    KC_J,    KC_UP,   KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_0,    KC_B,    ALFRED,                         DASH,    KC_N,    PC_LTAB, KC_DOWN, PC_RTAB, KC_SLSH, KC_RSFT, \
    PS1,     PS2,     KC_LALT, KC_LGUI, LOWER,   KC_ENT , LANG,                           KC_BSPC, KC_SPC , RAISE,   KC_HOME, KC_END,  KC_PGUP, KC_UP    \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  MC  |                    |      |   Y  |   U  |   I  |   O  |   [  |   ]  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | MC_L |                    | MC_R |   H  | Bksp |  Up  | Space|   ;  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |Alfred|                    | DASH |   N  | Left | Down | Right| Enter| Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | PS1  | PS2  |  ALt | GUI  |||||||| Lower| Enter| LANG |||||||| Bksp | Space| Raise|||||||| Home | End  | Pgup | Pgdn |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, \
    KC_TAB,  KC_7,    KC_8,    KC_9,    KC_R,    KC_T,    MC,                             _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_LBRC, KC_RBRC,  \
    KC_LCTL, KC_4,    KC_5,    KC_6,    KC_F,    KC_G,    MC_L,                           MC_R,    KC_H,    KC_BSPC, KC_UP,   KC_SPC,  KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALFRED,                         DASH,    KC_N,    KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  KC_RSFT, \
    PS1,     PS2,     KC_LALT, KC_LGUI, LOWER,   KC_ENT , LANG,                           KC_BSPC, KC_ENT , RAISE,   KC_HOME, KC_END,  KC_PGUP, KC_UP    \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
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
