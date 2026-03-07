# Makefile pour SecureVault-update

CC = gcc
CFLAGS = -Wall -g
TARGET = securevault

# Tous les fichiers source
SRC = \
    crypto/aes.c \
    crypto/kyber.c \
    crypto/dilithium.c \
    vault/encrypt.c \
    vault/decrypt.c \
    intelligence/attack_index.c \
    intelligence/incident_engine.c \
    log/secure_log.c \
    core/entropy_analyzer.c \
    main.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Règle par défaut : build
all: $(TARGET)

# Compilation de l’exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean