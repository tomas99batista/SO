#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0)
    {
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0)    //Se ret > 0 e o pai
        sleep(1);   //Sleep e fica em espera q o filho faca as suas coisas e depois faz as suas

    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d\n", getpid(), getppid());

    return EXIT_SUCCESS;
}

/*  >linha 9 exec pelo pai
    >na linha 10 e feito o fork o que resulta no pai e filho
    >na linha 5 irao ser exec os comandos para o pai e o filho
    >Impressao: 1 (linha 9) + 2 (pai e filho) x 2 (linha 15 tem \n)
    >5 linhas impressas

    processo-pai do programa em execução >>> Bash
*/