#include "crypto.h"
#include <stdio.h>

void kyber_generate_keypair(uint8_t *public_key, uint8_t *secret_key) {
    (void)public_key; // Suppression de l'avertissement de variable non utilisée
    (void)secret_key; // Suppression de l'avertissement de variable non utilisée
    printf("[Kyber] Génération de clé simulée.\n");
}

void kyber_encapsulate(const uint8_t *public_key, uint8_t *ciphertext, uint8_t *shared_secret) {
    (void)public_key; // Suppression de l'avertissement de variable non utilisée
    (void)ciphertext; // Suppression de l'avertissement de variable non utilisée
    (void)shared_secret; // Suppression de l'avertissement de variable non utilisée
    printf("[Kyber] Encapsulation simulée.\n");
}

void kyber_decapsulate(const uint8_t *secret_key, const uint8_t *ciphertext, uint8_t *shared_secret) {
    (void)secret_key; // Suppression de l'avertissement de variable non utilisée
    (void)ciphertext; // Suppression de l'avertissement de variable non utilisée
    (void)shared_secret; // Suppression de l'avertissement de variable non utilisée
    printf("[Kyber] Décapsulation simulée.\n");
}