#include "proto.h"

std::unordered_map<
    std::string,
    std::unordered_map<
        int,
        void (*)(void)
    >
> action_map;

extern std::unordered_map<
    std::string,
    void (*)(void)
> func_map;

void read_inputmap() {
    std::ifstream input("inputs.txt");

    std::string name;
    char ch;
    std::string action_name;

    while (input >> name >> ch >> action_name) {
        std::unordered_map<int, void (*)(void)>& state_cat = action_map[name];
        if (action_map[name].empty()) action_map[name] = {};
        state_cat[(int)ch] = func_map[action_name];
    }

    input.close();
}
