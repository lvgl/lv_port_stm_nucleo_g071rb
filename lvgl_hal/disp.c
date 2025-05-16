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

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/
void Error_Handler(void);

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
#define DOUBLE_BUFFERING 0

#if DOUBLE_BUFFERING == 1
#define BUF_SIZE 240 * 14
#else
#define BUF_SIZE 240 * 24
#endif

static lv_color_t buf1[BUF_SIZE];
static lv_disp_draw_buf_t draw_buf1;

#if DOUBLE_BUFFERING == 1
static lv_color_t buf2[BUF_SIZE];
#endif

void disp_init(void)
{
	if(BSP_LCD_Init(0, LCD_ORIENTATION_PORTRAIT) != BSP_ERROR_NONE) {
		Error_Handler();
	}
	if(BSP_LCD_DisplayOn(0) != BSP_ERROR_NONE) {
		Error_Handler();
	}

#if DOUBLE_BUFFERING == 1
	lv_disp_draw_buf_init(&draw_buf1, buf1, buf2, BUF_SIZE);
#else
	lv_disp_draw_buf_init(&draw_buf1, buf1, NULL, BUF_SIZE);
#endif

	static lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.draw_buf = &draw_buf1;
	disp_drv.hor_res = 240;
	disp_drv.ver_res = 320;
	disp_drv.flush_cb = flush_cb;
	lv_disp_t * disp = lv_disp_drv_register(&disp_drv);
	lv_disp_set_theme(disp, lv_theme_basic_init(disp));
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

extern SPI_HandleTypeDef hspi1;

static void flush_cb(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);

#if DOUBLE_BUFFERING == 1
    BSP_LCD_WaitForTransferToBeDone(0);
	BSP_LCD_FillRGBRect(0, 1, color, area->x1, area->y1, lv_area_get_width(area), lv_area_get_height(area));
#else
	BSP_LCD_FillRGBRect(0, 1, color, area->x1, area->y1, lv_area_get_width(area), lv_area_get_height(area));
    BSP_LCD_WaitForTransferToBeDone(0);
#endif

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	lv_disp_flush_ready(drv);
}
