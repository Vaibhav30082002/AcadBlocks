#include <iostream>
#include <math.h>
using namespace std;
int
sender (int b[10], int k)
{
  int checksum, sum = 0, i;
  cout<<"\n****SENDER****\n";
  for (i = 0; i < k; i++)
    sum += b[i];
  cout<<"SUM IS:" <<sum;
  checksum = ~sum;
  cout<<"\nSENDER's CHECKSUM IS: "<< checksum;
  return checksum;
}

int receiver (int c[10], int k, int scheck)
{
  int checksum, sum = 0, i;
  cout<< "\n\n****RECEIVER****\n";
  for (i = 0; i < k; i++)
    sum += c[i];
  cout<<" RECEIVER SUM IS: "<<sum;
  sum = sum + scheck;
  checksum = ~sum;
  cout<<"\nRECEIVER's CHECKSUM IS: "<<checksum;
  return checksum;
}

int main ()
{
  int a[10], i, m, scheck, rcheck;
  cout<< "\nENTER SIZE OF THE STRING:";
  cin>>m;
  cout<<"\nENTER THE ELEMENTS OF THE ARRAY:";
  for (i = 0; i < m; i++)
    cin>> a[i];
  scheck = sender (a, m);
  rcheck = receiver (a, m, scheck);
  if (rcheck == 0)
    cout<< "\n\nNO ERROR IN TRANSMISSION\n\n";
  else
    cout<<"\n\nERROR DETECTED";
  return 0;
}
