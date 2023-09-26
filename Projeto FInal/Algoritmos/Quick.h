#include <stdio.h>

int particione(int vetor[], int esq, int dir) {
  int x = vetor[esq];
  int up = dir;
  int down = esq;

  while (down < up) {
    while ((vetor[down] <= x) && (down < dir)) {
      down++;
    }
    while (vetor[up] > x) {
      up--;
    }
    if (down < up) {
      int aux = vetor[down];
      vetor[down] = vetor[up];
      vetor[up] = aux;
    }
  }
  vetor[esq] = vetor[up];
  vetor[up] = x;
  return up;
}

int lomutoParticione(int vetor[], int esq, int dir) {
  int i = esq;
  int pivo = vetor[i];
  int j = i + 1;
  int aux;

  while (j < dir) {
    if (vetor[j] > vetor[i]) {
      j++;
    } else {
      i++;
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
    }
  }
  aux = pivo;
  vetor[esq] = vetor[i];
  vetor[i] = aux;

  int part = particione(vetor, esq, dir);
  return i;
}

void lomuto(int vetor[], int esq, int dir) {
  int i;
  if (dir > esq) {
    i = lomutoParticione(vetor, esq, dir);
    lomuto(vetor, esq, i - 1);
    lomuto(vetor, i + 1, dir);
  }
}

void quickSort(int vetor[], int esq, int dir) {
  int i;
  if (dir > esq) {
    i = particione(vetor, esq, dir);
    quickSort(vetor, esq, i - 1);
    quickSort(vetor, i + 1, dir);
  }
}
