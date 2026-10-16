#pragma once

#include <lvgl.h>
#include <stdbool.h>

bool is_version_screen_active(void);
void set_version_screen_active(bool active);
void draw_version_screen(lv_obj_t *canvas);
