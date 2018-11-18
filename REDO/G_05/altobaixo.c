#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    // int random_number = rand() % 100 + 1;
    int random_number = (int)((100 - 1 +1)*((double)rand()/RAND_MAX) + 1);

    printf("%d", random_number);
    int tentativa = 0;
    int count = 0;
    do
    {
        printf("Tentativa: ");
        count++;
        scanf("%d", &tentativa);
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
