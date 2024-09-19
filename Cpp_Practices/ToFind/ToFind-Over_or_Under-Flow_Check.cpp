// Overflow and Underflow correcter

#include<iostream>
using namespace std;

void inputCheck(int input);

int main()
{
  int input;
  cout<<"File Size(0 to 255)"<<endl;
  cin>>input;
  cout<<"User Input: "<<input<<endl;
  inputCheck(input);

  return 0;
}

void inputCheck(int input)
{
  int check = 0;
  if(input>=0 && input<=255)
  {
   cout<<"Input size("<<input<<") Ok";
  }
  else if(input>255)
  {
   while(input>255)
   {
     input -=255;
     check++;
   }
   cout<<"Overflowed("<<check<<") Corrected Input -> "<<input;
  }
  else if(input<0)
  {
   while(input<0)
   {
     input +=255;
     check++;
   }
   cout<<"Underflowed("<<check<<") Corrected Input -> "<<input;
  }
}
