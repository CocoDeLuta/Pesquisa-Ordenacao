#include <stdlib.h>
#include <stdio.h>

// Função para transferir dados de um arquivo para um vetor
void transferirVetor(int *vetor, FILE *ponteiro) 
{
    char line[20]; // Define uma string para armazenar cada linha do arquivo
    int cont = 0; 

    while (!feof(ponteiro)) // Enquanto não chegar ao final do arquivo
    {
        fscanf(ponteiro, "%s", line); // Lê uma linha do arquivo
        vetor[cont] = atof(line); // Converte a linha para um número e armazena no vetor
        cont++; 
    }
}
