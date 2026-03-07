/*
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
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "vault/vault.h"
#include "intelligence/intelligence.h"

int main() {

    uint8_t data[64] = "SecureVault test message";
    uint8_t ciphertext[128];
    uint8_t decrypted[64];
    uint8_t password[32] = "superpassword";

    printf("Message original: %s\n", data);

    vault_encrypt_data(data, ciphertext, password);
    vault_decrypt_data(ciphertext, decrypted, password);

    printf("Message dechiffre: %s\n", decrypted);

    // Test du moteur d'intelligence
    int score = compute_attack_score(5, 1, 0, 2);

    printf("Attack score: %d\n", score);

    is_attack_probable(score);
    return 0;
}