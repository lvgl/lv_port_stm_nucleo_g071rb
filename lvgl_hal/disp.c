/**
 * @file disp.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "disp.h"
#include "Drivers/BSP/lcd/lcd_io.h"

/*********************
 *      DEFINES
 *********************/
#define BUF_SIZE 240 * 24

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void flush_cb(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void disp_init(void)
{
	static lv_color_t buf1[BUF_SIZE];
	static lv_disp_draw_buf_t draw_buf;
	lv_disp_draw_buf_init(&draw_buf, buf1, NULL, BUF_SIZE);

	static lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.draw_buf = &draw_buf;
	disp_drv.hor_res = 240;
	disp_drv.ver_res = 320;
	disp_drv.flush_cb = flush_cb;
	lv_disp_t * disp = lv_disp_drv_register(&disp_drv);
	lv_disp_set_theme(disp, lv_theme_basic_init(disp));
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void flush_cb(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color)
{
	BSP_LCD_FillRGBRect(0, 1, color, area->x1, area->y1, lv_area_get_width(area), lv_area_get_height(area));
	BSP_LCD_WaitForTransferToBeDone(0);
	lv_disp_flush_ready(drv);
}
