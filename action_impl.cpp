#include "proto.h"

std::unordered_map<
    std::string,
    void (*)(void)
> func_map = {
    {
        "ADVANCE_DIALOG", [](void) {
            log("Advancing dialog...");
        }
    }, {
        "EXIT", [](void) {
            extern bool running;
            running = false;
        }
    }, {
        "MOVE_UP", [](void) {
            log("Move up...");
        }
    }, {
        "TURN_UP", [](void) {
            log("Turn up...");
        }
    }, {
        "MOVE_LEFT", [](void) {
            log("Move left...");
        }
    }, {
        "TURN_LEFT", [](void) {
            log("Turn left...");
        }
    }, {
        "MOVE_DOWN", [](void) {
            log("Move down...");
        }
    }, {
        "TURN_DOWN", [](void) {
            log("Turn down...");
        }
    }, {
        "MOVE_RIGHT", [](void) {
            log("Move right...");
        }
    }, {
        "TURN_RIGHT", [](void) {
            log("Turn right...");
        }
    }, {
        "INTERACT", [](void) {
            log("Interacting...");
        }
    }, {
        "RESPAWN", [](void) {
            respawn();
        }
    }, {
        "DRAW_MAP", [](void) {
            draw_map({}, {});
        }
    }
};
