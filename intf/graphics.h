#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "display.h"
#include "types.h"

void draw_box(
    uint8_t start_x,
    uint8_t start_y,
    uint8_t end_x,
    uint8_t end_y
);

void horizontal_line(uint8_t x, uint8_t y, uint8_t h);
void verticle_line(uint8_t x, uint8_t y, uint8_t w);

#endif