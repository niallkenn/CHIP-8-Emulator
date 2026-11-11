#include "instructions.h"
#include "graphics.h"

void _00E0(void) {
    for (int i = 0; i < 64 * 32; i++) Buffer[i] = 0;

    fill_canvas(canvas, 0);
}