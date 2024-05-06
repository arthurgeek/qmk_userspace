#include "ansi.h"
#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _FN,
    _TOP_RGB,
    _NP_RGB,
};

// clang-format off

#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define TOP_RGB  MO(_TOP_RGB)
#define NP_RGB   MO(_NP_RGB)
#define MAC_PRTA G(S(KC_4))
#define MAC_PRTO G(S(KC_5))
#define MAC_LOCK G(C(KC_Q))
#define WM_LEFT  HYPR(KC_LEFT)
#define WM_UP    HYPR(KC_UP)
#define WM_RGHT  HYPR(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_tkl_ansi(
	KC_ESC,       KC_BRMD,  KC_BRMU,  MAC_TASK, MAC_SEARCH, MAC_VOICE, MAC_DND, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,   KC_VOLU,    COLEMAK,     MAC_PRTA,          MAC_PRTO,            MAC_LOCK,
	KC_GRV,       KC_1,     KC_2,     KC_3,     KC_4,       KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,     KC_BSPC,     WM_LEFT,           WM_UP,               WM_RGHT,
	KC_TAB,       KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,   KC_RBRC,    KC_BSLS,     KC_HOME,           KC_END,              MAC_GLOBE,
	KC_CAPS,      KC_A,     KC_S,     KC_D,     KC_F,       KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   KC_ENT,
	KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                                               KC_UP,
	KC_LCTL,      KC_LOPT,  KC_LCMD,                                   KC_SPC,                             KC_RCMD, KC_ROPT,   MO(_FN),    KC_RCTL,     KC_LEFT,           KC_DOWN,             KC_RGHT),

[_COLEMAK] = LAYOUT_tkl_ansi(
	_______,      _______,  _______,  _______,  _______,    _______,   _______, _______, _______, _______, _______, _______,   _______,    QWERTY,      _______,           _______,             _______,
	_______,      _______,  _______,  _______,  _______,    _______,   _______, KC_BSLS, KC_7,    KC_8,    KC_9,    KC_0,      _______,    _______,     _______,           _______,             _______,
	_______,      KC_Q,     KC_W,     KC_F,     KC_P,       KC_B,      KC_LBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,   KC_MINS,    KC_SCLN,     _______,           _______,             _______,
	_______,      KC_A,     KC_R,     KC_S,     KC_T,       KC_G,      KC_RBRC, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,      _______,
	_______,      KC_X,     KC_C,     KC_D,     KC_V,       KC_Z,      KC_SLSH, KC_K,    KC_H,    KC_COMM, KC_DOT,  _______,                                               _______,
	_______,      _______,  _______,                                   _______,                            _______, _______,   _______,    _______,     _______,           _______,             _______),

[_FN] = LAYOUT_tkl_ansi(
	_______,      KC_F1,    KC_F2,    KC_F3,    KC_F4,      KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,     KC_F13,      _______,           MAC_PRT,             _______,
	_______,      LNK_BLE1, LNK_BLE2, LNK_BLE3, LNK_RF,     _______,   _______, _______, _______, _______, _______, _______,   _______,    TOG_USB_SLP, SLEEP_TIMEOUT_INC, DEBOUNCE_PRESS_SHOW, DEBOUNCE_PRESS_INC,
	_______,      _______,  _______,  _______,  _______,    _______,   _______, _______, _______, _______, _______, DEV_RESET, SLEEP_MODE, BAT_SHOW,    SLEEP_TIMEOUT_DEC, SLEEP_TIMEOUT_SHOW,  DEBOUNCE_PRESS_DEC,
	TOG_CAPS_IND, _______,  _______,  _______,  _______,    _______,   _______, _______, _______, _______, _______, _______,   _______,
	_______,      _______,  _______,  _______,  _______,    _______,   NP_RGB,  TOP_RGB, RGB_SPD, RGB_SPI, _______, _______,                                               RGB_VAI,
	_______,      _______,  _______,                                   _______,                            _______, _______,   _______,    _______,     RGB_MOD,           RGB_VAD,             RGB_HUI),

[_TOP_RGB] = LAYOUT_tkl_ansi(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, SIDE_SPD, SIDE_SPI, _______,                             SIDE_VAI,
	_______, _______, _______, _______,                            _______,                              _______, _______, _______, SIDE_MOD, SIDE_VAD, SIDE_HUI),

[_NP_RGB] = LAYOUT_tkl_ansi(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______,  _______,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, LOGO_SPD, LOGO_SPI, _______,                             LOGO_VAI,
	_______, _______, _______, _______,                            _______,                              _______, _______, _______, LOGO_MOD, LOGO_VAD, LOGO_HUI),
};

// clang-format on

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
