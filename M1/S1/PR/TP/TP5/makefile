#			Programmation Repartie (4I400)
#		Makefile pour TM 5. Introduction aux sémaphores


# Documentation: http://www.gnu.org/software/make/manual/make.html
CC =gcc
LFLAGS =
CFLAGS =-W -Wall -ansi -pedantic -Iinclude

BIN =bin/
OBJ =obj/
INCLUDE =include/
LIB =lib/
SRC =src/

.SUFFIXES:

HC=
O=


.PHONY: all clean test
all: $(BIN)wait_barrier $(BIN)prod_conso_partagees
test: test-wait_barrier test-prod_conso_partagees

test-wait_barrier: $(BIN)wait_barrier
	-bin/wait_barrier 4

test-prod_conso_partagees: $(BIN)prod_conso_partagees
	-echo "123456789" | bin/prod_conso_partagees 5 3


clean: 
	rm -rf $(OBJ)*.o $(BIN)*

$(BIN)%: $(OBJ)%.o $O
	@if [ -d $(BIN) ]; then : ; else mkdir $(BIN); fi
	$(CC) $(LFLAGS) -o $@ $^

$(OBJ)%.o: $(SRC)%.c $(HC)
	@if [ -d $(OBJ) ]; then : ; else mkdir $(OBJ); fi
	$(CC) $(CFLAGS) -o $@ -c $<

$(INCLUDE)%.h:
	@if [ -d $(INCLUDE) ]; then : ; else mkdir $(INCLUDE); fi

