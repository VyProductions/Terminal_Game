#include "proto.h"

char** display = nullptr;   // Content of display
int r, c;                   // Screen coordinate
int nrows, ncols;           // Dimension of display
WINDOW* wnd;                // N-curses window struct
state_t prog_state;         // Current program state (context)

void sys_start() {
    log("[Application Start]");

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

std::istream& operator>>(std::istream& in, state_t& s) {
    std::string name;

    if (!(in >> name)) {
        s = UNKNOWN;

        throw std::runtime_error("state_t::operator>>: Input failed.");
    } else if (name == "DIALOG") {
        s = DIALOG;
    } else if (name == "TEXT_PROMPT") {
        s = TEXT_PROMPT;
    } else if (name == "OPTION_PROMPT") {
        s = OPTION_PROMPT;
    } else if (name == "PLAYER_CONTROL") {
        s = PLAYER_CONTROL;
    } else {
        s = UNKNOWN;

        throw std::runtime_error(
            "state_t::operator>>: Unknown state name '" + name + "'"
        );
    }

    return in;
}
