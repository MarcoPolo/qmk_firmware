// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _Layer_m 3
//#define _Layer_y 4
#define _Layer_com 4
#define _Layer_ent 5
//#define _Layer_hk 6
#define _Layer_mcom 6

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_q_tab = 1
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
  [TD_q_tab]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,       KC_U,    KC_I,    KC_O,    KC_P   ,
    KC_A, KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LCTL,  KC_LSFT, LCTL_T(KC_BSPC),  LGUI_T(KC_TAB), LCTL_T(KC_ENT), KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_LALT
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
  [_RS] = LAYOUT( 
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                 MO(_Layer_y), KC_7,      KC_8, KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                  MO(_Layer_h), KC_4,      KC_5, KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                 KC_GRV,       KC_1,      KC_2, KC_3, KC_BSLS ,
    TG(_LW), KC_INS,  KC_LCTL, KC_LSFT, KC_BSPC, KC_LGUI, KC_SPC, KC_LALT,      KC_TRNS,   KC_0,  KC_DOT, KC_EQL  ),

   */

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_1, KC_2,   KC_3,   KC_4, KC_5,                            KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_DLR,                  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSLS,
    KC_LCBR, KC_RCBR, KC_LCBR, KC_RCBR, KC_EQL,                 KC_GRV,       MO(_Layer_m),      MO(_Layer_com), KC_DOT, KC_SLSH,
    LALT(KC_LCTL), KC_INS,  KC_LCTL, KC_LSFT, LCTL_T(KC_BSPC), KC_LGUI, LCTL_T(KC_ENT), KC_LALT,      KC_TRNS,   KC_0,  KC_EQL, KC_LALT  ),

  [_Layer_m] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_ENT, KC_ENT,                         KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), LGUI(LSFT(KC_TAB)),  LGUI(KC_TAB), KC_DLR,                         KC_TRNS, LCTL(KC_LALT),   MO(_Layer_mcom),   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, RESET,                          KC_GRV,  KC_1,    KC_2,   KC_VOLD, KC_VOLU ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, LCTL(KC_LALT), KC_LCTL, KC_SPC, KC_LALT,  KC_TRNS, KC_0, KC_SLCK, KC_PAUS  ),

  [_Layer_mcom] = LAYOUT(
    KC_EXLM, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_ENT,                         KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_MS_L, KC_MS_D, KC_MS_R, KC_DLR,                         KC_TRNS, LCTL(KC_LALT),    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, RESET,                          KC_GRV,  KC_1,    KC_2,    KC_VOLD, KC_VOLU ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, LCTL(KC_LALT), KC_LCTL, KC_SPC, KC_LALT,  KC_TRNS, KC_0, KC_SLCK, KC_PAUS  ),

  [_Layer_com] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_ENT, KC_ENT,                         KC_TRNS, KC_LGUI, KC_LCTL, KC_9, KC_ASTR ,
    KC_TAB, LSFT(KC_TAB), KC_DOWN, KC_RGHT, KC_DLR,                     KC_TRNS, KC_4,    KC_5,    KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, RESET,                          KC_GRV,  KC_1,    KC_2,    KC_3, KC_BSLS ,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, LCTL(KC_LALT), KC_LCTL, KC_SPC, KC_LALT, KC_TRNS, KC_LGUI,    KC_DOT, KC_EQL  ),

  [_Layer_ent] = LAYOUT(
    KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,            KC_NO, KC_NO, KC_I,   KC_NO, KC_NO,
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,                KC_NO,  KC_NO,    KC_NO,   KC_NO, KC_NO,
    KC_ESC, KC_TAB, KC_LCTL,  KC_LALT, KC_LGUI,  KC_LGUI, KC_TRNS, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_NO
    ),


  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
