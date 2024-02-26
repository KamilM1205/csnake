#include "world.h"
#include <stdint.h>
#include <string.h>
#include "trace.h"

int32_t
world_init(p_world_t world) {
    memset(world, 0, sizeof(world_t));

    return 0;
}

int32_t
world_update(p_world_t world) {
    return 0;
}

int32_t
world_draw(p_world_t world) {
    return 0;
}

void
world_deinit(p_world_t world) {}
