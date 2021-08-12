IDIR=../include
CC=gcc
CFLAGS=-I $(IDIR)

_DEPS=header.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))


CLIENT_DIR=.
_CLIENT_OBJ=main.o
CLIENT_OBJ=$(CLIENT_DIR)/$(_CLIENT_OBJ)

$(CLIENT_DIR)/client: $(CLIENT_OBJ) utils.o 
	$(CC) -o client $(CLIENT_OBJ) utils.o $(CFLAGS)

$(CLIENT_OBJ): $(CLIENT_DIR)/main.c $(DEPS)
	$(CC) -c -o $(CLIENT_OBJ) $(CLIENT_DIR)/main.c $(CFLAGS)

utils.o : ../utils.c $(DEPS)
	$(CC) -c ../utils.c $(CFLAGS)
