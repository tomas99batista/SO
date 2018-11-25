#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int randmax, randmin;
    if (argc != 3)
    {
        printf("Pfv insira 2 args apenas, o valor max e o min para gerar rand\n");
        return EXIT_FAILURE;
    }
    else
    {
        randmax = atoi(argv[1]);
        randmin = atoi(argv[2]);
    }
    int random_number = (int)((randmax - randmin + 1) * ((double)rand() / RAND_MAX) + 1);

    printf("%d\n", random_number);
    int tentativa = 0;
    int count = 0;
    do
    {
        printf("Tentativa: ");
        scanf("%d", &tentativa);
        count++;
        if (tentativa == random_number)
        {
            printf("Parabens! Numero era %d\nAcertaste apos %d tentativas\n", tentativa, count);
        }
        else
        {
            if (tentativa > random_number)
            {
                printf("Numero muito alto, tenta + baixo\n");
            }
            else
            {
                printf("Numero muito baixo, tenta + alto\n");
            }
        }

    } while (tentativa != random_number);
}
