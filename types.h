#ifndef TYPES_H
#define TYPES_H

#include <chrono>
#include <curses.h>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

enum state_t {
    UNKNOWN, DIALOG, TEXT_PROMPT, OPTION_PROMPT, PLAYER_CONTROL
};

class Console {
public:
    using tick_t = std::chrono::time_point<std::chrono::high_resolution_clock>;

    Console() { open(); }

    ~Console() { close(); }

    void open() {
        logfile.open("log.txt", std::ios::out | std::ios::trunc);
        origin = std::chrono::high_resolution_clock::now();
    }

    void close() { logfile.close(); }

    template <class T>
    void _log(const T& msg) {
        now = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(now - origin);
        logfile << "[" << ftick(diff.count()) << "] " << msg << std::endl;
    }
private:
    std::string ftick(int64_t ticks) {
        std::string h  = std::to_string(ticks / (3'600'000'000));
        std::string m  = std::to_string((ticks % 3'600'000'000) / 60'000'000);
        std::string s  = std::to_string((ticks % 60'000'000) / 1'000'000);
        std::string us = std::to_string((ticks % 1'000'000));
        h = std::string(9 - h.length(), '0') + h;
        m = std::string(2 - m.length(), '0') + m;
        s = std::string(2 - s.length(), '0') + s;
        us = std::string(6 - us.length(), '0') + us;

        return h + ':' + m + ':' + s + '.' + us;
    }

    tick_t origin;
    tick_t now;

    std::ofstream logfile;
};

struct message_t {
    // for each int... M.S. Bytes : L.S. Byte -> format : character
    std::vector<int> header;

    // list of words in the content of the message. Same fmt options as header
    std::list<std::vector<int> > content;

    // list of selectable action prompts associated with message
    // - each option is separated further into a list of words. Same fmt options
    //   as header
    std::list<std::list<std::vector<int> > > options;
};

typedef std::unordered_map<
    int,            // Input keycode value
    void (*)(void)  // Function for that input given the program context
> keybind_t;

#endif
