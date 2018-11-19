#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;
    Person p;
    int np; //Num de pessoas 
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    //Interativo, pessoa e que diz qnts pessoas quer
    printf("Num de pessoas?\n");
    scanf("%d", &np);
 

    /* Write 10 itens on a file */
    //for(i = 0 ; i < 10 ; i++)
        //p.age = p.age+1;
        //p.height = p.height+0.03;
        //fwrite(&p, sizeof(Person), 1, fp);

    for(i=0; i < np; i++)
    {    
        printf("Nome, Idade, Altura?\n");
        scanf(" %[^\n]", p.name);   //le ate ao fim ou seja \n, 
                                    //no ultimo scanf o buffer ainda n leu um \n, 
                                    //ou seja por isso pomos _\n
        scanf("%d", &p.age);
        scanf("%lf", &p.height);
        fwrite(&p,sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}