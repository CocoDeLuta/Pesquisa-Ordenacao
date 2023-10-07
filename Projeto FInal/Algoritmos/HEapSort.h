#include <stdio.h>

void heapfy_down(int *a, int i, int tamanho){
  int maior = i;
  int esquerda = 2*i+1;
  int direita = 2*i+2;

  if(esquerda < tamanho && a[esquerda] > a[maior]){
    maior = esquerda;
  }

  if(direita < tamanho && a[direita] > a[maior]){
    maior = direita;
  }

  if(maior != i){
    int temp = a[i];
    a[i] = a[maior];
    a[maior] = temp;
    heapfy_down(a, maior, tamanho);
  }
}

void heapSort(int *a, int tamanho){
  for( int i = tamanho /2 - 1; i >=0; i--){
    heapfy_down(a, i, tamanho);
  }

  for(int i = tamanho -1; i>= 0; i--){
      int temp = a[0];
      a[0] = a[i];
      a[i] = temp;
    heapfy_down(a, 0, i);
  }
}