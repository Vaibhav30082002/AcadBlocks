//
//  main.cpp
//  multiple regression CAT 1
//
//  Created by Vaibhav Shah on 27/12/21.
//

#include <iostream>
#include <cmath>
using namespace std;
void solve(){
    int size;
    cout<<"Enter the size:";
    cin>>size;
    float z[size];
    float y1[size];
    float zo[2];
    float sum_of_z=0;
    float sq_sum_of_z=0;
    cout<<"Enter the values of z :";
    for(int i=0; i<size; i++){
        cin>>z[i];
        sum_of_z+=z[i];
        sq_sum_of_z+=(z[i]*z[i]);
    }
    cout<<"Enter the values of y :";
    for(int i=0; i<size; i++){
        cin>>y1[i];
    }

    cout<<"Enter the value of Z0: ";
    for(int i=0; i<2; i++){
        cin>>zo[i];
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

    cout<<"Now, y = ";
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
    cout<<"Now, tanspose(z)*y = |"<<z_trans_y1[0][0]<<"|"<<endl;
    cout<<"                      |"<<z_trans_y1[1][0]<<"|"<<endl;
    cout<<endl;

    cout<<"Bcap = inverse(transpose(z)*(z))*tanspose(z)*y"<<endl;
    cout<<"Bcap = |"<<inv_p[0][0]<<" "<<inv_p[0][1]<<"| * |"<<z_trans_y1[0][0]<<"|"<<endl;
    cout<<"        |"<<inv_p[1][0]<<" "<<inv_p[1][1]<<"|   |"<<z_trans_y1[1][0]<<"|"<<endl;
    cout<<endl;

    float B1[2][1];
    B1[0][0]=(inv_p[0][0]*z_trans_y1[0][0])+(inv_p[0][1]*z_trans_y1[1][0]);
    B1[1][0]=(inv_p[1][0]*z_trans_y1[0][0])+(inv_p[1][1]*z_trans_y1[1][0]);
    
    cout<<"Bcap = |"<<B1[0][0]<<"|"<<endl;
    cout<<"        |"<<B1[1][0]<<"|"<<endl;

    cout<<endl<<endl;


    cout<<"ycap = "<<B1[0][0]<<" + "<<B1[1][0]<<"z"<<endl;


    cout<<endl<<endl;


    cout<<"Now, Ycap = z*Bcap "<<endl;
    cout<<"Ycap = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<1<<" "<<z[i]<<"|";
        if(i==0){
            cout<<" |"<<B1[0][0]<<"|";
        }
        else if(i==1){
            cout<<" |"<<B1[1][0]<<"|";
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
    }
    cout<<"Ycap = |";
    for(int i=0; i<size; i++){
        cout<<Ycap[i][0]<<"|";
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
        ecap[i][0]=y1[i]-Ycap[i][0];


        cout<<"|"<<y1[i]<<"|";
        if(i==0){
            cout<<"-";
        }
        else{
            cout<<" ";
        }
        cout<<"|"<<Ycap[i][0]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"       ";
    }
    cout<<endl<<endl;
    cout<<"Ecap = ";
    for(int i=0; i<size; i++){
        cout<<"|"<<ecap[i][0]<<"|"<<endl;
        if(i==size-1){
            break;
        }
        cout<<"       ";
    }
    cout<<endl<<endl<<endl;


    cout<<"Now, The residual sum of squares = trans(Ecap)*Ecap"<<endl;
    float res_sos = 0;
    for(int i=0; i<size; i++){
        res_sos+=(ecap[i][0]*ecap[i][0]);
    }
    cout<<"Therefore, residual sum of squares = "<<res_sos<<endl<<endl;

    cout<<endl;

// Calculation of coefficient of determination (R^2)
    cout<<"The coefficient of determination R^2 is given by"<<endl;
    cout<<"R^2 = --formula--"<<endl<<endl;


    float ybar = 0;
    for (int i=0; i<size; i++){
        ybar+=y1[i];
    }
    cout<<"Now, ybar = "<<ybar<<"/"<<size<<endl;
    ybar = ybar/size;
    cout<<"Ybar = "<<ybar<<endl;

    float sumof_ycap_y = 0;
    float lolol;
    for(int i=0; i<size; i++){
        lolol = y1[i]-ybar;
        sumof_ycap_y+=(lolol*lolol);
    }


    cout<<"R^2 = "<<"--formula--"<<endl;
    cout<<"R^2 = "<<1 - res_sos/sumof_ycap_y<<endl;
    cout<<endl<<endl;

// Calculation of 95%...

    cout<<"Now, we have, "<<endl;
    cout<<"Zo = "<<"|"<<zo[0]<<"|"<<endl;
    cout<<"     "<<"|"<<zo[1]<<"|"<<endl;
    cout<<endl;

    float trans_zo_bcap = 0;
    trans_zo_bcap+=(zo[0]*B1[0][0]+zo[1]*B1[1][0]);
    cout<<"Therefore, trans(Zo)*Bcap = "<<trans_zo_bcap<<endl;
    cout<<"Now, \n S^2 = --formula--"<<endl;
    float s_sq = 0;
    cout<<"S^2 = "<<res_sos<<"/("<<size<<"-(1+1))"<<endl;
    cout<<"S^2 = "<<res_sos<<"/"<<size-2<<endl;
    s_sq = res_sos/(size-2);
    cout<<"S^2 = "<<s_sq<<endl;

    float s_lol = sqrt(s_sq);
    cout<<"Therefore, S = "<<s_lol<<endl;

    cout<<endl;

    
    // calc of Sroot...
    float hello[2] = {0};
    hello[0] = ((zo[0]*inv_p[0][0])+(zo[1]*inv_p[1][0]));
    hello[1]  =((zo[0]*inv_p[0][1])+(zo[1]*inv_p[1][1]));

    cout<<"trans(zo)*inv(trans(z)*z) = |"<<hello[0]<<" "<<hello[1]<<"|\n";
    cout<<endl;

    float hello2 = (hello[0]*zo[0])+(hello[1]*zo[1]);
    cout<<"Therefore, trans(zo)*inv(trans(z)*z)*zo = "<<hello2<<endl;

    cout<<"So, root(trans(zo)*inv(trans(z)*z)*zo) = "<<sqrt(hello2)<<endl<<endl;

    float xyz = s_lol*(sqrt(hello2));
    cout<<"s*root(trans(zo)*inv(trans(z)*z)*zo) = "<<xyz<<endl;

    cout<<endl<<endl;
    cout<<"S^2*inv(trans(z)*z) = "<<endl;
    float world[2][2];
    world[0][0]=s_sq*inv_p[0][0];
    world[0][1]=s_sq*inv_p[0][1];
    world[1][0]=s_sq*inv_p[1][0];
    world[1][1]=s_sq*inv_p[1][1];
    cout<<world[0][0]<<" "<<world[0][1]<<endl;
    cout<<world[1][0]<<" "<<world[1][1]<<endl;
    cout<<endl;

    cout<<"var(B) = "<<world[1][1]<<endl;
    cout<<"Sqrt(var(B)) = "<<sqrt(world[1][1])<<endl;;
    cout<<"B0cap = "<<B1[0][0]<<endl;
    cout<<"B1cap = "<<B1[1][0]<<endl;
}
int main(){
    solve();
    return 0;
}
