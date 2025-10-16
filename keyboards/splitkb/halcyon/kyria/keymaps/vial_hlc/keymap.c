// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _GALLIUM = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _ADJUST,
    _PT,
    _PT_COMBO
};

// Custom keycodes for Portuguese characters using dead keys
enum custom_keycodes {
    PT_A_TILDE = SAFE_RANGE,  // ã: KC_TILD + KC_A
    PT_A_ACUTE,                // á: KC_QUOT + KC_A
    PT_A_GRAVE,                // à: KC_GRV + KC_A
    PT_E_ACUTE,                // é: KC_QUOT + KC_E
    PT_E_CIRC,                 // ê: KC_CIRC + KC_E
    PT_I_ACUTE,                // í: KC_QUOT + KC_I
    PT_O_ACUTE,                // ó: KC_QUOT + KC_O
    PT_O_CIRC,                 // ô: KC_CIRC + KC_O
    PT_O_TILDE,                // õ: KC_TILD + KC_O
    PT_C_CEDILLA,              // ç: KC_QUOT + KC_C (just outputs ç)
    PT_CAO,                    // ção
    PT_CA_TILDE,               // çã
    PT_COES,                   // ções
    PT_QU                      // qu
};

// Aliases for readability
#define SYM      MO(_SYM)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MSE_TAB  LT(_MOUSE, KC_TAB)
#define MED_ENT  LT(_MEDIA, KC_ENT)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define FUN_BSP  LT(_FUN, KC_BSPC)
#define ADJUST   MO(_ADJUST)
#define PT_COMBO OSL(_PT_COMBO)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Gallium with Home Row Mods (CAGS)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   B  |   L  |   D  |   C  |   V  |                              |   J  |   Y  |   O  |   U  |   ,  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctl/N| Alt/R|GUI/T |Sft/S |   G  |                              |   P  |Sft/H |GUI/A |Alt/E |Ctl/I |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   X  |   Q  |   M  |   W  |   Z  |  [   | Caps |  |      |  ]   |   K  |   F  |  ' " | ;  : | .  > |  /  ?  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| Esc  |Med/En|Nav/Sp|Mse/Tb|  |  Sym |Num/Sp|Fun/Bs|      | App  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GALLIUM] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_B        , KC_L        , KC_D        , KC_C        , KC_V ,                                             KC_J, KC_Y        , KC_O        , KC_U        , KC_COMM     , _______,
     _______ , LCTL_T(KC_N), LALT_T(KC_R), LGUI_T(KC_T), LSFT_T(KC_S), KC_G ,                                             KC_P, RSFT_T(KC_H), RGUI_T(KC_A), RALT_T(KC_E), RCTL_T(KC_I), _______,
     _______ , KC_X        , KC_Q        , KC_M        , KC_W        , KC_Z , KC_LBRC, KC_CAPS, _______, KC_RBRC,         KC_K, KC_F        , KC_QUOT     , KC_SCLN     , KC_DOT      , KC_SLSH,
                                           ADJUST , KC_ESC , MED_ENT, NAV_SPC, MSE_TAB, SYM    , NUM_SPC, FUN_BSP, OSL(_PT), KC_APP,
                                           KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
    ),

/*
 * Nav Layer: Miryoku navigation and editing
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Redo |Paste | Copy | Cut  | Undo |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl | Alt  | GUI  |Shift |      |                              | Caps | Left | Down |  Up  |Right |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      | |      |      |Insert| Home | PgDn | PgUp | End  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______, _______,                                     KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer: Miryoku mouse emulation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Redo |Paste | Copy | Cut  | Undo |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl | Alt  | GUI  |Shift |      |                              |      | MLeft| MDown| MUp  |MRight|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      | |      |      |      | WLeft| WDown| WUp  |WRight|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Btn1 |      |  | Btn3 | Btn1 | Btn2 |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______, _______,                                     KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, _______,
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                     _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                                _______, _______, _______, KC_BTN1, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Media Layer: Media controls and RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |RGBTog|RGBMod|RGBHue|RGBSat|RGBVal|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl | Alt  | GUI  |Shift |      |                              |      | Prev | Vol- | Vol+ | Next |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      | |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Stop | Play | Mute |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MEDIA] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______, _______,                                     RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, _______,
     _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                     _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Num Layer: Numpad on left hand
 *
 * ,--------,-------------------------------------                              ,-------------------------------------------.
 * |        |   [    |   7  |   8  |   9  |   ]  |                              |      |      |      |      |      |        |
 * |--------|--------+------+------+------+------+                              |------+------+------+------+------+--------|
 * |        |   ;    |   4  |   5  |   6  |   =  |                              |      |Shift | Ctrl | Alt  | GUI  |        |
 * |--------|--------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   `    |   1  |   2  |   3  |  \   |      |      |  |      |      |      |      |      |      |      |        |
 * `--------`----------------------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                          |      |   .  |   0  |   -  |      |  |      |      |      |      |      |
 *                          `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT_split_3x6_5_hlc(
     _______, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                                     _______, _______, _______, _______, _______, _______,
     _______, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                                      _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
     _______, KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, KC_DOT , KC_0   , KC_MINS, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Symbols on left hand (shifted versions of Num)
 *
 * ,--------,-------------------------------------                              ,-------------------------------------------.
 * |        |   {    |   &  |   *  |   (  |   }  |                              |      |      |      |      |      |        |
 * |--------|--------+------+------+------+------+                              |------+------+------+------+------+--------|
 * |        |   :    |   $  |   %  |   ^  |   +  |                              |      |Shift | Ctrl | Alt  | GUI  |        |
 * |--------|--------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ~    |   !  |   @  |   #  |   |  |      |      |  |      |      |      |      |      |      |      |        |
 * `--------`----------------------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                          |      |   (  |   )  |   _  |      |  |      |      |      |      |      |
 *                          `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, _______, _______,
     _______, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
     _______, KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Fun Layer: Function keys (mirrors Num layout)
 *
 * ,--------,-------------------------------------                              ,-------------------------------------------.
 * |        |  F12   |  F7  |  F8  |  F9  |PrtSc |                              |      |      |      |      |      |        |
 * |--------|--------+------+------+------+------+                              |------+------+------+------+------+--------|
 * |        |  F11   |  F4  |  F5  |  F6  |ScrLk |                              |      |Shift | Ctrl | Alt  | GUI  |        |
 * |--------|--------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F10   |  F1  |  F2  |  F3  |Pause |      |      | |      |      |      |      |      |      |      |        |
 * `--------`----------------------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                          |      | App  | Space| Tab  |      |  |      |      |      |      |      |
 *                          `----------------------------------'  `----------------------------------'
 */
    [_FUN] = LAYOUT_split_3x6_5_hlc(
     _______, KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,                                     _______, _______, _______, _______, _______, _______,
     _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
     _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, KC_APP , KC_SPC , KC_TAB , _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: RGB controls
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |TOG   |SAT+  |HUE+  |VAL+  |NEXT  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      | |      |      |      |SAT-  |HUE-  |VAL-  |PREV  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                     RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * PT Layer: Portuguese accented characters
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   õ  |   ó  |   ô  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctl  | Alt  | GUI  |Shift |      |                              |      |   á  |   ã  |   é  |   í  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  qu  |      |      |      |      |      |  |      |      |      | COMBO|   à  |   ê  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_PT] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______   , _______,                                         _______, PT_O_TILDE , PT_O_ACUTE , PT_O_CIRC, _______, _______,
     _______, _______, _______, _______, _______   , _______,                                         _______, PT_A_ACUTE , PT_A_TILDE , PT_E_ACUTE, PT_I_ACUTE, _______,
     _______, _______, PT_QU   , _______, _______   , _______, _______, _______, _______, _______, _______, PT_COMBO   , PT_A_GRAVE, PT_E_CIRC , _______ , _______,
                                _______, _______   , _______, _______, _______, _______   , _______    , _______   , _______, _______,
                                _______, _______   , _______, _______, _______, _______   , _______    , _______   , _______, _______
    ),

/*
 * PT_COMBO Layer: Portuguese character combinations (activated by OSL at F position in PT layer)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |  ção |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |  çã  | ções |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |   ç  |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_PT_COMBO] = LAYOUT_split_3x6_5_hlc(
     _______, _______, _______, _______, _______, _______,                                     _______, _______    , PT_CAO     , _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                                     _______, _______    , PT_CA_TILDE, PT_COES , _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, PT_C_CEDILLA, _______   , _______ , _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
#define LED_L_ADJUST 10   // Adjust
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
    LED_L_LBRC, LED_L_CAPS, LED_L_ADJUST, LED_L_ESC,
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
static void set_gallium_layer_leds(void) {
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
    rgb_matrix_set_color(LED_L_ESC, COLOR_SYMBOLS);     // . (dot)
    rgb_matrix_set_color(LED_L_MED_ENT, COLOR_NUMBERS); // 0
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

static void set_adjust_layer_leds(void) {
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

// RGB lighting for layers
bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _GALLIUM:
            set_gallium_layer_leds();
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
        case _ADJUST:
            set_adjust_layer_leds();
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

// Helper functions for Portuguese dead key characters
static inline void send_acute_accent(uint16_t base_char, bool shifted) {
    tap_code(KC_QUOT);  // Dead key '
    if (shifted) {
        tap_code16(S(base_char));
    } else {
        tap_code(base_char);
    }
}

static inline void send_circumflex(uint16_t base_char, bool shifted) {
    tap_code16(S(KC_6));  // Dead key ^ (Shift+6)
    if (shifted) {
        tap_code16(S(base_char));
    } else {
        tap_code(base_char);
    }
}

static inline void send_tilde(uint16_t base_char, bool shifted) {
    tap_code16(S(KC_GRV));  // Shift+` for tilde dead key
    if (shifted) {
        tap_code16(S(base_char));
    } else {
        tap_code(base_char);
    }
}

static inline void send_grave_accent(uint16_t base_char, bool shifted) {
    tap_code(KC_GRV);  // Dead key `
    if (shifted) {
        tap_code16(S(base_char));
    } else {
        tap_code(base_char);
    }
}

// Handle custom keycodes for Portuguese characters using dead keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    bool shifted = get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
        // Simple dead key characters
        case PT_A_TILDE:   send_tilde(KC_A, shifted);         return false;  // ã / Ã
        case PT_A_ACUTE:   send_acute_accent(KC_A, shifted);  return false;  // á / Á
        case PT_A_GRAVE:   send_grave_accent(KC_A, shifted);  return false;  // à / À
        case PT_E_ACUTE:   send_acute_accent(KC_E, shifted);  return false;  // é / É
        case PT_E_CIRC:    send_circumflex(KC_E, shifted);    return false;  // ê / Ê
        case PT_I_ACUTE:   send_acute_accent(KC_I, shifted);  return false;  // í / Í
        case PT_O_ACUTE:   send_acute_accent(KC_O, shifted);  return false;  // ó / Ó
        case PT_O_CIRC:    send_circumflex(KC_O, shifted);    return false;  // ô / Ô
        case PT_O_TILDE:   send_tilde(KC_O, shifted);         return false;  // õ / Õ
        case PT_C_CEDILLA: send_acute_accent(KC_C, shifted);  return false;  // ç / Ç

        // Combination characters
        case PT_CAO:  // ção / ÇÃO
            send_acute_accent(KC_C, shifted);  // ç / Ç
            send_tilde(KC_A, shifted);         // ã / Ã
            if (shifted) {
                tap_code16(S(KC_O));
            } else {
                tap_code(KC_O);
            }
            return false;

        case PT_CA_TILDE:  // çã / ÇÃ
            send_acute_accent(KC_C, shifted);  // ç / Ç
            send_tilde(KC_A, shifted);         // ã / Ã
            return false;

        case PT_COES:  // ções / ÇÕES
            send_acute_accent(KC_C, shifted);  // ç / Ç
            send_tilde(KC_O, shifted);         // õ / Õ
            if (shifted) {
                tap_code16(S(KC_E));
                tap_code16(S(KC_S));
            } else {
                tap_code(KC_E);
                tap_code(KC_S);
            }
            return false;

        // qu / QU
        case PT_QU:
            if (shifted) {
                tap_code16(S(KC_Q));     // Q
                tap_code16(S(KC_U));     // U
            } else {
                tap_code(KC_Q);          // q
                tap_code(KC_U);          // u
            }
            return false;
    }
    return true;
}
