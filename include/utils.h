#ifndef _UTILS_H_
#define _UTILS_H_

#ifdef _MSC_VER

#include <direct.h>
#define GET_CWD() _getcwd(NULL, 0);

#else

#include <unistd.h>
#define GET_CWD() getcwd(NULL, 0);

#endif /* _MSC_VER */

#endif /* _UTILS_H_ */
