CC = gcc
CFLAGS = -Wall -Wextra -I./include -g
SRC = src/main.c src/auth.c src/routes.c src/booking.c src/receipt.c src/helpers.c
OBJ = $(SRC:.c=.o)
EXEC = bus_reservation

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
