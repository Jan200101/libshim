#include <stdlib.h>

#include "print.h"
#include "wrap.h"

#pragma GCC visibility push(default)

void* malloc(size_t size) {
    return REAL(malloc)(size);
}

void free(void* ptr)
{
    return REAL(free)(ptr);
}

void* calloc(size_t nmemb, size_t size)
{
    return REAL(calloc)(nmemb, size);
}

void* realloc(void *ptr, size_t size)
{
    return REAL(realloc)(ptr, size);
}

#pragma GCC visibility pop
