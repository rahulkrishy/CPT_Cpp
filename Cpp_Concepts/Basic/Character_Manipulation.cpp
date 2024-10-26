// Character manipulation - modifying individual characters in a string
/*
<cctype> library (also known as <ctype.h> in C) provides various character manipulation functions 
that help determine the type or properties of characters and can transform them accordingly. B
elow is a list of commonly used functions:

Character Classification Functions:s
These functions return a non-zero integer if the character meets the condition; otherwise, they return zero.

isalnum(int ch): Checks if the character is alphanumeric (a letter or a digit).
isalpha(int ch): Checks if the character is alphabetic (a letter).
iscntrl(int ch): Checks if the character is a control character.
isdigit(int ch): Checks if the character is a digit (0-9).
isgraph(int ch): Checks if the character has a graphical representation (excluding space).
islower(int ch): Checks if the character is lowercase.
isprint(int ch): Checks if the character is printable, including space.
ispunct(int ch): Checks if the character is a punctuation mark.
isspace(int ch): Checks if the character is a whitespace character (' ', '\t', '\n', '\v', '\f', '\r').
isupper(int ch): Checks if the character is uppercase.
isxdigit(int ch): Checks if the character is a hexadecimal digit (0-9, a-f, or A-F).

Character Conversion Functions:
These functions are used to convert characters to a different case. 
They return the converted character or the original character if no conversion is possible.

tolower(int ch): Converts a character to lowercase (if it’s an uppercase letter).
toupper(int ch): Converts a character to uppercase (if it’s a lowercase letter).
*/

#include<bits/stdc++.h>
// #include<iostream>
// #include<cctype>
using namespace std;

int main(){
  char message[] = {"Hello i am Iron Man 707. "};
  int count{};
  char message1[size(message)];

  // Check count in c String 
  cout<<"Number at index ";
  for(size_t i {0}; i<size(message); ++i){
    if(isdigit(message[i])){
      cout<<"["<<i<<"] ";
      ++count;
    }
  }
  cout<<endl;
  cout<<"Number count: "<<count<<endl;

  // Check upperCase
  count = 0;
  for(auto c: message){
    if(isupper(c)){
      ++count;
    }
  }
  cout<<"Uppercase count: "<<count<<endl;

  // Convert to UpperCase
  for(size_t i{0}; i<size(message); ++i){
    message1[i] = toupper(message[i]);
  }

  cout<<"UPPERCASE: "<<message1<<endl;

}
