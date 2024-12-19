// These functions suck and are old but sue them for inspiration if you want to

// distance of image from the left side of the screen
#define OFFSET 0
// set frequency for delays
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

#define PAGES 8
#define COLUMNS 128
void writeDrawing() {
    for (int i = 0; i < PAGES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            int index = i * COLUMNS + j;
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