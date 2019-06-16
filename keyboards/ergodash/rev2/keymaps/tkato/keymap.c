#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

// sudo -s
// make ergodash/rev2:tkato:avrdude

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// PyCharm
#define PC_LTAB LGUI(LSFT(KC_LBRC))
#define PC_RTAB LGUI(LSFT(KC_RBRC))
#define PC_RUN LCTL(LSFT(KC_R))
#define PC_DEBUG LCTL(LSFT(KC_D))

// Cmd + Space
#define KC_LANG LGUI(KC_SPC)
#define CMDTAB LGUI(KC_TAB)

#define ALFRED LALT(KC_SPC)

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

#define RSPC LT(_RAISE, KC_SPC)
#define LENT LT(_LOWER, KC_ENT)
//#define LESC LT(_LOWER, M(0))
#define LESC LT(_LOWER, KC_ESC)
#define LOWGUI LT(_LOWER, KC_LGUI)
#define L_TAB LT(_LOWER, KC_TAB)
#define LLANG2 LT(_LOWER, KC_LANG2)
#define LBSPC LT(_LOWER, KC_BSPC)

#define SENT SFT_T(KC_ENT)
#define G_G GUI_T(KC_G)
#define S_F SFT_T(KC_F)

//Tap Dance Declarations
enum {
  TD_LANG2_LANG1 = 0,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
//  [TD_LANG2_LANG1]  = ACTION_TAP_DANCE_DOUBLE(KC_LANG1, KC_LANG2),
  [TD_LANG2_LANG1]  = ACTION_TAP_DANCE_DOUBLE(KC_LANG, KC_LANG2),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |   -  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | LANG1|      |Alfred|      |   N  |   M  |   ,  |   .  |   /  |   =  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | LCLK | RCLK |  Cmd | Alt  ||||||||EscCmd| Enter| LANG |||||||| Bksp | Space| Shift||||||||  F7  |  F8  |  PS1 |  PS2 |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                        _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                        _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LANG2,                       ALFRED,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
    KC_BTN1, KC_BTN2, KC_LALT, KC_LALT, GUI_T(KC_ESC), SENT,    TD(TD_LANG2_LANG1),             KC_BSPC, RSPC,    LOWER,   KC_F7,   KC_F8,   PS1,     PS2   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |  (   |  )   |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |  [   |  ]   |      |                    |      |  '   |   ↑  |   `  |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------|------|
   * |      |      |      |      |      | Esc  |      |                    |      |  ←   |   ↓  |   →  |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      |||||||| PCRUN|PCDBG |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,                        _______, KC_QUOT, KC_UP,   KC_GRV,  _______, _______, _______, \
    _______, _______, _______, _______, _______, M(0),    _______,                        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, PC_RUN,  PC_DEBUG,_______, _______  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   $  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  ~   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, KC_F11,  KC_F12,  _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_RPRN, KC_LPRN, _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______  \
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0: // EN -> ESC
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LANG2)SS_TAP(X_ESCAPE));
        }
        break;
    }
    return MACRO_NONE;
}
