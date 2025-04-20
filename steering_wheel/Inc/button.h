#ifndef BUTTON_H
#define BUTTON_H

#include "gpio.h"
#include "stm32l4xx.h"
#include <stdbool.h>
#include <stdio.h>
#include "tim.h"
#include "can_ids.h"
#include "can_controller.h"

#define NUM_BUTTONS 11

typedef enum {
  BUTTON_STATE_PRESSED,
  BUTTON_STATE_RELEASED,
} ButtonState_t;

typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
  ButtonState_t button_state;
  bool debouncing_flag;
  uint32_t can_id;
} Button_t;

//void Buttons_OnTick();

#endif