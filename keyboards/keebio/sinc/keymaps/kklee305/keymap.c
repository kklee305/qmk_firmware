#include QMK_KEYBOARD_H

enum custom_keycodes {
    MACRO0  = SAFE_RANGE,
    MACRO1  = SAFE_RANGE,
    MACRO2  = SAFE_RANGE,
    MACRO3  = SAFE_RANGE,
    MACRO4  = SAFE_RANGE,
    MACRO5  = SAFE_RANGE,
    MACRO6  = SAFE_RANGE,
    MACRO7  = SAFE_RANGE,
    MACRO8  = SAFE_RANGE,
    MACRO9  = SAFE_RANGE,
    MACRO   = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    KC_MUTE,           KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,  KC_F24,
      KC_P8,   KC_P9,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSPC,  KC_DEL,
      KC_P6,   KC_P7,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
      KC_P4,   KC_P5,  KC_F13,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT,  KC_END,
      KC_P2,   KC_P3, KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,   MO(1),
      KC_P0,   KC_P1, KC_LCTL, KC_LGUI, KC_LALT,  KC_APP,  KC_SPC,  KC_SPC,           KC_SPC,  KC_SPC, KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    _______,          _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     MACRO8,  MACRO9, _______, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     MACRO6,  MACRO7, _______, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     MACRO4,  MACRO5, _______, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,   MACRO, _______, _______, _______,          _______, _______,
     MACRO2,  MACRO3, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     MACRO0,  MACRO1, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_R);
        } else {
            tap_code(KC_WH_L);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MACRO:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("6@k^HG*s");
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};