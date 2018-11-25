#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int num;
    printf("Num de words a passar?: ");
    scanf("%i", &num);
    char words[120];
    for (int i = 1; i <= num; i++)
    {
        printf("Word %i: ", i);
        scanf("%s", words);
    }
    for (int j = 0; j < sizeof(words); j++)
    {
        printf("%c", words[j]);
    }
}