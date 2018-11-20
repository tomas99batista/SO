#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int val, opt;
    while ((opt = getopt(argc, argv, "abc:")) != -1)
    {
        switch (opt)
        {
        case 'a':
            printf("SOp\n");
            break;
        case 'b':
            printf("Aveiro\n");
            break;
        case 'c':
            val = atoi(optarg);
            printf("%d\n", val);
            break;
        default:
            fprintf(stderr, "Usage: %s [-a] [-b] [-c valor]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}