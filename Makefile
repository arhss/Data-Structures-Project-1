CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = build
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
   $(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_DIR)