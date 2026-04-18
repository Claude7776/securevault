#include "crypto.h"
#include <stdio.h>

void vault_decrypt(const char *filename, uint8_t *output, const uint8_t *key)
{
    FILE *f = fopen(filename, "rb");

    uint8_t iv[16];
    uint8_t ciphertext[1024];

    fread(iv, 1, 16, f);
    int len = fread(ciphertext, 1, 1024, f);

    fclose(f);

    int dec_len = aes_decrypt(ciphertext, len, key, iv, output);
    output[dec_len] = '\0';
}
