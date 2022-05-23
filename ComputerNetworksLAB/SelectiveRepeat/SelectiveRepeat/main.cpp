//
//  main.cpp
//  SelectiveRepeat
//
//  Created by Vaibhav Shah on 25/02/22.
//

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>

using namespace std;

int ptr=0;
//int timestamp=0;
int receiver(int a[],int n, int z){
    for(int i=0;i<n;i++){
         int flag=rand()%2;
         if(flag){
             cout<<"received frame "<<a[i]<<endl;
         }
         else{
            cout<<"not received frame "<<a[i]<<endl;
            return a[i];
         }
    }
    return -1;
   
}
void sender(int N,int nf,int z){
    int arr[N];
        lab:
        for(int i=0;i<N && ptr<nf;i++)
       { cout<<"SENT FRAME "<<ptr<<endl;
           usleep(z*1000);
       arr[i]=ptr;
       ptr++;
       }
    int dec=receiver(arr,N,z);
    if(dec==-1){
        cout<<"acknowledge recievd all data recieved by receiver "<<endl;
        return;
    }
    else{
     int flag=rand()%2;
             if(flag){
                 ff:
                 cout<<"acknowledege recived for frame "<<dec<<endl;
                 fff:
                 cout<<"SENT FRAME "<<dec<<endl;
                 usleep(z*1000);
                 int s[1]={dec};
                 int af=receiver(s,1,z);
                 if(af==-1){
                    cout<<"acknowledge recievd all data recieved by receiver "<<endl;
                    return;
                 }
                 else{
                     int flag2=rand()%2;
                     if(flag2){
                         goto ff;
                     }
                     else{
                          cout<<"acknowledege recived for frame "<<af<<endl;
                         goto fff;
                     }
                 }
             }
             else{
                 cout<<"acknowledege not recived for frame "<<dec<<endl;
                 ptr-=N;
                 goto lab;
             }
    }
    return;
}

int main(){
    int nf,N,z;
    cout<<"Enter the number of frames : ";
    cin>>nf;
    cout<<"Enter the Window Size : ";
    cin>>N;
    cout<<"Enter Timeout time (1-10 (ms)) : ";
    cin>>z;
    for(int i=0;i<nf;i+=N){
        sender(N,nf,z);
    }
    return 0;
}
