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
 *   It can't... macros it is!
 */

/*
 * SpaceMau5
 * built on top of SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */

// TODO:
#define GRV_IS_ESC
#define APP_IS_LAYER_FN
//#define CAPS_IS_BACKSPACE
//#define VI_KEYS

// TODO: MACROTIZE THE SHIT OUT OF THIS EVEN MORE
// At least one of the following should remain uncommented!
#define QWERTY_ENABLE
#define COLEMAK_ENABLE
#define DVORAK_ENABLE
#define WORKMAN_ENABLE

#ifdef QWERTY_ENABLE
#define QWERTY_LAYER 0
#else
#define QWERTY_LAYER -1
#endif

#ifdef COLEMAK_ENABLE
#define COLEMAK_LAYER ( QWERTY_LAYER + 1 )
#else
#define COLEMAK_LAYER ( QWERTY_LAYER )
#endif

#ifdef DVORAK_ENABLE
#define DVORAK_LAYER ( COLEMAK_LAYER + 1 )
#else
#define DVORAK_LAYER ( COLEMAK_LAYER )
#endif

#ifdef WORKMAN_ENABLE
#define WORKMAN_LAYER ( DVORAK_LAYER + 1 )
#else
#define WORKMAN_LAYER ( DVORAK_LAYER )
#endif

#ifdef GRV_IS_ESC
#define GRV_LAYER ( WORKMAN_LAYER + 1 )
#else
#define GRV_LAYER ( WORKMAN_LAYER )
#endif

#define SPACEFN_LAYER ( GRV_LAYER + 1 )
#define LAYOUT_LAYER ( SPACEFN_LAYER + 1 )

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer (Qwerty)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Backsp|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Fn1    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Fn2        |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |      Space (Fn0)       |Alt |Gui |Fn3 |Ctrl|
     * `-----------------------------------------------------------'
     */
#ifdef QWERTY_ENABLE
    [QWERTY_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        BSPC,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,  \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,FN3, RCTL),
#endif
    
#ifdef COLEMAK_ENABLE
    [COLEMAK_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,     ENT,  \
        FN1, Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,          FN2, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,FN3, RCTL),
#endif

#ifdef DVORAK_ENABLE
    [DVORAK_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC, \
        TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS, \
        BSPC,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,     ENT,  \
        FN1, SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,             FN2, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,FN3, RCTL),
#endif

#ifdef WORKMAN_ENABLE
    [WORKMAN_LAYER] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSLS, \
        BSPC,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,     ENT,  \
        FN1, Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,          FN2, \
        LCTL,LGUI,LALT,          FN0,                     RALT,RGUI,FN3, RCTL),
#endif

#ifdef GRV_IS_ESC
    [GRV_LAYER] = KEYMAP_ANSI(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
#endif
    
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
    [SPACEFN_LAYER] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \
        TRNS,TRNS,TRNS,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),

    [LAYOUT_LAYER] = KEYMAP_ANSI(
	FN4, FN5, FN6, FN7, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
	TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
	TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
	TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
	TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(SPACEFN_LAYER, KC_SPACE),
    [1] = ACTION_LAYER_MODS(GRV_LAYER, MOD_LSFT), // tilde
    [2] = ACTION_LAYER_MODS(GRV_LAYER, MOD_RSFT),
    [3] = ACTION_LAYER_MOMENTARY(LAYOUT_LAYER),
    [4] = ACTION_DEFAULT_LAYER_SET(0),
    [5] = ACTION_DEFAULT_LAYER_SET(1),
    [6] = ACTION_DEFAULT_LAYER_SET(2),
    [7] = ACTION_DEFAULT_LAYER_SET(3),
};
