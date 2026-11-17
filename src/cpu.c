#include "cpu.h"
#include "instructions.h"
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

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
            switch (b2) {
                case 0xE0:
                    _00E0();
                    break;

                case 0xEE:
                    _00EE();
                    break;
                
                default:
                                    printf("%02X\n", instruction);

                    exit(1);
            }

            break;
        
        case 0x1:
            _1nnn(instruction & 0xFFF);
            break;
        
        case 0x2:
            _2nnn(instruction & 0xFFF);
            break;

        case 0x3:
            _3xkk(b1 & 0xF, b2);
            break;
        
        case 0x4:
            _4xkk(b1 & 0xF, b2);
            break;

        case 0x5:
            _5xy0(b1 & 0xF, (b2 >> 4) & 0xF);
            break;

        case 0x6:
            _6xkk(b1 & 0xF, b2);
            break;

        case 0x7:
            _7xkk(b1 & 0xF, b2);
            break;

        case 0x8:
            switch (b2 & 0xF) {
                case 0x0:
                    _8xy0(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x1:
                    _8xy1(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x2:
                    _8xy2(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x3:
                    _8xy3(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x4:
                    _8xy4(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x5:
                    _8xy5(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x6:
                    _8xy6(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0x7:
                    _8xy7(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                case 0xE:
                    _8xyE(b1 & 0xF, (b2 >> 4) & 0xF);
                    break;

                default:
                                    printf("%02X\n", instruction);

                    exit(1);
            }    

            break;

        case 0x9:
            _9xy0(b1 & 0xF, (b2 >> 4) & 0xF);
            break;
        
        case 0xA:
            _Annn(instruction & 0xFFF);
            break;

        case 0xB:
            _Bnnn(instruction & 0xFFF);
            break;

        case 0xC:
            _Cxkk(b1 & 0xF, b2);
            break;

        case 0xD:
            _Dxyn(b1 & 0xF, (b2 >> 4) & 0xF, b2 & 0xF);
            break;

        case 0xE:
            switch (b2) {
                case 0x9E:
                    _Ex9E(b1 & 0xF);
                    break;

                case 0xA1:
                    _ExA1(b1 & 0xF);
                    break;

                default:
                    printf("%02X\n", instruction);
                    exit(1);
            }

            break;

        case 0xF:
            switch (b2) {
                case 0x07:
                    _Fx07(b1 & 0xF);
                    break;
                
                case 0x0A:
                    _Fx0A(b1 & 0xF);
                    break;

                case 0x15:
                    _Fx15(b1 & 0xF);
                    break;

                case 0x18:
                    _Fx18(b1 & 0xF);
                    break;

                case 0x1E:
                    _Fx1E(b1 & 0xF);
                    break;

                case 0x29:
                    _Fx29(b1 & 0xF);
                    break;

                case 0x33:
                    _Fx33(b1 & 0xF);
                    break;

                case 0x55:
                    _Fx55(b1 & 0xF);
                    break;

                case 0x65:
                    _Fx65(b1 & 0xF);
                    break;

                default:
                                    printf("%02X\n", instruction);

                    exit(1);
            }

            break;

        default:
                            printf("%02X\n", instruction);

            exit(1);
    }
}

