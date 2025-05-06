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

static lv_obj_t * my_rect;
static lv_obj_t * my_other_rect;

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

#define DEMO 2

#if DEMO == 0
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
#elif DEMO == 1
void ui_Menu_screen_init(void)
{
    ui_Menu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Menu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Menu, lv_color_hex(0x181C29), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Menu);
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

    ui_Header_Sub2 = ui_Header_Sub_create(ui_Menu);
    lv_obj_set_x(ui_Header_Sub2, 0);
    lv_obj_set_y(ui_Header_Sub2, 0);

    lv_label_set_text(ui_comp_get_child(ui_Header_Sub2, UI_COMP_HEADER_SUB_LABEL1), "About");
}
#elif DEMO == 2
void ui_Menu_screen_init(void)
{
    ui_Menu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Menu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_tiled(ui_Menu, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    my_rect = lv_obj_create(ui_Menu);
    lv_obj_set_size(my_rect, 240, 320);
    lv_obj_set_pos(my_rect, 0, 0);
    lv_obj_set_style_bg_color(my_rect, (lv_color_t)LV_COLOR_MAKE(0, 0, 255), 0);
}
#elif DEMO == 3
void ui_Menu_screen_init(void)
{
    ui_Menu = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Menu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_tiled(ui_Menu, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    my_rect = lv_obj_create(ui_Menu);
    lv_obj_set_size(my_rect, 240, 320);
    lv_obj_set_pos(my_rect, 0, 0);
    lv_obj_set_style_bg_color(my_rect, (lv_color_t)LV_COLOR_MAKE(0, 0, 255), 0);

    my_other_rect = lv_obj_create(ui_Menu);
    lv_obj_set_size(my_other_rect, 240, 320);
    lv_obj_set_pos(my_other_rect, 0, 0);
    lv_obj_set_style_bg_color(my_other_rect, (lv_color_t)LV_COLOR_MAKE(255, 0, 0), 0);
    lv_obj_set_style_bg_opa(my_other_rect, LV_OPA_50, 0);
}
#else
#error "Select valid demo."
#endif

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    group_main = lv_group_create();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    lv_group_set_default(group_main);
    ui_Menu_screen_init();
    lv_disp_load_scr(ui_Menu);
}
