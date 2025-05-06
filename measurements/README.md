# STM32G071RB Aircon Demo - Main Menu

## Size

- Aircon demo with **only** the main menu screen.
- Map files are attached. Can be visualized [here](https://jotux.github.io/GccMapVisualizer/).

### GCC -O3

- Application size: 115.16 KB

### GCC -Os

- Application size: 90.25 KB

## Performance

After every render and flush the entire screen is invalidated:

```c
while (1)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    lv_timer_handler();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    lv_obj_invalidate(lv_scr_act());
    HAL_Delay(100);
}
```

Time spent in `refr_invalid_areas`, `lv_timer_handler`, and `flush_cb` were measured.

- `lv_timer_handler`: main entry point.
- `refr_invalid_areas`: does the actual rendering.
- `flush_cb`: flushes the buffer to the display.

### GCC -O3

For **one** draw cycle (i.e. one call of `lv_timer_handler` where the entire screen is invalidated) the time spent in each function:

- Total high time for 'refr_invalid_areas': 0.041673 seconds
- Total high time for 'lv_timer_handler': 0.081085 seconds
- Total high time for 'flush_cb': 0.039619 seconds
- Percentage of lv_timer_handler spent rendering: 0.513939%
- Percentage of lv_timer_handler spent flushing: 0.488605%

The total render time for the entire screen is 41.7 ms.

### GCC -Os

For **one** draw cycle (i.e. one call of `lv_timer_handler` where the entire screen is invalidated) the time spent in each function:

- Total high time for 'refr_invalid_areas': 0.048788 seconds
- Total high time for 'lv_timer_handler': 0.088276 seconds
- Total high time for 'flush_cb': 0.039669 seconds
- Percentage of lv_timer_handler spent rendering: 0.552679%
- Percentage of lv_timer_handler spent flushing: 0.449372%

The total render time for the entire screen is 48.8 ms.

# STM32G071RB Aircon Demo - About Menu (text)

## Size

- Aircon demo with **only** the about screen.
- Map files are attached. Can be visualized [here](https://jotux.github.io/GccMapVisualizer/).

### GCC -O3

- Application size: 113.14 KB

### GCC -Os

- Application size: 88.27 KB

## Performance

After every render and flush the entire screen is invalidated:

```c
while (1)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
    lv_timer_handler();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    lv_obj_invalidate(lv_scr_act());
    HAL_Delay(100);
}
```

Time spent in `refr_invalid_areas`, `lv_timer_handler`, and `flush_cb` were measured.

- `lv_timer_handler`: main entry point.
- `refr_invalid_areas`: does the actual rendering.
- `flush_cb`: flushes the buffer to the display.

### GCC -O3

For **one** draw cycle (i.e. one call of `lv_timer_handler` where the entire screen is invalidated) the time spent in each function:

- Total high time for 'refr_invalid_areas': 0.338090 seconds
- Total high time for 'lv_timer_handler': 0.377485 seconds
- Total high time for 'flush_cb': 0.039615 seconds
- Percentage of lv_timer_handler spent rendering: 0.895639%
- Percentage of lv_timer_handler spent flushing: 0.104944%

The total render time for the entire screen is 338 ms.

### GCC -Os

For **one** draw cycle (i.e. one call of `lv_timer_handler` where the entire screen is invalidated) the time spent in each function:

- Total high time for 'refr_invalid_areas': 0.408352 seconds
- Total high time for 'lv_timer_handler': 0.447829 seconds
- Total high time for 'flush_cb': 0.039679 seconds
- Percentage of lv_timer_handler spent rendering: 0.911847%
- Percentage of lv_timer_handler spent flushing: 0.088603%

The total render time for the entire screen is 408 ms.
