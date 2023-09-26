#include <stdio.h>

void imprimeVetor(int vetor[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d \t",vetor[i]);
  }
}