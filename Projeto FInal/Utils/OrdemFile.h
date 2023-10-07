#include <stdio.h>
#include "OverwriteFile.h"

// Função para verificar a ordem de um arquivo
void ordemFile(FILE *ponteiro, int situacao, int tam) 
{
    //situacao = 0 -> arquivo não existe
    //situacao = 1 -> arquivo existe

    int i = 0; // Define uma variável para armazenar a escolha do usuário

    if (situacao == 1) 
    {
        printf("Arquivo já está escrito, deseja sobreescrever?\n1. Sim\n2. Não\n"); 
        while ((i != 1) && (i != 2)) // Enquanto a escolha do usuário não for 1 ou 2
        {
            scanf("%d", &i); // Lê a escolha do usuário
            if ((i != 1) && (i != 2)) // Se a escolha for inválida
            {
                FraseCor("Opção inválida", "r"); // Exibe uma mensagem de erro
            }
        }
    }
    else // Se o arquivo não estiver escrito
    {
        i = 1; // Define a escolha do usuário como 1 (sobrescrever)
    }

    if (i == 1) // Se o usuário escolheu sobrescrever o arquivo
    {
        overwriteFile(ponteiro, tam); // Chama a função para sobrescrever o arquivo
    }
}