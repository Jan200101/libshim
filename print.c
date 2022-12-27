#include <string.h>
#include <unistd.h>

#include "print.h"

void print(const char* str, ...)
{
    write(STDOUT_FILENO, str, strlen(str));
}
