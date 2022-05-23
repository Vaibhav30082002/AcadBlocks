//
//  main.cpp
//  checksum
//
//  Created by Vaibhav Shah on 04/02/22.
//

/*
 Write a program to implement internet checksum for error correction and detection.
*/
#include<iostream>

using namespace std;

string s1,s2,s3,s4;

string binaryAddition(string a, string b){
   string result = "";
   int temp = 0;
   int size_a = a.size() - 1;
   int size_b = b.size() - 1;
   while (size_a >= 0 || size_b >= 0 || temp == 1){
      temp += ((size_a >= 0)? a[size_a] - '0': 0);
      temp += ((size_b >= 0)? b[size_b] - '0': 0);
      result = char(temp % 2 + '0') + result;
      temp /= 2;
      size_a--; size_b--;
   }
   if(result.size()>a.size()){
    result= binaryAddition(result.substr(1,result.size()-1),"1");
   }
   return result;
}

char flip(char c) {return (c == '0')? '1': '0';}

string binaryCompliment(string s){
    string complement="";
    for (int i = 0; i < s.length(); i++)
        complement += flip(s[i]);
    return complement;
}

int main(){
    cout<<"\n\n---SENDER'S SIDE---\n\n";
    cout<<"Enter data unit 1 of 8 bits: ";
    cin>>s1;
    cout<<"Enter data unit 2 of 8 bits: ";
    cin>>s2;
    cout<<"Enter data unit 3 of 8 bits: ";
    cin>>s3;
    cout<<"Enter data unit 4 of 8 bits: ";
    cin>>s4;

    string sender_sum=binaryAddition(s4, binaryAddition(s3, binaryAddition(s1,s2)));
    string checksum=binaryCompliment(sender_sum);

    cout<<"\nSender side sum and the checksum respectively are "<<sender_sum<<" and "<<checksum<<endl;
    cout<<"\n\n---RECEIVER'S SIDE---\n\n";
    cout<<"Enter data unit 1 of 8 bits: ";
    cin>>s1;
    cout<<"Enter data unit 2 of 8 bits: ";
    cin>>s2;
    cout<<"Enter data unit 3 of 8 bits: ";
    cin>>s3;
    cout<<"Enter data unit 4 of 8 bits: ";
    cin>>s4;
    cout<<"Enter CHECKSUM of 8 bits: ";
    string rec_checksum;
    cin>>rec_checksum;

    string receiver_sum=binaryAddition(rec_checksum, binaryAddition(s4, binaryAddition(s3, binaryAddition(s1,s2))));
    string finalsum=binaryCompliment(receiver_sum);

    cout<<"The final value at receiver end is "<<finalsum<< " and hence :";

    if(finalsum=="00000000")cout<<endl<<"-----------------ACCEPTED-----------------\n";
    else cout<<endl<<"-----------------NOT ACCEPTED-----------------\n";
}
