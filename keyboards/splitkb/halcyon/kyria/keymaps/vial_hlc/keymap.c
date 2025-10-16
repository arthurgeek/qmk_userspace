// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layers.h"
#include "portuguese.h"
#include "keymap_blocks.h"


// Kyria-specific layout wrapper (3x6 matrix + 5 thumbs + extras)
#define LAYOUT_wrapper(...) LAYOUT_split_3x6_5_hlc(__VA_ARGS__)

// Kyria-specific layer (starts after generic layers)
#define _RGB _LAYER_COUNT  // RGB control layer

// Kyria-specific aliases
#define RGB   MO(_RGB)

// Kyria-specific RGB layer blocks (RGB controls)
#define ____________________RGB_L1_____________________ _______, _______, _______, _______, _______
#define ____________________RGB_L2_____________________ _______, _______, _______, _______, _______
#define ____________________RGB_L3_____________________ _______, _______, _______, _______, _______
#define ____________________RGB_R1_____________________ _______, _______, _______, _______, _______
#define ____________________RGB_R2_____________________ RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT
#define ____________________RGB_R3_____________________ _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Alpha with Home Row Mods (CAGS)
 */
    [_ALPHA] = LAYOUT_wrapper(
     _______ , ____________________ALPHA_L1___________________ ,                                             ____________________ALPHA_R1___________________ , _______,
     OSL(_PT), ____________________ALPHA_L2___________________ ,                                             ____________________ALPHA_R2___________________ , _______,
     _______ , ____________________ALPHA_L3___________________ , KC_LBRC, KC_CAPS, _______, KC_RBRC,         ____________________ALPHA_R3___________________ , KC_SLSH,
                                           RGB , ________________ALPHA_THUMBS_L_________________, KC_NO  , ________________ALPHA_THUMBS_R_________________, _______, KC_APP,
                                           KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
    ),

/*
 * Nav Layer: Miryoku navigation and editing
 */
    [_NAV] = LAYOUT_wrapper(
     _______, ___________________NAV_L1______________________ ,                                     ___________________NAV_R1______________________ , _______,
     _______, ___________________NAV_L2______________________ ,                                     ___________________NAV_R2______________________ , _______,
     _______, ___________________NAV_L3______________________ , _______, _______, _______, _______, ___________________NAV_R3______________________ , _______,
                                _______, ________________NAV_THUMBS_L___________________, _______,    _______, ________________NAV_THUMBS_R___________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer: Miryoku mouse emulation
 */
    [_MOUSE] = LAYOUT_wrapper(
     _______, __________________MOUSE_L1_____________________ ,                                     __________________MOUSE_R1_____________________ , _______,
     _______, __________________MOUSE_L2_____________________ ,                                     __________________MOUSE_R2_____________________ , _______,
     _______, __________________MOUSE_L3_____________________ , _______, _______, _______, _______, __________________MOUSE_R3_____________________ , _______,
                                _______, _______________MOUSE_THUMBS_L__________________, _______,    _______, _______________MOUSE_THUMBS_R__________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * Media Layer: Media controls and RGB
 */
    [_MEDIA] = LAYOUT_wrapper(
     _______, __________________MEDIA_L1_____________________ ,                                     RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, _______,
     _______, __________________MEDIA_L2_____________________ ,                                     __________________MEDIA_R2_____________________ , _______,
     _______, __________________MEDIA_L3_____________________ , _______, _______, _______, _______, __________________MEDIA_R3_____________________ , _______,
                                _______, _______________MEDIA_THUMBS_L__________________, _______,    _______, _______________MEDIA_THUMBS_R__________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * Num Layer: Numpad on left hand
 */
    [_NUM] = LAYOUT_wrapper(
     _______, ___________________NUM_L1______________________ ,                                     ___________________NUM_R1______________________ , _______,
     _______, ___________________NUM_L2______________________ ,                                      ___________________NUM_R2______________________ , _______,
     _______, ___________________NUM_L3______________________ , _______, _______, _______, _______, ___________________NUM_R3______________________ , _______,
                                _______, ________________NUM_THUMBS_L___________________, _______,    _______, ________________NUM_THUMBS_R___________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Symbols on left hand (shifted versions of Num)
 */
    [_SYM] = LAYOUT_wrapper(
     _______, ___________________SYM_L1______________________ ,                                     ___________________SYM_R1______________________ , _______,
     _______, ___________________SYM_L2______________________ ,                                     ___________________SYM_R2______________________ , _______,
     _______, ___________________SYM_L3______________________ , _______, _______, _______, _______, ___________________SYM_R3______________________ , _______,
                                _______, ________________SYM_THUMBS_L___________________, _______,    _______, ________________SYM_THUMBS_R___________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * Fun Layer: Function keys (mirrors Num layout)
 */
    [_FUN] = LAYOUT_wrapper(
     _______, ___________________FUN_L1______________________ ,                                     ___________________FUN_R1______________________ , _______,
     _______, ___________________FUN_L2______________________ ,                                     ___________________FUN_R2______________________ , _______,
     _______, ___________________FUN_L3______________________ , _______, _______, _______, _______, ___________________FUN_R3______________________ , _______,
                                _______, ________________FUN_THUMBS_L___________________, _______,    _______, ________________FUN_THUMBS_R___________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * RGB Layer: RGB controls
 */
   [_RGB] = LAYOUT_wrapper(
    _______, ____________________RGB_L1_____________________ ,                                     ____________________RGB_R1_____________________ , _______,
    _______, ____________________RGB_L2_____________________ ,                                     ____________________RGB_R2_____________________ , _______,
    _______, ____________________RGB_L3_____________________ , _______, _______, _______, _______, ____________________RGB_R3_____________________ , _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * PT Layer: Portuguese accented characters
 */
    [_PT] = LAYOUT_wrapper(
     _______, ___________________PT_L1_______________________ ,                                         ___________________PT_R1_______________________ , _______,
     _______, ___________________PT_L2_______________________ ,                                         ___________________PT_R2_______________________ , _______,
     _______, ___________________PT_L3_______________________ , _______, _______, _______, _______, ___________________PT_R3_______________________ , _______,
                                _______, _________________PT_THUMBS_L___________________, _______,    _______, _________________PT_THUMBS_R___________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

/*
 * PT_COMBO Layer: Portuguese character combinations
 */
    [_PT_COMBO] = LAYOUT_wrapper(
     _______, _________________PT_COMBO_L1___________________ ,                                     _________________PT_COMBO_R1___________________ , _______,
     _______, _________________PT_COMBO_L2___________________ ,                                     _________________PT_COMBO_R2___________________ , _______,
     _______, _________________PT_COMBO_L3___________________ , _______, _______, _______, _______, _________________PT_COMBO_R3___________________ , _______,
                                _______, ______________PT_COMBO_THUMBS_L________________, _______,    _______, ______________PT_COMBO_THUMBS_R________________, _______,
                                _______, _______, _______, _______, _______    ,        _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      | |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
// clang-format on

// Predictive Tap Hold side layout
const uint8_t pth_side_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_5_hlc(
 PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_L,                                           PTH_R, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R,
 PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_L,                                           PTH_R, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R,
 PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_L,               PTH_R, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R,
                             PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R,
                             PTH_L, PTH_L, PTH_L, PTH_L, PTH_L, PTH_R, PTH_R, PTH_R, PTH_R, PTH_R
);

// RGB Matrix LED indices - LEFT SIDE
#define LED_L_B 29        // B
#define LED_L_L 28        // L
#define LED_L_D 27        // D
#define LED_L_C 26        // C
#define LED_L_V 25        // V
#define LED_L_N 23        // N (Ctrl)
#define LED_L_R 22        // R (Alt)
#define LED_L_T 21        // T (GUI)
#define LED_L_S 20        // S (Shift)
#define LED_L_G 19        // G
#define LED_L_X 17        // X
#define LED_L_Q 16        // Q
#define LED_L_M 15        // M
#define LED_L_W 14        // W
#define LED_L_Z 13        // Z
#define LED_L_LBRC 12     // [ (left bracket)
#define LED_L_CAPS 11     // Caps Lock
#define LED_L_RGB 10   // RGB control layer
#define LED_L_ESC 9       // Esc
#define LED_L_MED_ENT 8   // Med/Ent
#define LED_L_NAV_SPC 7   // Nav/Spc
#define LED_L_MSE_TAB 6   // Mse/Tab

// RGB Matrix LED indices - RIGHT SIDE
#define LED_R_J 56        // J
#define LED_R_Y 57        // Y
#define LED_R_O 58        // O
#define LED_R_U 59        // U
#define LED_R_COMM 60     // , (comma)
#define LED_R_P 50        // P
#define LED_R_H 51        // H
#define LED_R_A 52        // A
#define LED_R_E 53        // E
#define LED_R_I 54        // I
#define LED_R_RBRC 43     // ] (right bracket)
#define LED_R_K 44        // K
#define LED_R_F 45        // F
#define LED_R_QUOT 46     // ' (quote)
#define LED_R_SCLN 47     // ; (semicolon)
#define LED_R_DOT 48      // . (dot)
#define LED_R_SLSH 49     // / (slash)
#define LED_R_SYM 37      // Sym
#define LED_R_NUM_SPC 38  // Num/Spc
#define LED_R_FUN_BSP 39  // Fun/Bsp
#define LED_R_OSL_PT 40   // OSL(PT)
#define LED_R_APP 41      // App

// LED arrays for iteration
static const uint8_t left_side_leds[] = {
    LED_L_B, LED_L_L, LED_L_D, LED_L_C, LED_L_V,
    LED_L_N, LED_L_R, LED_L_T, LED_L_S, LED_L_G,
    LED_L_X, LED_L_Q, LED_L_M, LED_L_W, LED_L_Z,
    LED_L_LBRC, LED_L_CAPS, LED_L_RGB, LED_L_ESC,
    LED_L_MED_ENT, LED_L_NAV_SPC, LED_L_MSE_TAB
};
#define LEFT_SIDE_LED_COUNT (sizeof(left_side_leds) / sizeof(left_side_leds[0]))

static const uint8_t right_side_leds[] = {
    LED_R_J, LED_R_Y, LED_R_O, LED_R_U, LED_R_COMM,
    LED_R_P, LED_R_H, LED_R_A, LED_R_E, LED_R_I,
    LED_R_RBRC, LED_R_K, LED_R_F, LED_R_QUOT, LED_R_SCLN,
    LED_R_DOT, LED_R_SLSH, LED_R_SYM, LED_R_NUM_SPC,
    LED_R_FUN_BSP, LED_R_OSL_PT, LED_R_APP
};
#define RIGHT_SIDE_LED_COUNT (sizeof(right_side_leds) / sizeof(right_side_leds[0]))

// Initialize RGB to solid color mode on startup
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // Set to black (off)
}

// Color definitions for semantic groupings
#define COLOR_CTRL      0, 0, 255       // Control modifier
#define COLOR_ALT       255, 0, 255     // Alt modifier
#define COLOR_GUI       0, 255, 0       // GUI modifier
#define COLOR_SHIFT     255, 255, 0     // Shift modifier
#define COLOR_ARROWS    0, 255, 255     // Movement (arrows)
#define COLOR_EDIT      0, 255, 0       // Editing operations (copy/paste/undo)
#define COLOR_CAPS      255, 0, 0       // Caps Lock
#define COLOR_MOUSE     255, 255, 0     // Mouse movement
#define COLOR_WHEEL     128, 128, 255   // Mouse wheel
#define COLOR_BUTTON    255, 128, 128   // Mouse buttons
#define COLOR_MEDIA     255, 128, 0     // Media controls (prev/next)
#define COLOR_VOLUME    128, 255, 128   // Volume controls
#define COLOR_RGB       255, 0, 255     // RGB lighting controls
#define COLOR_NUMBERS   255, 200, 0     // Numbers
#define COLOR_SYMBOLS   128, 0, 255     // Symbols (!@#$%^&*)
#define COLOR_FUN       255, 64, 128    // Function keys (F1-F12)
#define COLOR_MISC1     200, 100, 80    // Special/Misc keys
#define COLOR_MISC2      64, 64, 64     // Special/Misc keys

// Portuguese characters - semantic grouping
#define COLOR_PT_A      255, 100, 0     // A-like characters (ã, á, à) - Orange
#define COLOR_PT_E      0, 255, 150     // E-like characters (é, ê) - Teal/Cyan-green
#define COLOR_PT_I      150, 0, 255     // I-like character (í) - Purple
#define COLOR_PT_O      255, 200, 0     // O-like characters (ó, ô, õ) - Yellow-orange
#define COLOR_PT_C      255, 0, 100     // Ç character - Pink/Magenta
#define COLOR_PT_QU     100, 150, 255   // QU - Light blue

#ifdef HLC_TFT_DISPLAY
// Display layer colors for layers 8 and 9
#define HSV_LAYER_8     180, 255, 255   // Cyan
#define HSV_LAYER_9     200, 255, 255   // Light blue
#endif

// Helper functions to turn off all keys on each side
static void turn_off_all_left_side_keys(void) {
    for (uint8_t i = 0; i < LEFT_SIDE_LED_COUNT; i++) {
        rgb_matrix_set_color(left_side_leds[i], 0, 0, 0);
    }
}

static void turn_off_all_right_side_keys(void) {
    for (uint8_t i = 0; i < RIGHT_SIDE_LED_COUNT; i++) {
        rgb_matrix_set_color(right_side_leds[i], 0, 0, 0);
    }
}

// Helper functions to set up modifiers (which also turn off other keys)
static void set_left_side_modifiers(void) {
    turn_off_all_left_side_keys();

    // Set left side home row modifiers
    rgb_matrix_set_color(LED_L_N, COLOR_CTRL);   // Ctrl
    rgb_matrix_set_color(LED_L_R, COLOR_ALT);    // Alt
    rgb_matrix_set_color(LED_L_T, COLOR_GUI);    // GUI
    rgb_matrix_set_color(LED_L_S, COLOR_SHIFT);  // Shift
}

static void set_right_side_modifiers(void) {
    turn_off_all_right_side_keys();

    // Set right side home row modifiers
    rgb_matrix_set_color(LED_R_H, COLOR_SHIFT);  // Shift
    rgb_matrix_set_color(LED_R_A, COLOR_GUI);    // GUI
    rgb_matrix_set_color(LED_R_E, COLOR_ALT);    // Alt
    rgb_matrix_set_color(LED_R_I, COLOR_CTRL);   // Ctrl
}

// Layer-specific RGB handlers
static void set_alpha_layer_leds(void) {
    set_left_side_modifiers();
    set_right_side_modifiers();
}

static void set_nav_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // Editing operations
    rgb_matrix_set_color(LED_R_J, COLOR_EDIT);    // Redo
    rgb_matrix_set_color(LED_R_Y, COLOR_EDIT);    // Paste
    rgb_matrix_set_color(LED_R_O, COLOR_EDIT);    // Copy
    rgb_matrix_set_color(LED_R_U, COLOR_EDIT);    // Cut
    rgb_matrix_set_color(LED_R_COMM, COLOR_EDIT); // Undo

    // Caps Lock
    rgb_matrix_set_color(LED_R_P, COLOR_CAPS);  // Caps

    // Arrow keys
    rgb_matrix_set_color(LED_R_H, COLOR_ARROWS);  // Left
    rgb_matrix_set_color(LED_R_A, COLOR_ARROWS);  // Down
    rgb_matrix_set_color(LED_R_E, COLOR_ARROWS);  // Up
    rgb_matrix_set_color(LED_R_I, COLOR_ARROWS);  // Right

    // Navigation keys
    rgb_matrix_set_color(LED_R_RBRC, COLOR_MISC1);  // Insert
    rgb_matrix_set_color(LED_R_K, COLOR_MISC1);     // Home
    rgb_matrix_set_color(LED_R_F, COLOR_MISC2);     // PgDn
    rgb_matrix_set_color(LED_R_QUOT, COLOR_MISC2);  // PgUp
    rgb_matrix_set_color(LED_R_SCLN, COLOR_MISC2);  // End
}

static void set_mouse_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // Editing operations
    rgb_matrix_set_color(LED_R_J, COLOR_EDIT);    // Redo
    rgb_matrix_set_color(LED_R_Y, COLOR_EDIT);    // Paste
    rgb_matrix_set_color(LED_R_O, COLOR_EDIT);    // Copy
    rgb_matrix_set_color(LED_R_U, COLOR_EDIT);    // Cut
    rgb_matrix_set_color(LED_R_COMM, COLOR_EDIT); // Undo

    // Mouse movement
    rgb_matrix_set_color(LED_R_H, COLOR_MOUSE);  // Mouse Left
    rgb_matrix_set_color(LED_R_A, COLOR_MOUSE);  // Mouse Down
    rgb_matrix_set_color(LED_R_E, COLOR_MOUSE);  // Mouse Up
    rgb_matrix_set_color(LED_R_I, COLOR_MOUSE);  // Mouse Right

    // Mouse wheel
    rgb_matrix_set_color(LED_R_K, COLOR_WHEEL);    // Wheel Left
    rgb_matrix_set_color(LED_R_F, COLOR_WHEEL);    // Wheel Down
    rgb_matrix_set_color(LED_R_QUOT, COLOR_WHEEL); // Wheel Up
    rgb_matrix_set_color(LED_R_SCLN, COLOR_WHEEL); // Wheel Right

    // Mouse buttons
    rgb_matrix_set_color(LED_R_SYM, COLOR_BUTTON);     // Btn3
    rgb_matrix_set_color(LED_R_NUM_SPC, COLOR_BUTTON); // Btn1
    rgb_matrix_set_color(LED_R_FUN_BSP, COLOR_BUTTON); // Btn2
}

static void set_media_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // RGB controls
    rgb_matrix_set_color(LED_R_J, COLOR_RGB);    // RGB Toggle
    rgb_matrix_set_color(LED_R_Y, COLOR_RGB);    // RGB Mode
    rgb_matrix_set_color(LED_R_O, COLOR_RGB);    // RGB Hue+
    rgb_matrix_set_color(LED_R_U, COLOR_RGB);    // RGB Sat+
    rgb_matrix_set_color(LED_R_COMM, COLOR_RGB); // RGB Val+

    // Media controls
    rgb_matrix_set_color(LED_R_H, COLOR_MISC1);  // Prev
    rgb_matrix_set_color(LED_R_I, COLOR_MISC1);  // Next

    // Volume controls
    rgb_matrix_set_color(LED_R_A, COLOR_VOLUME);  // Vol-
    rgb_matrix_set_color(LED_R_E, COLOR_VOLUME);  // Vol+

    // Media controls
    rgb_matrix_set_color(LED_R_SYM, COLOR_MISC1);     // Stop
    rgb_matrix_set_color(LED_R_NUM_SPC, COLOR_MISC1); // Play
    rgb_matrix_set_color(LED_R_FUN_BSP, COLOR_VOLUME); // Mute
}

static void set_num_layer_leds(void) {
    turn_off_all_left_side_keys();

    // Numbers
    rgb_matrix_set_color(LED_L_B, COLOR_NUMBERS);  // 7
    rgb_matrix_set_color(LED_L_L, COLOR_NUMBERS);  // 8
    rgb_matrix_set_color(LED_L_D, COLOR_NUMBERS);  // 9
    rgb_matrix_set_color(LED_L_N, COLOR_NUMBERS);  // 4
    rgb_matrix_set_color(LED_L_R, COLOR_NUMBERS);  // 5
    rgb_matrix_set_color(LED_L_T, COLOR_NUMBERS);  // 6
    rgb_matrix_set_color(LED_L_X, COLOR_NUMBERS);  // 1
    rgb_matrix_set_color(LED_L_Q, COLOR_NUMBERS);  // 2
    rgb_matrix_set_color(LED_L_M, COLOR_NUMBERS);  // 3

    // Symbols
    rgb_matrix_set_color(LED_L_C, COLOR_SYMBOLS);       // ] (bracket)
    rgb_matrix_set_color(LED_L_S, COLOR_SYMBOLS);       // = (equals)
    rgb_matrix_set_color(LED_L_W, COLOR_SYMBOLS);       // \ (backslash)
    rgb_matrix_set_color(LED_L_ESC, COLOR_NUMBERS);     // 0
    rgb_matrix_set_color(LED_L_MED_ENT, COLOR_SYMBOLS); // . (dot)
    rgb_matrix_set_color(LED_L_NAV_SPC, COLOR_SYMBOLS); // - (minus)

    set_right_side_modifiers();
}

static void set_sym_layer_leds(void) {
    turn_off_all_left_side_keys();

    // Symbols
    rgb_matrix_set_color(LED_L_B, COLOR_SYMBOLS);       // &
    rgb_matrix_set_color(LED_L_L, COLOR_SYMBOLS);       // *
    rgb_matrix_set_color(LED_L_D, COLOR_SYMBOLS);       // (
    rgb_matrix_set_color(LED_L_N, COLOR_SYMBOLS);       // $
    rgb_matrix_set_color(LED_L_R, COLOR_SYMBOLS);       // %
    rgb_matrix_set_color(LED_L_T, COLOR_SYMBOLS);       // ^
    rgb_matrix_set_color(LED_L_X, COLOR_SYMBOLS);       // !
    rgb_matrix_set_color(LED_L_Q, COLOR_SYMBOLS);       // @
    rgb_matrix_set_color(LED_L_M, COLOR_SYMBOLS);       // #
    rgb_matrix_set_color(LED_L_C, COLOR_SYMBOLS);       // } (brace)
    rgb_matrix_set_color(LED_L_S, COLOR_SYMBOLS);       // + (plus)
    rgb_matrix_set_color(LED_L_W, COLOR_SYMBOLS);       // | (pipe)
    rgb_matrix_set_color(LED_L_ESC, COLOR_SYMBOLS);     // (
    rgb_matrix_set_color(LED_L_MED_ENT, COLOR_SYMBOLS); // )
    rgb_matrix_set_color(LED_L_NAV_SPC, COLOR_SYMBOLS); // _ (underscore)

    set_right_side_modifiers();
}

static void set_fun_layer_leds(void) {
    turn_off_all_left_side_keys();

    // Function keys
    rgb_matrix_set_color(LED_L_B, COLOR_FUN);  // F7
    rgb_matrix_set_color(LED_L_L, COLOR_FUN);  // F8
    rgb_matrix_set_color(LED_L_D, COLOR_FUN);  // F9
    rgb_matrix_set_color(LED_L_N, COLOR_FUN);  // F4
    rgb_matrix_set_color(LED_L_R, COLOR_FUN);  // F5
    rgb_matrix_set_color(LED_L_T, COLOR_FUN);  // F6
    rgb_matrix_set_color(LED_L_X, COLOR_FUN);  // F1
    rgb_matrix_set_color(LED_L_Q, COLOR_FUN);  // F2
    rgb_matrix_set_color(LED_L_M, COLOR_FUN);  // F3
    rgb_matrix_set_color(LED_L_C, COLOR_FUN);  // F12 (or PrtSc)
    rgb_matrix_set_color(LED_L_S, COLOR_FUN);  // F11 (or ScrLk)
    rgb_matrix_set_color(LED_L_W, COLOR_FUN);  // F10 (or Pause)

    // Utility keys
    rgb_matrix_set_color(LED_L_ESC, COLOR_MISC1);     // App
    rgb_matrix_set_color(LED_L_MED_ENT, COLOR_MISC1); // Space
    rgb_matrix_set_color(LED_L_NAV_SPC, COLOR_MISC1); // Tab

    set_right_side_modifiers();
}

static void set_rgb_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // RGB controls
    rgb_matrix_set_color(LED_R_P, COLOR_RGB);    // Toggle
    rgb_matrix_set_color(LED_R_H, COLOR_RGB);    // Sat+
    rgb_matrix_set_color(LED_R_A, COLOR_RGB);    // Hue+
    rgb_matrix_set_color(LED_R_E, COLOR_RGB);    // Val+
    rgb_matrix_set_color(LED_R_I, COLOR_RGB);    // Mode Next
    rgb_matrix_set_color(LED_R_K, COLOR_RGB);    // Sat-
    rgb_matrix_set_color(LED_R_F, COLOR_RGB);    // Hue-
    rgb_matrix_set_color(LED_R_QUOT, COLOR_RGB); // Val-
    rgb_matrix_set_color(LED_R_SCLN, COLOR_RGB); // Mode Prev
}

static void set_pt_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // QU combination
    rgb_matrix_set_color(LED_L_Q, COLOR_PT_QU);  // qu

    // Portuguese characters - semantic grouping by vowel family
    // O-like characters (ó, ô, õ)
    rgb_matrix_set_color(LED_R_Y, COLOR_PT_O);      // õ
    rgb_matrix_set_color(LED_R_O, COLOR_PT_O);      // ó
    rgb_matrix_set_color(LED_R_U, COLOR_PT_O);      // ô

    // A-like characters (ã, á, à)
    rgb_matrix_set_color(LED_R_A, COLOR_PT_A);      // ã
    rgb_matrix_set_color(LED_R_H, COLOR_PT_A);      // á
    rgb_matrix_set_color(LED_R_QUOT, COLOR_PT_A);   // à

    // E-like characters (é, ê)
    rgb_matrix_set_color(LED_R_E, COLOR_PT_E);      // é
    rgb_matrix_set_color(LED_R_SCLN, COLOR_PT_E);   // ê

    // I-like character (í)
    rgb_matrix_set_color(LED_R_I, COLOR_PT_I);      // í

    // Ç/OSL character - activates combo layer
    rgb_matrix_set_color(LED_R_F, COLOR_PT_C);      // COMBO (OSL)
}

static void set_pt_combo_layer_leds(void) {
    set_left_side_modifiers();
    turn_off_all_right_side_keys();

    // Set Portuguese combinations
    rgb_matrix_set_color(LED_R_O, COLOR_PT_O);   // ção (O position)
    rgb_matrix_set_color(LED_R_A, COLOR_PT_A);   // çã (A position)
    rgb_matrix_set_color(LED_R_E, COLOR_PT_E);   // ções (E position)
    rgb_matrix_set_color(LED_R_F, COLOR_PT_C);   // ç (F position)
}

// RGB lighting for layers with debouncing (prevent flashing during PTH)
bool rgb_matrix_indicators_user(void) {
    static uint8_t last_confirmed_layer = 0;
    static uint8_t last_detected_layer = 0;
    static uint32_t layer_change_timer = 0;
    uint8_t current_layer = get_highest_layer(layer_state);

    // Detect layer change
    if (current_layer != last_detected_layer) {
        layer_change_timer = timer_read();
        last_detected_layer = current_layer;
    }

    // Determine which layer to display
    uint8_t display_layer;
    if (timer_elapsed(layer_change_timer) >= 150) {
        // Layer is stable, update confirmed layer
        display_layer = current_layer;
        last_confirmed_layer = current_layer;
    } else {
        // Still debouncing, keep showing last confirmed layer
        display_layer = last_confirmed_layer;
    }

    // Update RGB for the display layer
    switch (display_layer) {
        case _ALPHA:
            set_alpha_layer_leds();
            break;
        case _NAV:
            set_nav_layer_leds();
            break;
        case _MOUSE:
            set_mouse_layer_leds();
            break;
        case _MEDIA:
            set_media_layer_leds();
            break;
        case _NUM:
            set_num_layer_leds();
            break;
        case _SYM:
            set_sym_layer_leds();
            break;
        case _FUN:
            set_fun_layer_leds();
            break;
        case _RGB:
            set_rgb_layer_leds();
            break;
        case _PT:
            set_pt_layer_leds();
            break;
        case _PT_COMBO:
            set_pt_combo_layer_leds();
            break;
    }

    return false;
}

// Delegate Portuguese character handling to shared code
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_portuguese(keycode, record);
}

#ifdef HLC_TFT_DISPLAY
#include "hlc_tft_display/hlc_tft_display.h"
#include "qp_surface.h"
#include "graphics/fonts/Retron2000-20.qff.h"

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

    // Only update display if layer has been stable for 150ms
    if (timer_elapsed(layer_change_timer) >= 150 && current_layer != last_displayed_layer && current_layer < 10) {
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
