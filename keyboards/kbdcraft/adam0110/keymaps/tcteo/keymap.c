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

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//   uint8_t layer = get_highest_layer(layer_state|default_layer_state);
//   switch (layer) {
//     case _BASE:
//       rgb_matrix_set_color(0, 0x00, 0xFF, 0x00); // base: green
//       break;
//     case _BASE_AAPL:
//       rgb_matrix_set_color(0, 0xFF, 0x00, 0x00); // apple: red
//       break;
//     case _FN1:
//       rgb_matrix_set_color(0, 0x00, 0x00, 0xFF); // fn1: blue
//       break;
//     case _FN2:
//       rgb_matrix_set_color(0, 0xFF, 0x00, 0xFF); // fn2: magenta
//       break;
//     default:
//       //rgb_matrix_set_color(0, 0x00, 0x00, 0x00); // off
//       rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF); // white
//       break;
//   }
//   if (host_keyboard_led_state().caps_lock) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//       if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
//         rgb_matrix_set_color(i, RGB_RED);
//       }
//     }
//   }
//   return false;
// }

void eeconfig_init_user(void) {  // EEPROM is getting reset
    // rgb_matrix_enable();
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
    switch (get_highest_layer(state)) {
      case _BASE:
    //     rgb_matrix_set_color_all(0,0,0);
    //     rgb_matrix_set_color_all(0xFF, 0x00, 0x00); // red
        rgb_matrix_set_color(led_num, 0x00, 0x00, 0xFF); // blue
        break;
      case _BASE_AAPL:
    //     rgb_matrix_set_color_all(0,0,0);
    //     rgb_matrix_set_color_all(0x00, 0xFF, 0x00); // green
        rgb_matrix_set_color(led_num, 0xFF, 0x00, 0x00); // red
        break;
      case _FN1:
    //     rgb_matrix_set_color_all(0,0,0);
    //     rgb_matrix_set_color_all(0x00, 0x00, 0xFF); // blue
        rgb_matrix_set_color(led_num, 0x00, 0xFF, 0x00); // green
        break;
      case _FN2:
    //     rgb_matrix_set_color_all(0,0,0);
    //     rgb_matrix_set_color_all(0xFF, 0x00, 0xFF); // magenta
        rgb_matrix_set_color(led_num, 0xFF, 0x00, 0xFF); // magenta
        break;
      default:
    //     rgb_matrix_set_color_all(0,0,0);
    //     rgb_matrix_set_color_all(0xFF, 0xFF, 0xFF); // white
        rgb_matrix_set_color(led_num, 0xFF, 0xFF, 0xFF); // white
        break;
    }


    return state;
}

//     int led_num = 50;
//     uint8_t layer = get_highest_layer(state);
//     dprintf("layer: %d\n", layer);
//     return state;
// }


// bool rgb_matrix_indicators_user(void) {
//     int led_num = 50;

//     switch (get_highest_layer(layer_state)) {
//       case _BASE:
//         // rgb_matrix_set_color_all(0,0,0);
//         // rgb_matrix_set_color_all(0x00, 0x00, 0xFF); // blue
//         rgb_matrix_set_color(led_num, 0x00, 0x00, 0xFF); // blue
//         break;
//       case _BASE_AAPL:
//         // rgb_matrix_set_color_all(0,0,0);
//         // rgb_matrix_set_color_all(0xFF, 0x00, 0x00); // red
//         rgb_matrix_set_color(led_num, 0xFF, 0x00, 0x00); // red
//         break;
//       case _FN1:
//         // rgb_matrix_set_color_all(0,0,0);
//         // rgb_matrix_set_color_all(0x00, 0xFF, 0x00); // green
//         rgb_matrix_set_color(led_num, 0x00, 0xFF, 0x00); // green
//         break;
//       case _FN2:
//         // rgb_matrix_set_color_all(0,0,0);
//         // rgb_matrix_set_color_all(0xFF, 0x00, 0xFF); // magenta
//         rgb_matrix_set_color(led_num, 0xFF, 0x00, 0xFF); // magenta
//         break;
//       default:
//         // rgb_matrix_set_color_all(0,0,0);
//         // rgb_matrix_set_color_all(0xFF, 0xFF, 0xFF); // white
//         rgb_matrix_set_color(led_num, 0xFF, 0xFF, 0xFF); // white
//         break;
//     }
//   return false;
// }

    // int led_num = 50;
    // if (false) {
    //     return true;
    // } else if (IS_LAYER_ON(_FN1)) {
    //     dprint("fn1");
    //     rgb_matrix_set_color(led_num, 0x00, 0x00, 0xFF); // fn1: blue
    //     rgb_matrix_set_color_all(0x00, 0x00, 0xFF); // fn1: blue
    // } else if (IS_LAYER_ON(_FN2)) {
    //     dprint("fn2");
    //     rgb_matrix_set_color(led_num, 0xFF, 0x00, 0xFF); // fn2: magenta
    //     rgb_matrix_set_color_all(0xFF, 0x00, 0xFF); // fn2: magenta
    // } else if (IS_LAYER_ON(_BASE_AAPL)) {
    //     dprint("aapl");
    //     rgb_matrix_set_color(led_num, 0xFF, 0x00, 0x00); // apple: red
    //     rgb_matrix_set_color_all(0xFF, 0x00, 0x00); // apple: red
    // } else if (IS_LAYER_ON(_BASE)) {
    //     dprint("base");
    //     rgb_matrix_set_color(led_num, 0x00, 0xFF, 0x00); // base: green
    //     rgb_matrix_set_color_all(0x00, 0xFF, 0x00); // base: green
    // } else {
    //     rgb_matrix_set_color(led_num, 0xFF, 0xFF, 0xFF); // white
    //     rgb_matrix_set_color_all(0xFF, 0xFF, 0xFF); // white
    // }
    // return true;


void keyboard_post_init_user(void) {
    // rgb_matrix_enable();
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=false;
  //debug_mouse=true;

//   rgb_matrix_mode(RGB_MATRIX_CUSTOM_empty_effect);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_empty_effect);


}

#undef NO_DEBUG
#undef NO_PRINT



