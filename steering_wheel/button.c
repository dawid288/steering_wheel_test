#include "button.h"

Button_t buttons[NUM_BUTTONS] = {
    {FULL_GAS_BUTTON_GPIO_Port, FULL_GAS_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {HALF_GAS_BUTTON_GPIO_Port, HALF_GAS_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {MODE1_BUTTON_GPIO_Port, MODE1_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {MODE2_BUTTON_GPIO_Port, MODE2_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {HORN_BUTTON_GPIO_Port, HORN_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {TIME_BUTTON_GPIO_Port, TIME_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {SC_CLOSE_BUTTON_GPIO_Port, SC_CLOSE_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {EMERGENCY_BUTTON_GPIO_Port, EMERGENCY_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {FUELCELL_RACE_MODE_GPIO_Port, FUELCELL_RACE_MODE_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {FUELCELL_PREPARETORACE_MODE_GPIO_Port, FUELCELL_PREPARETORACE_MODE_Pin, BUTTON_STATE_RELEASED, 0, 0},
    {FUELCELL_OFF_MODE_BUTTON_GPIO_Port, FUELCELL_OFF_MODE_BUTTON_Pin, BUTTON_STATE_RELEASED, 0, 0},
};

void CheckButtons()
{
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        GPIO_PinState state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);

        if (!buttons[i].DebouncingFlag)
        {
            if ((state == GPIO_PIN_RESET && buttons[i].buttonState == BUTTON_STATE_RELEASED) ||
                (state == GPIO_PIN_SET && buttons[i].buttonState == BUTTON_STATE_PRESSED))
            {
                buttons[i].DebouncingFlag = 1;
                buttons[i].DebouncingStart = HAL_GetTick();
            }
        }
        else
        {
            if (HAL_GetTick() - buttons[i].DebouncingStart  >= 5)
            {
                state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
                buttons[i].DebouncingFlag = 0;

                if(state == GPIO_PIN_RESET && buttons[i].buttonState == BUTTON_STATE_RELEASED)
                {
                    buttons[i].buttonState = BUTTON_STATE_PRESSED;
                    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
                    printf("BUTTON_ON\n");
                }
                else if (state == GPIO_PIN_SET && buttons[i].buttonState == BUTTON_STATE_PRESSED)
                {
                    buttons[i].buttonState = BUTTON_STATE_RELEASED;
                    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
                    printf("BUTTON_OFF\n");

                }
            }
    }
    }
}