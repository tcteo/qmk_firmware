#include QMK_KEYBOARD_H
#include "print.h"

enum layers {
    _BASE = 0,
    _BASE_AAPL,
    _FN1,
    _FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_64_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,   KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                              KC_NO,   MO(_FN1),KC_LEFT,  KC_DOWN, KC_RGHT
 ),
    [_BASE_AAPL] = LAYOUT_64_ansi(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LOPT, KC_LCMD,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN1] = LAYOUT_64_ansi(
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        KC_NO,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, KC_PSCR,  KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPI, RGB_SPD, KC_NO,    KC_VOLU,            KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   NK_TOGG, KC_NO,   KC_NO,   KC_INS,  KC_NO,    KC_VOLD,  KC_PGUP,  KC_MUTE,
        KC_NO,   KC_NO,   KC_NO,                     KC_NO,                              MO(_FN2),KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END
    ),

    [_FN2] = LAYOUT_64_ansi(
        TG(_BASE_AAPL), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_RBT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,                     KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
};

void eeconfig_init_user(void) {
    rgb_matrix_enable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    xprintf("Layer State: 0b%0b (%u)\n", state, get_highest_layer(state));
    switch (get_highest_layer(state)) {
      case _BASE:
        xprintf("_BASE\n");
        break;
      case _BASE_AAPL:
        xprintf("layer: _BASE_AAPL\n");
        break;
      case _FN1:
        xprintf("layer: _FN1\n");
        break;
      case _FN2:
        xprintf("layer: _FN2\n");
        break;
      default:
        xprintf("layer: ???\n");
        break;
    }

    int led_num = 50;
    rgb_matrix_set_color_all(0,0,0); // all off
    // rgb_matrix_set_color(led_num, 0x00, 0x00, 0x00); // off
    switch (get_highest_layer(state)) {
      case _BASE:
        rgb_matrix_set_color(led_num, 0x00, 0x00, 0xFF); // blue
        break;
      case _BASE_AAPL:
        rgb_matrix_set_color(led_num, 0xFF, 0x00, 0x00); // red
        break;
      case _FN1:
        rgb_matrix_set_color(led_num, 0x00, 0xFF, 0x00); // green
        break;
      case _FN2:
        rgb_matrix_set_color(led_num, 0xFF, 0x00, 0xFF); // magenta
        break;
      default:
        rgb_matrix_set_color(led_num, 0xFF, 0xFF, 0xFF); // white
        break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
                // When toggling RGB on/off, also switch back to the empty_effect, which allows custom RGB code to take effect.
                rgb_matrix_toggle();
                rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_empty_effect);
            }
            return false;
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    // rgb_matrix_enable();
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;

    // Set to empty_effect on boot.
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_empty_effect);

    // Set to base layer on boot. Explicitly call this to set LED indicator state.
    layer_clear();
    layer_on(_BASE);
}

#undef NO_DEBUG
#undef NO_PRINT



