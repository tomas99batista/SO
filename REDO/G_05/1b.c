#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int argumentos = -1;
    for(int j = 0; j< argc; j++){
        argumentos++;
    }
    if (argc != 3)
    {
        printf("Num errado de args, %d, deve passar apenas dois\n", argumentos);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            printf("Argument %d: \"%s\"\n", i, argv[i]);
        }
    }
    return EXIT_SUCCESS;
}
