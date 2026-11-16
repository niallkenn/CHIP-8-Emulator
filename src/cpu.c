#include <stdio.h>
#include "cpu.h"
#include "instructions.h"
#include "memory.h"

uint16_t fetch(void) {
    uint16_t instruction = 0;

    // big endian
    instruction = RAM[PC + 1]; // second byte
    instruction |= (RAM[PC] << 8) & 0xFF00; // first byte

    return instruction;
}

void decode_and_excecute(uint16_t instruction) {
    uint8_t b1 = (instruction >> 8) & 0xFF;
    uint8_t b2 = instruction & 0xFF;

    switch ((b1 >> 4) & 0xF) {
        case 0x0:
            if (instruction == 0x00EE) _00EE();
            else _00E0();
            break;
        
        case 0x1:
            _1nnn(instruction & 0xFFF);
            break;
        
        
        default:
            exit(1);
    }
}

