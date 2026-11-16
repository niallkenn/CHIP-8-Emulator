#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// fetches instruction from memory
uint16_t fetch(void);
// decodes and excecutes said instruction
void decode_and_excecute(uint16_t instruction);

#endif // CPU_H
