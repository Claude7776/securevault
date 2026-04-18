#ifndef VAULT_H
#define VAULT_H

#include <stdint.h>

void vault_encrypt(const char *input, const char *filename, const uint8_t *key);
void vault_decrypt(const char *filename, uint8_t *output, const uint8_t *key);

#endif
