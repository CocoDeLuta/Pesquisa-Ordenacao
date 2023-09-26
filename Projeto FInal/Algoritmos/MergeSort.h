#include <stdio.h>

void merge(int vetor[], int esq, int meio, int dir){
  int auxSize = dir - esq +1;
  int aux[auxSize];

  for(int i = esq; i<=dir; i++){
    aux[i-esq] = vetor[i];
  }

  int i = esq;
  int j = meio+1;
  int k = esq;
  while(i <= meio && j <= dir){
    if(aux[i - esq] <= aux[j - esq]){
      vetor[k] = aux[i - esq];
      i++;
    }else{
      vetor[k] = aux[j - esq];
      j++;
    }
    k++;
  }

  while(i <= meio){
    vetor[k] = aux[i - esq];
    i++;
    k++;
  }

  while(j <= dir){
    vetor[k] = aux[j - esq];
    j++;
    k++;
  }
}


void mergesort(int vetor[], int esq, int dir){
  if(esq < dir){
    int meio = (esq+dir)/2;
    mergesort(vetor,esq,meio);
    mergesort(vetor, meio+1, dir);
    merge(vetor, esq, meio, dir);
  }
}
