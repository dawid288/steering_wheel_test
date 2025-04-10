#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l4xx_hal.h"
#include "gpio.h"
#include <stdbool.h>
#include <stdio.h>

#define NUM_BUTTONS 11

typedef enum {
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_RELEASED,
} ButtonState_t;

typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
    ButtonState_t buttonState;
    bool DebouncingFlag;
    uint32_t DebouncingStart;
} Button_t;

void CheckButtons();


#endif