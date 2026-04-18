#include "crypto.h"
#include <openssl/evp.h>
#include <string.h>

void derive_key(const char *password, uint8_t *key, uint8_t *salt)
{
    PKCS5_PBKDF2_HMAC(password, strlen(password),
                      salt, 16,
                      100000,
                      EVP_sha256(),
                      KEY_SIZE, key);
}
