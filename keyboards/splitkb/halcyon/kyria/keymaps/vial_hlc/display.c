// Copyright 2024 Arthur Zapparoli
// SPDX-License-Identifier: GPL-2.0-or-later

#ifdef HLC_TFT_DISPLAY
#include "hlc_tft_display/hlc_tft_display.h"
#include "qp_surface.h"
#include "graphics/fonts/Retron2000-20.qff.h"
#include "layers.h"

#define HSV_LAYER_ON 17, 191, 245   // Bright
#define HSV_LAYER_OFF 17, 104, 77   // Dim

static painter_font_handle_t my_font;

painter_device_t lcd;
painter_device_t lcd_surface;

// All 10 layers (matching enum order in layers.h)
static const char *layer_names[] = {
    "Alpha", "Media", "Nav", "Mouse", "Sym", "Num", "Fun", "PT", "PT+", "RGB"
};

bool module_post_init_user(void) {
    my_font = qp_load_font_mem(font_Retron2000_20);

    // Draw all 10 layer names initially
    for (uint8_t i = 0; i < 10; i++) {
        uint16_t y = 5 + (i * (my_font->line_height + 2));
        if (i == 0) {
            qp_drawtext_recolor(lcd_surface, 5, y, my_font, layer_names[i], HSV_LAYER_ON, HSV_BLACK);
        } else {
            qp_drawtext_recolor(lcd_surface, 5, y, my_font, layer_names[i], HSV_LAYER_OFF, HSV_BLACK);
        }
    }

    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
    return false;
}

bool display_module_housekeeping_task_user(bool second_display) {
    if (second_display) {
        return true;
    }

    static uint8_t last_displayed_layer = 0;
    static uint8_t last_detected_layer = 0;
    static uint32_t layer_change_timer = 0;
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

    // Detect layer change
    if (current_layer != last_detected_layer) {
        layer_change_timer = timer_read();
        last_detected_layer = current_layer;
    }

    // Only update display if layer has been stable for configured debounce time
    if (timer_elapsed(layer_change_timer) >= LAYER_DEBOUNCE_MS && current_layer != last_displayed_layer && current_layer < 10) {
        // Redraw only the changed layers
        for (uint8_t i = 0; i < 10; i++) {
            if (i == current_layer || i == last_displayed_layer) {
                uint16_t y = 5 + (i * (my_font->line_height + 2));

                // Active: bright, Inactive: dim
                if (i == current_layer) {
                    qp_drawtext_recolor(lcd_surface, 5, y, my_font, layer_names[i], HSV_LAYER_ON, HSV_BLACK);
                } else {
                    qp_drawtext_recolor(lcd_surface, 5, y, my_font, layer_names[i], HSV_LAYER_OFF, HSV_BLACK);
                }
            }
        }

        qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
        last_displayed_layer = current_layer;
    }

    return false;
}
#endif

