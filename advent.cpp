#define N_DELAY  // Do not pause for input (comment out to disable)

#include "proto.h"

#define UP      279165
#define DOWN    279166
#define RIGHT   279167
#define LEFT    279168

extern char** display;             // Content of display
extern int r, c;                   // Screen coordinate
extern int nrows, ncols;           // Dimension of display
extern WINDOW* wnd;                // N-curses window struct

using namespace std::chrono_literals;

int main() {
    int ch;  // Keycode value

    sys_start();

    bool running = true;
    int beer = 3;

    // Game Loop
    while (running) {
        ch = get_ch(wnd);

        switch (ch) {
            case (int)'q':  // Exit keybind
                log(std::string("Key pressed: ") + (char)ch);
                log("  Exiting...");
                running = false;
                break;

            #ifdef N_DELAY
            case ERR:  // No input entered
                break;
            #endif

            default:  // Unrecognized input
                break;
        }
    }

    sys_exit();
}
