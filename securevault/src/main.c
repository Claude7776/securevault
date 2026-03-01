#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <unistd.h>

#include "file.h"
#include "crypto.h"
#include "utils.h"

#define MAGIC "SVLT2026"
#define MAGIC_SIZE 8
#define SALT_SIZE 16
#define IV_SIZE 12
#define TAG_SIZE 16

// -------------------------------
// Écriture du header .vlt
// -------------------------------
void write_header(FILE *out, unsigned char *salt, unsigned char *iv)
{
    fwrite(MAGIC, 1, MAGIC_SIZE, out);
    fwrite(salt, 1, SALT_SIZE, out);
    fwrite(iv, 1, IV_SIZE, out);
}

// -------------------------------
// Lecture et vérification header
// -------------------------------
int read_header(FILE *in, unsigned char *salt, unsigned char *iv)
{
    unsigned char magic[MAGIC_SIZE];
    fread(magic, 1, MAGIC_SIZE, in);
    if (memcmp(magic, MAGIC, MAGIC_SIZE) != 0) {
        printf("Fichier non valide\n");
        return 0;
    }
    fread(salt, 1, SALT_SIZE, in);
    fread(iv, 1, IV_SIZE, in);
    return 1;
}

// -------------------------------
// Lecture mot de passe masqué
// -------------------------------

void get_password(char *password, size_t size)
{
    char *pw = getpass("Mot de passe : ");
    if (!pw) handle_error("Lecture mot de passe échouée");
    strncpy(password, pw, size-1);
    password[size-1] = '\0'; // assurer terminaison
}

// -------------------------------
// Main
// -------------------------------
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s -e|-d <file>\n", argv[0]);
        return 1;
    }

    char password[128];
    get_password(password, sizeof(password));

    if (strcmp(argv[1], "-e") == 0) {
        // Lecture fichier
        unsigned char *buffer = NULL;
        long size;
        if (!read_file(argv[2], &buffer, &size))
            handle_error("Impossible de lire le fichier");

        // Génération salt + iv
        unsigned char salt[SALT_SIZE];
        unsigned char iv[IV_SIZE];
        RAND_bytes(salt, SALT_SIZE);
        RAND_bytes(iv, IV_SIZE);

        // Dérivation clé
        unsigned char key[32];
        derive_key(password, salt, key);

        // Chiffrement
        unsigned char *ciphertext = malloc(size);
        unsigned char tag[TAG_SIZE];
        if (!ciphertext) handle_error("Mémoire insuffisante");

        int clen = encrypt_data(buffer, size, key, iv, ciphertext, tag);

        // Écriture fichier .vlt
        char outname[256];
        snprintf(outname, sizeof(outname), "%s.vlt", argv[2]);
        FILE *out = fopen(outname, "wb");
        if (!out) handle_error("Impossible de créer fichier .vlt");

        write_header(out, salt, iv);
        fwrite(ciphertext, 1, clen, out);
        fwrite(tag, 1, TAG_SIZE, out);
        fclose(out);

        printf("Fichier chiffré avec succès: %s\n", outname);

        secure_free(buffer);
        secure_free(ciphertext);
    }
    else if (strcmp(argv[1], "-d") == 0) {
        // Lecture fichier .vlt
        FILE *in = fopen(argv[2], "rb");
        if (!in) handle_error("Impossible de lire le fichier .vlt");

        unsigned char salt[SALT_SIZE], iv[IV_SIZE];
        if (!read_header(in, salt, iv)) {
            fclose(in);
            return 1;
        }

        // Taille ciphertext
        fseek(in, 0, SEEK_END);
        long fsize = ftell(in);
        long clen = fsize - MAGIC_SIZE - SALT_SIZE - IV_SIZE - TAG_SIZE;
        rewind(in);
        fseek(in, MAGIC_SIZE + SALT_SIZE + IV_SIZE, SEEK_SET);

        unsigned char *ciphertext = malloc(clen);
        unsigned char tag[TAG_SIZE];
        fread(ciphertext, 1, clen, in);
        fread(tag, 1, TAG_SIZE, in);
        fclose(in);

        // Dérivation clé
        unsigned char key[32];
        derive_key(password, salt, key);
	if (derive_key(password, salt, key) != 0)
		handle_error("Échec dérivation clé");
        // Déchiffrement
        unsigned char *plaintext = malloc(clen);
        int plen = decrypt_data(ciphertext, clen, key, iv, tag, plaintext);
        if (plen < 0) {
            printf("Mot de passe incorrect ou fichier corrompu\n");
            secure_free(ciphertext);
            secure_free(plaintext);
            return 1;
        }

        // Écriture fichier déchiffré
        char outname[256];
        snprintf(outname, sizeof(outname), "%s.dec", argv[2]);
        if (!write_file(outname, plaintext, plen))
            handle_error("Impossible d'écrire fichier déchiffré");

        printf("Fichier déchiffré avec succès: %s\n", outname);

        secure_free(ciphertext);
        secure_free(plaintext);
    }
    else {
        printf("Option invalide\n");
        return 1;
    }

    // Effacer mot de passe de la mémoire
    memset(password, 0, sizeof(password));

    return 0;
}
