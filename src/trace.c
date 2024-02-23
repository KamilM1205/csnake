#include "trace.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

FILE* TRACE_FILE = NULL;

int32_t
trace_init(char** argv) {
    char* curr_path;
    char* exe_path;

    if (!strrchr(argv[0], PATH_SLASH)) {
        exe_path = GET_CWD();
    } else {
        char* path;

        int32_t pos = strrchr(argv[0], PATH_SLASH) - argv[0];
        path = malloc(pos);
        memcpy(path, argv[0], pos);
        curr_path = GET_CWD();
        chdir(path);
        exe_path = GET_CWD();
        chdir(curr_path);

        free(path);
    }
    size_t trace_path_size = strlen(exe_path) + strlen("/trace.txt");
    char* trace_path = malloc(trace_path_size);
    strcat(trace_path, exe_path);
    strcat(trace_path, "/trace.txt");

    TRACE_FILE = fopen(trace_path, "w+");
    //free(trace_path);
    if (TRACE_FILE == NULL) {
        printf("Error: couldn't open trace file.\n");
        return -1;
    }

    return 0;
}

int32_t
trace_close() {
    if (TRACE_FILE == NULL) {
        printf("Error: cannot close trace file because it's not open.\n");
        return -1;
    }

    fclose(TRACE_FILE);
    TRACE_FILE = NULL;
    return 0;
}
