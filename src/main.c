#include "memory.h"
#include "graphics.h"
#include "instructions.h"
#include "cpu.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "keyboard.h"

int main(void) {
    int option;
    char rom[51];

    do {
        printf("1. Select ROM\n2. List ROMs\n");

        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n');
            option = 0;
        }

        switch (option) {
            case 1:
                scanf("%50s", rom);
                break;

            case 2:
                printf("\n");
                system("ls -1 roms/*.ch8 2>/dev/null | xargs -n 1 basename");
                printf("\n");
                break;

            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (option != 1);

    initialise_memory(rom);
    initialise_graphics();

    srand(time(NULL));

    while (1) {
        // 10 clock cycles, per frame
        for (int i = 0; i < 10; i++) {
            uint16_t instruction = fetch();
            PC += 2;
            decode_and_excecute(instruction);
        }

        if (delayTimer > 0) delayTimer--;
        if (soundTimer > 0) soundTimer--;

        update_canvas(canvas);
        if (draw_flag == 1) {
            update_screen();
            draw_flag = 0;
        }

        handle_keys();

        usleep(16666); //  60 fps
    }

    return 0;
}