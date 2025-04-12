#include "button.h"

Button_t buttons[NUM_BUTTONS] = {
    {BUTTON_FULL_GAS_GPIO_Port, BUTTON_FULL_GAS_Pin, BUTTON_STATE_RELEASED, 0,
     0},
    {BUTTON_HALF_GAS_GPIO_Port, BUTTON_HALF_GAS_Pin, BUTTON_STATE_RELEASED, 0,
     0},
    {BUTTON_MODE1_GPIO_Port, BUTTON_MODE1_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_MODE2_GPIO_Port, BUTTON_MODE2_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_HORN_GPIO_Port, BUTTON_HORN_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_TIME_GPIO_Port, BUTTON_TIME_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_SC_CLOSE_GPIO_Port, BUTTON_SC_CLOSE_Pin, BUTTON_STATE_RELEASED, 0,
     0},
    {BUTTON_EMERGENCY_GPIO_Port, BUTTON_EMERGENCY_Pin, BUTTON_STATE_RELEASED, 0,
     0},
    {BUTTON_FUELCELL_RACE_MODE_GPIO_Port, BUTTON_FUELCELL_RACE_MODE_Pin,
     BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_FUELCELL_PREPARE_TO_RACE_MODE_GPIO_Port,
     BUTTON_FUELCELL_PREPARE_TO_RACE_MODE_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {BUTTON_FUELCELL_OFF_MODE_GPIO_Port, BUTTON_FUELCELL_OFF_MODE_Pin,
     BUTTON_STATE_RELEASED, 0, 0},
};

void Buttons_OnTick() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    GPIO_PinState state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);

    if (!buttons[i].debouncing_flag) {
      if ((state == GPIO_PIN_RESET &&
           buttons[i].button_state == BUTTON_STATE_RELEASED) ||
          (state == GPIO_PIN_SET &&
           buttons[i].button_state == BUTTON_STATE_PRESSED)) {
        buttons[i].debouncing_flag = 1;
        buttons[i].debouncing_start = HAL_GetTick();
      }
    } else {
      if (HAL_GetTick() - buttons[i].debouncing_start >= 5) {
        state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
        buttons[i].debouncing_flag = 0;

        if (state == GPIO_PIN_RESET &&
            buttons[i].button_state == BUTTON_STATE_RELEASED) {
          buttons[i].button_state = BUTTON_STATE_PRESSED;
          HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
          printf("BUTTON_ON\n");
        } else if (state == GPIO_PIN_SET &&
                   buttons[i].button_state == BUTTON_STATE_PRESSED) {
          buttons[i].button_state = BUTTON_STATE_RELEASED;
          HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
          printf("BUTTON_OFF\n");
        }
      }
    }
  }
}