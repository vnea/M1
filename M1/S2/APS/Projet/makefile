LEX = flex
YACC = yacc -d -v -l -t
CC = gcc

Projet: y.tab.c lex.yy.c cellule.o ensemble.o
	$(CC) -o Projet y.tab.c lex.yy.c cellule.o ensemble.o -ll -lfl

y.tab.c y.tab.h: Projet.y
	$(YACC) Projet.y 

lex.yy.c: Projet.lex y.tab.h
	$(LEX) Projet.lex

cellule.o: cellule.c
	$(CC) -o cellule.o -c cellule.c

ensemble:o ensemble.c
	$(CC) -o ensemble.o -c ensemble.c

