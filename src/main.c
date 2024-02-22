#include "app.h"
#include "trace.h"

int
main(int argc, char** argv) {
    int32_t status;
    p_app_t app;

    status = trace_init(argv);
    if (status != 0) {
        return -1;
    }
    TRACE(TRACE_LEVEL_INFO, "Starting game...");

    status = app_init(&app);
    if (status != 0) {
        goto exit;
    }

    status = app_run_loop(app);
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
