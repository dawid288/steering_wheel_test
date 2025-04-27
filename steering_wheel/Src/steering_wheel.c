#include "steering_wheel.h"


volatile flags_t flags;
volatile time_t time;
volatile uint8_t lap_number = 0;
volatile uint8_t time_reset_button_press_counter = 0;

void steering_wheel_init()
{
  lv_init();
  lv_port_disp_init();
  ui_init();
  CAN_Init(&hcan1);
  CAN_FilterConfig(&hcan1);
}

int i = 0;
uint8_t buffer[20];
void steering_wheel_loop()
{
  i++;
  if(i>=70)
  {
    i=0;
  }

  if(i<= 40)
  {
    lv_obj_set_style_bg_color(objects.sc_voltage_bar, lv_color_hex(0xD71717), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(objects.messages_area, lv_color_hex(0xD71717), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_text(objects.messages_area, "Press SC close button");
  }
  else 
  { 
    lv_obj_set_style_bg_color(objects.sc_voltage_bar, lv_color_hex(0xff2acf4f), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(objects.messages_area, lv_color_hex(0xff2acf4f), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_text(objects.messages_area, "SC voltage is ok");
  }
    lv_timer_handler();
    ui_tick();
    disp_set_time(time.min_counter, time.sec_counter, time.min_sum, time.sec_sum, flags.time_send_flag);
    disp_set_lap_number(lap_number, flags.lap_send_flag);
    lv_bar_set_value(objects.sc_voltage_bar, i, LV_ANIM_ON);
    sprintf(buffer, "%u V", i);
    lv_label_set_text(objects.sc_voltage, buffer);
    CAN_ReceiveMessage(&rx_data);
}
