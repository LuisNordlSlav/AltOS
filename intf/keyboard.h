#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "types.h"

enum KEYCODES {

    __MAX__
};

struct KeyState {
    enum KEYCODES code;
    uint8_t is_pressed;
    uint64_t timestamp;
};

#endif