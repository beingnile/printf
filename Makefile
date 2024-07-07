CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Wno-format -std=gnu89

TARGET = print
SRCS = main.c _printf.c print_helpers.c utilities.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
