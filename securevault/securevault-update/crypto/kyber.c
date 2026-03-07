#include "crypto.h"
#include <stdio.h>

void kyber_generate_keypair(uint8_t *public_key, uint8_t *secret_key) {
    printf("[Kyber] Génération de clé simulée.\n");
}

void kyber_encapsulate(const uint8_t *public_key, uint8_t *ciphertext, uint8_t *shared_secret) {
    printf("[Kyber] Encapsulation simulée.\n");
}

void kyber_decapsulate(const uint8_t *secret_key, const uint8_t *ciphertext, uint8_t *shared_secret) {
    printf("[Kyber] Décapsulation simulée.\n");
}