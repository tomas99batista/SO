#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("PFV insira 1 argumento para o ficheiro e nao %d", argc - 1);
        return EXIT_FAILURE;
    }
    FILE *fp = NULL;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Falha ao abrir o ficheiro!");
        return EXIT_FAILURE;
    }
    char palavras[300];
    int countwords, countup, countdown;
    countwords = 0;
    countdown = 0;
    countup = 0;
    while (fgets(palavras, 300, fp) != NULL)
    {
        printf("%s", palavras);
        countwords++;
        for (int i = 0; i < strlen(palavras); i++)
        {
            int letra = (int)palavras[i];
            if (islower(letra))
            {
                countdown++;
            }
            else if (isupper(letra))
            {
                countup++;
            }
        }
    }
    printf("palavras: %d\nlower: %d\nupper: %d\n", countwords, countdown, countup);
    fclose(fp);
    return EXIT_SUCCESS;
}