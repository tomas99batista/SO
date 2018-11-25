#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize;
    int *numbers;
    numSize = argc - 1;
    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);
    FILE *fp = fopen("nums.txt","r");
    int val;
    while(fscanf(fp,"%d", &val)==1){
        numbers[i]=val;
        i++;
    }
    // while(fread(&numbers, sizeof(fp)-1,1,fp)){
        // i++;
    // }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, i, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for(int j = 0 ; j < i ;j++)
    {
        printf("%d\n", numbers[j]);
    }

    return EXIT_SUCCESS;
}
