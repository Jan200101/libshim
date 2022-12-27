#ifndef WRAP_H
#define WRAP_H

#include <dlfcn.h>

#include "defines.h"

#define _REAL(n) __real_##n
#define REAL(n) \
    ({ \
        if (!_REAL(n)) \
            _REAL(n) = dlsym(RTLD_NEXT, XSTR(n)); \
        _REAL(n); \
    })

extern void *(*_REAL(malloc))(size_t size);
extern void (*_REAL(free))(void *ptr);
extern void *(*_REAL(calloc))(size_t nmemb, size_t size);
extern void *(*_REAL(realloc))(void *ptr, size_t size);

#endif /* WRAP_H */
