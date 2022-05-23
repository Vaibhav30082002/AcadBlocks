//
//  main.cpp
//  manova
//
//  Created by Vaibhav Shah on 27/12/21.
//

#include <iostream>
#include <cmath>
using namespace std;
void solve(){
    int n1, n2, n3;

    // user inputs
    cout<<"Enter sample size of table 1(n1):";
    cin>>n1;
    cout<<"Enter the table 1 elements: "<<endl;
    float t1[2][n1];
    for(int i=0; i<n1; i++){
        cin>>t1[0][i]>>t1[1][i];
    }
    
    cout<<"Enter sample size of table 2(n2):";
    cin>>n2;
    cout<<"Enter the table 1 elements: "<<endl;
    float t2[2][n2];
    for(int i=0; i<n2; i++){
        cin>>t2[0][i]>>t2[1][i];
    }
    
    cout<<"Enter sample size of table 3(n3):";
    cin>>n3;
    cout<<"Enter the table 3 elements: "<<endl;
    float t3[2][n3];
    for(int i=0; i<n3; i++){
        cin>>t3[0][i]>>t3[1][i];
    }
    cout<<endl<<endl;


    // display the tables
    cout<<"------------------------------------\n";
    cout<<"The matrix is : "<<endl;
    int max_n = n1;
    if(n2>max_n){
        max_n = n2;
    }
    if(n3>max_n){
        max_n = n3;
    }

    

    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<"|"<<t1[0][i]<<"| ";
        }
        else{
            
        }
    }
    cout<<endl;
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<"|"<<t1[1][i]<<"| ";
        }
        else{

        }
    }
    cout<<endl<<endl;


    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<"|"<<t2[0][i]<<"| ";
        }
        else{
            
        }
    }
    cout<<endl;
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<"|"<<t2[1][i]<<"| ";
        }
        else{

        }
    }
    cout<<endl<<endl;


    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<"|"<<t3[0][i]<<"| ";
        }
        else{
            
        }
    }
    cout<<endl;
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<"|"<<t3[1][i]<<"| ";
        }
        else{

        }
    }
    cout<<endl<<endl;


    // now means
    cout<<endl;
    float x1[2]={0};
    float x2[2]={0};
    float x3[2]={0};
    float x[2]={0};

    for(int i=0; i<n1; i++){
        x1[0]+=t1[0][i];
        x1[1]+=t1[1][i];
        x[0]+=t1[0][i];
        x[1]+=t1[1][i];

    }
    for(int i=0; i<n2; i++){
        x2[0]+=t2[0][i];
        x2[1]+=t2[1][i];
        x[0]+=t2[0][i];
        x[1]+=t2[1][i];
    }
    for(int i=0; i<n3; i++){
        x3[0]+=t3[0][i];
        x3[1]+=t3[1][i];
        x[0]+=t3[0][i];
        x[1]+=t3[1][i];
    }

    // print the means
    x1[0] = x1[0]/n1;
    x1[1] = x1[1]/n1;
    cout<<"x1 bar = "<<"|"<<x1[0]<<"|"<<endl;
    cout<<"         "<<"|"<<x1[1]<<"|"<<endl;
    cout<<endl;


    x2[0] = x2[0]/n2;
    x2[1] = x2[1]/n2;
    cout<<"x2 bar = "<<"|"<<x2[0]<<"|"<<endl;
    cout<<"         "<<"|"<<x2[1]<<"|"<<endl;
    cout<<endl;


    x3[0] = x3[0]/n3;
    x3[1] = x3[1]/n3;
    cout<<"x3 bar = "<<"|"<<x3[0]<<"|"<<endl;
    cout<<"         "<<"|"<<x3[1]<<"|"<<endl;
    cout<<endl;

    int n = n1+n2+n3;
    x[0] = x[0]/n;
    x[1] = x[1]/n;
    cout<<"x bar = "<<"|"<<x[0]<<"|"<<endl;
    cout<<"        "<<"|"<<x[1]<<"|"<<endl;
    cout<<endl;


    cout<<endl;
    // now obs = mean + treatment effect + residual
    float te1[3];
    te1[0] = x1[0]-x[0];
    te1[1] = x2[0]-x[0];
    te1[2] = x3[0]-x[0];

    float r1[n];
    int k = 0;
    for(int i=0; i<n1; i++){
        r1[k] = t1[0][i] - x1[0];
        k++;
    }
    for(int i=0; i<n2; i++){
        r1[k] = t2[0][i] - x2[0];
        k++;
    }
    for(int i=0; i<n1; i++){
        r1[k] = t3[0][i] - x3[0];
        k++;
    }

    // display first ...
    cout<<"Now, Observation = mean + treatment + residual"<<endl;
    cout<<"Therefore, "<<endl;
    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<t1[0][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<x[0]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<te1[0]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    k = 0;
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<r1[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";


    cout<<endl; //...


    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<t2[0][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  =  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<x[0]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  +  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<te1[1]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  +  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<r1[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";


    cout<<endl;//...


    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<t3[0][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<x[0]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<te1[2]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<r1[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";
    
    cout<<endl<<endl;



    // SSobs = SSmean + SStr + SSres
    cout<<"Now, SSobs = SSmean + SStr + SSres"<<endl;
    float ssobs_top = 0;
    float ssmean_top = 0;
    float sste_top = 0;
    float ssres_top = 0;
    
    ssmean_top = n*(x[0]*x[0]);

    sste_top+=(te1[0]*te1[0]*n1);
    sste_top+=(te1[1]*te1[1]*n2);
    sste_top+=(te1[2]*te1[2]*n3);

    k = 0;
    for(int i=0; i<n; i++){
        ssres_top+=(r1[k]*r1[k]);
        k++;
    }

    ssobs_top = ssres_top + sste_top + ssmean_top;
    cout<<ssobs_top<<" = "<<ssmean_top<<" + ";
    cout<<sste_top<<" + "<<ssres_top<<endl;
    cout<<endl;

    cout<<"Total SS (corrected) = SSobs - SSmean"<<endl;
    cout<<"Total SS (corrected) = "<<ssobs_top<<" - "<<ssmean_top<<endl;
    cout<<"Total SS (corrected) = "<<ssobs_top-ssmean_top<<endl;










    // display second...
    float te2[3];
    te2[0] = x1[1]-x[1];
    te2[1] = x2[1]-x[1];
    te2[2] = x3[1]-x[1];

    float r2[n];
    k = 0;
    for(int i=0; i<n1; i++){
        r2[k] = t1[1][i] - x1[1];
        k++;
    }
    for(int i=0; i<n2; i++){
        r2[k] = t2[1][i] - x2[1];
        k++;
    }
    for(int i=0; i<n1; i++){
        r2[k] = t3[1][i] - x3[1];
        k++;
    }




    cout<<endl<<endl;
    cout<<"Repeating this operation for the observations on the second variable, we have\n";
    cout<<"Again, Observation = mean + treatment + residual"<<endl;
    cout<<"So, "<<endl;
    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<t1[1][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<x[1]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<te2[0]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    k = 0;
    for(int i=0; i<max_n; i++){
        if(i<n1){
            cout<<r2[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";


    cout<<endl; //...


    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<t2[1][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  =  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<x[1]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  +  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<te2[1]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|  +  ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n2){
            cout<<r2[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";


    cout<<endl;//...


    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<t3[1][i]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<x[1]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<te2[2]<<" ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";

    cout<<"| ";
    for(int i=0; i<max_n; i++){
        if(i<n3){
            cout<<r2[k]<<" ";
            k++;
        }
        else{
            cout<<"  ";
        }
    }
    cout<<"|     ";
    
    cout<<endl<<endl;



    // SSobs = SSmean + SStr + SSres
    cout<<"Now, SSobs = SSmean + SStr + SSres"<<endl;
    float ssobs_bottom = 0;
    float ssmean_bottom = 0;
    float sste_bottom = 0;
    float ssres_bottom = 0;
    
    ssmean_bottom = n*(x[1]*x[1]);

    sste_bottom+=(te2[0]*te2[0]*n1);
    sste_bottom+=(te2[1]*te2[1]*n2);
    sste_bottom+=(te2[2]*te2[2]*n3);

    k = 0;
    for(int i=0; i<n; i++){
        ssres_bottom+=(r2[k]*r2[k]);
        k++;
    }

    ssobs_bottom = ssres_bottom + sste_bottom + ssmean_bottom;
    cout<<ssobs_bottom<<" = "<<ssmean_bottom<<" + ";
    cout<<sste_bottom<<" + "<<ssres_bottom<<endl;
    cout<<endl;

    cout<<"Total SS (corrected) = SSobs - SSmean"<<endl;
    cout<<"Total SS (corrected) = "<<ssobs_bottom<<" - "<<ssmean_bottom<<endl;
    cout<<"Total SS (corrected) = "<<ssobs_bottom-ssmean_bottom<<endl;





    // step 3
    cout<<endl<<endl;

    float mean = 0;
    float treatment = 0;
    float residual = 0;
    float total = 0;

    mean = n*(x[0]*x[1]);

    treatment = (n1*te1[0]*te2[0])+(n2*te1[1]*te2[1])+(n3*te1[2]*te2[2]);

    k = 0;
    for(int i=0; i<n; i++){
        residual+=(r1[k]*r2[k]);
        k++;
    }

    for(int i=0; i<n1; i++){
        total+=(t1[0][i]*t1[1][i]);
    }
    for(int i=0; i<n2; i++){
        total+=(t2[0][i]*t2[1][i]);
    }
    for(int i=0; i<n3; i++){
        total+=(t3[0][i]*t3[1][i]);
    }

    cout<<"Mean : ";
    for(int i=0; i<n; i++){
        cout<<x[0]<<"("<<x[1]<<") ";
        if(i==n-1){
            break;
        }
        cout<<"+ ";
    }
    cout<<" = "<<n<<"("<<x[0]<<"*"<<x[1]<<") = ";
    cout<<mean<<endl;


    cout<<"Treatment : "<<n1<<"("<<te1[0]<<")("<<te2[0]<<") + ";
    cout<<n2<<"("<<te1[1]<<")("<<te2[1]<<") + ";
    cout<<n3<<"("<<te1[2]<<")("<<te2[2]<<")";
    cout<<" = "<<treatment<<endl;


    cout<<"Residual : ";
    for(int i=0; i<4; i++){
        cout<<"("<<r1[i]<<")("<<r2[i]<<") ";
        cout<<"+ ";
    }
    cout<<".... + ("<<r1[n-1]<<")("<<r2[n-1]<<") = "<<residual<<endl;


    cout<<"Total : ";
    for(int i=0; i<2; i++){
        cout<<"("<<t1[0][i]<<")("<<t1[1][i]<<") ";
        cout<<"+ ";
    }
    cout<<".... + ("<<t3[0][n3-1]<<")("<<t3[1][n3-1]<<") = "<<total<<endl;


    cout<<endl;
    cout<<"Total (corrected) cross product = total cross product - mean cross product"<<endl;
    cout<<"Total (corrected) cross product = "<<total<<" - "<<mean<<" = "<<total-mean<<endl;



    cout<<endl<<endl;


    float t[2][2];
    float r[2][2];
    float to[2][2];

    t[0][0] = sste_top;
    t[1][1] = sste_bottom;
    t[0][1] = treatment;
    t[1][0] = treatment;

    r[0][0] = ssres_top;
    r[1][1] = ssres_bottom;
    r[0][1] = residual;
    r[1][0] = residual;

    to[0][0] = t[0][0] + r[0][0];
    to[1][1] = t[1][1] + r[1][1];
    to[0][1] = t[0][1] + r[0][1];
    to[1][0] = t[1][0] + r[1][0];

    int dof1 = 3 - 1;
    int dof2 = n - 3;

    // printing manova table...
    cout<<"Now, MANOVA table : "<<endl;

    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Source of variation  Matrix of SS and Cross Prod  Degrees of freedom"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Treatment             "<<"|"<<t[0][0]<<" "<<t[0][1]<<"|"<<"                       ";
    cout<<3<<" - "<<1<<" = "<<dof1<<endl;
    cout<<"                      "<<"|"<<t[1][0]<<" "<<t[1][1]<<"|"<<endl<<endl;

    cout<<"Residual              "<<"|"<<r[0][0]<<" "<<r[0][1]<<"|"<<"                       ";
    cout<<n1<<"+"<<n2<<"+"<<n3<<"-"<<3<<"="<<dof2<<endl;
    cout<<"                      "<<"|"<<r[1][0]<<" "<<r[1][1]<<"|"<<endl<<endl;

    cout<<"--------------------------------------------------------------------"<<endl;

    cout<<"Total(corrected)      "<<"|"<<to[0][0]<<" "<<to[0][1]<<"|"<<"                       ";
    cout<<n<<"-"<<1<<"="<<dof1+dof2<<endl;
    cout<<"                      "<<"|"<<to[1][0]<<" "<<to[1][1]<<"|"<<endl<<endl;

    cout<<"--------------------------------------------------------------------"<<endl;


    cout<<endl;

    cout<<"Also, we can verify :"<<endl;
    cout<<"|"<<to[0][0]<<" "<<to[1][0]<<"| = |"<<t[0][0]<<" "<<t[1][0]<<"|  |"<<r[0][0]<<" "<<r[1][0]<<"|\n";
    cout<<"|"<<to[0][1]<<" "<<to[1][1]<<"|   |"<<t[0][1]<<" "<<t[1][1]<<"|  |"<<r[0][1]<<" "<<r[1][1]<<"|\n";

    cout<<endl<<endl;


    cout<<"Now, A* = |W|/|B+W| "<<endl<<endl;
    float w = r[0][0]*r[1][1] - r[1][0]*r[0][1];
    float bw = to[0][0]*to[1][1] - to[1][0]*to[0][1];

    cout<<"       "<<"|"<<r[0][0]<<" "<<r[1][0]<<"|"<<endl;
    cout<<"       "<<"|"<<r[0][1]<<" "<<r[1][1]<<"|"<<endl;
    cout<<"A* =  -----------   "<<endl;
    cout<<"       "<<"|"<<to[0][0]<<" "<<to[1][0]<<"|"<<endl;
    cout<<"       "<<"|"<<to[0][1]<<" "<<to[1][1]<<"|"<<endl;

    cout<<endl;

    cout<<"      "<<r[0][0]<<"("<<r[1][1]<<") - ("<<r[1][0]<<"*"<<r[0][1]<<")"<<endl;
    cout<<"A* = "<<"-------------------"<<endl;
    cout<<"      "<<to[0][0]<<"("<<to[1][1]<<") - ("<<to[1][0]<<"*"<<to[0][1]<<")"<<endl;
    cout<<endl;

    cout<<"A* = "<<w<<"/"<<bw<<" = "<<w/bw<<endl<<endl;
    float lol = w/bw;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl<<endl;

    
    cout<<"In case you need it : \nsqrt(A*) = "<<sqrt(lol)<<endl;
    cout<<"1 - sqrt(A*) = "<<1 - sqrt(lol)<<endl;
    cout<<"(1 - sqrt(A*))/sqrt(A*) = "<<(1-sqrt(lol))/sqrt(lol)<<endl;

    cout<<endl<<endl;
    cout<<"Dedicated to TBD..."<<endl;
}
int main(){
    solve();
    return 0;
}
