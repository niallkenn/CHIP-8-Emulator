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

void _3xkk(uint8_t x, uint8_t kk) {
    if (V[x] == kk) PC+=2;
}

void _4xkk(uint8_t x, uint8_t kk) {
    if (V[x] != kk) PC+=2;
}


void _5xy0(uint8_t x, uint8_t y) {
    if (V[x] == V[y]) PC+=2;
}

void _6xkk(uint8_t x, uint8_t kk) {
    V[x] = kk;
}

void _7xkk(uint8_t x, uint8_t kk) {
    V[x] += kk;
}

void _8xy0(uint8_t x, uint8_t y) {
    V[x] = V[y];
}

void _8xy1(uint8_t x, uint8_t y) {
    V[x] = V[x] | V[y];
}

void _8xy2(uint8_t x, uint8_t y) {
    V[x] = V[x] & V[y];
}

void _8xy3(uint8_t x, uint8_t y) {
    V[x] = V[x] ^ V[y];
}

void _8xy4(uint8_t x, uint8_t y) {
    uint32_t sum = V[x] + V[y];

    if (sum > 255) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }

    V[x] = sum & 0xFF;
}

void _8xy5(uint8_t x, uint8_t y) {
    if (V[x] > V[y]) {
        V[0xF] = 1; // NOT borrow
    } else {
        V[0xF] = 0; // NOT borrow
    }

    V[x] -= V[y];
}

void _8xy6(uint8_t x, uint8_t y) {
    if (V[x] & 1) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }

    V[x] = V[x] >> 1;
}

void _8xy7(uint8_t x, uint8_t y) {
    if (V[y] > V[x]) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }

    V[x] = V[y] - V[x];
}

void _8xyE(uint8_t x, uint8_t y) {
    if ((V[x] >> 7) & 1) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }

    V[x] = V[x] << 1;
}

void _9xy0(uint8_t x, uint8_t y) {
    if (V[x] != V[y]) PC += 2;
}

void _Annn(uint16_t nnn) {
    I = nnn;
}
