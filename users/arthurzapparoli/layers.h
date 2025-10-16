// Copyright 2024 Arthur Zapparoli
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

enum layers {
    _GALLIUM = 0,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _PT,
    _PT_COMBO,
    _LAYER_COUNT  // Sentinel: keyboards can add custom layers starting from this value
};

// Common layer-tap and momentary layer aliases (matching thumb layout)
#define MED_ESC  LT(_MEDIA, KC_ESC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MSE_TAB  LT(_MOUSE, KC_TAB)
#define SYM_BSP  LT(_SYM, KC_BSPC)
#define NUM_ENT  LT(_NUM, KC_ENT)
#define FUN_DEL  LT(_FUN, KC_DEL)
#define PT_COMBO OSL(_PT_COMBO)

