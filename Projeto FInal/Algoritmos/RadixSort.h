#include <stdio.h>
#include <malloc.h>
#include <math.h>

void radixSort(int A[], int tamanho){
  int base = 10, r;
  int digit = 3;
  int *B = (int *)malloc(tamanho*sizeof(int)); 
  int *C = (int *)malloc(tamanho*sizeof(int));
  for(int m = 0; m < digit; m++){
    for(int j = 0; j < tamanho; j++){
      r = (A[j] / (int)(pow(10.0,m))) % base;
      ++C[r];
    }

    for(int i = 1; i < base; i++){
      C[i] += C[i - 1];
    }

    for(int j = tamanho-1; j >= 0; --j){
      r = (A[j] / (int)(pow(10.0,m))) % base;
      int i = --C[r];
      B[i] = A[j];
    }

    for( int j = 0; j < tamanho; ++j){
      A[j] = B[j];
    }
  }
}
