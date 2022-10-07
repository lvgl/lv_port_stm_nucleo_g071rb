/**
 * @file indev.h
 *
 */

#ifndef INDEV_H
#define INDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void indev_init(void);

/**********************
 * GLOBAL VARIABLES
 **********************/
extern lv_indev_t * joy_indev;

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*INDEV_H*/
