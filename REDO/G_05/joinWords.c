#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, j, numChars;
    char arg[100], sentence[100];

    numChars = 0;
    for (i = 1; i < argc; i++)
    {
        strcat(arg, argv[i]);
    }


    printf("Sentence: %s\n%li\n", arg, strlen(arg));
    return 0;
}