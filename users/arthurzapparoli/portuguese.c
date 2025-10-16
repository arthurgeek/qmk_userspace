// Copyright 2024 Arthur Zapparoli
// SPDX-License-Identifier: GPL-2.0-or-later

#include "portuguese.h"

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

// Handle Portuguese keycodes
bool process_portuguese(uint16_t keycode, keyrecord_t *record) {
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

        default:
            return true;  // Process all other keycodes normally
    }
}

