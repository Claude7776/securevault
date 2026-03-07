CC = gcc
CFLAGS = -Wall -g
SRC = $(wildcard crypto/*.c vault/*.c intelligence/*.c log/*.c core/*.c main.c)
OBJ = $(SRC:.c=.o)
TARGET = securevault

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
