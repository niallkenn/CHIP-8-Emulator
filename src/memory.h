#ifndef MEM_H
#define MEM_H

#include <stdint.h>

// Start of all programs
#define PROGRAM_BASE 0x200

// 4Kb RAM
extern uint8_t RAM[4096];
// 8 bit registers
extern uint8_t V[16];
// Index register, 16bit
extern uint16_t I;
// program counter, stores next instruction address
extern uint16_t PC;
// Stack pointer, points at top of stack
extern uint8_t SP;
// Stack , 16 16bit values only used to store addresses to return to after subroutine. ONLY ALLOWS 16 LEVELS OF NESTING
extern uint16_t Stack[16];
// Screen, pixel buffer 64*32
extern uint8_t Screen[64*32];
// counters
extern uint8_t delayTimer;
extern uint8_t soundTimer;

void initialise_memory(void);

#endif // MEM_H