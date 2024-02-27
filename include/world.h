#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct {
  char* id;
  void* data;
  int32_t (*update_ptr)(void*, float);
  int32_t (*draw_ptr)(void*);
  int32_t (*deinit_ptr)(void*);
} object_t, *p_object_t;

typedef struct {
  object_t* wobjects;
  size_t  wobjects_count;
} world_t, *p_world_t;

int32_t world_init(p_world_t world);
void world_update(p_world_t world, float dt);
void world_draw(p_world_t world);
void world_deinit(p_world_t world);

int32_t world_add_object(p_world_t world, object_t obj);
void world_delete_object(p_world_t world, char* obj);
p_object_t world_find_object(p_world_t, char* id);
 
#endif /* _WORLD_H_ */
