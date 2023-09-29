#include "proto.h"

const vec2_t SPAWN_POINT = {0, 0};
player_t player {"", 100, 0, {0, 0}, SPAWN_POINT};

void respawn() {
    log(player.player_name + " has died...");
    player.position = player.spawn_point;
}
