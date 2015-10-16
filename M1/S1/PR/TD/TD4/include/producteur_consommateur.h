#define PRODUCTEUR int c; printf("Prod\n"); while((c = getchar()) != EOF){ push(c); }

#define CONSOMMATEUR printf("Conso\n"); while(1) { putchar(pop()); fflush(stdout); }
