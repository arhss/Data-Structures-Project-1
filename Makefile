CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = build
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)