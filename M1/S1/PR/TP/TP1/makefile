BIN_DIR=bin
INC_DIR=include
OBJ_DIR=obj
SRC_DIR=src

all: $(BIN_DIR)/max_calcul $(BIN_DIR)/chaine_proc $(BIN_DIR)/synchro_proc $(BIN_DIR)/kill_proc $(BIN_DIR)/stop_and_go

$(BIN_DIR)/max_calcul : $(OBJ_DIR)/max_calcul.o $(OBJ_DIR)/max_func.o
	gcc $(OBJ_DIR)/max_calcul.o $(OBJ_DIR)/max_func.o -o $(BIN_DIR)/max_calcul

$(OBJ_DIR)/max_func.o : $(SRC_DIR)/max_func.c $(INC_DIR)/max_func.h
	gcc -c $(SRC_DIR)/max_func.c -o $(OBJ_DIR)/max_func.o

$(OBJ_DIR)/max_calcul.o : $(SRC_DIR)/max_calcul.c $(OBJ_DIR)/max_func.o
	gcc -c $(SRC_DIR)/max_calcul.c -o $(OBJ_DIR)/max_calcul.o

$(BIN_DIR)/chaine_proc : $(OBJ_DIR)/chaine_proc.o
	gcc $(OBJ_DIR)/chaine_proc.o -o $(BIN_DIR)/chaine_proc

$(OBJ_DIR)/chaine_proc.o : $(SRC_DIR)/chaine_proc.c
	gcc -c $(SRC_DIR)/chaine_proc.c -o $(OBJ_DIR)/chaine_proc.o

$(BIN_DIR)/kill_proc : $(OBJ_DIR)/kill_proc.o
	gcc $(OBJ_DIR)/kill_proc.o -o $(BIN_DIR)/kill_proc

$(OBJ_DIR)/kill_proc.o : $(SRC_DIR)/kill_proc.c
	gcc -c $(SRC_DIR)/kill_proc.c -o $(OBJ_DIR)/kill_proc.o

$(BIN_DIR)/stop_and_go : $(OBJ_DIR)/stop_and_go.o
	gcc $(OBJ_DIR)/stop_and_go.o -o $(BIN_DIR)/stop_and_go

$(OBJ_DIR)/stop_and_go.o : $(SRC_DIR)/stop_and_go.c
	gcc -c $(SRC_DIR)/stop_and_go.c -o $(OBJ_DIR)/stop_and_go.o
