#ifndef CRYPTO_H
#define CRYPTO_H

int     derive_key(const char *password,
                   unsigned char *salt,
                   unsigned char *key);

int     encrypt_data(unsigned char *plaintext, int plaintext_len,
                     unsigned char *key, unsigned char *iv,
                     unsigned char *ciphertext, unsigned char *tag);

int     decrypt_data(unsigned char *ciphertext, int ciphertext_len,
                     unsigned char *key, unsigned char *iv,
                     unsigned char *tag, unsigned char *plaintext);

#endif
