#ifndef __ensemble__
#define __ensemble__

typedef struct cellule_ensemble{
	int val;
	struct cellule_ensemble* succ;
}ensemble;

ensemble* creerEnsemble (int);
ensemble* copierEnsemble (ensemble*);
ensemble* additionner (ensemble*, ensemble*);
ensemble* soustraire(ensemble*, ensemble*);
ensemble* multiplier(ensemble*, ensemble*);
ensemble* adjonction(int, ensemble*);
int nbElements(ensemble*);
void afficherEnsemble(ensemble*);

#endif
