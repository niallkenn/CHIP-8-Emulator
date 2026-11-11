#include "memory.h"
#include "graphics.h"
#include "instructions.h"
#include <unistd.h>

int main(void) {
    initialise_memory();
    initialise_graphics();

    while(1) update_canvas(canvas);

    return 0;
}