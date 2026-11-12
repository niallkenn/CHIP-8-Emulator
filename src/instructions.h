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
// return from subroutine
void _00EE(void);
// jump to location nnn
void _1nnn(uint16_t nnn);
// call subroutine at nnn
void _2nnn(uint16_t nnn);
// skip next instruction if Vx = kk
void _3xkk(uint8_t x, uint8_t kk);
// skip next instruction if Vx != kk
void _4xkk(uint8_t x, uint8_t kk);
// skip next instruction if Vx = Vy
void _5xy0(uint8_t x, uint8_t y);
// set Vx = kk
void _6xkk(uint8_t x, uint8_t kk);
// set Vx = Vx + kk
void _7xkk(uint8_t x, uint8_t kk);
// set Vx = Vy
void _8xy0(uint8_t x, uint8_t y);
// set Vx = Vx OR Vy
void _8xy1(uint8_t x, uint8_t y);
// set Vx = Vx AND Vy
void _8xy2(uint8_t x, uint8_t y);
// set Vx = Vx XOR Vy
void _8xy3(uint8_t x, uint8_t y);
// set Vx = Vx + Vy and set VF = carry
void _8xy4(uint8_t x, uint8_t y);
// set Vx = Vx - Vy and set VF = NOT borrow
void _8xy5(uint8_t x, uint8_t y);
// set Vx = Vx shift right 1
void _8xy6(uint8_t x, uint8_t y);
// set Vx = Vy - Vx and set VF = NOT borrow
void _8xy7(uint8_t x, uint8_t y);
// set Vx = Vx shift left 1
void _8xyE(uint8_t x, uint8_t y);
// skip next instruction if Vx != Vy
void _9xy0(uint8_t x, uint8_t y);
// set I = nnn
void _Annn(uint16_t nnn);
// jmp to nnn + V0
void _Bnnn(uint16_t nnn);
// set Vx = random byte AND kk
void _Cxkk(uint8_t x, uint8_t kk);
// display n byte sprite starting at memory loc I at Vx, Vy and set VF = collision
void _Dxyn(uint8_t x, uint8_t y, uint8_t n);
// skip next instruction if key with the value of Vx is pressed
void _Ex9E(uint8_t x);
// skip next instruction if key with the value of Vx is not pressed
void _ExA1(uint8_t x);
// set Vx = delay timer value
void _Fx07(uint8_t x);
// wait for a key press, store the value of the key in Vx
void _Fx0A(uint8_t x);
// set delay timer = Vx
void _Fx15(uint8_t x);
// set sound timer = Vx
void _Fx18(uint8_t x);
// set I = I + Vx
void _Fx1E(uint8_t x);
// set I = loc of sprite for digit Vx
void _Fx29(uint8_t x);
// store BCD representation of Vx in mem locs I, I+1, I+2, hundreds, tens, units
void _Fx33(uint8_t x);
// store registers 0-F in memory starting at location I
void _Fx55(uint8_t x);
// read registers 0-F from memory starting at location I
void _Fx65(uint8_t x);
#endif // INS_H