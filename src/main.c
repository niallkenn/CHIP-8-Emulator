#include "memory.h"
#include "graphics.h"
#include "instructions.h"
#include <unistd.h>
#include <time.h>

int main(void) {
    initialise_memory();
    initialise_graphics();

    srand(time(NULL));

    while(1) update_canvas(canvas);

    return 0;
}