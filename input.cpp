#include "proto.h"

extern std::unordered_map<
    state_t,             // Program contexts / states
    std::unordered_map<
        int,             // Input keycode value
        void (*)(void)   // Function for that input given the program context
    >
> action_map;

int get_ch(WINDOW* wnd) {
    static int arr[3] {};

    int result = 0;
    arr[0] = wgetch(wnd);

    switch (*arr) {
        case 27:
            arr[1] = wgetch(wnd);
            arr[2] = wgetch(wnd);
            result = 270000 + 100 * arr[1] + arr[2];
            break;
        default: result = arr[0]; break;
    }

    return result;
}

void process_input(int keycode) {
    extern state_t prog_state;

    if (
        action_map[prog_state].size() != 0 &&
        action_map[prog_state][keycode] != nullptr
    ) {
        action_map[prog_state][keycode]();
    }
}