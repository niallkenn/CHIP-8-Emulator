#include "keyboard.h"
#include "memory.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "graphics.h"

void handle_keys(void) {
    XEvent event;
    while (XPending(canvas->display)) {
        XNextEvent(canvas->display, &event);

        switch (event.type) {
            case KeyPress: {
                KeySym key = XLookupKeysym(&event.xkey, 0);

                if (key == XK_x) Keyboard[0x0] = 1;
                else if (key == XK_1) Keyboard[0x1] = 1;
                else if (key == XK_2) Keyboard[0x2] = 1;
                else if (key == XK_3) Keyboard[0x3] = 1;
                else if (key == XK_q) Keyboard[0x4] = 1;
                else if (key == XK_w) Keyboard[0x5] = 1;
                else if (key == XK_e) Keyboard[0x6] = 1;
                else if (key == XK_a) Keyboard[0x7] = 1;
                else if (key == XK_s) Keyboard[0x8] = 1;
                else if (key == XK_d) Keyboard[0x9] = 1;
                else if (key == XK_z) Keyboard[0xA] = 1;
                else if (key == XK_c) Keyboard[0xB] = 1;
                else if (key == XK_4) Keyboard[0xC] = 1;
                else if (key == XK_r) Keyboard[0xD] = 1;
                else if (key == XK_f) Keyboard[0xE] = 1;
                else if (key == XK_v) Keyboard[0xF] = 1;

                if (key == XK_Escape) exit(0);
                break;
            }
            
            case KeyRelease: {
                KeySym key2 = XLookupKeysym(&event.xkey, 0);

                if (key2 == XK_x) Keyboard[0x0] = 0;
                else if (key2 == XK_1) Keyboard[0x1] = 0;
                else if (key2 == XK_2) Keyboard[0x2] = 0;
                else if (key2 == XK_3) Keyboard[0x3] = 0;
                else if (key2 == XK_q) Keyboard[0x4] = 0;
                else if (key2 == XK_w) Keyboard[0x5] = 0;
                else if (key2 == XK_e) Keyboard[0x6] = 0;
                else if (key2 == XK_a) Keyboard[0x7] = 0;
                else if (key2 == XK_s) Keyboard[0x8] = 0;
                else if (key2 == XK_d) Keyboard[0x9] = 0;
                else if (key2 == XK_z) Keyboard[0xA] = 0;
                else if (key2 == XK_c) Keyboard[0xB] = 0;
                else if (key2 == XK_4) Keyboard[0xC] = 0;
                else if (key2 == XK_r) Keyboard[0xD] = 0;
                else if (key2 == XK_f) Keyboard[0xE] = 0;
                else if (key2 == XK_v) Keyboard[0xF] = 0;

                break;
            }
        }
    }
}