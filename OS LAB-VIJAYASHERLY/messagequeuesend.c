#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    key_t key;
    char msg[50];
    int msgQID;
    typedef struct msgbuf
    {
        long int mtype;
        char mtext[50];
    }msgbuf;
    msgbuf message_send, message_recieve;
    message_send.mtype=1;
    key=101;
    if ((msgQID=msgget(key, IPC_CREAT | 0666)) <0)
    {
        perror("msgget");
        exit(-1);
    }
    printf ("Message Queue is created, ID: %d\n" , msgQID);
    do
    {
        printf("Enter the message to be sent:");
        scanf ("%s" ,msg) ;
        if (strcmp(msg,"stop") ==0)
        {
            break;
        }
        strcpy(message_send.mtext, msg);
        if (msgsnd (msgQID, &message_send, strlen(message_send.mtext)+1, IPC_NOWAIT)<0)
        {
            perror ("msgsnd") ;
            exit(-1);
        }
        printf( "Message ..%s.. sent to server successfully\n", message_send.mtext);
        system("/Users/vaibhavshah/Desktop/20BBS0162_OS_LAB/server");
        if (msgrcv(msgQID,&message_recieve,sizeof(message_recieve.mtext),1,IPC_NOWAIT)<0)
        {
            perror("msgsnd");
            exit(-1);
        }
            printf("Message recieved from server:%s \n",message_recieve.mtext);
        }while(1);
    printf( "Interaction with server about to terminate\n");
        return 0;
    }
