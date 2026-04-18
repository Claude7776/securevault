#include "crypto.h"
#include <stdio.h>
#include <string.h>

void vault_encrypt(const char *input, const char *filename, const uint8_t *key)
{
    uint8_t iv[16];
    uint8_t ciphertext[1024];

    int len = aes_encrypt((uint8_t*)input, strlen(input), key, iv, ciphertext);

    FILE *f = fopen(filename, "wb");
    fwrite(iv, 1, 16, f);
    fwrite(ciphertext, 1, len, f);
    fclose(f);
}
