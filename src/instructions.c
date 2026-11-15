#include "instructions.h"
#include "graphics.h"
#include <stdlib.h>

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

    V[x] = sum & 0xFF;

    if (sum > 255) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
}

void _8xy5(uint8_t x, uint8_t y) {
    uint32_t diff = V[x] - V[y];

    V[x] = diff;

    if (V[x] >= V[y]) {
        V[0xF] = 1; // NOT borrow
    } else {
        V[0xF] = 0; // NOT borrow
    }
}

void _8xy6(uint8_t x, uint8_t y) {
    V[x] = V[x] >> 1;
    if (V[x] & 1) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
}

void _8xy7(uint8_t x, uint8_t y) {
    V[x] = V[y] - V[x];
    if (V[y] >= V[x]) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }

}

void _8xyE(uint8_t x, uint8_t y) {
    V[x] = V[x] << 1;

    if ((V[x] >> 7) & 1) {
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
}

void _9xy0(uint8_t x, uint8_t y) {
    if (V[x] != V[y]) PC += 2;
}

void _Annn(uint16_t nnn) {
    I = nnn;
}

void _Bnnn(uint16_t nnn) {
    PC = nnn + V[0];
}

void _Cxkk(uint8_t x, uint8_t kk) {
    int r = rand() % 256;

    V[x] = r & kk;
}

void _Dxyn(uint8_t x, uint8_t y, uint8_t n) {
    V[0xF] = 0;

    for (int i = 0; i < n; i++) {
        uint8_t byte = RAM[I + i];

        int py = (V[y] + i) % 32;

        for (int j = 0; j < 8; j++) {
            int px = (V[x] + j) % 64;
            int pixel = py * 64 + px; 

            uint8_t spritePixel = (byte >> (7 - j)) & 1;

            if (spritePixel == 1) {
                if (Buffer[pixel] == 1) {
                    V[0xF] = 1;
                }
                Buffer[pixel] ^= 1;
            }
        }
    }
}

void _Ex9E(uint8_t x) {
    if (Keyboard[V[x] & 0xF] == 1) {
        PC += 2;
    }
}

void _ExA1(uint8_t x) {
    if (!(Keyboard[V[x] & 0xF] == 1)) {
        PC += 2;
    }
}

void _Fx07(uint8_t x) {
    V[x] = delayTimer;
}

void _Fx0A(uint8_t x) {
    for (int i = 0; i < 16; i++) {
        if (Keyboard[i]) {
            V[x] = i;
            return;
        }
    }
    PC -= 2; // again
}

void _Fx15(uint8_t x) {
    delayTimer = V[x];
}

void _Fx18(uint8_t x) {
    soundTimer = V[x];
}

void _Fx1E(uint8_t x) {
    I += V[x];
}

void _Fx29(uint8_t x) {
    I = 5 * (V[x] & 0xF);
}

void _Fx33(uint8_t x) {
    int value = V[x];

    RAM[I + 2] = value % 10; // units
    RAM[I + 1] = (value / 10) % 10;
    RAM[I] = (value / 100) % 10;
}

void _Fx55(uint8_t x) {
    for (int i = 0; i <= x; i++) {
        RAM[I + i] = V[i];
    }
}

void _Fx65(uint8_t x) {
    for (int i = 0; i <= x; i++) {
        V[i] = RAM[I + i];
    }
}