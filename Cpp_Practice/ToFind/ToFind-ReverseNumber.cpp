#include<iostream>
using namespace std;

int main()
{
  // Declare variables
  int number, reversed = 0, digit;

  // Get the number from the user
  cout << "Enter the number to reverse: ";
  cin >> number;

  // Reverse the number
  while(number >= 1)
  {
    // Extract the last digit
    digit = number % 10;

    // Build the reversed number
    reversed = (reversed * 10) + digit;
    
    // Remove the last digit
    number = number / 10;
  }

  // Display the reversed number
  cout << "Reverse Number: " << reversed;

  return 0;
}
