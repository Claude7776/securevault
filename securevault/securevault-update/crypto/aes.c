#include "crypto.h"
#include <string.h>
#include <stdio.h>

void aes_encrypt(const uint8_t *plaintext, uint8_t *ciphertext, const uint8_t *key) {
    // Squelette : copie directe
    memcpy(ciphertext, plaintext, 64);
    printf("[AES] Encryption simulée.\n");
}

void aes_decrypt(const uint8_t *ciphertext, uint8_t *plaintext, const uint8_t *key) {
    memcpy(plaintext, ciphertext, 64);
    printf("[AES] Décryption simulée.\n");
}