#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Num errado de args, %d, deve passar apenas 3 (num, operacao, num)\n", argc-1);
    }
    else
    {
        double num1 = atof(argv[1]);
        double num2 = atof(argv[3]);
        char op = *argv[2];
        // switch(op){
        //     case '+':
        //etc etc etc etc
        //     break;
        // }
        if (strncmp(argv[2], "+", 1) == 0)
        {
            float resultado = num1 + num2;
            printf("%f %s %f = %f\n", num1, argv[2], num2, resultado);
        }
        else if (strncmp(argv[2], "-", 1) == 0)
        {
            float resultado = num1 - num2;
            printf("%f %s %f = %f\n", num1, argv[2], num2, resultado);
        }
        else if (strncmp(argv[2], "x", 1) == 0)
        {
            float resultado = num1 * num2;
            printf("%f %s %f = %f\n", num1, argv[2], num2, resultado);
        }
        else if (strncmp(argv[2], "/", 1) == 0)
        {

            float resultado = num1 / num2;
            printf("%f %s %f = %f\n", num1, argv[2], num2, resultado);
        }
        else if (strncmp(argv[2], "p", 1) == 0)
        {

            // float resultado = pow(num1, num2);
            // printf("%f %s %f = %f\n", num1, argv[2], num2, resultado);
            printf("pow bugado");
        }
        else
        {
            printf("argv[2] nao definida %s", argv[2]);
        }
    }

    return EXIT_SUCCESS;
}
