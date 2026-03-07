#!/bin/bash
# Script pour créer l'architecture SecureVault-update avec Git et commit initial

PROJECT="securevault-update"

# 1️⃣ Création des dossiers
DIRS=(
    "$PROJECT/crypto"
    "$PROJECT/vault"
    "$PROJECT/intelligence"
    "$PROJECT/log"
    "$PROJECT/core"
)

for dir in "${DIRS[@]}"; do
    mkdir -p "$dir"
    echo "Créé : $dir"
done

# 2️⃣ Création des fichiers vides avec header
FILES=(
    "$PROJECT/crypto/crypto.h"
    "$PROJECT/crypto/aes.c"
    "$PROJECT/crypto/kyber.c"
    "$PROJECT/crypto/dilithium.c"
    "$PROJECT/vault/encrypt.c"
    "$PROJECT/vault/decrypt.c"
    "$PROJECT/vault/vault.h"
    "$PROJECT/intelligence/incident_engine.c"
    "$PROJECT/intelligence/attack_index.c"
    "$PROJECT/intelligence/intelligence.h"
    "$PROJECT/log/secure_log.c"
    "$PROJECT/log/secure_log.h"
    "$PROJECT/core/entropy_analyzer.c"
    "$PROJECT/core/core.h"
    "$PROJECT/main.c"
)

for file in "${FILES[@]}"; do
    touch "$file"
    echo "// $file" >> "$file"
    echo "Créé fichier : $file"
done

# 3️⃣ Création d'un Makefile minimal
cat <<EOL > "$PROJECT/Makefile"
CC = gcc
CFLAGS = -Wall -g
SRC = \$(wildcard crypto/*.c vault/*.c intelligence/*.c log/*.c core/*.c main.c)
OBJ = \$(SRC:.c=.o)
TARGET = securevault

all: \$(TARGET)

\$(TARGET): \$(OBJ)
	\$(CC) \$(CFLAGS) -o \$@ \$^

clean:
	rm -f \$(OBJ) \$(TARGET)

.PHONY: all clean
EOL

echo "Makefile créé"

git add .
git commit -m "Initial commit: SecureVault-update skeleton"
echo "Dépôt Git initialisé et commit créé"

echo "✅ Architecture SecureVault-update prête avec Git !"
