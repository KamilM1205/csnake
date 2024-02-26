#include "app.h"
#include "trace.h"
#include "world.h"

int
main(int argc, char** argv) {
    int32_t status;
    app_t app;
    world_t world;

    status = trace_init(argv);
    if (status != 0) {
        return -1;
    }
    TRACE(TRACE_LEVEL_INFO, "Starting game...");

    status = app_init(&app);
    if (status != 0) {
        goto exit;
    }

    status = world_init(&world);
    if (status != 0) {
        goto exit;
    }

    status = app_run_loop(&app, &world);
    if (status != 0) {
        goto exit;
    }

    status = app_deinit(&app);
    if (status != 0) {
        goto exit;
    }

exit:
    TRACE(TRACE_LEVEL_INFO, "Shutdowing game...")
    trace_close();
    return 0;
}
