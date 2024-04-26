// program to display prime numbers up to the specified limit

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  // Declare variables for user input and loop control
  int num, i, j;

  // Prompt the user to enter the Positive max Limit integer
  cout << "Enter the Positive max Limit integer: ";
  cin >> num;

  // Display message indicating that prime numbers up to 'num' will be printed
  cout << "Prime num upto " << num << " are ";

  // Outer loop to iterate through numbers from 2 to 'num'
  for (i = 2; i <= num; i++)
  {
    // Assume the current number 'i' is prime initially
    bool isPrime = true;

    // Inner loop to check divisibility of 'i' by numbers from 2 to the square root of 'i'
    for (j = 2; j <= sqrt(i); j++)
    {
      // If 'i' is divisible by 'j', set isPrime to false and break out of the loop
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }

    // If isPrime is still true after the inner loop, 'i' is a prime number
    if (isPrime)
    {
      // Print the prime number
      cout << i << " ";
    }
  }

  // Return 0 to indicate successful execution
  return 0;
}
