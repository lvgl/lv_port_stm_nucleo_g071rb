// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: stm32g1_v2

#ifndef _STM32G1_V2_UI_H
#define _STM32G1_V2_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void Move_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Menu(lv_event_t * e);
extern lv_obj_t * ui_Menu;
extern lv_obj_t * ui_Header;
void ui_event_Button_Aircon(lv_event_t * e);
extern lv_obj_t * ui_Button_Aircon;
void ui_event_Button_Time(lv_event_t * e);
extern lv_obj_t * ui_Button_Time;
void ui_event_Button_About(lv_event_t * e);
extern lv_obj_t * ui_Button_About;
extern lv_obj_t * ui_AirCon;
extern lv_obj_t * ui_Header_Sub;
void ui_event_Header_Sub_Back_Back(lv_event_t * e);
extern lv_obj_t * ui_List_Switch1;
extern lv_obj_t * ui_List_Switch2;
extern lv_obj_t * ui_List_Switch3;
extern lv_obj_t * ui_Dropdown1;
extern lv_obj_t * ui_List_Switch4;
extern lv_obj_t * ui_Roller;
extern lv_obj_t * ui_SetTime;
extern lv_obj_t * ui_Header_Sub1;
void ui_event_Header_Sub1_Back_Back(lv_event_t * e);
extern lv_obj_t * ui_Set_Hours;
extern lv_obj_t * ui_Set_Minutes;
extern lv_obj_t * ui_Roller_Hour;
extern lv_obj_t * ui_Roller_Minute;
extern lv_obj_t * ui_List_Switch5;
extern lv_obj_t * ui_Dropdown2;
extern lv_obj_t * ui_About;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Set_Minutes1;
extern lv_obj_t * ui_Header_Sub2;
void ui_event_Header_Sub2_Back_Back(lv_event_t * e);


LV_IMG_DECLARE(ui_img_battery_png);    // assets\battery.png
LV_IMG_DECLARE(ui_img_wifi_png);    // assets\wifi.png
LV_IMG_DECLARE(ui_img_ble_png);    // assets\ble.png
LV_IMG_DECLARE(ui_img_corner_png);    // assets\corner.png
LV_IMG_DECLARE(ui_img_aircon_png);    // assets\aircon.png
LV_IMG_DECLARE(ui_img_time_png);    // assets\time.png
LV_IMG_DECLARE(ui_img_info_png);    // assets\info.png
LV_IMG_DECLARE(ui_img_back_png);    // assets\back.png
LV_IMG_DECLARE(ui_img_ellips_png);    // assets\ellips.png
LV_IMG_DECLARE(ui_img_circle_png);    // assets\circle.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
