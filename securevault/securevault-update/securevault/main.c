#include "crypto.h"
#include "vault.h"
#include <stdio.h>

int main()
{
    uint8_t key[32];
    uint8_t salt[16] = "randomsalt1234";

    derive_key("password", key, salt);

    vault_encrypt("Hello SecureVault", "vault.bin", key);

    uint8_t output[1024];
    vault_decrypt("vault.bin", output, key);

    printf("Decrypted: %s\n", output);

    return 0;
}
