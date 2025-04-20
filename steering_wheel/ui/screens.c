#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static lv_meter_scale_t * scale0;
lv_meter_indicator_t * indicator1;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // background_main
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.background_main = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 319, 240);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff323232), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // speed_meter
            lv_obj_t *obj = lv_meter_create(parent_obj);
            objects.speed_meter = obj;
            lv_obj_set_pos(obj, 63, 41);
            lv_obj_set_size(obj, 182, 182);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                scale0 = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xffffffff));
                lv_meter_set_scale_major_ticks(obj, scale, 8, 3, 10, lv_color_hex(0xffffffff), 10);
                lv_meter_set_scale_range(obj, scale, 0, 100, 300, 120);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xffff0000), -3);
                    indicator1 = indicator;
                    lv_meter_set_indicator_value(obj, indicator, 30);
                }
            }
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // speed_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.speed_label = obj;
            lv_obj_set_pos(obj, 131, 222);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Speed");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lap_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lap_label = obj;
            lv_obj_set_pos(obj, 1, 222);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Lap num");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // speed_area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.speed_area = obj;
            lv_obj_set_pos(obj, 116, 93);
            lv_obj_set_size(obj, 78, 78);
            lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, LV_PART_MAIN);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffcfcaca), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lap_number_area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.lap_number_area = obj;
            lv_obj_set_pos(obj, 0, 160);
            lv_obj_set_size(obj, 62, 62);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffcfcaca), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // time_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_label = obj;
            lv_obj_set_pos(obj, 253, 222);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Lap time");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lap_time_area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.lap_time_area = obj;
            lv_obj_set_pos(obj, 257, 163);
            lv_obj_set_size(obj, 62, 62);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffcfcaca), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // total_time_area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.total_time_area = obj;
            lv_obj_set_pos(obj, 255, 85);
            lv_obj_set_size(obj, 62, 62);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffcfcaca), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // time_label_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_label_1 = obj;
            lv_obj_set_pos(obj, 245, 147);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Total time");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // messages_area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.messages_area = obj;
            lv_obj_set_pos(obj, 1, 0);
            lv_obj_set_size(obj, 317, 38);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_CURSOR | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffcfcaca), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
