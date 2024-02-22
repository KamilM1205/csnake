#ifndef _APP_H_
#define _APP_H_

#include <SDL_render.h>
#include <SDL_video.h>
#include <stdint.h>

typedef struct {
    int32_t swidth, sheight;
    char* title;
    SDL_Window* window;
    SDL_Renderer* renderer;
} app_t, *p_app_t;

int32_t app_init(p_app_t app);
int32_t app_run_loop(p_app_t app);
int32_t app_deinit(p_app_t app);

#endif /* _APP_H_ */
