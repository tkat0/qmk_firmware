#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

// sudo -s
// make ergodash/rev2:tkat0:avrdude

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
  MY_ESC_G,
  MY_SPC_META,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// PyCharm
#define PC_LTAB LGUI(LSFT(KC_LBRC))
#define PC_RTAB LGUI(LSFT(KC_RBRC))
#define PC_RUN LCTL(LSFT(KC_R))
#define PC_DEBUG LCTL(LSFT(KC_D))

#define MY_LANG LGUI(KC_SPC)
#define MY_ENT_S SFT_T(KC_ENT)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |   -  |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  ||||||||      |      |Alfred||||||||   N  |   M  |   ,  |   .  |   /  |   =  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      | Alt  |||||||| Esc/ |Enter/| Lang |||||||| Bksp | Space| SYMB ||||||||      |      |  PS1 |  PS2 |
   * |      |      |      |      |||||||| GUI  |Shift |      ||||||||      | Meta |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    _______, _______, _______, _______, _______,  _______,  _______,                       _______,     _______, _______, _______, _______, _______, _______, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     _______,                       _______,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     _______,                       _______,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,               _______,    ALFRED,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
    _______, _______, _______, KC_LALT,           MY_ESC_G, MY_ENT_S, MY_LANG,    KC_BSPC, MY_SPC_META, LOWER,            _______, _______, PS1,     PS2   \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  ||||||||      |      |      ||||||||  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            _______,    _______,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______,          _______, _______, _______,    _______, _______, _______,          _______, _______, _______, _______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |  (   |  )   |      |                    |      |   ←  |   ↓  |   ↑  |   →  |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|------|
   * |      |      |      |      |  [   |  ]   ||||||||      |      |      ||||||||  '   |   `  |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      |||||||| PCRUN|PCDBG |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,  _______, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                      _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    _______, \
    _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,                      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
    _______, _______, _______, _______, KC_LBRC, KC_RBRC,          _______,    _______,          KC_QUOT, KC_GRV,  _______, _______,  _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,    _______, _______, _______,          _______, _______,  _______, _______  \
  ),


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool my_esc_g_pressed = false;
static bool my_space_meta_pressed = false;

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
        case MY_ESC_G:
            if (record->event.pressed) {
                // on keydown
                my_esc_g_pressed = true;
            } else {
                // on keyup
                if (my_esc_g_pressed) {
                    // tap operation
                    my_esc_g_pressed = false;
                    register_code(KC_ESC);
                    unregister_code(KC_ESC);
                } else {
                    // hold operation(post)
                    unregister_code(KC_LGUI);
                }
            }
            return false;
            // Tap: Space, Tap with another key X: META + X
        case MY_SPC_META:
            if (record->event.pressed) {
                // on keydown
                my_space_meta_pressed = true;
            } else {
                // on keyup
                if (my_space_meta_pressed) {
                    // tap operation
                    my_space_meta_pressed = false;
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                } else {
                    // hold operation(post)
                    layer_off(_RAISE);
                }
            }
            return false;
        default:
            // hold operation(pre)
            if (my_space_meta_pressed) {
                my_space_meta_pressed = false;
                layer_on(_RAISE);
            }
            if (my_esc_g_pressed) {
                my_esc_g_pressed = false;
                register_code(KC_LGUI);
            }
            break;
    }
    return true;
}
