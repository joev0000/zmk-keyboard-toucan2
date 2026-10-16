#include <zephyr/kernel.h>
#include "version.h"
#include "util.h"
#include "../assets/custom_fonts.h"

#ifndef TOUCAN_FIRMWARE_COMMIT
#define TOUCAN_FIRMWARE_COMMIT "unknown"
#endif

static bool show_version_screen = true;

bool is_version_screen_active(void) { return show_version_screen; }

void set_version_screen_active(bool active) { show_version_screen = active; }

void draw_version_screen(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_12, LV_TEXT_ALIGN_CENTER);
    lv_canvas_draw_text(canvas, 0, (SCREEN_HEIGHT - 12) / 2, SCREEN_WIDTH, &label_dsc,
                        TOUCAN_FIRMWARE_COMMIT);
}
