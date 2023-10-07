#include <stdio.h>
#include <malloc.h>
#include <math.h>

//função radixSort
void radixSort(int *vetor, int tam) {
    int i, exp = 1, maior = vetor[0];
    int *aux;
    aux = (int*) malloc(tam * sizeof (int));

    for (i = 0; i < tam; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior / exp > 0) {
        int bucket[10] = {0};
        for (i = 0; i < tam; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tam - 1; i >= 0; i--)
            aux[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tam; i++)
            vetor[i] = aux[i];
        exp *= 10;
    }
    free(aux);
}
