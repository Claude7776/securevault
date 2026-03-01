#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void handle_error(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

void secure_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}
