#include <stdio.h>
#include <stdlib.h>
#include "../include/max_func.h"

int main(int argc, char **argv) {
  if (argc > 1) {
      int length_arr = argc - 1;
      int *arr = malloc(sizeof(int) * length_arr);
      int i;
      for (i = 1; i < argc; ++i) {
          arr[i - 1] = atoi(argv[i]);
      }
     
      printf("La maximum est : %d\n", max_func(arr, length_arr));
      free(arr);
  }
  else {
      printf("Utilisation : max_calcul liste_de_nombres\n");
  }
 
  return 0;
}
