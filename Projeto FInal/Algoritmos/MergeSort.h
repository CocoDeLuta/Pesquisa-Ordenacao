#include <stdio.h>

void merge(int vetor[], int esquerda, int meio, int direita){
  int i, j, k;
  int n1 = meio - esquerda + 1;
  int n2 =  direita - meio;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = vetor[esquerda + i];
  for (j = 0; j < n2; j++)
    R[j] = vetor[meio + 1+ j];

  i = 0;
  j = 0;
  k = esquerda;
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      vetor[k] = L[i];
      i++;
    }
    else{
      vetor[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1){
    vetor[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    vetor[k] = R[j];
    j++;
    k++;
  }
}

//funcao mergesort
void mergeSort(int vetor[], int esquerda, int direita){
  if(esquerda < direita){
    int meio = (esquerda + direita)/2;
    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio+1, direita);
    merge(vetor, esquerda, meio, direita);
  }
}
