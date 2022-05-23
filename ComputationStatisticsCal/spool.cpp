//
//  main.cpp
//  Spool
//
//  Created by Vaibhav Shah on 27/12/21.
//

// as of now the no of attributes =  2

#include <iostream>

using namespace std;
float z(float y1, float y2, float p, float q){
    return y1*p + y2*q;
}
void solve(){
    int a;
    // cout<<"Enter the number of attributes:";
    // cin>>a;
    a = 2;
    int n1;
    cout<<"Enter the size of table 1 (n1) :";
    cin>>n1;
    float t11[n1];
    float t12[n1];
    // int t13[n1];
    cout<<"Enter table 1 first row elements : ";
    for(int i=0; i<n1; i++){
        cin>>t11[i];
    }
    cout<<"Enter table 1 second row elements : ";
    for(int i=0; i<n1; i++){
        cin>>t12[i];
    }

    int n2;
    cout<<"Enter the size of table 2 (n2) :";
    cin>>n2;
    float t21[n2];
    float t22[n2];
    // int t13[n1];
    cout<<"Enter table 2 first row elements : ";
    for(int i=0; i<n2; i++){
        cin>>t21[i];
    }
    cout<<"Enter table 2 second row elements : ";
    for(int i=0; i<n2; i++){
        cin>>t22[i];
    }


    cout<<"The entered tables are:\n";
    cout<<"Table 1"<<endl;
    cout<<" x| y"<<endl;
    cout<<"-----"<<endl;
    for(int i=0; i<n1; i++){
        cout<<t11[i]<<"|"<<t12[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Table 2"<<endl;
    cout<<" x| y"<<endl;
    cout<<"-----"<<endl;
    for(int i=0; i<n2; i++){
        cout<<t21[i]<<"|"<<t22[i]<<endl;
    }
    cout<<endl<<endl<<endl<<endl;
    // display to check if there any error in input


    
    // store float values only
    float p = 0, q = 0;
    for(int i=0; i<n1; i++){
        p+=t11[i];
        q+=t12[i];
    }

    cout<<"y1bar = ";
    cout<<"|"<<p<<"/"<<n1<<"|"<<endl;
    cout<<"        ";
    cout<<"|"<<q<<"/"<<n1<<"|"<<endl;
    cout<<endl;
    float y1[a][1];
    y1[0][0]= p/n1;
    y1[1][0]= q/n1;
    cout<<"therefore, y1bar = ";
    cout<<"|"<<y1[0][0]<<"|"<<endl;
    cout<<"                   ";
    cout<<"|"<<y1[1][0]<<"|"<<endl;
    cout<<endl<<endl;


    p = 0, q = 0;
    for(int i=0; i<n2; i++){
        p+=t21[i];
        q+=t22[i];
    }
    cout<<"y2bar = ";
    cout<<"|"<<p<<"/"<<n2<<"|"<<endl;
    cout<<"        ";
    cout<<"|"<<q<<"/"<<n2<<"|"<<endl;
    cout<<endl;
    float y2[a][1];
    y2[0][0]= p/n2;
    y2[1][0]= q/n2;
    cout<<"therefore, y2bar = ";
    cout<<"|"<<y2[0][0]<<"|"<<endl;
    cout<<"                   ";
    cout<<"|"<<y2[1][0]<<"|"<<endl;
    cout<<endl<<endl;

    cout<<"Now, let us calculate Spooled."<<endl;
    // add spolled formula
    cout<<"First of all, S1 = -formula-"<<endl<<endl;
    cout<<"S1 = 1/"<<n1-1<<"*"<<endl;
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
    cout<<"S1 = 1/"<<n1-1<<" * |"<<s1[0][0]<<" "<<s1[1][0]<<"|\n";
    cout<<"           |"<<s1[0][1]<<" "<<s1[1][1]<<"|\n\n\n";



    cout<<"Secondly, S2 = -formula-"<<endl<<endl;

    cout<<"S2 = 1/"<<n2-1<<"*"<<endl;
    // add a step before this
    float s2[2][2];
    s2[0][0]=0;
    s2[0][1]=0;
    s2[1][0]=0;
    s2[1][1]=0;
    cout<<"(";
    for(int i=0; i<n2; i++){
        k[0][0]=t21[i]-y2[0][0];
        k[1][0]=t22[i]-y2[1][0];
        cout<<"|"<<k[0][0]<<"|"<<endl;
        cout<<" |"<<k[1][0]<<"| * |"<<k[0][0]<<" "<<k[1][0]<<"|"<<endl;

        
        if(i==n2-1){
            cout<<")";
            break;
        }
        cout<<"+";
        // cout<<"("<<")"
    }
    cout<<endl;
    
    // cout<<"S1 = 1/"<<n1-1<<"*"<<endl;
    for(int i=0; i<n2; i++){
        k[0][0]=t21[i]-y2[0][0];
        k[1][0]=t22[i]-y2[1][0];

        temp[0][0]=k[0][0]*k[0][0];
        temp[0][1]=k[0][0]*k[1][0];
        temp[1][0]=temp[0][1];
        temp[1][1]=k[1][0]*k[1][0];

        s2[0][0]+=temp[0][0];
        s2[0][1]+=temp[0][1];
        s2[1][0]+=temp[1][0];
        s2[1][1]+=temp[1][1];
    }
    cout<<endl<<endl;
    cout<<"S2 = 1/"<<n2-1<<" * |"<<s2[0][0]<<" "<<s2[1][0]<<"|\n";
    cout<<"           |"<<s2[0][1]<<" "<<s2[1][1]<<"|\n\n\n";


    // now , spooled calculation
    cout<<endl;
    cout<<"Spooled = [n1-1/(n1-1)+(n2-1)]S1 +";
    cout<<" [n2-1/(n1-1)+(n2-1)]S2"<<endl;
    int d = (n1-1)+(n2-1);
    // cout<<"Spooled = (1/(n1-1)+(n2-1))(S1+S2)"<<endl;
    float Spool[2][2];
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            Spool[i][j]=0;
            Spool[i][j]+=s1[i][j];
            Spool[i][j]+=s2[i][j];
        }
    }
    cout<<"Spooled = 1/"<<d<<" |"<<Spool[0][0]<<" "<<Spool[1][0]<<"|"<<endl;
    cout<<"              |"<<Spool[0][1]<<" "<<Spool[1][1]<<"|"<<endl<<endl;
    float lol;
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            Spool[i][j]/=d;
        }
    }
    cout<<"Spooled = |"<<Spool[0][0]<<" "<<Spool[1][0]<<"|"<<endl;
    cout<<"          |"<<Spool[0][1]<<" "<<Spool[1][1]<<"|"<<endl;
    cout<<endl<<endl;




    // spooled inverse calculation
    float modSpooled = (Spool[0][0]*Spool[1][1])-(Spool[1][0]*Spool[0][1]);
    cout<<"Now, det(Spl) = "<<modSpooled<<endl;
    if(modSpooled==0){
        cout<<"As the determinant of Spooled is equals to zero, so its not possible to find discriminant function"<<endl;
        return;
    }
    float invSpooled[2][2];
    invSpooled[0][0]=Spool[1][1];
    invSpooled[1][1]=Spool[0][0];
    invSpooled[0][1]=-Spool[0][1];
    invSpooled[1][0]=-Spool[1][0];
    cout<<"Therefore,\ninverse(Spl) = (1/|Spl|)*adj(Spl)"<<endl;
    cout<<"inv(Spl) = (1/|Spl|)* |"<<invSpooled[0][0]<<" "<<invSpooled[0][1]<<"|"<<endl;
    cout<<"                      |"<<invSpooled[1][0]<<" "<<invSpooled[1][1]<<"|"<<endl;
    cout<<endl<<endl;

    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            invSpooled[i][j]/=modSpooled;
        }
    }
    cout<<"inv(Spl) = |"<<invSpooled[0][0]<<" "<<invSpooled[0][1]<<"|"<<endl;
    cout<<"           |"<<invSpooled[1][0]<<" "<<invSpooled[1][1]<<"|"<<endl;
    cout<<endl<<endl;

    // a calculation
    float diff[a][1];
    diff[0][0]=y1[0][0]-y2[0][0];
    diff[1][0]=y1[1][0]-y2[1][0];

    cout<<"Now, a = inv(Spl)*(y1mod - y2mod)"<<endl;

    cout<<"mod(y1) - mod(y2) = |"<<diff[0][0]<<"|"<<endl;
    cout<<"                    |"<<diff[1][0]<<"|"<<endl;
    cout<<endl;

    cout<<"a = "<<"|"<<invSpooled[0][0]<<" "<<invSpooled[0][1]<<"| * |"<<diff[0][0]<<"|"<<endl;
    cout<<"    "<<"|"<<invSpooled[1][0]<<" "<<invSpooled[1][1]<<"|   |"<<diff[1][0]<<"|"<<endl;
    cout<<endl;

    float aaa[a][1];
    aaa[0][0]=(invSpooled[0][0]*diff[0][0])+(invSpooled[0][1]*diff[1][0]);
    aaa[1][0]=(invSpooled[1][0]*diff[0][0])+(invSpooled[1][1]*diff[1][0]);

    cout<<"a = |"<<aaa[0][0]<<"|"<<endl;
    cout<<"    |"<<aaa[1][0]<<"|"<<endl;
    cout<<endl<<endl;


    // z calculation
    cout<<"Now, discriminant function = z = transpose(a)*y"<<endl;
    cout<<"z = |"<<aaa[0][0]<<" "<<aaa[1][0]<<"| * y"<<endl;
    cout<<"z = "<<aaa[0][0]<<"y1"<<" + ("<<aaa[1][0]<<"y2)"<<endl;
    cout<<endl<<endl;

    cout<<"Table 1"<<endl;
    cout<<"-------"<<endl;
    for(int i=0; i<n1; i++){
        cout<<z(aaa[0][0], aaa[1][0], t11[i], t12[i])<<endl;
    }
    cout<<endl<<endl;
    cout<<"Table 2"<<endl;
    cout<<"-------"<<endl;
    for(int i=0; i<n2; i++){
        cout<<z(aaa[0][0], aaa[1][0], t21[i], t22[i])<<endl;
    }

    cout<<"--------------------------------------------------:)"<<endl;
}
int main(){
    solve();
    cout<<"Dedicated to Rajesh Bhatt :)"<<endl;
    return 0;
}
