IDIR=../include
CC=gcc
CFLAGS=-I $(IDIR)

_DEPS=header.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))


SERVER_DIR=.
_SERVER_OBJ=main.o
SERVER_OBJ=$(SERVER_DIR)/$(_SERVER_OBJ)

$(SERVER_DIR)/server: $(SERVER_OBJ) utils.o 
	$(CC) -o server $(SERVER_OBJ) utils.o $(CFLAGS)

$(SERVER_OBJ): $(SERVER_DIR)/main.c $(DEPS)
	$(CC) -c -o $(SERVER_OBJ) $(SERVER_DIR)/main.c $(CFLAGS)

utils.o : ../utils.c $(DEPS)
	$(CC) -c ../utils.c $(CFLAGS)
