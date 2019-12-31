CC = gcc
CPATH = ./include
CFLAGS = -I $(CPATH) -Wall -Wextra -Werror
SRC = ./src

OBJECTS = $(.c=.o)

%.o : %.h %.c 
	$(CC) $(CFLAGS) %.c -o $@

all: $(OBJECTS) build

build: $(SRC)/build.c $(OBJECTS)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -f *.o build
