#include <stdio.h>

void insertsort(int vetor[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    int aux = vetor[i];
    int j = i-1;
    while(j >= 0 && aux < vetor[j]){
      vetor[j+1] = vetor[j];
      j = j-1;
      vetor[j+1] = aux;
    }
  }
}
