#include "display.h"

void kernel_main()
{
    print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_WHITE);
    print_clear();
    print_str(" AltOS Version 0.0.1");
}
