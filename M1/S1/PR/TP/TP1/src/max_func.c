#include "../include/max_func.h"

int max_func(int *arr, int length) {  
  int max = arr[0];    
  int i;
  for (i = 1; i < length; ++i) {
      if (arr[i] > max) {
          max = arr[i];
      }
  }
 
  return max;
}
