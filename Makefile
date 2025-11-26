CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iproducts -Iutils -Ierrors

SRC = $(wildcard *.c */*.c)
OBJ = $(SRC:.c=.o)
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)