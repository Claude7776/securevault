#include <string.h>
#include "crypto.h"

// -------------------------------
// Dérivation de clé (stub temporaire)
// -------------------------------
void derive_key(const char *password,
                unsigned char *salt,
                unsigned char *key)
{
    // Suppression des warnings pour les paramètres inutilisés
    (void)salt;

    // Copie simple temporaire (remplacera PBKDF2 plus tard)
    strncpy((char *)key, password, 32);
}

// -------------------------------
// Chiffrement (stub temporaire)
// -------------------------------
int encrypt_data(unsigned char *plaintext, int plaintext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *ciphertext)
{
    // Suppression des warnings
    (void)key;
    (void)iv;

    // Copie simple temporaire
    memcpy(ciphertext, plaintext, plaintext_len);
    return plaintext_len;
}

// -------------------------------
// Déchiffrement (stub temporaire)
// -------------------------------
int decrypt_data(unsigned char *ciphertext, int ciphertext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *plaintext)
{
    // Suppression des warnings
    (void)key;
    (void)iv;

    // Copie simple temporaire
    memcpy(plaintext, ciphertext, ciphertext_len);
    return ciphertext_len;
}
