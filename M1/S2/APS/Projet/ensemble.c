#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

ensemble* creerEnsemble (int val){
	ensemble* e = (ensemble*)malloc(sizeof(ensemble));
	e->val = val;
	e->succ = NULL;
	return e;
}

ensemble* copierEnsemble (ensemble* e1) {
	ensemble* e;
	ensemble* tmp;

	if(e1 != NULL) {
		e = creerEnsemble(e1->val);
		e1 = e1->succ;
		tmp = e;
	}
	while(e1 != NULL) {
		tmp->succ = creerEnsemble(e1->val);
		tmp = tmp->succ;
		e1 = e1->succ;
	}

	return e;
}

ensemble* additionner (ensemble* e1, ensemble* e2) {
	ensemble* e = NULL;
	ensemble* tmp;

	/* On initialise la premiere valeur de e */
	if((e1 != NULL) && (e2 != NULL)) {
		if(e1->val < e2->val) {
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
		}
		else if(e1->val > e2->val) {
			e = creerEnsemble(e2->val);
			e2 = e2->succ;
		}
		else{
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
			e2 = e2->succ;
		}
	}
	tmp = e;
	while((e1 != NULL) && (e2 != NULL)){
		if(e1->val < e2->val) {
			tmp->succ = creerEnsemble(e1->val);
			e1 = e1->succ;
		}
		else if(e1->val > e2->val) {
			tmp->succ = creerEnsemble(e2->val);
			e2 = e2->succ;
		}
		else{
			tmp->succ = creerEnsemble(e1->val);
			e1 = e1->succ;
			e2 = e2->succ;
		}
		tmp = tmp->succ;
	} 
	if(e1 == NULL) {
		if((e == NULL) && (e2 != NULL)) {
			e = creerEnsemble(e2->val);
			e2 = e2->succ;
			tmp = e;
		}
		while(e2 != NULL){
			tmp->succ = creerEnsemble(e2->val);
			tmp = tmp->succ;
			e2 = e2->succ;
		}
	}
	else {
		if((e == NULL) && (e1 != NULL)) {
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
			tmp = e;
		}
		while(e1 != NULL){
			tmp->succ = creerEnsemble(e1->val);
			tmp = tmp->succ;
			e1 = e1->succ;
		}
	}

	return e;
}

ensemble* soustraire(ensemble* e1, ensemble* e2) {
	ensemble* e = NULL;
	ensemble* tmp;

	/* On initialise la premiere valeur de e */
	while((e == NULL) && (e1 != NULL) && (e2 != NULL)) {
		if(e1->val < e2->val) {
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
		}
		else if(e1->val > e2->val) {
			while((e2 != NULL) && (e1->val > e2->val)) {
				e2 = e2->succ;
			}
		}
		else {
			e1 = e1->succ;
			e2 = e2->succ;	
		}
	}
	tmp = e;
	while((e1 != NULL) && (e2 != NULL)) {
		if(e1->val < e2->val) {
			tmp->succ = creerEnsemble(e1->val);
			tmp = tmp->succ;
			e1 = e1->succ;
		}
		else if(e1->val > e2->val) {
			while((e2 != NULL) && (e1->val > e2->val)) {
				e2 = e2->succ;
			}
		}
		else {
			e1 = e1->succ;
			e2 = e2->succ;	
		}
	}
	if(e2 == NULL) {
		if((e == NULL) && (e1 != NULL)) {
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
			tmp = e;
		}
		while(e1 != NULL){
			tmp->succ = creerEnsemble(e1->val);
			tmp = tmp->succ;
			e1 = e1->succ;
		}
	}
	
	return e;
}

ensemble* multiplier(ensemble* e1, ensemble* e2) {
	ensemble* e = NULL;
	ensemble* tmp;

	/* On initialise la premiere valeur de e */
	while((e == NULL) && (e1 != NULL) && (e2 != NULL)) {	
		if(e1->val < e2->val)
			e1 = e1->succ;
		else if(e1->val > e2->val)
			e2 = e2->succ;
		else {
			e = creerEnsemble(e1->val);
			e1 = e1->succ;
			e2 = e2->succ;
		}
	}
	tmp = e;
	while((e1 != NULL) && (e2 != NULL)) {
		if(e1->val < e2->val)
			e1 = e1->succ;
		else if(e1->val > e2->val)
			e2 = e2->succ;
		else{
			tmp->succ = creerEnsemble(e1->val);
			tmp = tmp->succ;
			e1 = e1->succ;
			e2 = e2->succ;
		}
	}
		
	return e;
}

int nbElements(ensemble* e) {
	int cpt = 0;

	while(e != NULL) {
		cpt++;
		e = e->succ;
	}
	return cpt;
}

void afficherEnsemble(ensemble* e){
	printf("[");
	while(e != NULL){
		if(e->succ != NULL)
			printf("%d ", e->val);
		else
			printf("%d", e->val);
		e = e->succ;
	}
	printf("]");
}








