CC=gcc
CFLAGS=-Wall -Wextra -Werror -Iinclude

SRC= main.c \
crypto/aes.c crypto/key.c \
vault/encrypt.c vault/decrypt.c \
log/secure_log.c \
intelligence/attack_index.c intelligence/incident_engine.c \
core/entropy_analyzer.c

all:
	$(CC) $(CFLAGS) $(SRC) -o securevault -lssl -lcrypto -lm

clean:
	rm -f securevault
