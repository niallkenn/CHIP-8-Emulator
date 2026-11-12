#include "instructions.h"
#include "graphics.h"

void _00E0(void) {
    for (int i = 0; i < 64 * 32; i++) Buffer[i] = 0;

    fill_canvas(canvas, 0);
}

void _00EE(void) {
    PC = Stack[SP];

    SP--;
}

void _1nnn(uint16_t nnn) {
    PC = nnn & 0xFFF;
}

void _2nnn(uint16_t nnn) {
    SP++;

    Stack[SP] = PC;

    PC = nnn & 0xFFF;
}