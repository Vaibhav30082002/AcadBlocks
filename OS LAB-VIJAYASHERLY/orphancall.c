// Name : Vaibhv Shah
// Reg No.: 20BBS0162
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
#include<stdlib.h>

int main()
{
  if (fork()==0){
    sleep(2);
    printf("\nHello from Child!\n");
  }
  else{
    //sleep(1);
    printf("Hello from Parent!\n");
  }
  system("ps -l");
  printf("\n");
  return 0;
}
