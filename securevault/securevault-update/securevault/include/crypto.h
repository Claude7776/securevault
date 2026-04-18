#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>

#define KEY_SIZE 32
#define IV_SIZE 16

int aes_encrypt(const uint8_t *plaintext, int plaintext_len,
                const uint8_t *key, uint8_t *iv,
                uint8_t *ciphertext);

int aes_decrypt(const uint8_t *ciphertext, int ciphertext_len,
                const uint8_t *key, uint8_t *iv,
                uint8_t *plaintext);

void derive_key(const char *password, uint8_t *key, uint8_t *salt);

#endif
