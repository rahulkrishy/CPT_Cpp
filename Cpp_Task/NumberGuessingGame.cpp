// Guess the Number Game:

#include<iostream>
#include<cstdlib>
#include<ctime> // Include this header for seeding the random number generator
using namespace std;

// rand() function used for generating pseudorandom numbers
// srand() for seeding the random number generator

int main()
{ 
  cout<<"Welcome to Guess the Number(1-9)";

  // Seed the random number generator with the current time
  long elapsedTime = time(0);  // jan 1 1970
  srand(elapsedTime);         // srand(time(0));
  // Generate a random number between 1 and 9
  int randomNumber = rand() % 9 + 1;

  int chances = 3,i,num;

  for (i=1;i<=3;++i)
  {
    cout<<"\n\nNo.of.Chances Remaining: "<< chances;
    cout<<"\nEnter the Guess num: ";
    cin>>num;
    chances--;
    if(randomNumber==num)
    {
      cout<<"\nCheers! "<<num<<" is Correct Guess.";
      break;
    }
    else if(chances == 0)
    {
      cout<<"\nWrong Guess..The Game lost";
    }
    else
    {
      cout<<"\nTry again..";
    }
  }
  cout<<"\n\nThe Random Number: "<<randomNumber;
}