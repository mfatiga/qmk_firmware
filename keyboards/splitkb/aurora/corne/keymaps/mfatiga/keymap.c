#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(
        KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_ESC  ,
        KC_LCTL , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    , KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_LALT ,
                                      MO(1)   , KC_BSPC , KC_SPC  , KC_ENT  , MO(2)   , KC_LGUI
    ),
	[1] = LAYOUT_split_3x6_3(
        KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSLS ,
        KC_LCTL , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_TILD , KC_PLUS , KC_EQL  , KC_LBRC , KC_RBRC , KC_PIPE ,
        KC_LSFT , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_GRV  , KC_MINS , KC_UNDS , KC_LCBR , KC_RCBR , KC_LALT ,
                                      _______ , KC_LALT , KC_SPC  , KC_ENT  , MO(3)   , KC_LGUI
    ),
	[2] = LAYOUT_split_3x6_3(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        KC_LCTL , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, XXXXXXX , XXXXXXX ,
        KC_LSFT , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL  , KC_LEFT , KC_DOWN , KC_RIGHT, XXXXXXX , XXXXXXX ,
                                      MO(3)   , KC_BSPC , KC_SPC  , KC_ENT  , _______ , KC_LGUI
    ),
	[3] = LAYOUT_split_3x6_3(
        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT ,
        RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
        RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                      _______ , KC_BSPC , KC_SPC  , KC_ENT  , _______ , KC_LGUI
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
