//
//  main.cpp
//  timeseries
//
//  Created by Vaibhav Shah on 27/12/21.
//

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 4
void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(float A[N][N], int n)
{
    float D = 0;
    if (n == 1)
        return A[0][0];

    float temp[N][N];

    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }

    return D;
}


void adjoint(float A[N][N],float adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
    float sign = 1, temp[N][N];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(float A[N][N], float inverse[N][N])
{
    // Find determinant of A[][]
    float det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    // Find adjoint
    float adj[N][N];
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/float(det);

    return true;
}

// Generic function to display the matrix. We use it to display
// both adjoin and inverse. adjoin is integer matrix and inverse
// is a float.
template<class T>
void display(T A[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void display2(float arr[2][2]){
    for(int i=0; i<2; i++){
        cout<<"| ";
        for(int j=0; j<2; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
}

void multiply(float a[2][2], float b[2][2], float c[2][2]){
    // c is the output
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
}
void solve(){
    int d = 2;
    cout<<"Enter the values of PHI (PHI11.. PHI12.. PHI21.. PHI22): ";
    float phi[d][d];
    for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            cin>>phi[i][j];
        }
    }

    cout<<"Enter the value of SIGMA (rho11..rho12..rho21..rho22): ";
    float rho[d][d];
    for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            cin>>rho[i][j];
        }
    }
    // input done


    // display the input matrixes
    cout<<"PHI = "<<"|"<<phi[0][0]<<" "<<phi[0][1]<<"|"<<endl;
    cout<<"      "<<"|"<<phi[1][0]<<" "<<phi[1][1]<<"|"<<endl;
    cout<<endl;
    cout<<"SIGMA = "<<"|"<<rho[0][0]<<" "<<rho[0][1]<<"|"<<endl;
    cout<<"        "<<"|"<<rho[1][0]<<" "<<rho[1][1]<<"|"<<endl;
    cout<<endl<<endl;

    cout<<"say, |||a = inv(I4 - b)*c|||"<<endl;

    float c[4];
    c[0] = rho[0][0];
    c[1] = rho[1][0];
    c[2] = rho[0][1];
    c[3] = rho[1][1];

    float b[N][N];
    b[0][0] = phi[0][0]*phi[0][0];
    b[0][1] = phi[0][0]*phi[0][1];
    b[0][2] = phi[0][1]*phi[0][0];
    b[0][3] = phi[0][1]*phi[0][1];

    b[1][0] = phi[0][0]*phi[1][0];
    b[1][1] = phi[0][0]*phi[1][1];
    b[1][2] = phi[0][1]*phi[1][0];
    b[1][3] = phi[0][1]*phi[1][1];

    b[2][0] = phi[1][0]*phi[0][0];
    b[2][1] = phi[1][0]*phi[0][1];
    b[2][2] = phi[1][1]*phi[0][0];
    b[2][3] = phi[1][1]*phi[0][1];

    b[3][0] = phi[1][0]*phi[1][0];
    b[3][1] = phi[1][0]*phi[1][1];
    b[3][2] = phi[1][1]*phi[1][0];
    b[3][3] = phi[1][1]*phi[1][1];

    cout<<endl;
    cout<<"b = "<<endl;
    display(b);
    cout<<endl<<endl;

    for(int i=0; i<N; i++){
        b[i][i] = 1 - b[i][i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j!=i){
                b[i][j]*=(-1);
            }
        }
    }

    cout<<"Therefore, (I-b) = "<<endl;
    display(b);
    cout<<endl<<endl;

    float inv[N][N];
    inverse(b, inv);

    cout<<"Now, inv(I-b) = "<<endl;
    display(inv);

    cout<<endl<<endl;

    float y[4];
    for(int i=0; i<N; i++){
        y[i] = inv[i][0]*c[0] + inv[i][1]*c[1] + inv[i][2]*c[2] + inv[i][3]*c[3];
    }

    float ultaL0[2][2];
    ultaL0[0][0] = y[0];
    ultaL0[1][0] = y[1];
    ultaL0[0][1] = y[2];
    ultaL0[1][1] = y[3];

    cout<<endl;
    cout<<"L(0) = "<<endl;
    display2(ultaL0);
    cout<<endl<<endl;
    

    float phiTrans[2][2];
    phiTrans[0][0] = phi[0][0];
    phiTrans[1][1] = phi[1][1];
    phiTrans[1][0] = phi[0][1];
    phiTrans[0][1] = phi[1][0];


    float ultaL1[2][2];
    multiply(ultaL0, phiTrans, ultaL1);
    cout<<"L(1) = L(0)*trans(phi) = "<<endl;
    display2(ultaL1);
    cout<<endl;

    float ultaL2[2][2];
    multiply(ultaL1, phiTrans, ultaL2);
    cout<<"L(2) = L(1)*trans(phi) = "<<endl;
    display2(ultaL2);
    cout<<endl;

    float ultaL3[2][2];
    multiply(ultaL2, phiTrans, ultaL3);
    cout<<"L(3) = L(2)*trans(phi) = "<<endl;
    display2(ultaL3);
    cout<<endl;

    float ultaL4[2][2];
    multiply(ultaL3, phiTrans, ultaL4);
    cout<<"L(4) = L(3)*trans(phi) = "<<endl;
    display2(ultaL4);
    cout<<endl;

    float ultaL5[2][2];
    multiply(ultaL4, phiTrans, ultaL5);
    cout<<"L(5) = L(4)*trans(phi) = "<<endl;
    display2(ultaL5);
    cout<<endl;

    float z = 0;




    float sqrtinverseV[2][2];
    sqrtinverseV[0][0] = sqrt(1/ultaL0[0][0]);
    sqrtinverseV[1][1] = sqrt(1/ultaL0[1][1]);
    sqrtinverseV[0][1] = z;
    sqrtinverseV[1][0] = z;
    cout<<endl;
    
    cout<<"V^(-1/2) = "<<endl;
    display2(sqrtinverseV);
    cout<<endl<<endl;

    float intermediate0[2][2];
    float roh0[2][2];
    multiply(sqrtinverseV, ultaL0, intermediate0);
    cout<<endl;
    multiply(intermediate0,sqrtinverseV,roh0);
    cout<<"roh0 = V^(-1/2)*ulta0* V^(-1/2) = " <<endl;
    cout<<endl;
    display2(intermediate0);
    cout <<" \n *\n\n";
    display2(sqrtinverseV);
    cout<<endl;
    cout<<"roh0 = " <<endl;
    display2(roh0);
    cout<<endl;

    float intermediate1[2][2];
    float roh1[2][2];
    multiply(sqrtinverseV, ultaL1, intermediate1);
    cout<<endl;
    multiply(intermediate1,sqrtinverseV,roh1);
    cout<<"roh1 = V^(-1/2)*ulta1* V^(-1/2) = " <<endl;
    cout<<endl;
    display2(intermediate1);
    cout <<" \n *\n\n";
    display2(sqrtinverseV);
    cout<<endl;
    cout<<"roh1 = " <<endl;
    display2(roh1);
    cout<<endl;

    float intermediate2[2][2];
    float roh2[2][2];
    multiply(sqrtinverseV, ultaL2, intermediate2);
    cout<<endl;
    multiply(intermediate2,sqrtinverseV,roh2);
    cout<<"roh2 = V^(-1/2)*ulta2* V^(-1/2) = " <<endl;
    cout<<endl;
    display2(intermediate2);
    cout <<" \n *\n\n";
    display2(sqrtinverseV);
    cout<<endl;
    cout<<"roh2 = " <<endl;
    display2(roh2);
    cout<<endl;




    cout<<"--------------DONE------------"<<endl;



}
int main(){
    solve();
    return 0;
}
