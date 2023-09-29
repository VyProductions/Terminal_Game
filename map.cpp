#include "proto.h"

extern int r, c;
extern int nrows, ncols;

void draw_map(vec2_t top_left, vec2_t bottom_right) {
    for (int _r = 0; _r < nrows; ++_r) {
        for (int _c = 0; _c < ncols; ++_c) {
            mvaddch(_r, _c, (char)(rand() % 26 + 'a'));
        }
    }

    log("New frame.");
}
