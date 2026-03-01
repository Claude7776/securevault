#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "utils.h"

int read_file(const char *filename,
              unsigned char **buffer,
              long *size)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
        return 0;

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    *buffer = malloc(*size);
    if (!*buffer)
        handle_error("Memory allocation failed");

    fread(*buffer, 1, *size, file);
    fclose(file);

    return 1;
}

int write_file(const char *filename,
               unsigned char *buffer,
               long size)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
        return 0;

    fwrite(buffer, 1, size, file);
    fclose(file);

    return 1;
}
