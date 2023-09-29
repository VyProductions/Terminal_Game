#include "proto.h"

int r, c;                   // Screen coordinate
int nrows, ncols;           // Dimension of display
WINDOW* wnd;                // N-curses window struct
state_t prog_state;         // Current program state (context)
bool running;               // Whether application should continue or not
Console console;            // Output log file interface

static std::unordered_map<
    state_t,
    std::string
> state_name_map = {
    { UNKNOWN, "UNKNOWN" },
    { DIALOG, "DIALOG" },
    { TEXT_PROMPT, "TEXT_PROMPT" },
    { OPTION_PROMPT, "OPTION_PROMPT" },
    { PLAYER_CONTROL, "PLAYER_CONTROL" }
};

static std::unordered_map<
    std::string,
    state_t
> name_state_map = {
    { "UNKNOWN", UNKNOWN },
    { "DIALOG", DIALOG },
    { "TEXT_PROMPT", TEXT_PROMPT },
    { "OPTION_PROMPT", OPTION_PROMPT },
    { "PLAYER_CONTROL", PLAYER_CONTROL }
};

void sys_start() {
    log("[Application Start]");

    read_inputmap();

    prog_state = DIALOG;
    running = true;
    r = c = 0;

    wnd = initscr();
    cbreak();
    noecho();
    scrollok(wnd, true);

    #ifdef N_DELAY
    nodelay(wnd, true);
    #endif

    getmaxyx(wnd, nrows, ncols);
    clear();
    refresh();
    curs_set(0);
    mvaddch(0, 0, ' ');  // Update cursor by printing a space.
}

void sys_exit() {
    log("[Application End]");

    endwin();
}

std::string state_name(const state_t& name) {
    return state_name_map[name];
}

state_t name_state(const std::string& name) {
    return (state_t)(
        name_state_map.contains(name) * name_state_map[name]
    );
}
