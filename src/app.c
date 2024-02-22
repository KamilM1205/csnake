#include "app.h"
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_hints.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include "trace.h"

int32_t
app_init(p_app_t app) {
    TRACE(TRACE_LEVEL_INFO, "Initializing App...");

    app = malloc(sizeof(app_t));

    app->swidth = 640;
    app->sheight = 480;
    app->title = "CSnake";

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        TRACE(TRACE_LEVEL_ERROR, "SDL_Init throwed error: %s", SDL_GetError());
        return -1;
    }

    return 0;
}

int32_t
app_run_loop(p_app_t app) {
    int32_t renderer_flags, window_flags;
    SDL_Event event;
    renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    window_flags = 0;

    app->window = SDL_CreateWindow(app->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, app->swidth,
                                   app->sheight, window_flags);
    if (!app->window) {
        TRACE(TRACE_LEVEL_ERROR, "SDL_CreateWindow throwed error: %s", SDL_GetError());
        return -1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);
    if (!app->renderer) {
        TRACE(TRACE_LEVEL_ERROR, "SDL_CreateRenderer throwed error: %s", SDL_GetError());
        return -1;
    }

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: return 0;
            default: break;
        }
    }

    return 0;
}

int32_t
app_deinit(p_app_t app) {
    free(app);

    return 0;
}
