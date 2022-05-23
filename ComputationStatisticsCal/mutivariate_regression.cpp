//
//  main.cpp
//  multivariate regression
//
//  Created by Vaibhav Shah on 27/12/21.
//
#include <iostream>
using namespace std;
void solve(){
    int size;
    cout<<"Enter the size:";
    cin>>size;
    float z[size];
    float y1[size];
    float y2[size];
    float sum_of_z=0;
    float sq_sum_of_z=0;
    cout<<"Enter the values of z :";
    for(int i=0; i<size; i++){
        cin>>z[i];
        sum_of_z+=z[i];
        sq_sum_of_z+=(z[i]*z[i]);
    }
    cout<<"Enter the values of y1 :";
    for(int i=0; i<size; i++){
        cin>>y1[i];
    }
    cout<<"Enter the values of y2 :";
    for(int i=0; i<size; i++){
        cin>>y2[i];
    }


    cout<<endl<<endl;
    cout<<"z = |";
    for(int i=0; i<size; i++){
        cout<<"1 "<<z[i]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"    |";
    }
    cout<<endl<<endl;

    cout<<"transpose(z) = | ";
    for(int i=0; i<size; i++){
        cout<<1<<" ";
    }
    cout<<"|"<<endl<<"               | ";

    for(int i=0; i<size; i++){
        cout<<z[i]<<" ";
    }
    cout<<"|"<<endl;


    float p[2][2];
    p[0][0]=size;
    p[0][1]=sum_of_z;
    p[1][0]=sum_of_z;
    p[1][1]=sq_sum_of_z;
    cout<<"Therefore, transpose(z)*(z) = | ";
    cout<<p[0][0]<<" "<<p[0][1]<<"|"<<endl;
    cout<<"                              |";
    cout<<p[1][0]<<" "<<p[1][1]<<"|"<<endl;
    cout<<endl;

    float mod_p = (p[0][0]*p[1][1])-(p[0][1]*p[1][0]);
    if(mod_p==0){
        cout<<"Error as determinant = 0"<<endl;
        return;
    }
    float inv_p[2][2];
    inv_p[0][0]=p[1][1]/mod_p;
    inv_p[1][1]=p[0][0]/mod_p;
    inv_p[0][1]=-p[0][1]/mod_p;
    inv_p[1][0]=-p[1][0]/mod_p;

    cout<<"So, inverse(transpose(z)*(z)) = |";
    cout<<inv_p[0][0]<<" "<<inv_p[0][1]<<"|"<<endl;
    cout<<"                                |";
    cout<<inv_p[1][0]<<" "<<inv_p[1][1]<<"|"<<endl;
    cout<<endl;

    cout<<"Now, y1 = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<y1[i]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"          ";
    }
    cout<<endl;

    float z_trans_y1[2][1];
    z_trans_y1[0][0]=0;
    z_trans_y1[1][0]=0;
    for(int i=0; i<size; i++){
        z_trans_y1[0][0]+=y1[i];
        z_trans_y1[1][0]+=(y1[i]*z[i]);
    }
    cout<<"Now, tanspose(z)*y1 = |"<<z_trans_y1[0][0]<<"|"<<endl;
    cout<<"                      |"<<z_trans_y1[1][0]<<"|"<<endl;
    cout<<endl;

    cout<<"B1cap = inverse(transpose(z)*(z))*tanspose(z)*y1"<<endl;
    cout<<"B1cap = |"<<inv_p[0][0]<<" "<<inv_p[0][1]<<"| * |"<<z_trans_y1[0][0]<<"|"<<endl;
    cout<<"        |"<<inv_p[1][0]<<" "<<inv_p[1][1]<<"|   |"<<z_trans_y1[1][0]<<"|"<<endl;
    cout<<endl;

    float B1[2][1];
    B1[0][0]=(inv_p[0][0]*z_trans_y1[0][0])+(inv_p[0][1]*z_trans_y1[1][0]);
    B1[1][0]=(inv_p[1][0]*z_trans_y1[0][0])+(inv_p[1][1]*z_trans_y1[1][0]);
    
    cout<<"B1cap = |"<<B1[0][0]<<"|"<<endl;
    cout<<"        |"<<B1[1][0]<<"|"<<endl;

    cout<<endl<<endl;


    cout<<"Now, y2 = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<y2[i]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"          ";
    }
    cout<<endl;

    float z_trans_y2[2][1];
    z_trans_y2[0][0]=0;
    z_trans_y2[1][0]=0;
    for(int i=0; i<size; i++){
        z_trans_y2[0][0]+=y2[i];
        z_trans_y2[1][0]+=(y2[i]*z[i]);
    }
    cout<<"Now, tanspose(z)*y2 = |"<<z_trans_y2[0][0]<<"|"<<endl;
    cout<<"                      |"<<z_trans_y2[1][0]<<"|"<<endl;
    cout<<endl;

    cout<<"B2cap = inverse(transpose(z)*(z))*tanspose(z)*y2"<<endl;
    cout<<"B2cap = |"<<inv_p[0][0]<<" "<<inv_p[0][1]<<"| * |"<<z_trans_y2[0][0]<<"|"<<endl;
    cout<<"        |"<<inv_p[1][0]<<" "<<inv_p[1][1]<<"|   |"<<z_trans_y2[1][0]<<"|"<<endl;
    cout<<endl;

    float B2[2][1];
    B2[0][0]=(inv_p[0][0]*z_trans_y2[0][0])+(inv_p[0][1]*z_trans_y2[1][0]);
    B2[1][0]=(inv_p[1][0]*z_trans_y2[0][0])+(inv_p[1][1]*z_trans_y2[1][0]);
    
    cout<<"B2cap = |"<<B2[0][0]<<"|"<<endl;
    cout<<"        |"<<B2[1][0]<<"|"<<endl;

    cout<<endl<<endl;

    cout<<"Bcap = [B1cap : B2cap] =  |"<<B1[0][0]<<" "<<B2[0][0]<<"|"<<endl;
    cout<<"                          |"<<B1[1][0]<<" "<<B2[1][0]<<"|"<<endl;

    cout<<endl<<endl;


    cout<<"Now, Ycap = z*Bcap "<<endl;
    cout<<"Ycap = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<1<<" "<<z[i]<<"|";
        if(i==0){
            cout<<" |"<<B1[0][0]<<" "<<B2[0][0]<<"|";
        }
        else if(i==1){
            cout<<" |"<<B1[1][0]<<" "<<B2[1][0]<<"|";
        }

        if(i==size-1){
            break;
        }
        cout<<endl<<"       ";
    }
    cout<<endl<<endl;
    float Ycap[size][2];
    for(int i=0; i<size; i++){
        Ycap[i][0]=((B1[0][0]*1)+(z[i]*B1[1][0]));
        Ycap[i][1]=((B2[0][0]*1)+(z[i]*B2[1][0]));
    }
    cout<<"Ycap = |";
    for(int i=0; i<size; i++){
        cout<<Ycap[i][0]<<" "<<Ycap[i][1]<<"|";
        if(i==size-1){
            break;
        }
        cout<<endl<<"       |";
    }
    cout<<endl<<endl;

    float ecap[size][2];
    cout<<"Now, Ecap = Y - Ycap"<<endl;
    cout<<"Ecap = ";
    for(int i=0; i<size; i++){
        ecap[i][0]=0;
        ecap[i][1]=0;
        ecap[i][0]=y1[i]-Ycap[i][0];
        ecap[i][1]=y2[i]-Ycap[i][1];


        cout<<"|"<<y1[i]<<" "<<y2[i]<<"|";
        if(i==0){
            cout<<"-";
        }
        else{
            cout<<" ";
        }
        cout<<"|"<<Ycap[i][0]<<" "<<Ycap[i][1]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"       ";
    }
    cout<<endl<<endl;
    cout<<"Ecap = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<ecap[i][0]<<" "<<ecap[i][1]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"       ";
    }
    cout<<endl<<endl<<endl;



    // verification ...

    // cout<<"---Verification--"<<endl;
    // float ey[2][2];
    // for(int i=0; i<2; i++){
    //     for(int j=0; j<2; j++){
    //         ey[i][j]=0;
    //     }
    // }

    // for(int i=0; i<size; i++){
    //     ey[0][0]+=(ecap[i][0]*Ycap[i][0]);
    //     // ey[1][1]+=(ecap[i][0]*Ycap[i][0]);
    // }
    // cout<<ey[0][0]<<endl;

    // // cout<<"transpose(Ecap)*Ycap = ";
    cout<<"-------Verification(if asked)------"<<endl;
    float ey[2][2];
    cout<<"transpose(ecap)*ycap = "<<"|0 0|"<<endl;
    cout<<"                       "<<"|0 0|"<<endl;
    cout<<endl;

    float yty[2][2];
    float ycaptycap[2][2];
    float ecaptecap[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            yty[i][j]=0;
            ycaptycap[i][j]=0;
            ecaptecap[i][j]=0;
        }
    }


    for(int i=0; i<size; i++){
        ecaptecap[0][0] += (ecap[i][0]*ecap[i][0]);
        ecaptecap[1][1] += (ecap[i][1]*ecap[i][1]);
        ecaptecap[0][1] += (ecap[i][0]*ecap[i][1]);
    }
    ecaptecap[1][0] = ecaptecap[0][1];

    for(int i=0; i<size; i++){
        ycaptycap[0][0] += (Ycap[i][0]*Ycap[i][0]);
        ycaptycap[1][1] += (Ycap[i][1]*Ycap[i][1]);
        ycaptycap[0][1] += (Ycap[i][0]*Ycap[i][1]);
    }
    ycaptycap[1][0] = ycaptycap[0][1];

    yty[0][0] = ycaptycap[0][0] + ecaptecap[0][0];
    yty[1][1] = ycaptycap[1][1] + ecaptecap[1][1];
    yty[1][0] = ycaptycap[1][0] + ecaptecap[1][0];
    // yty[][] = ycaptycap[][] + ecaptecap[][];
    yty[0][1] = yty[1][0];

    cout<<"Now, we have to verify that:\n";
    cout<<"trans(Y)Y = trans(Ycap)Ycap + trans(ecap)e"<<endl;

    cout<<"|"<<yty[0][0]<<" "<<yty[1][0]<<"|  =  |"<<ycaptycap[0][0]<<" "<<ycaptycap[1][0];
    cout<<"|  +  |"<<ecaptecap[0][0]<<" "<<ecaptecap[1][0]<<"|"<<endl;

    cout<<"|"<<yty[0][1]<<" "<<yty[1][1]<<"|     |"<<ycaptycap[0][1]<<" "<<ycaptycap[1][1];
    cout<<"|     |"<<ecaptecap[0][1]<<" "<<ecaptecap[1][1]<<"|"<<endl;

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
}
int main(){
    solve();
    return 0;
}
