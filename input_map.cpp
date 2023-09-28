#include "proto.h"

std::unordered_map<
    state_t,
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

    state_t state;
    char ch;
    std::string action_name;

    while (input >> state >> ch) {
        std::getline(input, action_name, '\n');

        std::unordered_map<int, void (*)(void)>& state_cat = action_map[state];
        state_cat[(int)ch] = func_map[action_name];
    }

    input.close();
}
