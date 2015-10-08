BIN_DIR=bin
INC_DIR=include
OBJ_DIR=obj
SRC_DIR=src

all: $(BIN_DIR)/lectures $(BIN_DIR)/extended-grep $(BIN_DIR)/inverser-fichier $(BIN_DIR)/inverser-pread

$(BIN_DIR)/lectures : $(OBJ_DIR)/lectures.o
	gcc $(OBJ_DIR)/lectures.o -o $(BIN_DIR)/lectures

$(OBJ_DIR)/lectures.o : $(SRC_DIR)/lectures.c
	gcc -c $(SRC_DIR)/lectures.c -o $(OBJ_DIR)/lectures.o

$(BIN_DIR)/extended-grep : $(OBJ_DIR)/extended-grep.o
	gcc $(OBJ_DIR)/extended-grep.o -o $(BIN_DIR)/extended-grep

$(OBJ_DIR)/extended-grep.o : $(SRC_DIR)/extended-grep.c
	gcc -c $(SRC_DIR)/extended-grep.c -o $(OBJ_DIR)/extended-grep.o

$(BIN_DIR)/inverser-fichier : $(OBJ_DIR)/inverser-fichier.o
	gcc $(OBJ_DIR)/inverser-fichier.o -o $(BIN_DIR)/inverser-fichier

$(OBJ_DIR)/inverser-fichier.o : $(SRC_DIR)/inverser-fichier.c
	gcc -c $(SRC_DIR)/inverser-fichier.c -o $(OBJ_DIR)/inverser-fichier.o

$(BIN_DIR)/inverser-pread : $(OBJ_DIR)/inverser-pread.o
	gcc $(OBJ_DIR)/inverser-pread.o -o $(BIN_DIR)/inverser-pread

$(OBJ_DIR)/inverser-pread.o : $(SRC_DIR)/inverser-pread.c
	gcc -c $(SRC_DIR)/inverser-pread.c -o $(OBJ_DIR)/inverser-pread.o
