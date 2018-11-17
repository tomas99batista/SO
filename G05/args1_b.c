#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    //if(argc != 2)
      //  printf("Num de argumentos errado, deve pasar 2 args: \"%s\"\n", length(argv));        

    else{
        int i;
        for(i = 0 ; i < argc ; i++)
        {
            printf("Argument %d: \"%s\"\n", i, argv[i]);        
        }
    }
    
    return EXIT_SUCCESS;
}