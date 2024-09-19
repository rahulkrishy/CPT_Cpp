// Program to check the string is palindrome or not

#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  cout << "Enter the word to check palindrome: ";
  cin >> input;

  // Reverse the input string directly using a loop
  string reversed = "";
  for (int i = input.size() - 1; i >= 0; i--) {
    reversed += input[i];
  }

  // Compare the original and reversed strings
  if (input == reversed) {
    cout << "It's a palindrome";
  } else {
    cout << "Not a palindrome";
  }

  return 0;
}