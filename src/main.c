#include "display.h"
#include "graphics.h"

void int_to_string(int num, char *str) {
    int i = 0, sign = 0;
    
    // Handle negative numbers
    if (num < 0) {
        sign = 1;
        num = -num;
    }

    // Convert digits to characters
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    // Add sign if negative
    if (sign) {
        str[i++] = '-';
    }

    // Add null terminator
    str[i] = '\0';

    // Reverse the string
    int len = i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void kernel_main()
{
    print_set_colour(PRINT_COLOUR_BLACK, PRINT_COLOUR_WHITE);
    print_clear();
    print_str("    AltOS Version 0.0.1\n\n");

    #define COUNT 1000000
    char thing[10];
    for (int x = 0; x < COUNT * 100; x++) {
        if ((x % COUNT) == 0) {
            int_to_string(x / COUNT, &thing);
            print_str(&thing);
            if (x % (5 * COUNT) == 0)
                print_str("\n");
        }
    }
    

    // int R = 175;
    // for (int c = R; c < R + 24; c++) {
    //     int_to_string(c, &thing);
    //     print_str(&thing);
    //     print_str(" : ");
    //     print_char(c);
    //     print_char('\n');
    // }
    draw_box(20, 10, 30, 20);
}
