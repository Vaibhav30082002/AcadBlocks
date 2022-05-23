//
//  main.cpp
//  HammingCode
//
//  Created by Vaibhav Shah on 11/02/22.
//
/*
 #include <iostream>
 #include <math.h>
 #include <cstring>
 using namespace std;
 
 int parity_check(int n,int i,int code[])
 {
 int p=0,k;
 for(int j=i;j<=n;j=k+i)
 {
 for(k=j;k<j+i && k<=n;k++)
 
 {
 if(code[k]==1)
 p++;
 }
 }
 if(p%2==0)
 return 0;
 else
 return 1;
 }
 
 void hamming_code(int data[], int num)
 {
 int r=0,m=0,n,j=1,c,code[50];
 
 while((r+num+1)>(pow(2,r)))
 r++;
 
 n=num+r;
 cout<<"No. of Reductant bits are: "<< r << endl;
 
 for(int i=1;i<=n;i++)
 {
 if(i==pow(2,m) && m<=r)
 {
 code[i]=0;
 m++;
 }
 else
 {
 code[i]=data[j];
 j++;
 }
 }
 
 m=0;
 cout<< "Reductant bits are: ";
 for(int i=1;i<=n;i++)
 {
 if(i==pow(2,m) && m<=r)
 {
 c=parity_check(n,i,code);
 code[i]=c;
 
 cout<<" "<< c;
 
 m++;
 }
 }
 cout<<endl;
 cout<<"The hamming code for given data is: ";
 for(int i=n;i>0;i--)
 cout<<" "<<code[i];
 cout<<"\n\nEnter the received code: ";
 for(int i=n;i>0;i--)
 cin>>code[i];
 m=j=c=0;
 for(int i=1;i<=n;i++)
 {
 if(i==pow(2,m) && m<=r)
 {
 c=c+(pow(2,j)*parity_check(n,i,code));    // decimal value of error code
 j++;
 m++;
 }
 }
 if(c==0)
 cout<<"\nReceived word is correct.\n";
 else
 {
 cout<<"There is error in bit "<<c<<"\n\nThe corrected code should be: ";
 if(code[c]==1)
 code[c]=0;
 else
 code[c]=1;
 for(int i=n;i>0;i--)
 cout<<" "<<code[i];
 }
 cout<<"\n"<<endl;
 }
 
 int main()
 {
 int data[50], num;
 
 cout<<"Enter the size of data: ";
 cin>>num;
 cout<<"Enter the data: ";
 for(int i=num;i>0;i--)
 cin>>data[i];
 
 hamming_code(data, num);
 
 return 0;
 }
 
 */

#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>#include<sys/socket.h> #include<netdb.h> #include<stdlib.h> #include<string.h> #define MAX 80 #define PORT 43454 #define SA struct sockaddr
void func(int sockfd) { char buff[MAX]; int n;
    for(;;) { bzero(buff,MAX); read(sockfd,buff,sizeof(buff)); printf("From client: %s\t To client : ",buff); bzero(buff,MAX); n=0; while((buff[n++]=getchar())!='\n'); write(sockfd,buff,sizeof(buff)); if(strncmp("exit",buff,4)==0) { printf("Server Exit...\n"); break;
    } }
} int main() { int sockfd,connfd,len; struct sockaddr_in servaddr,cli;
    sockfd=socket(AF_INET,SOCK_STREAM,0); if(sockfd==-1)
    { printf("socket creation failed...\n"); exit(0);
    } else
    printf("Socket successfully created..\n"); bzero(&servaddr,sizeof(servaddr)); servaddr.sin_family=AF_INET; servaddr.sin_addr.s_addr=htonl(INADDR_ANY); servaddr.sin_port=htons(PORT); if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr)))!=0) {
        printf("socket bind failed...\n"); exit(0); } else
    printf("Socket successfully binded..\n"); if((listen(sockfd,5))!=0) { printf("Listen failed...\n");
        exit(0); }
    else
        printf("Server listening..\n"); len=sizeof(cli);
    connfd=accept(sockfd,(SA *)&cli,&len); if(connfd<0) { printf("server acccept failed...\n"); exit(0);
    } else printf("server acccept the client...\n"); func(connfd); close(sockfd); }

