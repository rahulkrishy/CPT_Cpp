// Literal - Data is represented directly into the code without through some other variable to memory

// This C++ program demonstrates the use of const, constexpr, and constinit.

#include<iostream>
using namespace std;

// Define a const variable with a known 'compile-time' value
const int val1 {33};

// Define a constexpr variable with a known compile-time value
constexpr int val2{34};

// Define a variable with a runtime value
int val3 {35};

// Use constinit to initialize a variable at compile time
constinit int age = 88;

// Combine const and constinit for initialization
const constinit int age1 {val1};

// Attempting to initialize with a non-const variable would lead to a compiler error
// constinit int age2 {val3}; // Error: val3 is evaluated at runtime

// Use constinit for a compile-time initialized double
const constinit double weight {33.33};

int main()
{
  // constinit can't be used inside the main fumction

  // constexpr:

  // Declare a constant variable using const
  const int var1 = 5;

  // Declare a constant variable using constexpr
  constexpr int var2 = 10;

  // Perform a compile-time check using static_assert for var1
  // This will cause a compilation error if the condition is not true
  static_assert(var1 == 5);
  cout << "Compile time Check for var1 passed" << endl;

  // Perform a compile-time check using static_assert for var2
  // This will cause a compilation error if the condition is not true
  static_assert(var2 == 10);
  cout << "Compile time Check for var2 passed" << endl;

  // constinit: 

  // Output the values of constinit variables
  std::cout << "age : " << age << std::endl;
  std::cout << "age1 : " << age1 << std::endl;

  // Change the value of a constinit variable
  age = 33;
  std::cout << "age : " << age << std::endl;
  
  // Output the value of a constinit double variable
  std::cout << "weight : " << weight << std::endl;
  // Attempting to change the value of a constinit double variable would result in a compiler error

  return 0;
}
