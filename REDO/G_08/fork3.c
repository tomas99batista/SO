#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
    case -1: /* fork falhou */
        perror("Erro no fork\n");
        return EXIT_FAILURE;
    case 0: /* processo filho */
        //if (execl ("/bin/ls","/bin/ls","-l",NULL) < 0)
        if (execl("./child", "./child", NULL) < 0)
        {
            perror("erro no lancamento da aplicacao");
            return EXIT_FAILURE;
        }
        printf("Porque é que eu não apareço?\n");
        break;
    default: /* processo pai */
        sleep(1);
        printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }

    return EXIT_SUCCESS;
}

//From @tiagocmendes (GitHub)
/*
    Respostas à questão 3 do guião 8
    Linha 7 - Pai - 0 segundos
    Linha 8 - Pai e Filho
    Linhas 10 a 12 - ninguém
    Linhas 13 e 14 - Filho
    Linhas 15 a 17 - ninguém
    Linhas a seguir à 20 - Pai
   
    Em Bash, quando se faz $./child, a Bash faz um fork() para criar um novo processo e depois faz um
    exec() para criar um novo programa.
    $exec ./child, mata a Bash. 

    Ao fim de executar o exec() no filho, o PID vai-se manter.
    O exec() não cria um novo processo: executa do ínicio um novo programa dentro de um processo que já existia
    Quando o ls terminar, o processo 1015 também termina.
    O exec() não tem valor de retorno.
    
    int execl(char *path, char *arg0,..);
                    |- *path -> caminho para o executável
                    |- *arg0 -> define argv[0], argv[1] (lista terminada com NULL)
*/