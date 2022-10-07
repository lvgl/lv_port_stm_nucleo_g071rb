// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: stm32g1_v2

#ifndef _STM32G1_V2_UI_COMP_H
#define _STM32G1_V2_UI_COMP_H

#include "ui.h"

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx);
extern uint32_t LV_EVENT_GET_COMP_CHILD;

// COMPONENT Button
#define UI_COMP_BUTTON_BUTTON 0
#define UI_COMP_BUTTON_CORNER1 1
#define UI_COMP_BUTTON_CORNER2 2
#define UI_COMP_BUTTON_CORNER3 3
#define UI_COMP_BUTTON_CORNER4 4
#define UI_COMP_BUTTON_BUTTON_TEXT 5
#define UI_COMP_BUTTON_BUTTON_IMAGE 6
#define _UI_COMP_BUTTON_NUM 7
lv_obj_t * ui_Button_create(lv_obj_t * comp_parent);

// COMPONENT Header Sub
#define UI_COMP_HEADER_SUB_HEADER_SUB 0
#define UI_COMP_HEADER_SUB_LABEL1 1
#define UI_COMP_HEADER_SUB_BACK 2
#define _UI_COMP_HEADER_SUB_NUM 3
lv_obj_t * ui_Header_Sub_create(lv_obj_t * comp_parent);

// COMPONENT Header
#define UI_COMP_HEADER_HEADER 0
#define UI_COMP_HEADER_BATTERY 1
#define UI_COMP_HEADER_WIFI 2
#define UI_COMP_HEADER_BLE 3
#define UI_COMP_HEADER_TIME 4
#define UI_COMP_HEADER_DATE 5
#define _UI_COMP_HEADER_NUM 6
lv_obj_t * ui_Header_create(lv_obj_t * comp_parent);

// COMPONENT List Switch
#define UI_COMP_LIST_SWITCH_LIST_SWITCH 0
#define UI_COMP_LIST_SWITCH_LIST_TEXT 1
#define UI_COMP_LIST_SWITCH_SWITCH1 2
#define _UI_COMP_LIST_SWITCH_NUM 3
lv_obj_t * ui_List_Switch_create(lv_obj_t * comp_parent);

// COMPONENT Roller
#define UI_COMP_ROLLER_ROLLER 0
#define _UI_COMP_ROLLER_NUM 1
lv_obj_t * ui_Roller_create(lv_obj_t * comp_parent);

#endif
