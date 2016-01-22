#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cellule.h"

cellule* creerCellule (char* cle, ensemble* ens){
	cellule* c = (cellule*)malloc(sizeof(cellule));
	c->cle = (char*)malloc(strlen(cle) + 1);
	strcpy(c->cle, cle);
	c->ens = ens;
	c->succ = NULL;
	return c;
}

/* Insere en tete de liste */
void inserer( cellule** tete, cellule* c ){
	c->succ = *tete;
	*tete = c;
}

/* Renvoie la cellule ayant id pour cle ou null si elle n'existe pas */
cellule* rechercher( cellule* tete, char* id){
	cellule* c = tete;
	while( (c!=NULL)  && (strcmp(c->cle, id) != 0) ){
		c = c->succ;
	}
	return c;
}

void detruireCellule (cellule* c){
	free(c->cle);
}

void detruireListe( cellule* tete){
	cellule* c = tete;
	cellule* c2 = NULL;
	while( c != NULL ){
		c2 = c->succ;
		detruireCellule(c);
		free(c);
		c = c2;
	}	
}
