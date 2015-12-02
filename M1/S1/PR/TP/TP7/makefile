#			Programmation Repartie (4I400)
#		Makefile pour TM 7. Simulation d'un service FTP


# Documentation: http://www.gnu.org/software/make/manual/make.html
CC =gcc
LFLAGS =
CFLAGS =-W -Wall -ansi -pedantic -Iinclude

DIR=.
BIN=$(DIR)/bin/
OBJ=$(DIR)/obj/
INCLUDE=$(DIR)/include/
LIB=$(DIR)/lib/
SRC=$(DIR)/src/

.SUFFIXES:

HC=
O=

.PHONY: all clean test test-ftp_server test-ftp_client
all: $(BIN)ftp_server $(BIN)ftp_client

test: test-ftp_server test-ftp_client

test-ftp_server: $(BIN)ftp_server
	-$$PWD/bin/ftp_server 2000 /tmp &

test-ftp_client: $(BIN)ftp_client
	-$$PWD/bin/ftp_client 127.0.0.1 2000

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

