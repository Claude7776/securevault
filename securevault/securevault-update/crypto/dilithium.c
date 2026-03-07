#include "crypto.h"
#include <stdio.h>

void dilithium_sign(const uint8_t *message, uint8_t *signature, const uint8_t *secret_key) {
    printf("[Dilithium] Signature simulée.\n");
}

int dilithium_verify(const uint8_t *message, const uint8_t *signature, const uint8_t *public_key) {
    printf("[Dilithium] Vérification simulée.\n");
    return 1; // toujours valide pour le squelette
}