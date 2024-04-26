// Swapping Two Number without temp variable 
#include<iostream>
using namespace std;

int main() {
  int a=20, b=10,temp;
  cout<<"Before Swapping:\n";
  cout<<a<<"\t"<<b;
  a = a+b;
  b = a-b;
  a = a-b;  
  cout<<"\nAfter Swapping:\n";
  cout<<a<<"\t"<<b;

  return 0;

}