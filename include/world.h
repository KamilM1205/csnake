#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdint.h>
typedef struct {
  char* id;
  int32_t (*init_ptr)(void*);
  int32_t (*update_ptr)(void*, float);
  int32_t (*draw_ptr)(void*);
} object, *p_object;

typedef struct {
  object* wobjects; 
} world_t, *p_world_t;

int32_t world_init(p_world_t world);
int32_t world_update(p_world_t world);
int32_t world_draw(p_world_t world);
void world_deinit(p_world_t world);

void world_add_object(p_object obj);
void world_delete_object(p_object obj);
p_object world_find_object(char* id);
 
#endif /* _WORLD_H_ */
