#ifndef _TRACE_H_
#define _TRACE_H_

#include <stdint.h>
#include <stdio.h>

extern FILE* TRACE_FILE;

#ifdef _WIN32
#define PATH_SLASH '\\'
#else
#define PATH_SLASH '/'
#endif /* _WIN32 */

#define TRACE_LEVEL_INFO  "INFO"
#define TRACE_LEVEL_ERROR "ERROR"

#define TRACE(level, _fmt_, ...)                                                                                       \
    if (TRACE_FILE != NULL) {                                                                                          \
        fprintf(TRACE_FILE, "%s: " _fmt_ "\n", level, ##__VA_ARGS__);                                                  \
    } else {                                                                                                           \
        printf("Error: trace file is not open.");                                                                      \
    }

int32_t trace_init(char** argv);
int32_t trace_close();

#endif /* _TRACE_H_ */
