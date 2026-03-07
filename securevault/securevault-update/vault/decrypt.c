#include "vault.h"
#include "../crypto/crypto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void vault_decrypt_data(const uint8_t *ciphertext, uint8_t *data, const uint8_t *password) {
    uint8_t key[32];
    memcpy(key, password, 32); // même dérivation simulée
    aes_decrypt(ciphertext, data, key);
}