#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    char args[124];
    char word[60];

    for(int i = 1; i<argc; i++){
        strcat(word, argv[i]);
        args[i-1]=*word;
    }
    printf("%s",args);
}  