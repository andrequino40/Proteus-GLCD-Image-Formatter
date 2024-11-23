// distance of 64x64 image from left side (maximum 64)
#define OFFSET 32
// set frequency for delays
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

#include "drawing.h"

void writeDrawing() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 64; ++j) {
            int index = i * 64 + j;
            writeByte(i, OFFSET + j, drawing[index]);
        }
    }
}

void loop(char scroll_up, int num_loops){
    char increment;
    int start;
    if (scroll_up) {
        increment = 1;
        start = 0;
    } else {
        increment = -1;
        start = 63;
    }
    
    int loop = 0;
    int num_line = start;
    while (loop < num_loops) {
        setStartLine(num_line); 
        __delay_ms(25);
        num_line+= increment;
        
        char next_loop;
        next_loop = (scroll_up) ? (num_line > 63) : (num_line < 0);
        if (next_loop) {
            loop++;
            num_line = start;
        }
    }
}

void animateDrawing() {
    while(1) {
            loop(1, 3);
            __delay_ms(1000);
            loop(0, 3);
            __delay_ms(1000);
    }
}