#ifndef __DISPLAY_H__
#define __DISPLAY_H__

// Includes
#include "types.h"

// Types
enum {
    PRINT_COLOUR_BLACK = 0,
    PRINT_COLOUR_BLUE = 1,
    PRINT_COLOUR_GREEN = 2,
    PRINT_COLOUR_CYAN = 3,
    PRINT_COLOUR_RED = 4,
    PRINT_COLOUR_MAGENTA = 5,
    PRINT_COLOUR_BROWN = 6,
    PRINT_COLOUR_LIGHT_GREY = 7,
    PRINT_COLOUR_DARK_GREY = 8,
    PRINT_COLOUR_LIGHT_BLUE = 9,
    PRINT_COLOUR_LIGHT_GREEN = 10,
    PRINT_COLOUR_LIGHT_CYAN = 11,
    PRINT_COLOUR_LIGHT_RED = 12,
    PRINT_COLOUR_PINK = 13,
    PRINT_COLOUR_YELLOW = 14,
    PRINT_COLOUR_WHITE = 15,
};

struct Char {
    uint8_t character;
    uint8_t colour;
};

// Declerations
void print_clear();
void print_char(char c);
void print_str(char* s);
void print_set_colour(uint8_t foreground, uint8_t background);
void set_char_at(uint8_t x, uint8_t y, char c);
void print_str_at(uint8_t x, uint8_t y, char* str);

#endif
