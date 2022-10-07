// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: stm32g1_v2

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
lv_group_t * group_main;
lv_group_t * group_aircon;
lv_group_t * group_clock;
lv_group_t * group_about;

void Move_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Menu(lv_event_t * e);
lv_obj_t * ui_Menu;
lv_obj_t * ui_Header;
void ui_event_Button_Aircon(lv_event_t * e);
lv_obj_t * ui_Button_Aircon;
void ui_event_Button_Time(lv_event_t * e);
lv_obj_t * ui_Button_Time;
void ui_event_Button_About(lv_event_t * e);
lv_obj_t * ui_Button_About;
lv_obj_t * ui_AirCon;
lv_obj_t * ui_Header_Sub;
void ui_event_Header_Sub_Back_Back(lv_event_t * e);
lv_obj_t * ui_List_Switch1;
lv_obj_t * ui_List_Switch2;
lv_obj_t * ui_List_Switch3;
lv_obj_t * ui_Dropdown1;
lv_obj_t * ui_List_Switch4;
lv_obj_t * ui_Roller;
lv_obj_t * ui_SetTime;
lv_obj_t * ui_Header_Sub1;
void ui_event_Header_Sub1_Back_Back(lv_event_t * e);
lv_obj_t * ui_Set_Hours;
lv_obj_t * ui_Set_Minutes;
lv_obj_t * ui_Roller_Hour;
lv_obj_t * ui_Roller_Minute;
lv_obj_t * ui_List_Switch5;
lv_obj_t * ui_Dropdown2;
lv_obj_t * ui_About;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Set_Minutes1;
lv_obj_t * ui_Header_Sub2;
void ui_event_Header_Sub2_Back_Back(lv_event_t * e);

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
extern lv_indev_t * joy_indev;

///////////////////// FUNCTIONS ////////////////////
void ui_event_Menu(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lv_indev_set_group(joy_indev, group_main);
    }
}

void ui_event_Aircon(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lv_indev_set_group(joy_indev, group_aircon);
    }
}

void ui_event_Clock(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lv_indev_set_group(joy_indev, group_clock);
    }
}

void ui_event_About(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        lv_indev_set_group(joy_indev, group_about);
    }
}

void ui_event_Button_Aircon(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_AirCon, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_Button_Time(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SetTime, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_Button_About(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_About, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_Header_Sub_Back_Back(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menu, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_Header_Sub1_Back_Back(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menu, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}
void ui_event_Header_Sub2_Back_Back(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Menu, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Menu_screen_init(void)
{
    ui_Menu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Menu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_tiled(ui_Menu, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header = ui_Header_create(ui_Menu);
    lv_obj_set_x(ui_Header, 0);
    lv_obj_set_y(ui_Header, 0);

    ui_Button_Aircon = ui_Button_create(ui_Menu);
    lv_obj_set_x(ui_Button_Aircon, 0);
    lv_obj_set_y(ui_Button_Aircon, 39);

    ui_Button_Time = ui_Button_create(ui_Menu);
    lv_obj_set_x(ui_Button_Time, 0);
    lv_obj_set_y(ui_Button_Time, 132);

    lv_label_set_text(ui_comp_get_child(ui_Button_Time, UI_COMP_BUTTON_BUTTON_TEXT), "Set Time");

    lv_img_set_src(ui_comp_get_child(ui_Button_Time, UI_COMP_BUTTON_BUTTON_IMAGE), &ui_img_time_png);

    ui_Button_About = ui_Button_create(ui_Menu);
    lv_obj_set_x(ui_Button_About, 0);
    lv_obj_set_y(ui_Button_About, 225);

    lv_label_set_text(ui_comp_get_child(ui_Button_About, UI_COMP_BUTTON_BUTTON_TEXT), "About");

    lv_img_set_src(ui_comp_get_child(ui_Button_About, UI_COMP_BUTTON_BUTTON_IMAGE), &ui_img_info_png);

    lv_obj_add_event_cb(ui_Button_Aircon, ui_event_Button_Aircon, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button_Time, ui_event_Button_Time, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button_About, ui_event_Button_About, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Menu, ui_event_Menu, LV_EVENT_ALL, NULL);

}
void ui_AirCon_screen_init(void)
{
    ui_AirCon = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_AirCon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_AirCon, lv_color_hex(0x191F2B), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Sub = ui_Header_Sub_create(ui_AirCon);
    lv_obj_set_x(ui_Header_Sub, 0);
    lv_obj_set_y(ui_Header_Sub, 0);

    ui_List_Switch1 = ui_List_Switch_create(ui_AirCon);
    lv_obj_set_x(ui_List_Switch1, 0);
    lv_obj_set_y(ui_List_Switch1, 35);

    ui_List_Switch2 = ui_List_Switch_create(ui_AirCon);
    lv_obj_set_x(ui_List_Switch2, 0);
    lv_obj_set_y(ui_List_Switch2, 85);

    lv_label_set_text(ui_comp_get_child(ui_List_Switch2, UI_COMP_LIST_SWITCH_LIST_TEXT), "Turbo");

    lv_obj_add_state(ui_comp_get_child(ui_List_Switch2, UI_COMP_LIST_SWITCH_SWITCH1), LV_STATE_CHECKED);       /// States
    lv_obj_clear_state(ui_comp_get_child(ui_List_Switch2, UI_COMP_LIST_SWITCH_SWITCH1), LV_STATE_CHECKED);     /// States

    ui_List_Switch3 = ui_List_Switch_create(ui_AirCon);
    lv_obj_set_x(ui_List_Switch3, 0);
    lv_obj_set_y(ui_List_Switch3, 135);

    lv_label_set_text(ui_comp_get_child(ui_List_Switch3, UI_COMP_LIST_SWITCH_LIST_TEXT), "Fan Swing");

    lv_obj_add_flag(ui_comp_get_child(ui_List_Switch3, UI_COMP_LIST_SWITCH_SWITCH1),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    ui_Dropdown1 = lv_dropdown_create(ui_List_Switch3);
    lv_dropdown_set_options(ui_Dropdown1, "Off\nLow\nMid\nHigh");
    lv_obj_set_width(ui_Dropdown1, 100);
    lv_obj_set_height(ui_Dropdown1, 26);
    lv_obj_set_x(ui_Dropdown1, 0);
    lv_obj_set_y(ui_Dropdown1, -1);
    lv_obj_set_align(ui_Dropdown1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_Dropdown1, lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Dropdown1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Dropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_outline_color(ui_Dropdown1, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_Dropdown1, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_Dropdown1, 3, LV_PART_MAIN | LV_STATE_FOCUSED);

    lv_obj_set_style_text_color(lv_dropdown_get_list(ui_Dropdown1), lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(lv_dropdown_get_list(ui_Dropdown1), 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_hor(lv_dropdown_get_list(ui_Dropdown1), 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_size(lv_dropdown_get_list(ui_Dropdown1), 3, LV_PART_SCROLLBAR);


    ui_List_Switch4 = ui_List_Switch_create(ui_AirCon);
    lv_obj_set_height(ui_List_Switch4, 137);
    lv_obj_set_width(ui_List_Switch4, lv_pct(100));
    lv_obj_set_x(ui_List_Switch4, 0);
    lv_obj_set_y(ui_List_Switch4, 185);
    lv_obj_set_style_pad_left(ui_List_Switch4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List_Switch4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List_Switch4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List_Switch4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_align(ui_comp_get_child(ui_List_Switch4, UI_COMP_LIST_SWITCH_LIST_TEXT), LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_comp_get_child(ui_List_Switch4, UI_COMP_LIST_SWITCH_LIST_TEXT), "Mode selection");

    lv_obj_add_flag(ui_comp_get_child(ui_List_Switch4, UI_COMP_LIST_SWITCH_SWITCH1),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    ui_Roller = ui_Roller_create(ui_List_Switch4);
    lv_obj_set_x(ui_Roller, 0);
    lv_obj_set_y(ui_Roller, 0);

    lv_obj_add_event_cb(ui_Header_Sub, ui_event_Header_Sub_Back_Back,
                        LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_AirCon, ui_event_Aircon, LV_EVENT_ALL, NULL);

}
void ui_SetTime_screen_init(void)
{
    ui_SetTime = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SetTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SetTime, lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Sub1 = ui_Header_Sub_create(ui_SetTime);
    lv_obj_set_x(ui_Header_Sub1, 0);
    lv_obj_set_y(ui_Header_Sub1, 0);

    lv_label_set_text(ui_comp_get_child(ui_Header_Sub1, UI_COMP_HEADER_SUB_LABEL1), "Set Time");

    ui_Set_Hours = lv_label_create(ui_SetTime);
    lv_obj_set_width(ui_Set_Hours, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Set_Hours, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Set_Hours, 44);
    lv_obj_set_y(ui_Set_Hours, 52);
    lv_label_set_text(ui_Set_Hours, "Hours");
    lv_obj_set_style_text_color(ui_Set_Hours, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Set_Minutes = lv_label_create(ui_SetTime);
    lv_obj_set_width(ui_Set_Minutes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Set_Minutes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Set_Minutes, -39);
    lv_obj_set_y(ui_Set_Minutes, 52);
    lv_obj_set_align(ui_Set_Minutes, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Set_Minutes, "Minutes");
    lv_obj_set_style_text_color(ui_Set_Minutes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller_Hour = ui_Roller_create(ui_SetTime);
    lv_roller_set_options(ui_Roller_Hour,
                          "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24",
                          0);
    lv_obj_set_height(ui_Roller_Hour, 85);
    lv_obj_set_width(ui_Roller_Hour, lv_pct(30));
    lv_obj_set_x(ui_Roller_Hour, 30);
    lv_obj_set_y(ui_Roller_Hour, 70);
    lv_obj_set_align(ui_Roller_Hour, LV_ALIGN_TOP_LEFT);

    ui_Roller_Minute = ui_Roller_create(ui_SetTime);
    lv_roller_set_options(ui_Roller_Minute,
                          "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59",
                          0);
    lv_obj_set_height(ui_Roller_Minute, 85);
    lv_obj_set_width(ui_Roller_Minute, lv_pct(30));
    lv_obj_set_x(ui_Roller_Minute, -30);
    lv_obj_set_y(ui_Roller_Minute, 70);
    lv_obj_set_align(ui_Roller_Minute, LV_ALIGN_TOP_RIGHT);

    ui_List_Switch5 = ui_List_Switch_create(ui_SetTime);
    lv_obj_set_height(ui_List_Switch5, 78);
    lv_obj_set_width(ui_List_Switch5, lv_pct(100));
    lv_obj_set_x(ui_List_Switch5, 0);
    lv_obj_set_y(ui_List_Switch5, 172);
    lv_obj_set_style_border_side(ui_List_Switch5, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_List_Switch5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_List_Switch5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_List_Switch5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_List_Switch5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_align(ui_comp_get_child(ui_List_Switch5, UI_COMP_LIST_SWITCH_LIST_TEXT), LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_comp_get_child(ui_List_Switch5, UI_COMP_LIST_SWITCH_LIST_TEXT), "Timezone");

    lv_obj_add_flag(ui_comp_get_child(ui_List_Switch5, UI_COMP_LIST_SWITCH_SWITCH1),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    ui_Dropdown2 = lv_dropdown_create(ui_List_Switch5);
    lv_dropdown_set_options(ui_Dropdown2,
                            "China\nNepal\nIndia\nCrimea\nSpain\nVenezuela\nSamoa\nUSA\nCanada\nSudan\nIran\nNew Zealand\nAustralia");
    lv_obj_set_height(ui_Dropdown2, 26);
    lv_obj_set_width(ui_Dropdown2, lv_pct(100));
    lv_obj_set_x(ui_Dropdown2, 0);
    lv_obj_set_y(ui_Dropdown2, 27);
    lv_obj_add_flag(ui_Dropdown2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_Dropdown2, lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dropdown2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Dropdown2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Dropdown2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Dropdown2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Dropdown2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_outline_color(ui_Dropdown2, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_Dropdown2, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_Dropdown2, 3, LV_PART_MAIN | LV_STATE_FOCUSED);

    lv_obj_set_style_text_color(lv_dropdown_get_list(ui_Dropdown2), lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(lv_dropdown_get_list(ui_Dropdown2), 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_hor(lv_dropdown_get_list(ui_Dropdown2), 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_size(lv_dropdown_get_list(ui_Dropdown2), 3, LV_PART_SCROLLBAR);

    lv_obj_add_event_cb(ui_Header_Sub1, ui_event_Header_Sub1_Back_Back,
                        LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_SetTime, ui_event_Clock, LV_EVENT_ALL, NULL);

}
void ui_About_screen_init(void)
{
    ui_About = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_About, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_About, lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_About);
    lv_obj_set_height(ui_Panel2, 288);
    lv_obj_set_width(ui_Panel2, lv_pct(100));
    lv_obj_set_align(ui_Panel2, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_bg_opa(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);

    ui_Set_Minutes1 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Set_Minutes1, lv_pct(100));   /// 1
    lv_obj_set_height(ui_Set_Minutes1, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Set_Minutes1, "A minimal demo to control an Air Conditioner using an STM32G071 with 128kB Flash and 36 kB RAM running at 64MHz. No external memory is used.\n\n"
"The board has no touchpad therefore the UI can be navigated by a joystick. Up/down selects the previous/next widget, left/right changes the selected widget's value. On press the selected value is applied or a button widget is clicked.");
    lv_obj_set_style_text_color(ui_Set_Minutes1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Set_Minutes1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Sub2 = ui_Header_Sub_create(ui_About);
    lv_obj_set_x(ui_Header_Sub2, 0);
    lv_obj_set_y(ui_Header_Sub2, 0);

    lv_label_set_text(ui_comp_get_child(ui_Header_Sub2, UI_COMP_HEADER_SUB_LABEL1), "About");

    lv_obj_add_event_cb(ui_Header_Sub2, ui_event_Header_Sub2_Back_Back,
                        LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_About, ui_event_About, LV_EVENT_ALL, NULL);

}



void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    group_main = lv_group_create();
    group_aircon = lv_group_create();
    group_clock = lv_group_create();
    group_about = lv_group_create();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    lv_group_set_default(group_main);
    ui_Menu_screen_init();
    lv_group_set_default(group_aircon);
    ui_AirCon_screen_init();
    lv_group_set_default(group_clock);
    ui_SetTime_screen_init();
    lv_group_set_default(group_about);
    ui_About_screen_init();
    lv_disp_load_scr(ui_Menu);
}
