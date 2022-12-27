#include <stddef.h>

#include "wrap.h"

void *(*_REAL(malloc))(size_t size) = NULL;
void (*_REAL(free))(void *ptr) = NULL;
void *(*_REAL(calloc))(size_t nmemb, size_t size) = NULL;
void *(*_REAL(realloc))(void *ptr, size_t size) = NULL;

#ifdef __GNUC__
void __attribute__((constructor)) __wrap_init()
{
    // set the real values up as soon as possible
    REAL(malloc);
    REAL(free);
    REAL(calloc);
    REAL(realloc);
}
#endif
