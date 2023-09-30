#include "proto.h"

std::unordered_map<
    vec2_t,
    object_t
> map_set;

extern std::wstring** display;
extern int r, c;
extern int nrows, ncols;

void draw_display() {
    for (int _r = 0; _r < nrows; ++_r) {
        for (int _c = 0; _c < ncols; ++_c) {
            mvaddwstr(_r, _c, display[_r][_c].c_str());
        }
    }
}
