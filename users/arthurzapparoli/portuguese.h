// Copyright 2024 Arthur Zapparoli
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

// Custom keycodes for Portuguese characters using dead keys
enum portuguese_keycodes {
    PT_A_TILDE = SAFE_RANGE,  // ã: KC_TILD + KC_A
    PT_A_ACUTE,                // á: KC_QUOT + KC_A
    PT_A_GRAVE,                // à: KC_GRV + KC_A
    PT_A_CIRC,                 // â: KC_CIRC + KC_A
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
    PT_QU,                     // qu
    PT_SAFE_RANGE              // Use this for any keyboard-specific custom keycodes
};

// Function to handle Portuguese keycodes
bool process_portuguese(uint16_t keycode, keyrecord_t *record);

