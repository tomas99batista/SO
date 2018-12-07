//Receive e print mensagem
//Create
//Connect
//Receive & print

//openCom
// closeCom
// receive
// main

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MSG_MAX  512    /* maximum size allowed for a message */

typedef struct message
{
    unsigned int size;   /* actual message size */
    char data[MSG_MAX];  /* message data */
} MESSAGE;

void listenerReceive (MESSAGE *msg)
{
    /* get a message, any type */
    if (msg_receive (csQueue, &container, sizeof(MESSAGE), 0L) == -1) { 
        perror ("Fail receiving message from client-server message queue");
        exit(EXIT_FAILURE);
    }
    *msg = container.msg;
    printf("[Server \'%d\'] message received from client \'%ld\'.\n", getpid(), container.client);
}