#ifndef VAULT_H
#define VAULT_H

#include <stdint.h>

void vault_encrypt_data(const uint8_t *data, uint8_t *ciphertext, const uint8_t *password);
void vault_decrypt_data(const uint8_t *ciphertext, uint8_t *data, const uint8_t *password);

#endif