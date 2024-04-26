// Number System Representation

#include<iostream>
#include<bitset>
using namespace std;

int main()
{

  int data {15};

  cout<<"data: (Decimal)     "     << showbase << dec << data << endl; //Decimal Representation - 15
  cout<<"data: (Octal)       "       << showbase << oct << data << endl; //Octal Representation - 017
  cout<<"data: (Hexadecimal) " << showbase << hex << data << endl; //Hexadecimal Representation - 0xf
  cout<<"data: (binary_16)   "      << bitset<16>(data) << endl; //Binary Representation - 0000000000001111

  return 0;
}
