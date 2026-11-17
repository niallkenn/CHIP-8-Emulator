#include "graphics.h"
#include "memory.h"

Canvas* canvas;

void initialise_graphics(void) {
    canvas = create_canvas(640, 320);

    XSelectInput(canvas->display, canvas->window, ExposureMask | KeyPressMask | KeyReleaseMask);
}

void update_screen(void) {
    fill_canvas(canvas, 0);
    for (int i = 0; i < sizeof(Buffer); i++) {
        if (Buffer[i] == 1) {
            int row = i / 64;
            int col = i % 64;

            draw_rect(canvas, col * 10, row * 10, (col * 10) + 10, (row * 10) + 10, 0xFFFFFF);
        }
    }
}