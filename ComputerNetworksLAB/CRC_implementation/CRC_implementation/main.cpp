//
//  main.cpp
//  CRC_implementation
//
//  Created by Vaibhav Shah on 04/02/22.
//

#include <iostream>
using namespace std;
int main ()
{
  int i, j, k;
//Get Frame
  int input_length;
  cout << "\n Enter length of the data: ";
  cin >> input_length;
  if (input_length > 8)
    {
      cout << "Invalid Input";
      return 0;
    }
  int arr[20];
  cout << "\n Enter the data: ";
  for (i = 0; i < input_length; i++)
    {
      cin >> arr[i];
    }
//Get Generator
  int output_length;
  cout << "\n Enter the length of Divisor: ";
  cin >> output_length;
  int g[20];

  cout << "\n Enter the Divisor: ";
  for (i = 0; i < output_length; i++)
    {
      cin >> g[i];
    }
  cout << "\n Sender Side:\n ";
//Append 0’s
  int rs = output_length - 1;
  cout << "\n\n Number of 0’s to be appended: " << rs;
  for (i = input_length; i < input_length + rs; i++)
    {
      arr[i] = 0;
    }
  int temp[20];
  for (i = 0; i < 20; i++)
    {
      temp[i] = arr[i];
    }
  cout << "\n\n Message after appending 0’s : ";
  for (i = 0; i < input_length + rs; i++)
    {
      cout << temp[i];
    }
//Division
  for (i = 0; i < input_length; i++)
    {
      j = 0;
      k = i;
//check whether it is divisible or not
      if (temp[k] >= g[j])
    {
      for (j = 0, k = i; j < output_length; j++, k++)
        {
          if ((temp[k] == 1 && g[j] == 1) || (temp[k] == 0 && g[j] == 0))
        {
          temp[k] = 0;
        }
          else
        {
          temp[k] = 1;
        }
        }
    }
    }
//CRC
  int crc[15];
  for (i = 0, j = input_length; i < rs; i++, j++)
    {
      crc[i] = temp[j];
    }
  cout << "\n\n CRC bits: ";
  for (i = 0; i < rs; i++)
    {
      cout << crc[i];
    }
  cout << "\n\n Transmitted Data: ";
  int tf[15];
  for (i = 0; i < input_length; i++)
    {
      tf[i] = arr[i];
    }
  for (i = input_length, j = 0; i < input_length + rs; i++, j++)
    {
      tf[i] = crc[j];
    }
  for (i = 0; i < input_length + rs; i++)
    {
      cout << tf[i];
    }
  cout << "\n\n Receiver side : ";
  cout << "\n\n Received Data: ";
  for (i = 0; i < input_length + rs; i++)/*
                                          6. Write a program to implement internet checksum for error correction and detection.
                                          */
                                          #include <iostream>
                                          #include <cstring>
                                          #include <cstdio>

                                          using namespace std;

                                          class Message   {
                                              char* str;
                                              int size;
                                              int checksum;
                                              int wordSize;
                                          public: Message(char str[])   {
                                                  size = (int) strlen(str);
                                                  this->str = str;
                                                  checksum = 0;
                                                  wordSize = ((size % 2) != 0 ? size + 1 : size) / 2;
                                              }
                                              void calculateChecksum(int initialChecksum = 0)    {
                                                  checksum = initialChecksum;
                                                  for(int i = 0; i < wordSize; i++)    {
                                                      checksum += (str[i*2]*256) + str[(i*2)+1];      //(256)base10 = (100)base16
                                                  }
                                                  if(checksum%65536 != 0)
                                                      checksum = (checksum/65536) + (checksum%65536);
                                                  checksum = 65535-checksum;
                                              }
                                              void printChecksum()    {
                                                  printf("%x",checksum);
                                              }
                                              bool validateMessage(int initialChecksum)  {
                                                  calculateChecksum(initialChecksum);
                                                  printChecksum();
                                                  return checksum == 0;
                                              }
                                          };

                                          int main() {
                                              int ch;
                                              bool k=true;
                                              char message[100];
                                              cout<<"Enter Message: ";
                                              cin>>message;
                                              Message m(message);
                                              while(k)    {
                                                  cout<<"\n1.Generate Checksum\n2.Detect Error in message\n3.Exit: ";
                                                  cin>>ch;
                                                  switch(ch)  {
                                                      case 1:
                                                          m.calculateChecksum();
                                                          cout<<"Checksum: ";
                                                          m.printChecksum();
                                                          break;
                                                      case 2:
                                                          cout<<"Enter checksum: ";
                                                          int init;
                                                          scanf("%x",&init);
                                                          if(m.validateMessage(init))
                                                              cout<<"Message valid ";
                                                          else
                                                              cout<<"Message invalid ";
                                                          break;
                                                      case 3:
                                                          k=false;
                                                          break;
                                                      default:
                                                          cout<<"Wrong input \n";
                                                  }
                                                  cout<<endl;
                                              }
                                              return 0;
                                          }
    {
      cout << tf[i];
    }
  for (i = 0; i < input_length + rs; i++)
    {
      temp[i] = tf[i];
    }
//Division
  for (i = 0; i < input_length; i++)
    {
      j = 0;
      k = i;
      if (temp[k] >= g[j])
    {
      for (j = 0, k = i; j < output_length; j++, k++)
        {
          if ((temp[k] == 1 && g[j] == 1) || (temp[k] == 0 && g[j] == 0))
        {
          temp[k] = 0;
        }
          else
        {
          temp[k] = 1;
        }
        }
    }
    }
  cout << "\n\n Remainder: ";
  int rrem[15];
  for (i = input_length, j = 0; i < input_length + rs; i++, j++)
    {
      rrem[j] = temp[i];
    }
  for (i = 0; i < rs; i++)
    {
      cout << rrem[i];
    }
  int flag = 0;
  for (i = 0; i < rs; i++)
    {
      if (rrem[i] != 0)
    {
      flag = 1;
    }
    }
  if (flag == 0)
    {
      cout << "\n\n Since Remainder is 0, hence the"
    " Message Transmitted from Sender to Receiver is Correct\n\n";
    }
  else
    {
      cout << "\n\n Since Remainder is not 0,"
    " hence the Message Transmitted from Sender to Receiver contains Error\n\n";
    }
}



































//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int
//main ()
//{
//  string a;
//  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, i = 0;
//  cout << "Sender Side\n";
//  cout << "Enter a 16 bit data word\n";
//  cin >> a;
//  if (a.size () != 16)
//    {
//      cout << "The dataword doesnt have 16 bits please re-enter\n";
//      cin >> a;
//    }
//  for (i = 0; i < a.size (); i++)
//    {
//      if (i < 4)
//    {
//        if(a[i] == '1')
//      {
//        a1 += pow (2, 3 - i % 4);
//      }
//    }
//      else if (i >= 4 && i < 8)
//    {
//      if (a[i] == '1')
//        {
//          a2 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 8 && i < 12)
//    {
//      if (a[i] == '1')
//        {
//          a3 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 12 && i < 16)
//    {
//      if (a[i] == '1')
//        {
//          a4 += pow (2, 3 - i % 4);
//        }
//    }
//    }
//  int sum;
//  sum = a1 + a2 + a3 + a4;
//  int bsum[32];
//  i = 0;
//  while (sum > 0)
//    {
//      bsum[i] = sum % 2;
//      sum = sum / 2;
//      i++;
//    }
//  int length_bsum = i - 1, carry = 0;
//  int arr2[4], arr3[4] = { 0, 0, 0, 0 };
//  for (int k = 0; k <= 3; k++)
//    {
//      arr2[3 - k] = bsum[k];
//    }
//  int j = 0;
//  int flag = 0;
//  for (i = 4; i < length_bsum + 1; i++)
//    {
//      arr3[3 - flag] = bsum[i];
//      flag++;
//    }
//  int chksum[4] = { 0, 0, 0, 0 };
//  for (i = 3; i >= 0; i--)
//    {
//      sum = arr2[i] + arr3[i] + carry;
//      carry = sum / 2;
//      if (sum % 2 == 0)
//    chksum[i] = 0;
//      else
//    chksum[i] = 1;
//    }
//  i = 3;
//  if (carry != 0)
//    {
//      for (i = 3; i >= 0; i--)
//    {
//      sum = chksum[i] + carry;
//      carry = sum / 2;
//      if (sum % 2 == 0)
//        chksum[i] = 0;
//      else
//        chksum[i] = 1;
//    }
//    }
//  for (i = 0; i < 4; i++)
//    {
//      chksum[i] = (chksum[i] == 0) ? 1 : 0;
//    }
//  cout << "The final checksum is :";
//  for (i = 0; i < 4; i++)
//    {
//      cout << chksum[i];
//    }
//  cout << "\nThe codeword sent to the receiver is :";
//  cout << a;
//  for (i = 0; i < 4; i++)
//    {
//      cout << chksum[i];
//    }
//  string receiver;
//  cout << "\n\nReceiver Side\n";
//  cout << "Enter the receiver side codeword: ";
//  cin >> receiver;
//  int ra1 = 0, ra2 = 0, ra3 = 0, ra4 = 0, ra5_chksum = 0;
//  for (i = 0; i < receiver.size (); i++)
//    {
//      if (i < 4)
//    {
//      if (receiver[i] == '1')
//        {
//          ra1 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 4 && i < 8)
//    {
//      if (receiver[i] == '1')
//        {
//          ra2 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 8 && i < 12)
//    {
//      if (receiver[i] == '1')
//        {
//          ra3 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 12 && i < 16)
//    {
//      if (receiver[i] == '1')
//        {
//          ra4 += pow (2, 3 - i % 4);
//        }
//    }
//      else if (i >= 16 && i < 20)
//    {
//      if (receiver[i] == '1')
//        {
//          ra5_chksum += pow (2, 3 - i % 4);
//        }
//    }
//    }
//  int rec_sum;
//  rec_sum = ra1 + ra2 + ra3 + ra4 + ra5_chksum;
//  int bin_rec_sum[4];
//  i = 0;
//  while (rec_sum > 0)
//    {
//      bin_rec_sum[i] = rec_sum % 2;
//      rec_sum = rec_sum / 2;
//      i++;
//    }
//  int rec_arr2[4], rec_arr3[4] = { 0, 0, 0, 0 };
//  for (int k = 0; k <= 3; k++)
//    {
//      rec_arr2[3 - k] = bin_rec_sum[k];
//    }
//  j = 0;
//  flag = 0;
//  for (i = 4; i < length_bsum + 1; i++)
//    {
//      rec_arr3[3 - flag] = bin_rec_sum[i];
//      flag++;
//    }
//    sum = 0;
//    carry = 0;
//  int rec_chksum[4] = { 0, 0, 0, 0 };
//  for (i = 3; i >= 0; i--)
//    {
//      sum = rec_arr2[i] + rec_arr3[i] + carry;
//      carry = sum / 2;
//      if (sum % 2 == 0)
//    rec_chksum[i] = 0;
//      else
//    rec_chksum[i] = 1;
//    }
//  i = 3;
//  if (carry != 0)
//    {
//      for (i = 3; i >= 0; i--)
//    {
//      sum = rec_chksum[i] + carry;
//      carry = sum / 2;
//      if (sum % 2 == 0)
//        rec_chksum[i] = 0;
//      else
//        rec_chksum[i] = 1;
//    }
//    }
//  for (i = 0; i < 4; i++)
//    {
//      rec_chksum[i] = (rec_chksum[i] == 0) ? 1 : 0;
//    }
//  cout << "\nThe Sums complement is :";
//  flag = 0;
//  for (i = 3; i >= 0; i--)
//    {
//      cout << rec_chksum[i];
//      if (rec_chksum[i] != 0)
//    flag++;
//    }
//  if (flag != 0)
//    cout << "\nTHERE IS AN ERROR\n";
//  else
//    cout << "\nTHERE IS NO ERROR\n";
//  return 0;
//}






//#include<stdio.h> #include<conio.h> #include<math.h>
//int sender(int b[10],int k) {
//int checksum,sum=0,i; printf("\n****SENDER****\n");
//for(i=0;i<k;i++) sum+=b[i];
//printf("SUM IS: %d",sum);
//checksum=~sum;
//printf("\nSENDER's CHECKSUM IS:%d",checksum); return checksum;
//}
//int receiver(int c[10],int k,int scheck) {
//int checksum,sum=0,i;
//printf("\n\n****RECEIVER****\n"); for(i=0;i<k;i++)
//sum+=c[i];
//printf(" RECEIVER SUM IS:%d",sum); sum=sum+scheck;
//checksum=~sum;
//printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
//return checksum;
//}
//int main() {
//int a[10],i,m,scheck,rcheck;
//printf("\nENTER SIZE OF THE STRING:"); scanf("%d",&m);
//printf("\nENTER THE ELEMENTS OF THE ARRAY:"); for(i=0;i<m;i++)
//scanf("%d",&a[i]);
//scheck=sender(a,m);
//rcheck=receiver(a,m,scheck);
//if(rcheck==0)
//printf("\n\nNO ERROR IN TRANSMISSION\n\n"); else
//printf("\n\nERROR DETECTED"); getch();
//return 0; }
