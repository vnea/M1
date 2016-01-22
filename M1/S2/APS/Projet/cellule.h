#ifndef __cellule__
#define __cellule__

#include "ensemble.h"

typedef struct cellule_type{
	char* cle;
	ensemble* ens;
	struct cellule_type* succ;
}cellule;

cellule* creerCellule (char*, ensemble*);
void inserer( cellule**, cellule*);
cellule* rechercher( cellule*, char*);
void detruireCellule (cellule*);
void detruireListe( cellule*);

#endif
