#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()

{
    printf("Vaibhav Shah\n");
    printf("20BBS0162\n");
    pid_t pid;
    pid=fork();
    char str[1000];
    
    if (pid<0)
    {
        fprintf(stderr,"Fork failed\n");
        return 1;
    }
    else if (pid==0)
    {
        printf("\n__CHILD PROCESS EXECUTION__\n");
        printf("Enter a string\n");
        fgets(str, sizeof str, stdin);
        char words[100][100];
        int j=0, k=0;
            for(int i=0;i<=(strlen(str));i++)
            {
                if(str[i]==' '|| str[i]=='\0' || str[i]=='.')
                {
                        words[k][j]='\0';
                        k++;
                        j=0;
                }
                else
                {
                        words[k][j]=str[i];
                        j++;
                }
            }
            
            printf("\n Strings or words after split by space are :\n");
            for(int i=0;i < k;i++)
                printf(" %s\n",words[i]);
            printf("------CHILD PROCESS TERMINATING-----\n");
        }
        
        else
    {
        printf("------Parent Process Executing-----\n");
        wait(NULL);
        printf("-----Parent Process Terminating-----\n");
    }
    
    return 0;
}


