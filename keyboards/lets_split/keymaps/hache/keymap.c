#define TAPPING_TOGGLE 2

#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
 
extern keymap_config_t keymap_config;
 
#define _A 0
#define _B 1
#define _C 2
#define _D 3
 
enum custom_keycodes {
  A = SAFE_RANGE,
  B,
  C,
  D,
};
 
#define _______ KC_TRNS
#define XXXXXXX KC_NO
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
[_A] = KEYMAP( \
  KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A, KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_BSLS, \
  KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
  MO(_D),   M(0), KC_LGUI, KC_LALT, MO(_B), KC_SPC, KC_ENT, TG(_C), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT \
),
 
[_B] = KEYMAP( \
  KC_TILD, KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, KC_GRV,   KC_QUOT,  KC_CIRC, KC_DQUO, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_QUOT, \
  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, \
  _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
 
[_C] = KEYMAP( \
  _______, _______, _______, _______,  _______, _______, _______, KC_NLCK, KC_KP_7, KC_KP_8,   KC_KP_9, KC_KP_MINUS, \
  _______, _______, _______, _______,  _______, _______, _______, _______, KC_KP_4, KC_KP_5,   KC_KP_6, KC_KP_PLUS, \
  _______, _______, _______, _______,  _______, _______, _______, _______, KC_KP_1, KC_KP_2,   KC_KP_3, KC_KP_SLASH, \
  _______, _______, _______, _______,  _______, _______, _______, _______, KC_KP_0, KC_KP_DOT, KC_BSPC, KC_KP_ASTERISK \
),
 
[_D] =  KEYMAP( \
  RESET,   KC_INS,  KC_PGUP, KC_PSCR,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_7,   KC_8,    KC_9,    _______, \
  _______, KC_HOME, KC_PGDN, KC_END,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_4,   KC_5,    KC_6,    _______, \
  KC_CAPS, _______, KC_SLCK, KC_PAUSE, KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_1,   KC_2,    KC_3,    _______, \
  _______, _______, _______, _______,  _______,  _______, _______, _______, KC_0,   _______, _______, _______ \
) 
 
 
};
 
// Test macro M(0)
 
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0:
            if (record->event.pressed) {
                return MACRO( T(G), T(G), T(SPC), T(E), T(Z), END );
            }
            break;
    }
    return MACRO_NONE;
};