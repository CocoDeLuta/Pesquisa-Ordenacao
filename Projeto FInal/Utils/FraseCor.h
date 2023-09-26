#include <stdlib.h>
#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

//A função Frase iprime uma string com uma cor especifica
void FraseCor(char frase[], char cor[])
{
    //Código de cores ANSI
    //https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
    switch(cor[0])
    {
        case 'r':
            printf(RED "%s" RESET, frase);
            break;
        case 'g':
            printf(GREEN "%s" RESET, frase);
            break;
        case 'y':
            printf(YELLOW "%s" RESET, frase);
            break;
        case 'b':
            printf(BLUE "%s" RESET, frase);
            break;
        case 'm':
            printf(MAGENTA "%s" RESET, frase);
            break;
        case 'c':
            printf(CYAN "%s" RESET, frase);
            break;
        default:
            printf(RESET "%s" RESET, frase);
            break;
    }
}