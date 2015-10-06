BIN_DIR=bin
INC_DIR=include
OBJ_DIR=obj
SRC_DIR=src

all: $(BIN_DIR)/forkfile $(BIN_DIR)/forkfilemax $(BIN_DIR)/mycp $(BIN_DIR)/remonte

$(BIN_DIR)/forkfile : $(OBJ_DIR)/forkfile.o
	gcc $(OBJ_DIR)/forkfile.o -o $(BIN_DIR)/forkfile

$(OBJ_DIR)/forkfile.o : $(SRC_DIR)/forkfile.c
	gcc -c $(SRC_DIR)/forkfile.c -o $(OBJ_DIR)/forkfile.o

$(BIN_DIR)/forkfilemax : $(OBJ_DIR)/forkfilemax.o
	gcc $(OBJ_DIR)/forkfilemax.o -o $(BIN_DIR)/forkfilemax

$(OBJ_DIR)/forkfilemax.o : $(SRC_DIR)/forkfilemax.c
	gcc -c $(SRC_DIR)/forkfilemax.c -o $(OBJ_DIR)/forkfilemax.o

$(BIN_DIR)/mycp : $(OBJ_DIR)/mycp.o
	gcc $(OBJ_DIR)/mycp.o -o $(BIN_DIR)/mycp

$(OBJ_DIR)/mycp.o : $(SRC_DIR)/mycp.c
	gcc -c $(SRC_DIR)/mycp.c -o $(OBJ_DIR)/mycp.o

$(BIN_DIR)/remonte : $(OBJ_DIR)/remonte.o
	gcc $(OBJ_DIR)/remonte.o -o $(BIN_DIR)/remonte

$(OBJ_DIR)/remonte.o : $(SRC_DIR)/remonte.c
	gcc -c $(SRC_DIR)/remonte.c -o $(OBJ_DIR)/remonte.o
