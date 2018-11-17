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
    Person p;
    int np; //num persons lidas
    Person ps[1024];
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    
    //ler ficheiro para array
    np = fread(ps, sizeof(Person),1024,fp); //np toma o valor de quantas pessoas leu
                                            //e o return do fp
    
    //add pessoas ao array
    for(int i=0; i < np; i++)
    {    
        printf("Nome, Idade, Altura?\n");
        scanf(" %[^\n]", p.name);   //le ate ao fim ou seja \n, 
                                    //no ultimo scanf o buffer ainda n leu um \n, 
                                    //ou seja por isso pomos _\n
        scanf("%d", &p.age);
        scanf("%lf", &p.height);
        
    }
    
    //escrever pessoas no file
    
    // /* read all the itens of the file */
    // while(fread(&p, sizeof(Person), 1, fp) == 1)
    // {
    //     printPersonInfo(&p);
    // }


    fclose(fp);
    return EXIT_SUCCESS;
}
