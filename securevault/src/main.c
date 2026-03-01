#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "crypto.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    unsigned char *buffer = NULL;
    long size;

    if (!read_file(argv[1], &buffer, &size))
        handle_error("Failed to read input file");

    unsigned char key[32] = {0};
    unsigned char iv[16] = {0};

    derive_key("password", NULL, key);

    unsigned char *encrypted = malloc(size);
    if (!encrypted)
        handle_error("Memory allocation failed");

    int encrypted_len = encrypt_data(buffer, size, key, iv, encrypted);

    if (!write_file(argv[2], encrypted, encrypted_len))
        handle_error("Failed to write output file");

    printf("Operation completed successfully.\n");

    secure_free(buffer);
    secure_free(encrypted);

    return 0;
}
