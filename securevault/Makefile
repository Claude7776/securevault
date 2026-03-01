CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/crypto.c src/file.c src/utils.c
OUT = build/vault

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build

re: clean all
