cc = gcc
CFLAGS = -Wall -Wextra -g -I./include
BINDIR = bin
LIBDIR = lib
LIB = $(LIBDIR)/libprojet.a

TARGET = $(BINDIR)/main
TEST_TARGET = $(BINDIR)/test_main
SRC = src/main.c src/system.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC =  $(BINDIR)/trajectoire
TEST_SRC = test/test_main.c

TEST_OBJ = $(TEST_SRC:.c=.o)



all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBDIR) -lprojet

test: test/test_main.o src/system.o src/utils.o
	$(CC) $(CFLAGS) -o $(BINDIR)/test_main src/system.o src/utils.o test/test_main.o -L$(LIBDIR) -lprojet


%.o: %.c
	$(CC) $(CFLAGS) -I./include -c $< -o $@
clean:
	rm -f $(OBJ) $(EXEC) $(TEST_OBJ) $(TEST_TARGET)
$(LIB):
	ar rcs $(LIB) lib/system.o lib/utils.o
 
.PHONY : all clean
