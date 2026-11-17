#ifndef GRAP_H
#define GRAP_H

#include "lib/myGL/utils.h"

// The screen window
extern Canvas* canvas;

// initialises screen / window
void initialise_graphics(void);
// updates screen based on buffer
void update_screen(void);

#endif  // GRAP_H