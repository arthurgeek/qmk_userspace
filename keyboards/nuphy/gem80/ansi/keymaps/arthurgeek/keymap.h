#pragma once

enum layers {
    _QWERTY,
    _COLEMAK,
    _GALLIUM,
    _FN,
    _TOP_RGB,
    _NP_RGB,
};

#define TOP_RGB MO(_TOP_RGB)
#define NP_RGB MO(_NP_RGB)
#define MAC_PRTA G(S(KC_4))
#define MAC_PRTO G(S(KC_5))
#define MAC_LOCK G(C(KC_Q))
#define WM_LEFT HYPR(KC_LEFT)
#define WM_UP HYPR(KC_UP)
#define WM_RGHT HYPR(KC_RGHT)
