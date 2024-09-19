// Check Entire string is Palindrome or Not
// 1) Make a lowercase
// 2) Remove punctuations
// 3) Reverse string
// 4) Check Palindrome

#include<iostream>
#include<string>
using namespace std;

// Function to convert the string to lowercase
string makeLowerCase(string str);

// Function to remove punctuation characters from the lowercase string
string removePunctuCase(string lowercase);

// Function to reverse the string
string reverseCase(string noPunctuCase);

// Function to check the string is palindrome
bool isPalindrome(string noPunctuCase,string reverseStr);

int main()
{
  // Input string
  string str;
  cout << "\nEnter the string to check a palindrome: \n-> ";
  getline(cin, str); // Using getline to capture the entire line including spaces

  // Convert the input string to lowercase
  string lowercase = makeLowerCase(str);

  // Remove punctuation characters from the lowercase string
  string noPunctuCase = removePunctuCase(lowercase);

  // Reverse the string
  string reverseStr = reverseCase(noPunctuCase);
  
  if(isPalindrome(noPunctuCase,reverseStr))
    cout<<str<<"  is a Palindrome String";
  else
    cout<<str<<"  is not a Palindrome String";

  return 0;
}

// Function to convert the string to lowercase
string makeLowerCase(string str)
{
  string lowerStr;
  for (int i = 0; i < str.length(); i++)
  {
    // Append the lowercase version of each character to the result string
    lowerStr += tolower(str[i]);
  }
  return lowerStr;
}

// Function to remove punctuation characters from the lowercase string
string removePunctuCase(string lowercase)
{
  // List of punctuation characters to be removed
  string punctuCase = ".,/!@#' *?;: ";

  // Result string after removing punctuation
  string noPunctuCase;

  for (int i = 0; i < lowercase.length(); i++)
  {
    // Check if the character is not in the punctuation list
    if (punctuCase.find(lowercase[i]) == string::npos)
    {
      // Append the character to the result string
      noPunctuCase += lowercase[i];
    }
  }

  return noPunctuCase;
}

// Function to reverse the string
string reverseCase(string noPunctuCase)
{
  string reverseStr = noPunctuCase; 
  int start = 0, end = noPunctuCase.length() - 1;

  while(start < end)
  {
    swap(reverseStr[start], reverseStr[end]);

    end--;
    start++;
  }
  return reverseStr;
}

// Function to check the string is palindrome
bool isPalindrome(string noPunctuCase,string reverseStr)
{
  if(noPunctuCase == reverseStr)
    return true;
  else
    return false;
}