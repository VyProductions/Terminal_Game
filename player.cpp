#include "proto.h"

const vec2_t SPAWN_POINT = {0, 0};
player_t player {L"", 100, 0, {1, 0}, SPAWN_POINT, UP};

void respawn() {
    log(player.player_name + L" has died...");
    player.position = player.spawn_point;
}
