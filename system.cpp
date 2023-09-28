#include "proto.h"

char** display = nullptr;   // Content of display
int r, c;                   // Screen coordinate
int nrows, ncols;           // Dimension of display
WINDOW* wnd;                // N-curses window struct
state_t prog_state;         // Current program state (context)

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
    bool exiting = false;
    c = 2;
    
    while (r >= nrows) {
        --r;
        scrl(1);
    }

    for (const char ch : std::string("Press any key to exit...")) {
        mvaddch(r, c++, (int)ch | A_BOLD);
    }

    while (!exiting) {
        int ch = get_ch(wnd);

        exiting = ch != ERR;
    }

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
