// Copyright 2024 Arthur Zapparoli
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "base_layers.h"

// =============================================================================
// CORE 3x5 LAYOUT BLOCKS - Universal across all split keyboards
// =============================================================================

// Alpha Base Layer - Left Hand (3x5)
#define ____________________ALPHA_L1___________________ KC_B        , KC_L        , KC_D        , KC_C        , KC_V
#define ____________________ALPHA_L2___________________ LCTL_T(KC_N), LALT_T(KC_R), LGUI_T(KC_T), LSFT_T(KC_S), KC_G
#define ____________________ALPHA_L3___________________ KC_X        , KC_Q        , KC_M        , KC_W        , KC_Z

// Alpha Base Layer - Right Hand (3x5)
#define ____________________ALPHA_R1___________________ KC_J, KC_Y        , KC_O        , KC_U        , KC_COMM
#define ____________________ALPHA_R2___________________ KC_P, RSFT_T(KC_H), RGUI_T(KC_A), RALT_T(KC_E), RCTL_T(KC_I)
#define ____________________ALPHA_R3___________________ KC_K, KC_F        , KC_QUOT     , KC_SCLN     , KC_DOT

// Nav Layer - Left Hand
#define ___________________NAV_L1______________________ _______, _______, _______, _______, _______
#define ___________________NAV_L2______________________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______
#define ___________________NAV_L3______________________ _______, _______, _______, _______, _______

// Nav Layer - Right Hand
#define ___________________NAV_R1______________________ KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO
#define ___________________NAV_R2______________________ KC_CAPS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
#define ___________________NAV_R3______________________ KC_INS , KC_HOME, KC_PGDN, KC_PGUP, KC_END

// Mouse Layer - Left Hand (same as Nav)
#define __________________MOUSE_L1_____________________ _______, _______, _______, _______, _______
#define __________________MOUSE_L2_____________________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______
#define __________________MOUSE_L3_____________________ _______, _______, _______, _______, _______

// Mouse Layer - Right Hand
#define __________________MOUSE_R1_____________________ KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO
#define __________________MOUSE_R2_____________________ _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
#define __________________MOUSE_R3_____________________ _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R

// Media Layer - Left Hand (same as Nav/Mouse)
#define __________________MEDIA_L1_____________________ _______, _______, _______, _______, _______
#define __________________MEDIA_L2_____________________ KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______
#define __________________MEDIA_L3_____________________ _______, _______, _______, _______, _______

// Media Layer - Right Hand
#define __________________MEDIA_R1_____________________ _______, _______, _______, _______, _______
#define __________________MEDIA_R2_____________________ _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
#define __________________MEDIA_R3_____________________ _______, _______, _______, _______, _______

// Num Layer - Left Hand
#define ___________________NUM_L1______________________ KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC
#define ___________________NUM_L2______________________ KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL
#define ___________________NUM_L3______________________ KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS

// Num Layer - Right Hand (modifiers)
#define ___________________NUM_R1______________________ _______, _______, _______, _______, _______
#define ___________________NUM_R2______________________ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI
#define ___________________NUM_R3______________________ _______, _______, _______, _______, _______

// Sym Layer - Left Hand
#define ___________________SYM_L1______________________ KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR
#define ___________________SYM_L2______________________ KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS
#define ___________________SYM_L3______________________ KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE

// Sym Layer - Right Hand (same as Num)
#define ___________________SYM_R1______________________ _______, _______, _______, _______, _______
#define ___________________SYM_R2______________________ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI
#define ___________________SYM_R3______________________ _______, _______, _______, _______, _______

// Fun Layer - Left Hand
#define ___________________FUN_L1______________________ KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR
#define ___________________FUN_L2______________________ KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL
#define ___________________FUN_L3______________________ KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS

// Fun Layer - Right Hand (same as Num/Sym)
#define ___________________FUN_R1______________________ _______, _______, _______, _______, _______
#define ___________________FUN_R2______________________ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI
#define ___________________FUN_R3______________________ _______, _______, _______, _______, _______

// PT Layer - Left Hand
#define ___________________PT_L1_______________________ _______, _______, _______, _______, _______
#define ___________________PT_L2_______________________ _______, _______, _______, _______, _______
#define ___________________PT_L3_______________________ _______, PT_QU  , _______, _______, _______

// PT Layer - Right Hand
#define ___________________PT_R1_______________________ _______, PT_O_TILDE, PT_O_ACUTE, PT_A_CIRC , _______
#define ___________________PT_R2_______________________ _______, PT_A_ACUTE, PT_A_TILDE, PT_E_ACUTE, PT_I_ACUTE
#define ___________________PT_R3_______________________ _______, PT_COMBO  , PT_A_GRAVE, PT_E_CIRC , PT_O_CIRC

// PT_COMBO Layer - Left Hand
#define _________________PT_COMBO_L1___________________ _______, _______, _______, _______, _______
#define _________________PT_COMBO_L2___________________ _______, _______, _______, _______, _______
#define _________________PT_COMBO_L3___________________ _______, _______, _______, _______, _______

// PT_COMBO Layer - Right Hand
#define _________________PT_COMBO_R1___________________ _______, _______, PT_CAO     , _______, _______
#define _________________PT_COMBO_R2___________________ _______, _______, PT_CA_TILDE, PT_COES, _______
#define _________________PT_COMBO_R3___________________ _______, PT_C_CEDILLA, _______, _______, _______

// =============================================================================
// THUMB CLUSTER BLOCKS - Universal 3-key clusters
// Keyboards with more thumbs add extra keys directly in their layouts
// =============================================================================

// Alpha Layer Thumbs (Left: Media/Esc, Nav/Space, Mouse/Tab | Right: Sym/Bksp, Num/Enter, Fun/Del)
#define ________________ALPHA_THUMBS_L_________________ MED_ESC, NAV_SPC, MSE_TAB
#define ________________ALPHA_THUMBS_R_________________ SYM_BSP, NUM_ENT, FUN_DEL

// Nav Layer Thumbs
#define ________________NAV_THUMBS_L___________________ _______, _______, _______
#define ________________NAV_THUMBS_R___________________ _______, _______, _______

// Mouse Layer Thumbs (Right click, Left click, Middle click)
#define _______________MOUSE_THUMBS_L__________________ _______, _______, _______
#define _______________MOUSE_THUMBS_R__________________ KC_BTN2, KC_BTN1, KC_BTN3

// Media Layer Thumbs
#define _______________MEDIA_THUMBS_L__________________ _______, _______, _______
#define _______________MEDIA_THUMBS_R__________________ KC_MSTP, KC_MPLY, KC_MUTE

// Num Layer Thumbs (0 is closer to numbers)
#define ________________NUM_THUMBS_L___________________ KC_0   , KC_DOT , KC_MINS
#define ________________NUM_THUMBS_R___________________ _______, _______, _______

// Sym Layer Thumbs
#define ________________SYM_THUMBS_L___________________ KC_LPRN, KC_RPRN, KC_UNDS
#define ________________SYM_THUMBS_R___________________ _______, _______, _______

// Fun Layer Thumbs
#define ________________FUN_THUMBS_L___________________ KC_APP , KC_SPC , KC_TAB
#define ________________FUN_THUMBS_R___________________ _______, _______, _______

// PT Layer Thumbs
#define _________________PT_THUMBS_L___________________ _______, _______, _______
#define _________________PT_THUMBS_R___________________ _______, _______, _______

// PT_COMBO Layer Thumbs
#define ______________PT_COMBO_THUMBS_L________________ _______, _______, _______
#define ______________PT_COMBO_THUMBS_R________________ _______, _______, _______

