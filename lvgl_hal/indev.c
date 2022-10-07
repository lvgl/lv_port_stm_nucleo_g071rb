/**
 * @file indev.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "indev.h"
#include "Drivers/BSP/key/key_io.h"

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
static void joy_read_cb(lv_indev_drv_t * drv, lv_indev_data_t * data);

/**********************
 *  GLOBAL VARIABLES
 **********************/
lv_indev_t * joy_indev;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void indev_init(void)
{
	if(BSP_KEY_Init(0, KEY_ORIENTATION_PORTRAIT) != BSP_ERROR_NONE) {
		Error_Handler();
	}

	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.read_cb = joy_read_cb;
	indev_drv.type = LV_INDEV_TYPE_KEYPAD;
	joy_indev = lv_indev_drv_register(&indev_drv);


}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void joy_read_cb(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
	uint8_t key;
	if(BSP_KEY_GetState(0, &key) == BSP_ERROR_NONE)
	{
		switch(key)
		{
		case BSP_KEY_CENTER:
			data->key = LV_KEY_ENTER;
			data->state = LV_INDEV_STATE_PRESSED;
			break;
		case BSP_KEY_LEFT:
			data->key = LV_KEY_LEFT;
			data->state = LV_INDEV_STATE_PRESSED;
			break;
		case BSP_KEY_RIGHT:
			data->key = LV_KEY_RIGHT;
			data->state = LV_INDEV_STATE_PRESSED;
			break;
		case BSP_KEY_UP:
			data->key = LV_KEY_PREV;
			data->state = LV_INDEV_STATE_PRESSED;
			break;
		case BSP_KEY_DOWN:
			data->key = LV_KEY_NEXT;
			data->state = LV_INDEV_STATE_PRESSED;
			break;
		default:
			break;
		}
	} else {
		data->state = LV_INDEV_STATE_RELEASED;
	}
}
