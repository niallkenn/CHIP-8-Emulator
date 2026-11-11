#ifndef INS_H
#define INS_H

#include "memory.h"

// nnn is a 12 bit value, lowest 12 bits of the instruction
// n   is a 4 bit value, lowest 4 bits of the instruction
// x   is a 4 bit value, lower 4 bits of the high byte of the instruction
// y   is a 4 bit value, upper 4 bits of the low byte of the instruction
// kk  is an 8 bit value, the lowest 8 bits of the instruction

// clear the display
void _00E0(void);

#endif // INS_H