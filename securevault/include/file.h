#ifndef FILE_H
#define FILE_H

#include <stdio.h>

int read_file(const char *filename,
              unsigned char **buffer,
              long *size);

int write_file(const char *filename,
               unsigned char *buffer,
               long size);

#endif
