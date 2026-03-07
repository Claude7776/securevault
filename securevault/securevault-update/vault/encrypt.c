#include "vault.h"
#include "../crypto/crypto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// dérivation de clé simulée
void derive_key_from_password(const uint8_t *password, uint8_t *key) {
    memcpy(key, password, AES_KEY_SIZE);
}

void vault_encrypt_data(const uint8_t *data, uint8_t *ciphertext, const uint8_t *password) {
    uint8_t key[AES_KEY_SIZE];
    derive_key_from_password(password, key);
    aes_encrypt(data, ciphertext, key);
}