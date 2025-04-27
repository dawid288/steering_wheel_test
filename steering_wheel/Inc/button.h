#ifndef BUTTON_H
#define BUTTON_H

#include "can_controller.h"
#include "can_ids.h"
#include "gpio.h"
#include "steering_wheel.h"
#include "stm32l4xx.h"
#include "tim.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


#define NUM_BUTTONS 11

typedef enum {
  BUTTON_STATE_PRESSED,
  BUTTON_STATE_RELEASED,
} button_state_t;

typedef struct {
  GPIO_TypeDef *port;
  uint16_t pin;
  button_state_t button_state;
  uint8_t debouncing_flag;
  uint32_t can_id;
} button_t;

#endif