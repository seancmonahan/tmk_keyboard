#include "keymap_common.h"

/* TODO:
 * Vi cursor mode?
 *   decide where pageup/down home/end go
 * Caps -> Backspace
 * Space+Caps -> Delete OR Toggle Caps??
 * Shift (either) + Esc -> Tilde
 * Other layouts
 *   Figure out alt layout selector
 * Mouse layer
 *   How to lock/unlock
 *   which are mouse buttons?
 * How do I allow extra base-layers to be macro'd out?
 *   And keep track of layer nums
 *   CHECK IF ACTION_LAYER_MODS can take computed values?
 */

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer (Qwerty)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Backsp|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Fn1    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Fn1        |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |      Space (Fn0)       |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        BSCP,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        FN1, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          FN1,  \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,APP, RCTL),
    
    /* Keymap 1: Colemak */
    [1] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,     ENT,  \
        FN1, Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,          FN1, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,APP, RCTL),
    /* Keymap 2: dvorak */
    [2] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC, \
        TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS, \
        BSPC,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,     ENT,  \
        FN1, SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,             FN1, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,APP, RCTL),
    /* Keymap 3: workman */
    [3] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,     ENT,  \
        FN1, Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,          FN1, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,APP, RCTL),

    [4] = KEYMAP_ANSI(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
    
    /* Overlay 5: SpaceFN
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [5] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \
        TRNS,TRNS,TRNS,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
};
