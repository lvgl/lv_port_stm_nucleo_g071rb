// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0 Beta1
// LVGL VERSION: 8.2
// PROJECT: stm32g1_v2


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT Button

lv_obj_t * ui_Button_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Button;
    cui_Button = lv_btn_create(comp_parent);
    lv_obj_set_width(cui_Button, 160);
    lv_obj_set_height(cui_Button, 81);
    lv_obj_set_x(cui_Button, 0);
    lv_obj_set_y(cui_Button, 41);
    lv_obj_set_align(cui_Button, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Button, lv_color_hex(0x20345A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Button_Text;
    cui_Button_Text = lv_label_create(cui_Button);
    lv_obj_set_width(cui_Button_Text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Button_Text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Button_Text, 0);
    lv_obj_set_y(cui_Button_Text, -8);
    lv_obj_set_align(cui_Button_Text, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(cui_Button_Text, "Air Conditioner");
    lv_obj_set_style_text_color(cui_Button_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Button_Text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_outline_color(cui_Button, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(cui_Button, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(cui_Button, 3, LV_PART_MAIN | LV_STATE_FOCUSED);


    lv_obj_t * cui_Button_Image;
    cui_Button_Image = lv_img_create(cui_Button);
    lv_img_set_src(cui_Button_Image, &ui_img_aircon_png);
    lv_obj_set_width(cui_Button_Image, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Button_Image, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Button_Image, 0);
    lv_obj_set_y(cui_Button_Image, -11);
    lv_obj_set_align(cui_Button_Image, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Button_Image, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Button_Image, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BUTTON_NUM);
    children[UI_COMP_BUTTON_BUTTON] = cui_Button;
    children[UI_COMP_BUTTON_BUTTON_TEXT] = cui_Button_Text;
    children[UI_COMP_BUTTON_BUTTON_IMAGE] = cui_Button_Image;
    lv_obj_add_event_cb(cui_Button, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Button, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Button;
}



// COMPONENT Header Sub

lv_obj_t * ui_Header_Sub_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Header_Sub;
    cui_Header_Sub = lv_btn_create(comp_parent);
    lv_obj_set_height(cui_Header_Sub, 32);
    lv_obj_set_width(cui_Header_Sub, lv_pct(100));
    lv_obj_set_align(cui_Header_Sub, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Header_Sub, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Header_Sub, lv_color_hex(0x20345A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Header_Sub, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Header_Sub, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Header_Sub, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Header_Sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Header_Sub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(cui_Header_Sub, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(cui_Header_Sub, 2, LV_PART_MAIN | LV_STATE_FOCUSED);


    lv_obj_t * cui_Label1;
    cui_Label1 = lv_label_create(cui_Header_Sub);
    lv_obj_set_width(cui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Label1, "Air Conditioner");
    lv_obj_set_style_text_color(cui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Back;
    cui_Back = lv_img_create(cui_Header_Sub);
    lv_img_set_src(cui_Back, LV_SYMBOL_LEFT);
    lv_obj_set_width(cui_Back, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Back, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Back, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(cui_Back, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Back, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(cui_Back, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_HEADER_SUB_NUM);
    children[UI_COMP_HEADER_SUB_HEADER_SUB] = cui_Header_Sub;
    children[UI_COMP_HEADER_SUB_LABEL1] = cui_Label1;
    children[UI_COMP_HEADER_SUB_BACK] = cui_Back;
    lv_obj_add_event_cb(cui_Header_Sub, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Header_Sub, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Header_Sub;
}



// COMPONENT Header

lv_obj_t * ui_Header_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Header;
    cui_Header = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Header, 26);
    lv_obj_set_width(cui_Header, lv_pct(100));
    lv_obj_set_align(cui_Header, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(cui_Header, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(cui_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Header, lv_color_hex(0x233458), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Header, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Header, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Battery;
    cui_Battery = lv_img_create(cui_Header);
    lv_img_set_src(cui_Battery, &ui_img_battery_png);
    lv_obj_set_width(cui_Battery, LV_SIZE_CONTENT);   /// 89
    lv_obj_set_height(cui_Battery, LV_SIZE_CONTENT);    /// 14
    lv_obj_set_align(cui_Battery, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(cui_Battery, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Battery, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Wifi;
    cui_Wifi = lv_img_create(cui_Header);
    lv_img_set_src(cui_Wifi, &ui_img_wifi_png);
    lv_obj_set_width(cui_Wifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Wifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Wifi, -30);
    lv_obj_set_y(cui_Wifi, 0);
    lv_obj_set_align(cui_Wifi, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(cui_Wifi, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Wifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_BLE;
    cui_BLE = lv_img_create(cui_Header);
    lv_img_set_src(cui_BLE, &ui_img_ble_png);
    lv_obj_set_width(cui_BLE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_BLE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_BLE, -57);
    lv_obj_set_y(cui_BLE, 0);
    lv_obj_set_align(cui_BLE, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(cui_BLE, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_BLE, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Time;
    cui_Time = lv_label_create(cui_Header);
    lv_obj_set_width(cui_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Time, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Time, "14:37");
    lv_obj_set_style_text_color(cui_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Date;
    cui_Date = lv_label_create(cui_Header);
    lv_obj_set_width(cui_Date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Date, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Date, "10 June");
    lv_obj_set_style_text_color(cui_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_HEADER_NUM);
    children[UI_COMP_HEADER_HEADER] = cui_Header;
    children[UI_COMP_HEADER_BATTERY] = cui_Battery;
    children[UI_COMP_HEADER_WIFI] = cui_Wifi;
    children[UI_COMP_HEADER_BLE] = cui_BLE;
    children[UI_COMP_HEADER_TIME] = cui_Time;
    children[UI_COMP_HEADER_DATE] = cui_Date;
    lv_obj_add_event_cb(cui_Header, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Header, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Header;
}



// COMPONENT List Switch

lv_obj_t * ui_List_Switch_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_List_Switch;
    cui_List_Switch = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_List_Switch, 50);
    lv_obj_set_width(cui_List_Switch, lv_pct(100));
    lv_obj_set_x(cui_List_Switch, 0);
    lv_obj_set_y(cui_List_Switch, 28);
    lv_obj_set_align(cui_List_Switch, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_List_Switch, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(cui_List_Switch, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_List_Switch, lv_color_hex(0x20345A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_List_Switch, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_List_Switch, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_List_Switch, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_List_Switch, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_List_Switch, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_List_Switch, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_List_Text;
    cui_List_Text = lv_label_create(cui_List_Switch);
    lv_obj_set_align(cui_List_Text, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_List_Text, "Quiet");
    lv_obj_set_style_text_color(cui_List_Text, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Switch1;
    cui_Switch1 = lv_switch_create(cui_List_Switch);
    lv_obj_set_width(cui_Switch1, 50);
    lv_obj_set_height(cui_Switch1, 25);
    lv_obj_set_align(cui_Switch1, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_bg_opa(cui_Switch1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cui_Switch1, &ui_img_ellips_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(cui_Switch1, lv_color_hex(0x20345A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(cui_Switch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch1, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(cui_Switch1, &ui_img_ellips_png, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_opa(cui_Switch1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(cui_Switch1, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch1, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(cui_Switch1, &ui_img_ellips_png, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_recolor(cui_Switch1, lv_color_hex(0x4DD549), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_recolor_opa(cui_Switch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_bg_opa(cui_Switch1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cui_Switch1, &ui_img_circle_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Switch1, 0, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_right(cui_Switch1, -3, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_top(cui_Switch1, 0, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_pad_bottom(cui_Switch1, 0, LV_PART_KNOB | LV_STATE_CHECKED);


    lv_obj_set_style_outline_color(cui_Switch1, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(cui_Switch1, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(cui_Switch1, 3, LV_PART_MAIN | LV_STATE_FOCUSED);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_LIST_SWITCH_NUM);
    children[UI_COMP_LIST_SWITCH_LIST_SWITCH] = cui_List_Switch;
    children[UI_COMP_LIST_SWITCH_LIST_TEXT] = cui_List_Text;
    children[UI_COMP_LIST_SWITCH_SWITCH1] = cui_Switch1;
    lv_obj_add_event_cb(cui_List_Switch, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_List_Switch, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_List_Switch;
}



// COMPONENT Roller

lv_obj_t * ui_Roller_create(lv_obj_t * comp_parent)
{
    lv_obj_t * cui_Roller;
    cui_Roller = lv_roller_create(comp_parent);
    lv_roller_set_options(cui_Roller, "Auto\nCool\nHeat\nFan", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(cui_Roller, 85);
    lv_obj_set_width(cui_Roller, lv_pct(59));
    lv_obj_set_align(cui_Roller, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_text_color(cui_Roller, lv_color_hex(0x7286AB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(cui_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(cui_Roller, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(cui_Roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(cui_Roller, 300, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(cui_Roller, lv_color_hex(0x181C29), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_outline_color(cui_Roller, lv_color_hex(0xe0a721), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(cui_Roller, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(cui_Roller, 3, LV_PART_MAIN | LV_STATE_FOCUSED);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_ROLLER_NUM);
    children[UI_COMP_ROLLER_ROLLER] = cui_Roller;
    lv_obj_add_event_cb(cui_Roller, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Roller, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Roller;
}
