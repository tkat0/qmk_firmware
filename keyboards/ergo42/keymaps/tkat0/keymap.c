#include QMK_KEYBOARD_H

// make ergo42/rev1:tkat0:avrdude

extern keymap_config_t keymap_config;

// Layer defenition
#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

enum custom_keycodes {
  MY_ESC_G = SAFE_RANGE,
  MY_SPC_META,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// My settings
// Super + Space
#define MY_LANG LGUI(KC_SPC)
// Tap: Enter, Long Tap: Shift
#define MY_ENT_S SFT_T(KC_ENT)

// PrintScreen to clipboard
#define MY_PS1 LGUI(LSFT(LCTL(KC_4)))
// PrintScreen to file
#define MY_PS2 LGUI(LSFT(KC_4))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   |      |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |   |      |   H  |   J  |   K  |   L  |   ;  |  -   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |      |   |      |   N  |   M  |   ,  |   .  |   /  |  =   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      | ALt  | Esc/ |Enter/| Lang |   | Bksp |Space/|SYMB  |      |      |MY_PS1|MY_PS2|
   * |      |      |      |      | GUI  |Shift |      |   |      |Meta  |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     XXXXXXX,    XXXXXXX, KC_Y,        KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
      KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     XXXXXXX,    XXXXXXX, KC_H,        KC_J,     KC_K,    KC_L,    KC_SCLN, KC_MINUS, \
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     XXXXXXX,    XXXXXXX, KC_N,        KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
      XXXXXXX,  XXXXXXX, XXXXXXX, KC_LALT, MY_ESC_G, MY_ENT_S, MY_LANG,    KC_BSPC, MY_SPC_META, MO(SYMB), XXXXXXX, XXXXXXX, MY_PS1,  MY_PS2   \
  ),


  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |   (  |   )  |      |   |      |   ←  |   ↓  |   ↑  |   →  |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |   [  |   ]  |      |   |      |   '  |   `  |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,    _______, KC_QUOT, KC_GRV,  _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |      |   |      |   ^  |   &  |   *  |  F11 |  F12 |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,    _______,  KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, _______, _______, _______, _______, _______, _______,    _______,  _______, _______, _______, _______, _______, _______ \
  )


};

static bool my_esc_g_pressed = false;
static bool my_space_meta_pressed = false;

// # tap
// [this handler]   MY_KEY pressed -> set flg ON
// [this handler]   MY_KEY release -> tap operation IF flg ON
//
// # hold
// [this handler]   MY_KEY pressed -> set flg ON
// [this handler]   OTHER_KEY pressed -> set flg OFF & hold operation (pre)
// [system handler] OTHER_KEY pressed
// [this handler]   MY_KEY release -> hold operation (post) IF flg OFF
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // Tap: Esc, Tap with another key X: GUI + X
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
                    layer_off(META);
                }
            }
            return false;
        default:
            // hold operation(pre)
            if (my_space_meta_pressed) {
                my_space_meta_pressed = false;
                layer_on(META);
            }
            if (my_esc_g_pressed) {
                my_esc_g_pressed = false;
                register_code(KC_LGUI);
            }
            break;
    }
    return true;
}
#define MY_SPC_META LT(META, KC_SPC)
