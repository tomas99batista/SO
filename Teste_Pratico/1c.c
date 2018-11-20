#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int n, r;
    if (argc < 2)
    {
        printf("ERRO nos argumentos\n");
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i++)
    {
        n = atoi(argv[i]);
        r += n;
        printf("%d", n);
    }
    printf("Resultado: %d\n", r);
    return EXIT_SUCCESS;
}