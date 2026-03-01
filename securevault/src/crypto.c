#include <string.h>
#include "crypto.h"

void derive_key(const char *password,
                unsigned char *salt,
                unsigned char *key)
{
    // TEMPORAIRE : copie simple
    // On remplacera par PBKDF2 plus tard
    strncpy((char *)key, password, 32);
}

int encrypt_data(unsigned char *plaintext, int plaintext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *ciphertext)
{
    // TEMPORAIRE : copie simple
    memcpy(ciphertext, plaintext, plaintext_len);
    return plaintext_len;
}

int decrypt_data(unsigned char *ciphertext, int ciphertext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *plaintext)
{
    // TEMPORAIRE : copie simple
    memcpy(plaintext, ciphertext, ciphertext_len);
    return ciphertext_len;
}
