CC = gcc
OPT = -O3
CFLAGS = -Wall -Wpedantic -Wextra -g $(OPT)
BINARY=main
OBJECTS=main.o graphics.o

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
