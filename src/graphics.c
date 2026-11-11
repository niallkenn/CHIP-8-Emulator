#include "graphics.h"

Canvas* canvas;

void initialise_graphics(void) {
    canvas = create_canvas(640, 320);
}