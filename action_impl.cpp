#include "proto.h"

std::unordered_map<
    std::string,
    void (*)(void)
> func_map = {
    {
        "ADVANCE_DIALOG",
        [](void) {
            log("Up invoked.");
        }
    }
};
