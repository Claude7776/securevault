#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include "crypto.h"
#include "utils.h"

#define KEY_SIZE 32      // 256 bits
#define IV_SIZE 12       // GCM standard
#define TAG_SIZE 16

// -------------------------------
// Dérivation clé PBKDF2
// -------------------------------
int derive_key(const char *password,
               unsigned char *salt,
               unsigned char *key)
{
    if (!PKCS5_PBKDF2_HMAC(password, strlen(password),
                           salt, 16,
                           100000, EVP_sha256(),
                           32, key))
    {
        return -1; // échec dérivation
    }
    return 0; // succès
}
// -------------------------------
// Chiffrement AES-256-GCM
// -------------------------------
int encrypt_data(unsigned char *plaintext, int plaintext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *ciphertext,
                 unsigned char *tag)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handle_error("EVP_CIPHER_CTX_new failed");

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        handle_error("EncryptInit failed");

    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv))
        handle_error("EncryptInit key/iv failed");

    int len;
    int ciphertext_len;

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handle_error("EncryptUpdate failed");
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handle_error("EncryptFinal failed");
    ciphertext_len += len;

    // récupérer le tag
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, TAG_SIZE, tag))
        handle_error("Get TAG failed");

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

// -------------------------------
// Déchiffrement AES-256-GCM
// -------------------------------
int decrypt_data(unsigned char *ciphertext, int ciphertext_len,
                 unsigned char *key,
                 unsigned char *iv,
                 unsigned char *tag,
                 unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handle_error("EVP_CIPHER_CTX_new failed");

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        handle_error("DecryptInit failed");

    if (1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv))
        handle_error("DecryptInit key/iv failed");

    int len;
    int plaintext_len;

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handle_error("DecryptUpdate failed");
    plaintext_len = len;

    // définir le tag avant final
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, TAG_SIZE, tag))
        handle_error("Set TAG failed");

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1; // mot de passe ou intégrité incorrecte
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}
