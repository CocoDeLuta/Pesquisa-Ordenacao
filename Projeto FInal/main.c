#include "lib.h"

#define LOW 500
#define MID 750
#define HIGH 1000

int main(void) // Função principal
{
    setlocale(LC_ALL, "en_US.UTF-8"); // formata o console
    system("cls");

    int sair = 0; // 0 = não sair, 1 = sair
    int flag, arqu = 0, tam;
    FILE *file500, *file750, *file1m;

    // variavel para continuar ou sair do programa
    int continuar = 1; // 0 = sair, 1 = continuar
    while (continuar == 1)
    {
        system("cls");
        sair = 0;
        while (sair == 0) // Enquanto o usuário não sair do programa
        {
            printf("Qual o tamanho do teste?"); // Pergunta ao usuário qual o tamanho do teste
            printf("\n1. 500k");
            printf("\n2. 750k");
            printf("\n3. 1kk\n");
            scanf("%d", &flag);

            arqu = flag;

            switch (flag)
            {
            case 1: // 500k
                tam = LOW;
                file500 = fopen("numeros500.txt", "w");
                if (file500 != NULL) // Se o arquivo foi aberto com sucesso
                {
                    ordemFile(file500, 1, tam); // Verifica a ordem do arquivo
                }
                else // Se o arquivo não foi aberto com sucesso
                {
                    ordemFile(file500, 0, tam); // Cria um novo arquivo
                }
                sair = 1;
                break;

            case 2: // (750k)
                tam = MID;
                file750 = fopen("numeros750.txt", "w");
                if (file750 != NULL)
                {
                    ordemFile(file750, 1, tam);
                }
                else
                {
                    ordemFile(file750, 0, tam);
                }
                sair = 1;
                break;

            case 3: //(1kk)
                tam = HIGH;
                file1m = fopen("numeros1m.txt", "w");
                if (file1m != NULL)
                {
                    ordemFile(file1m, 1, tam);
                }
                else
                {
                    ordemFile(file1m, 0, tam);
                }
                sair = 1;
                break;

            default:
                FraseCor("Opção inválida", "r");
                break;
            }
        }

        sair = 0;

        int vetor[tam];

        switch (arqu)
        {
        case 1: // 500k
            file500 = fopen("numeros500.txt", "r");
            transferirVetor(vetor, file500);
            break;

        case 2: // 750k
            file750 = fopen("numeros750.txt", "r");
            transferirVetor(vetor, file750);
            break;

        case 3: // 1kk
            file1m = fopen("numeros1m.txt", "r");
            transferirVetor(vetor, file1m);
            break;
        }

        // perguntar se quer imprimir o vetor
        printf("Deseja imprimir o os dados?\n1. Sim\n2. Não\n");
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("\n Dados gerados: \n");
            imprimeVetor(vetor, tam);
        }

        // Menu de ordenação
        while (sair == 0)
        {
            // perguntar qual o modo de ordenação
            printf("\n\nQual o modo de ordenação?\n1. InsertSort\n2. MergeSort\n3.QuickSort\n4.RadixSort\n5.HeapSort\n"); // Exibe um menu de opções
            scanf("%d", &flag);

            switch (flag)
            {
            case 1:
                FraseCor("Ordenando vetor...\n\n", "y");
                insertsort(vetor, tam);
                FraseCor("Vetor ordenado com sucesso!\n\n", "g");
                sair = 1; // Sai do menu de ordenação
                break;

            case 2:
                FraseCor("Ordenando vetor...\n\n", "y");
                mergeSort(vetor, 0, tam);
                FraseCor("Vetor ordenado com sucesso!\n\n", "g");

                sair = 1; // Sai do menu de ordenação
                break;

            case 3:
                FraseCor("Ordenando vetor...\n\n", "y");
                quickSort(vetor, 0, tam);
                FraseCor("Vetor ordenado com sucesso!\n\n", "g");

                sair = 1; // Sai do menu de ordenação
                break;

            case 4:
                FraseCor("Ordenando vetor...\n\n", "y");
                radixSort(vetor, tam);
                FraseCor("Vetor ordenado com sucesso!\n\n", "g");

                sair = 1; // Sai do menu de ordenação
                break;

            case 5:
                FraseCor("Ordenando vetor...\n\n", "y");
                heapSort(vetor, tam);
                FraseCor("Vetor ordenado com sucesso!\n\n", "g");
                sair = 1; // Sai do menu de ordenação
                break;

            default:
                FraseCor("Opção inválida\n\n", "r");

                break;
            }
        }

        // perguntar se quer imprimir o vetor
        printf("\n\nDeseja imprimir os dados?\n1. Sim\n2. Não\n");
        scanf("%d", &flag);
        if (flag == 1)
        {
            printf("\n Dados ordenado: \n");
            imprimeVetor(vetor, tam);
        }

        printf("\n\nDeseja sair do programa?\n0. Sim\n1. Não\n");
        scanf("%d", &continuar);
        printf("%d", continuar);
    }

    fclose(file500);
    fclose(file750);
    fclose(file1m);

    return 0;
}