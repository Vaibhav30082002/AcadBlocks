//
//  main.cpp
//  goBackARQ
//
//  Created by Vaibhav Shah on 25/02/22.
//
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

using namespace std;
int ptr = 0;
int c_time = 0;
int receiver(int a[], int n)
{

  int cnt = 0;
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    int flag = rand() % 2;
    if (flag)
    {
      c_time++;
      cout << "Received frame " << a[i] << " At Time: " << c_time << endl;
    }
    else
    {
      c_time++;
      cout << "Not received frame " << a[i] << " At Time: " << c_time << endl;
      cnt = 1;
    }
  }
  if (cnt == 1)
  {
    c_time++;
    return 0;
  }
  return 1;
}
void sender(int N, int nf)
{
  int arr[N];
lab:
  cout << endl;
  for (int i = 0; i < N && ptr < nf; i++)
  {
    c_time++;
    cout << "SENT FRAME " << ptr << " At time: " << c_time << endl;
    arr[i] = ptr;
    ptr++;
  }
  int dec = receiver(arr, N);
  if (dec == 0)
  {
    ptr -= N;
    c_time++;
    goto lab;
  }
  else
  {
    cout << endl;
    for (int i = 0; i < N; i++)
    {
      c_time++;
      int flag = rand() % 2;
      if (flag)
      {
        cout << "Acknowledege recived for frame " << arr[i] << " At time: " << c_time << endl;
      }
      else
      {
        c_time++;
        cout << "Acknowledege not recived for frame " << arr[i] << " At time: " << c_time << endl;
        ptr -= N;
        goto lab;
      }
    }
  }
}

int main()
{
  int n, N;
  cout << "Enter the number of frames : ";
  cin >> n;
  cout << "Enter the Window Size : ";
  cin >> N;
  for (int i = 0; i < n; i += N)
  {
    sender(N, n);
    
  }
  return 0;
}
