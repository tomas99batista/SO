#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int n1, n2, r;
    if (argc < 3)
    {
        printf("ERRO nos argumentos\n");
        return EXIT_FAILURE;
    }
    n1 = atoi(argv[1]);
    n2 = atoi(argv[2]);
    r = n1 * n2;
    printf("Resultado: %d\n", r);
    return EXIT_SUCCESS;
}