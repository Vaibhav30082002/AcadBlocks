//Vaibhav Shah
//20BBS0162

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char p[100] = "ls";
    system(p);
    printf("Enter the process name to kill: ");
    char process_first[100] = "pkill -f ";
    char process_second[100];
    scanf("%s", process_second);
    strcat(process_first, process_second);
    system(process_first);
    printf("Done !!\n");
    return 0;
}
