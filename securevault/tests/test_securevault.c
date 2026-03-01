#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "crypto.h"

int main()
{
    unsigned char plaintext[] = "Hello SecureVault!";
    unsigned char key[32] = {0};
    unsigned char iv[12] = {0};
    unsigned char salt[16] = {0};
    unsigned char ciphertext[128];
    unsigned char decrypted[128];
    unsigned char tag[16];

    // Dériver clé
    derive_key("motdepasse", salt, key);

    // Chiffrement
    int clen = encrypt_data(plaintext, strlen((char*)plaintext), key, iv, ciphertext, tag);

    // Déchiffrement
    int plen = decrypt_data(ciphertext, clen, key, iv, tag, decrypted);

    // Vérification
    decrypted[plen] = '\0';
    assert(strcmp((char*)plaintext, (char*)decrypted) == 0);

    // Mauvais mot de passe
    unsigned char wrong_key[32] = {0};
    derive_key("mauvais", salt, wrong_key);
    int fail = decrypt_data(ciphertext, clen, wrong_key, iv, tag, decrypted);
    assert(fail < 0);  // doit échouer

    printf("Tous les tests réussis ✅\n");
    return 0;
}
