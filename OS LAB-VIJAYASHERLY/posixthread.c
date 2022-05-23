// Vaibhav Shah
// 20BBS0162
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<pthread.h>
#include <unistd.h>
#include<string.h>
void *fileCopy(void *arg){
    FILE *fptr1,*fptr2;
    char c;
    fptr1 = fopen("file1.txt","r");
    if (fptr1 == NULL)
    {
        perror("Error: ");
        exit(0);
    }
    fptr2 = fopen("file2.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file2.txt\n");
        exit(0);
    }
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("\nContents copied\n");
    fclose(fptr1);
    fclose(fptr2);
}

void *spaceRemover(void *arg){
    int space = 0;
    int k = 0;
    char arr[] = " Hello . This is C Program!! \n";
    for (int i = 0; i < sizeof(arr); i++){
        while (k == 0 && i < sizeof(arr) && arr[i] == ' ') {
            i++;
        }
        
        if (arr[i] == ' ')
        {
            if (!space) {
                arr[k++] = arr[i];
                space = 1;
            }
        }
        else if (ispunct(arr[i]))
        {
            if (k > 0 && arr[k-1] == ' '){
                arr[k-1] = arr[i];
            }
            else {
                arr[k++] = arr[i];
            }
            space = 0;
        }
        else {
            arr[k++] = arr[i];
            space = 0;
        }
    }
    arr[k] = '\0';
    printf("\n %s",arr);
}

int main(){
    int x ;
    pthread_t t_id;
    if(pthread_create(&t_id, NULL, spaceRemover, (void *)1)){
        printf("does not work");
    }else{
        pthread_join(t_id, NULL);
    }
    pthread_t t_id2;
    if(pthread_create(&t_id2, NULL, fileCopy, (void *)1)){
        printf("does not work");
    }
    else {
        pthread_join(t_id2, NULL);
    }
}
