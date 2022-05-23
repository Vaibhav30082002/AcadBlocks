//
//  main.cpp
//  minimum likelihood CAT1
//
//  Created by Vaibhav Shah on 27/12/21.
//

#include <iostream>

using namespace std;
void solve(){
    int a = 2;
    int n1;
    cout<<"Enter the size of table 1 (n1) :";
    cin>>n1;
    float t11[n1];
    float t12[n1];
    int t13[n1];
    cout<<"Enter table 1 first row elements : ";
    for(int i=0; i<n1; i++){
        cin>>t11[i];
    }
    cout<<"Enter table 1 second row elements : ";
    for(int i=0; i<n1; i++){
        cin>>t12[i];
    }


    cout<<"The entered tables are:\n";
    cout<<"Table 1"<<endl;
    cout<<" x| y"<<endl;
    cout<<"-----"<<endl;
    for(int i=0; i<n1; i++){
        cout<<t11[i]<<"|"<<t12[i]<<endl;
    }
    cout<<endl<<endl;
    
    float p = 0, q = 0;
    for(int i=0; i<n1; i++){
        p+=t11[i];
        q+=t12[i];
    }

    cout<<"MU = ";
    cout<<"|"<<p<<"/"<<n1<<"|"<<endl;
    cout<<"        ";
    cout<<"|"<<q<<"/"<<n1<<"|"<<endl;
    cout<<endl;
    float y1[a][1];
    y1[0][0]= p/n1;
    y1[1][0]= q/n1;
    cout<<"therefore, MU = ";
    cout<<"|"<<y1[0][0]<<"|"<<endl;
    cout<<"                   ";
    cout<<"|"<<y1[1][0]<<"|"<<endl;
    cout<<endl<<endl;


    cout<<"SIGMAcap = -formula-"<<endl<<endl;
    cout<<"SIGMAcap = 1/"<<n1<<"*"<<endl;
    float k[a][1];
    // add a step before this
    float s1[2][2];
    s1[0][0]=0;
    s1[0][1]=0;
    s1[1][0]=0;
    s1[1][1]=0;
    float temp[2][2];
    cout<<"(";
    for(int i=0; i<n1; i++){
        k[0][0]=t11[i]-y1[0][0];
        k[1][0]=t12[i]-y1[1][0];
        cout<<"|"<<k[0][0]<<"|"<<endl;
        cout<<" |"<<k[1][0]<<"| * |"<<k[0][0]<<" "<<k[1][0]<<"|"<<endl;

        

        if(i==n1-1){
            cout<<")";
            break;
        }
        cout<<"+";
        // cout<<"("<<")"
    }
    cout<<endl<<endl;
    
    // cout<<"S1 = 1/"<<n1-1<<"*"<<endl;
    for(int i=0; i<n1; i++){
        k[0][0]=t11[i]-y1[0][0];
        k[1][0]=t12[i]-y1[1][0];

        temp[0][0]=k[0][0]*k[0][0];
        temp[0][1]=k[0][0]*k[1][0];
        temp[1][0]=temp[0][1];
        temp[1][1]=k[1][0]*k[1][0];

        s1[0][0]+=temp[0][0];
        s1[0][1]+=temp[0][1];
        s1[1][0]+=temp[1][0];
        s1[1][1]+=temp[1][1];
    }
    cout<<endl;
    cout<<"SIGMAcap = 1/"<<n1<<" * |"<<s1[0][0]<<" "<<s1[1][0]<<"|\n";
    cout<<"           |"<<s1[0][1]<<" "<<s1[1][1]<<"|\n\n\n";



    
}
int main(){
    solve();
    return 0;
}
