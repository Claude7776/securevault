#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>

#define AES_KEY_SIZE 32 // 256 bits

// AES encrypt / decrypt
void aes_encrypt(const uint8_t *plaintext, uint8_t *ciphertext, const uint8_t *key);
void aes_decrypt(const uint8_t *ciphertext, uint8_t *plaintext, const uint8_t *key);

// Post-quantum key encapsulation (squelette)
void kyber_generate_keypair(uint8_t *public_key, uint8_t *secret_key);
void kyber_encapsulate(const uint8_t *public_key, uint8_t *ciphertext, uint8_t *shared_secret);
void kyber_decapsulate(const uint8_t *secret_key, const uint8_t *ciphertext, uint8_t *shared_secret);

// Post-quantum signature
void dilithium_sign(const uint8_t *message, uint8_t *signature, const uint8_t *secret_key);
int dilithium_verify(const uint8_t *message, const uint8_t *signature, const uint8_t *public_key);

#endif