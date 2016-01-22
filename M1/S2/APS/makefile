LEX = flex
YACC = yacc -d -v -l -t
CC = gcc

Aps: y.tab.c lex.yy.c 
	$(CC) -o Aps y.tab.c lex.yy.c -ll -lfl

y.tab.c y.tab.h: aps.y
	$(YACC) aps.y 

lex.yy.c: aps.l y.tab.h
	$(LEX) aps.l

