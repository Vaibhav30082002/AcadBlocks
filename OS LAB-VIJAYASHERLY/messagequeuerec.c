#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#define MSG_SIZE 18
int main()
{
    key_t key;
    int msgQID;
    typedef struct msgbuf
    {
        long int mtype;
        char mtext[50];
    }msgbuf;
    msgbuf message_send, message_recieve;
    message_send.mtype=1;
    key=101;
    if ((msgQID=msgget(key, IPC_CREAT | 0666) )<0)
    {
        perror("msgget");
        exit(-1);
    }
    printf("Server Access successful\n");
    if (msgrcv(msgQID, &message_recieve, sizeof(message_recieve.mtext), 1, IPC_NOWAIT)<0)
    {
        perror("msgrcv");
        exit(-1);
    }
    printf("Message sent by client:%s \n", message_recieve.mtext);
    strcpy(message_send.mtext, "Processing");
    if (msgsnd (msgQID, &message_send, strlen(message_send.mtext)+1, IPC_NOWAIT)<0)
    {
        perror("msgsnd");
        exit(-1);
    }
    printf ("Message sent to client successfully\n");
    return 0;
}
