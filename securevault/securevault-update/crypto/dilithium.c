#include "crypto.h"
#include <stdio.h>

void dilithium_sign(const uint8_t *message, uint8_t *signature, const uint8_t *secret_key) {
    (void)message; // Suppression de l'avertissement de variable non utilisée
    (void)signature; // Suppression de l'avertissement de variable non utilisée
    (void)secret_key; // Suppression de l'avertissement de variable non utilisée
    printf("[Dilithium] Signature simulée.\n");
}

int dilithium_verify(const uint8_t *message, const uint8_t *signature, const uint8_t *public_key) {
    (void)message; // Suppression de l'avertissement de variable non utilisée
    (void)signature; // Suppression de l'avertissement de variable non utilisée
    (void)public_key; // Suppression de l'avertissement de variable non utilisée
    printf("[Dilithium] Vérification simulée.\n");
    return 1; // toujours valide pour le squelette
}