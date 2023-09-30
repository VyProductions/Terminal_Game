#include "proto.h"

std::unordered_map<
    std::string,
    void (*)(void)
> func_map = {
    {
        "ADVANCE_DIALOG", [](void) {
            log(L"Advancing dialog...");
        }
    }, {
        "EXIT", [](void) {
            extern bool running;
            running = false;
        }
    }, {
        "MOVE_UP", [](void) {
            log(L"Move up...");
        }
    }, {
        "TURN_UP", [](void) {
            log(L"Turn up...");
        }
    }, {
        "MOVE_LEFT", [](void) {
            log(L"Move left...");
        }
    }, {
        "TURN_LEFT", [](void) {
            log(L"Turn left...");
        }
    }, {
        "MOVE_DOWN", [](void) {
            log(L"Move down...");
        }
    }, {
        "TURN_DOWN", [](void) {
            log(L"Turn down...");
        }
    }, {
        "MOVE_RIGHT", [](void) {
            log(L"Move right...");
        }
    }, {
        "TURN_RIGHT", [](void) {
            log(L"Turn right...");
        }
    }, {
        "INTERACT", [](void) {
            log(L"Interacting...");
        }
    }, {
        "RESPAWN", [](void) {
            respawn();
        }
    }
};
