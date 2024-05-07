#include "macros.h"
#include "quantum.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case BRACES: // Types [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);

                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("<>");
                } else {
                    SEND_STRING("[]");
                }

                tap_code(KC_LEFT);   // Move cursor between braces.
                register_mods(mods); // Restore mods.
            }
            return false;

        case SELWORD: // Selects the current word under the cursor.
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
            }
            return false;

        case SELLINE: // Selects the current line.
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a" SS_LSFT("e")));
            }
            return false;

        case SRCHSEL: // Searches the current selection in a new tab.
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("ct") SS_DELAY(100) SS_LGUI("v") SS_TAP(X_ENTER));
            }
            return false;

        case JOINLN: // Join lines like Vim's `J` command.
            if (record->event.pressed) {
                SEND_STRING( // Go to the end of the line and tap delete.
                    SS_TAP(X_END) SS_TAP(X_DEL)
                    // In case this has joined two words together, insert one space.
                    SS_TAP(X_SPC) SS_LALT(
                        // Go to the beginning of the next word.
                        SS_TAP(X_RGHT) SS_TAP(X_LEFT)
                        // Select back to the end of the previous word. This should select
                        // all spaces and tabs between the joined lines from indentation
                        // or trailing whitespace, including the space inserted earlier.
                        SS_LSFT(SS_TAP(X_LEFT) SS_TAP(X_RGHT)))
                    // Replace the selection with a single space.
                    SS_TAP(X_SPC));
            }
            return false;
    }

    return true;
}
