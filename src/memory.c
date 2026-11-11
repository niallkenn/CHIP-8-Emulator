#include "memory.h"

// initialise
uint8_t RAM[4096];
// 8 bit registers
uint8_t V[16];
// Index register, 16bit
uint16_t I;
// program counter, stores next instruction address
uint16_t PC;
// Stack pointer, points at top of stack
uint8_t SP;
// Stack , 16 16bit values only used to store addresses to return to after subroutine. ONLY ALLOWS 16 LEVELS OF NESTING
uint16_t Stack[16];
// Screen, pixel buffer 64*32
uint8_t Buffer[64*32];
// counters
uint8_t delayTimer;
uint8_t soundTimer;

void initialise_memory(void) {
    for (int i = 0; i < 4096; i++) RAM[i] = 0;
    for (int i = 0; i < 16; i++) {
        V[i] = 0;
        Stack[i] = 0;
    }
    PC = PROGRAM_BASE;
    SP = 0;
    for (int i = 0; i < 64*32; i++) Buffer[i] = 0;
    delayTimer = 0;
    soundTimer = 0;

    // "0"
    RAM[0] = 0xF0;
    RAM[1] = 0x90;
    RAM[2] = 0x90;
    RAM[3] = 0x90;
    RAM[4] = 0xF0;

    // "1"
    RAM[5] = 0x20;
    RAM[6] = 0x60;
    RAM[7] = 0x20;
    RAM[8] = 0x20;
    RAM[9] = 0x70;

    // "2"
    RAM[10] = 0xF0;
    RAM[11] = 0x10;
    RAM[12] = 0xF0;
    RAM[13] = 0x80;
    RAM[14] = 0xF0;

    // "3"
    RAM[15] = 0xF0;
    RAM[16] = 0x10;
    RAM[17] = 0xF0;
    RAM[18] = 0x10;
    RAM[19] = 0xF0;

    // "4"
    RAM[20] = 0x90;
    RAM[21] = 0x90;
    RAM[22] = 0xF0;
    RAM[23] = 0x10;
    RAM[24] = 0x10;

    // "5"
    RAM[25] = 0xF0;
    RAM[26] = 0x80;
    RAM[27] = 0xF0;
    RAM[28] = 0x10;
    RAM[29] = 0xF0;

    // "6"
    RAM[30] = 0xF0;
    RAM[31] = 0x80;
    RAM[32] = 0xF0;
    RAM[33] = 0x90;
    RAM[34] = 0xF0;

    // "7"
    RAM[35] = 0xF0;
    RAM[36] = 0x10;
    RAM[37] = 0x20;
    RAM[38] = 0x40;
    RAM[39] = 0x40;

    // "8"
    RAM[40] = 0xF0;
    RAM[41] = 0x90;
    RAM[42] = 0xF0;
    RAM[43] = 0x90;
    RAM[44] = 0xF0;

    // "9"
    RAM[45] = 0xF0;
    RAM[46] = 0x90;
    RAM[47] = 0xF0;
    RAM[48] = 0x10;
    RAM[49] = 0xF0;

    // "A"
    RAM[50] = 0xF0;
    RAM[51] = 0x90;
    RAM[52] = 0xF0;
    RAM[53] = 0x90;
    RAM[54] = 0x90;

    // "B"
    RAM[55] = 0xE0;
    RAM[56] = 0x90;
    RAM[57] = 0xE0;
    RAM[58] = 0x90;
    RAM[59] = 0xE0;

    // "C"
    RAM[60] = 0xF0;
    RAM[61] = 0x80;
    RAM[62] = 0x80;
    RAM[63] = 0x80;
    RAM[64] = 0xF0;

    // "D"
    RAM[65] = 0xE0;
    RAM[66] = 0x90;
    RAM[67] = 0x90;
    RAM[68] = 0x90;
    RAM[69] = 0xE0;

    // "E"
    RAM[70] = 0xF0;
    RAM[71] = 0x80;
    RAM[72] = 0xF0;
    RAM[73] = 0x80;
    RAM[74] = 0xF0;

    // "F"
    RAM[75] = 0xF0;
    RAM[76] = 0x80;
    RAM[77] = 0xF0;
    RAM[78] = 0x80;
    RAM[79] = 0x80;
}