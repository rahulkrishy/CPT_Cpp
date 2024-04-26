// Prints ASCII character values for characters

#include <iostream>
using namespace std;

int main() {
  // Declare characters 'a' and 'b'.
  char a = 'a', b = 'b';

  // Print the ASCII value of 'a'.
  cout << "a: " << static_cast<int>(a) << endl;
  // Print the ASCII value of 'b'.
  cout << "b: " << static_cast<int>(b) << endl;
  // Print the sum of ASCII values of 'a' and 'b' (casted to int for clarity).
  cout << "a+b: " << static_cast<int>(a + b) << endl;

  // Loop through ASCII codes from 32 to 126 (excluding non-printable characters).
  for (int i = 32; i < 127; i++) {
    // Print the ASCII code and its corresponding character.
    cout << i << " : " << static_cast<char>(i) << endl;
  }

  return 0;
}
