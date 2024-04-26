// Bitwise swift Operator
// Bitwise left swift operator (<<) - multiplies by 2^n
// Bitwise right swift operator(>>) - divides by 2^n

// All math function are applicable greater than or the data type of int, if any smaller type will implicitly converted to base data type(int) or explicit conversion may applicable

#include<iostream>
#include<bitset>
#include <limits>
using namespace std;

int main()
{
  // To Find binary representation of the maximum integer value for datatype
  unsigned int maxValue = numeric_limits<unsigned short int>::max();

  // Calculate the number of bits needed to represent maxValue
  unsigned short int numBits = numeric_limits<unsigned short int>::digits;
  
  bitset<numeric_limits<unsigned short int>::digits> bitsetRepresentation(maxValue);
  cout << "Maximum unsigned short int value: " << maxValue << endl;
  cout << "Number of bits: " << numBits << endl;   //16 bits
  cout << "Bitset representation: " << bitsetRepresentation << endl;
  //

  unsigned short int data {0xff0u};
  
  std::cout << "Size of short int " << sizeof(short int) <<  std::endl;//  16 bits
  cout<<showbase;
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;

  // Bitwise Left Swift by 1
  data = static_cast<unsigned short int>(data << 1);  //data <<=2
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;

  // Bitwise Left Swift by 3
  data = static_cast<unsigned short int>(data << 3);
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;

  // Bitwise Left Swift by 1 (after size limit,swifted 1's can't be retrived)
  data = static_cast<unsigned short int>(data << 1);
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;

  // Bitwise Right Swift by 1 
  data = static_cast<unsigned short int>(data >> 1);
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;

  // Bitwise Right Swift by 1
  data = static_cast<unsigned short int>(data >> 1);
  cout<<"(Bin): "<<bitset<16>(data)<<" | Data (Dec): "<<dec<<data <<" | (Hex): "<<hex<<data<<endl;


  return 0;
}

