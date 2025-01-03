cc = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main.c src/systems.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC = bin/simulation

defaut : all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)
 
.PHONY : all clean