BIN_DIR=bin
INC_DIR=include
OBJ_DIR=obj
SRC_DIR=src

$(BIN_DIR)/max_calcul : $(OBJ_DIR)/max_calcul.o $(OBJ_DIR)/max_func.o
	gcc $(OBJ_DIR)/max_calcul.o $(OBJ_DIR)/max_func.o -o $(BIN_DIR)/max_calcul

$(OBJ_DIR)/max_func.o : $(SRC_DIR)/max_func.c $(INC_DIR)/max_func.h
	gcc -c $(SRC_DIR)/max_func.c -o $(OBJ_DIR)/max_func.o

$(OBJ_DIR)/max_calcul.o : $(SRC_DIR)/max_calcul.c $(OBJ_DIR)/max_func.o
	gcc -c $(SRC_DIR)/max_calcul.c -o $(OBJ_DIR)/max_calcul.o
