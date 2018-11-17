#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);     //Passa um void * -> int * -> int
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize,j;
    int *numbers;
    numSize = 100;

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);

    FILE *fp = fopen(argv[1], "r");
    i = 0;
    int val;
    while(fscanf(fp, "%d", &val)==1){
        numbers[i]=val;
        i++;
        }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, i, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for(j = 0 ; j < i ; j++)
    {
        printf("%d\n", numbers[j]);
    }

    return EXIT_SUCCESS;
}
