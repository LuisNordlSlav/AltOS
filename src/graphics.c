#include "graphics.h"

void draw_box(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y) {
    set_char_at(start_x, start_y, 218);
    set_char_at(start_x, end_y, 192);
    set_char_at(end_x, end_y, 217);
    set_char_at(end_x, start_y, 191);
    horizontal_line(start_x, start_y + 1, end_y - start_y - 1);
    horizontal_line(end_x, start_y + 1, end_y - start_y - 1);

    verticle_line(start_x + 1, start_y, end_x - start_x - 1);
    verticle_line(start_x + 1, end_y, end_x - start_x - 1);
}

void horizontal_line(uint8_t x, uint8_t y, uint8_t h) {
    for (int offset = 0; offset < h; offset++) {
        set_char_at(x, y + offset, 179);
    }
}

void verticle_line(uint8_t x, uint8_t y, uint8_t w) {
    for (int offset = 0; offset < w; offset++) {
        set_char_at(x + offset, y, 196);
    }
}

