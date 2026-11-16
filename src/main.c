#include "memory.h"
#include "graphics.h"
#include "instructions.h"
#include "cpu.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(void) {
    initialise_memory();
    initialise_graphics();

    srand(time(NULL));

    while (PC < ROM_Size + 0x200) {
        //update_canvas(canvas);
        decode_and_excecute(fetch());
        PC += 2;
    }

    return 0;
}