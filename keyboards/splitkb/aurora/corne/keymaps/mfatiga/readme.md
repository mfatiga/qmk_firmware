# Keymap
_This keymap is a copy of the default splitkb corne layout, with disabled rgb underglow and modified keymap._

Generated from keymap.json, disabled power led on the liatris controller.

# Config and compile

Install QMK tool and setup according to the [docs](https://docs.qmk.fm/).

Configure default keyboard and keymap:
```sh
qmk config user.keyboard=splitkb/aurora/corne
qmk config user.keymap=mfatiga
```

Compile configured (for Liatris controller):
```sh
qmk compile -e CONVERT_TO=liatris
```

Compile other (for Liatris controller):
```sh
qmk compile -e CONVERT_TO=liatris -kb splitkb/aurora/corne -km mfatiga
```

# Flashing
 - put into bootloader mode
 - mount new device
 - copy compiled firmware (found inside `~/qmk_firmware/`) to mounted directory

# Liatris power LED
## Turning the power LED off

By default, the power LED will be turned on all the time. If you wish to turn it off completely, place the following code in your **keymap.c**:

```c
void keyboard_pre_init_user(void) {  
  // Set our LED pin as output  
  setPinOutput(24);  
  // Turn the LED off  
  // (Due to technical reasons, high is off and low is on)  
  writePinHigh(24);  
}
```

When the keyboard is plugged in, the LED will initially power on. As soon as QMK starts running, it'll be turned off.

## Use the LED for Caps Lock

To use the LED as a Caps Lock indicator, add the following code to your **config.h**:
```c
#define LED_CAPS_LOCK_PIN 24  
#define LED_PIN_ON_STATE 0
```

## Old keymap.json
```json
{
    "keyboard": "splitkb/aurora/corne/rev1",
    "keymap": "default",
    "version": 1,
    "layout": "LAYOUT_split_3x6_3",
    "layers": [
        [
            "KC_TAB"  , "KC_Q"    , "KC_W"    , "KC_F"    , "KC_P"    , "KC_B"    , "KC_J"    , "KC_L"    , "KC_U"    , "KC_Y"    , "KC_SCLN" , "KC_ESC"  ,
            "KC_LCTL" , "KC_A"    , "KC_R"    , "KC_S"    , "KC_T"    , "KC_G"    , "KC_M"    , "KC_N"    , "KC_E"    , "KC_I"    , "KC_O"    , "KC_QUOT" ,
            "KC_LSFT" , "KC_Z"    , "KC_X"    , "KC_C"    , "KC_D"    , "KC_V"    , "KC_K"    , "KC_H"    , "KC_COMM" , "KC_DOT"  , "KC_SLSH" , "KC_LALT" ,
                                                "MO(1)"   , "KC_BSPC" , "KC_SPC"  , "KC_ENT"  , "MO(2)"   , "KC_LGUI"
        ],
        [
            "KC_TAB"  , "KC_EXLM" , "KC_AT"   , "KC_HASH" , "KC_DLR"  , "KC_PERC" , "KC_CIRC" , "KC_AMPR" , "KC_ASTR" , "KC_LPRN" , "KC_RPRN" , "KC_BSLS" ,
            "KC_LCTL" , "KC_1"    , "KC_2"    , "KC_3"    , "KC_4"    , "KC_5"    , "KC_TILD" , "KC_PLUS" , "KC_EQL"  , "KC_LBRC" , "KC_RBRC" , "KC_PIPE" ,
            "KC_LSFT" , "KC_6"    , "KC_7"    , "KC_8"    , "KC_9"    , "KC_0"    , "KC_GRV"  , "KC_MINS" , "KC_UNDS" , "KC_LCBR" , "KC_RCBR" , "KC_LALT" ,
                                                "_______" , "KC_LALT" , "KC_SPC"  , "KC_ENT"  , "MO(3)"   , "KC_LGUI"
        ],
        [
            "KC_F1"   , "KC_F2"   , "KC_F3"   , "KC_F4"   , "KC_F5"   , "KC_F6"   , "KC_F7"   , "KC_F8"   , "KC_F9"   , "KC_F10"  , "KC_F11"  , "KC_F12"  ,
            "KC_LCTL" , "KC_1"    , "KC_2"    , "KC_3"    , "KC_4"    , "KC_5"    , "KC_LEFT" , "KC_DOWN" , "KC_UP"   , "KC_RIGHT", "XXXXXXX" , "XXXXXXX" ,
            "KC_LSFT" , "KC_6"    , "KC_7"    , "KC_8"    , "KC_9"    , "KC_0"    , "KC_DEL"  , "KC_LEFT" , "KC_DOWN" , "KC_RIGHT", "XXXXXXX" , "XXXXXXX" ,
                                                "MO(3)"   , "KC_BSPC" , "KC_SPC"  , "KC_ENT"  , "_______" , "KC_LGUI"
        ],
        [
            "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "QK_BOOT" ,
            "RGB_TOG" , "RGB_HUI" , "RGB_SAI" , "RGB_VAI" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" ,
            "RGB_MOD" , "RGB_HUD" , "RGB_SAD" , "RGB_VAD" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" , "XXXXXXX" ,
                                                "_______" , "KC_BSPC" , "KC_SPC"  , "KC_ENT"  , "_______" , "KC_LGUI"
        ]
    ],
    "config": {
        "features": {
            "oled": true,
            "rgb_matrix": true,
            "rgblight": false
        },
        "encoder": {
            "enabled": false
        },
        "rgblight": {
            "hue_steps": 8,
            "saturation_steps": 8,
            "brightness_steps": 8,
            "sleep": true
        }
    }
}
```
