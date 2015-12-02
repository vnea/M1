#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sched.h>
#include <synch.h>
#include <callo.h>
#include <string.h>

#include <types.h>
#include <conf.h>
#include <buf.h>
#include <proc.h>



void util1(void) {
  struct buf *buf;
  int i;
  
  printf("UTIL1 : Demande de [%d, %d] ([dev, blkno])...\n", 0, 0);
  buf = getblk(0, 0);
  printf("UTIL1 : [%d, %d] obtenu\nUTIL1 : Debut du traitement...\n", 0, 0);

  for (i=0;i<4E7;i++);
  printf("UTIL1 : Fin du traitement...\n");

  printf("UTIL1 : Appel à bwrite !B_ASYNC...\n");
  strcpy (*(buf -> b_addr),"***UTIL1 MSG***");
  bwrite(buf);

  printf("####################### fin UTIL1\n");
}

void util2(void) {
  struct buf *buf;
  int i;
  
  for (i=0;i<4E3;i++);
  printf("UTIL2 : Demande de [%d, %d] ([dev, blkno])...\n", 0, 0);

  buf = bread(0, 0);
  printf ("UTIL2: [%d, %d] obtenu. Contenu: %s\n", 0,0, *(buf->b_addr));

  printf("UTIL2 : Debut du traitement...\n");
  for (i=0;i<4E7;i++);

  printf("UTIL2 : Fin du traitement...\n");
  printf("UTIL2 : Appel à brelse...\n");

  brelse(buf);
/*   printfreelist(); */
/*   phbuf(); */
  printf("####################### fin UTIL2\n");
}


/* Exemples de primitive d'election definie par l'utilisateur */
/* Remarques : les primitives d'election sont appelées directement */
/*             depuis la librairie. Elles ne sont appélée que si au */
/*             moins un processus est à l'etat pret (RUN) */
/*             Ces primitives manipulent la table globale des processus */
/*             définie dans sched.h */


/* Election aléatoire */
int RandomElect(void) {
  int i;
  do {
    i = (int) ((float)MAXPROC*rand()/(RAND_MAX+1.0));
   
  } while (Tproc[i].p_flag != RUN);
  
  return i;
}

int strategy(void *args) {
    printf("Strategy : accés au device %d\n", ((struct buf*)args)->b_dev);
    printf("Strategy : Fin e/s dans 50 ticks...\n"); 
    timeout(iodone, args, 50);
    return 0;
  }
  
  int strategy2() {
    printf("\nStrategy2 function...\n\n");
    return 0;
  }

int main (void) {
  
  int *j;
  
  
  int dev0, dev1;
  
  dev0 = adddev(&strategy);
  pbdevsw();
  dev1 = adddev(&strategy2);
  pbdevsw();

  init_poolbuf(5);
  pbuf();
  init_hbuf(4, 0x3);
  phbuf();
  printfreelist();
  
  j = (int *) malloc(sizeof(int));
  *j= 0;
  CreateProc((function_t)util1, j, 80);
  
  j = (int *) malloc(sizeof(int));
  *j= 1;
  CreateProc((function_t)util2, NULL, 80);  
  
  
  /* Definir une nouvelle primitive d'election avec un quantum de 1 seconde */
  SchedParam(NEW, 1, 100000, RandomElect);
  
  /*   Lancer l'ordonnanceur en mode non "verbeux" */
  sched(0);
  
  /* Imprimer les statistiques */
  PrintStat();
  
  return EXIT_SUCCESS;
}
