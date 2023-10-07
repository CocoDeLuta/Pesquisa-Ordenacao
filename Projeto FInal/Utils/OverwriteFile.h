#include <stdlib.h>
#include "FraseCor.h"

// Função para sobrescrever um arquivo com novos dados
void overwriteFile(FILE *ponteiro, int tam) 
{
    int flag = 0; 
    printf("Qual a ordem de escrita dos números?\n1. Ordenado\n2. Invertido\n3. Aleatório\n"); 
    scanf("%d", &flag); 

    switch (flag) 
    {
    case 1: //ordenado
        for (int i = 0; i < tam; i++) 
        {
            fprintf(ponteiro, "%d\n", i);
        }
        fclose(ponteiro); 
        break;

    case 2: // invertido
        for (int i = tam; i >= 1; i--) 
        {
            fprintf(ponteiro, "%d\n", i);
        }
        fclose(ponteiro); 
        break;

    case 3: // random
        for (int i = 1; i <= tam; i++) 
        {
            fprintf(ponteiro, "%d\n", rand() % tam);
        }
        fclose(ponteiro); 
        break;

    default: 
        FraseCor("Opção inválida", "r"); 
        break;
    }
}