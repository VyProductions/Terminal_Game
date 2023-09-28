#include "proto.h"

std::unordered_map<
    std::string,
    void (*)(void)
> func_map = {
    {
        "UP",
        [](void) {
            log("Up invoked.");
        }
    }
};
