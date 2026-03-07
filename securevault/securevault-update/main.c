// main.c
#include <stdio.h>
#include "crypto/crypto.h"
#include "vault/vault.h"
#include "intelligence/intelligence.h"
#include "log/secure_log.h"
#include "core/core.h"

int main() {
    printf("=== SecureVault v2: Post-Quantum + Intelligence ===\n");

    // Exemple d'appel à vault
    uint8_t data[64] = "Hello SecureVault!";
    uint8_t ciphertext[128];
    uint8_t password[32] = "supersecret";

    vault_encrypt_data(data, ciphertext, password);

    printf("Données chiffrées avec succès.\n");

    return 0;
}