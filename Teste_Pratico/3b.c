#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
typedef struct
{
    double x;
    double y;
} Point2D;

void printPoint2D(Point2D *p)
{
    printf("(%3.lf, %3.lf\n", p->x, p->y);
}
int sum = 0;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("PFV insira apenas 1 argumento para o ficheiro e nao %d", argc - 1);
        return EXIT_FAILURE;
    }
    FILE *fp = NULL;
    Point2D pt, sum;
    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        printf("Falha ao abrir o ficheiro!");
        return EXIT_FAILURE;
    }
    while (fread(&pt, sizeof(Point2D), 1, fp) == 1)
    {
        sum.x += pt.x;
        sum.y += pt.y;
    }
    printPoint2D(&sum);
    fclose(fp);
    return EXIT_SUCCESS;
}