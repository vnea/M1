BIN_DIR=bin
INC_DIR=include
OBJ_DIR=obj
SRC_DIR=src

all: $(BIN_DIR)/lectures

$(BIN_DIR)/lectures : $(OBJ_DIR)/lectures.o
	gcc $(OBJ_DIR)/lectures.o -o $(BIN_DIR)/lectures

$(OBJ_DIR)/lectures.o : $(SRC_DIR)/lectures.c
	gcc -c $(SRC_DIR)/lectures.c -o $(OBJ_DIR)/lectures.o
