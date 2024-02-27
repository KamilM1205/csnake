#include "world.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "trace.h"

int32_t
world_init(p_world_t world) {
    memset(world, 0, sizeof(world_t));
    return 0;
}

void
world_update(p_world_t world, float dt) {
    for (int i = 0; i < world->wobjects_count; i++) {
        if (world->wobjects[i].id != NULL) {
            world->wobjects[i].update_ptr(world->wobjects[i].data, dt);
        }
    }
}

void
world_draw(p_world_t world) {
    for (int i = 0; i < world->wobjects_count; i++) {
        if (world->wobjects[i].id != NULL) {
            world->wobjects[i].draw_ptr(world->wobjects[i].data);
        }
    }
}

void
world_deinit(p_world_t world) {
    for (int i = 0; i < world->wobjects_count; i++) {
        if (world->wobjects != NULL) {
            world->wobjects[i].deinit_ptr(world->wobjects[i].data);
        }
    }

    free(world->wobjects);
}

int32_t
world_add_object(p_world_t world, object_t obj) {
    object_t* objects;

    for (int i = 0; i < world->wobjects_count; i++) {
        if (world->wobjects[i].id != NULL) {
            if (world->wobjects[i].id == obj.id) {
                TRACE(TRACE_LEVEL_ERROR, "Error when tring add an object with an existing id(%s)", obj.id);
            }
        }
    }

    objects = realloc(world->wobjects, sizeof(object_t) * world->wobjects_count + 1);
    if (objects == NULL) {
        TRACE(TRACE_LEVEL_ERROR, "Couldn't reallocate world's objects.");
        return -1;
    }

    world->wobjects = objects;
    world->wobjects[world->wobjects_count - 1] = obj;
    world->wobjects_count++;

    return 0;
}

void world_delete_object(p_world_t world, char* id) {
    p_object_t object;
    size_t object_pos;

    object = world_find_object(world, id);
    if (object == NULL) {
        return;
    }

    object_pos = (object - world->wobjects) / sizeof(object_t);
}

p_object_t 
world_find_object(p_world_t world, char* id) {

    if (world->wobjects == NULL) {
        return NULL;
    }

    for (int i = 0; i < world->wobjects_count; i++) {
        if (world->wobjects[i] != NULL) {
            if (world->wobjects[i]->id == id) {
                return world->wobjects[i];
            }
        }
    }

    return NULL;
}
