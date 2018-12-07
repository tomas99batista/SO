//Le mensagem e send
//Create
//Connect
//Send

//openCom
//closeCom
//send
//mains

#include "comm.h"
#include "message.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MSG_KEY1 0x1111UL
#define MSG_KEY2 0x1112UL

static struct cont
{
    long client;
    MESSAGE msg;
} container;

static int csQueue,              /* client-server message queue */
           scQueue;              /* server-client message queue */


/* server side functions */

int OpenComm(void)
{
    int side = 0;
    
    /* creating client-server message queue */
    if ((csQueue = msg_create (MSG_KEY1)) == -1) { 
        if (errno == EEXIST) { 
            if ((csQueue = msg_connect (MSG_KEY1)) == -1) { 
                perror("Fail creating client-server message queue");
                exit(EXIT_FAILURE);
            }
            side = 1;
        }
        else { 
            perror("Fail creating client-server message queue");
            exit(EXIT_FAILURE);
        }
    }

    /* creating server-client message queue */
    if ((scQueue = msg_create (MSG_KEY2)) == -1) { 
        if (errno == EEXIST) { 
            if ((scQueue = msg_connect (MSG_KEY2)) == -1) { 
                perror("Fail creating server-client message queue");
                exit(EXIT_FAILURE);
            }
        }
        else { 
            perror("Fail creating server-client message queue");
            exit(EXIT_FAILURE);
        }
    }

    return side;
}


void servCloseComm(void)
{
    if (msg_destroy (csQueue) == -1) { 
        perror ("Fail destroying client-server message queue");
        exit(EXIT_FAILURE);
    }
    if (msg_destroy (scQueue) == -1) { 
        perror ("Fail destroying server-client message queue");
        exit(EXIT_FAILURE);
    }
}

/* client side functions */

void cliOpenComm(void)
{
    /* openning client-server message queue */
    if ((csQueue = msg_connect (MSG_KEY1)) == -1) { 
        perror("Fail accessing client-server message queue");
        exit(EXIT_FAILURE);
    }

    /* openning server-client message queue */
    if ((scQueue = msg_connect (MSG_KEY2)) == -1) { 
        perror("Fail accessing server-client message queue");
        exit(EXIT_FAILURE);
    }
}


void cliCloseComm(void)
{
    /* nothing to be done */
    return;
}


void Send(MESSAGE *msg)
{
    /* copy message into container */
    // container.client = 1L; //Changed to: Cabeçalho=PID em vez de 1
    container.client = getpid();
    container.msg = *msg;

    /* send message */
    if (msg_send_nb (csQueue, &container, sizeof(MESSAGE)) == -1) { 
        perror ("Fail sending message to client-server message queue");
        exit(EXIT_FAILURE);
    }

    printf("[Client \'%ld\'] message sent.\n", container.client);
}
