// Copyright 2023 TC Teo (@tcteo)
// Copyright 2023 FxStudio <FXS@fx-studio.cn>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 10
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS_RIGHT { A7, C4, C5, A4, A5 }
#define MATRIX_COL_PINS_RIGHT { A6, B0, B1, B4, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }

#define SPLIT_ACTIVITY_ENABLE

#ifdef SPLIT_KEYBOARD
#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_HAND_PIN C13
#define SERIAL_USART_SPEED 137000
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#endif // SPLIT_KEYBOARD

#ifdef RGB_MATRIX_ENABLE
#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6
#define RGB_MATRIX_DEFAULT_VAL 60
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#endif // RGB_MATRIX_ENABLE
