// Template specialization
/*
Template specialization in C++ refers to the process of providing a specialized implementation of a template for a specific data type or set of data types. 
It allows you to customize the behavior of a template for certain types while using the generic template for all other types. 
Template specialization can be used to optimize performance, handle special cases, or provide alternative implementations for specific data types.
There are two types of template specialization:
1)Explicit Template Specialization, you provide a separate definition for a specific data type or set of data types.
This allows you to override the default behavior of the template for the specified type(s).
2)Partial template specialization, you provide a specialized version of the template for a subset of possible template arguments.
This allows you to define alternative implementations for specific combinations of template parameters.

// Template specialization is commonly used in scenarios such as:
Optimizing performance for specific data types.
Handling special cases that require different behavior.
Providing alternative implementations for specific use cases.
*/

#include <iostream>
#include <string>
using namespace std;

// Generic class template for adding numbers or floats
template <typename T>
class Adder {
public:
    // Member function to add two values of type T
    T add(T a, T b) {
        return a + b;
    }

    // Member function to subtract two values of type T
    T subtract(T a, T b) {
        return a - b;
    }
};

// Class template specialization for adding strings
template <>
class Adder<string> {
public:
    // Member function to concatenate two strings
    string add(string a, string b) {
        return concatenate(a, b); // Specialized method for adding strings
    }

    // Member function to compare two strings
    string compare(string a, string b) {
        return (a == b) ? "Strings are equal" : "Strings are not equal";
    }

private:
    // Private member function to concatenate two strings
    string concatenate(string a, string b) {
        return a + b;
    }
};

int main() {
    // Adding numbers using the generic template
    Adder<int> intAdder; // Instantiate Adder class template with int type
    int num1 = 20, num2 = 10;
    cout << "Sum of numbers: " << intAdder.add(num1, num2) << endl; // Call add() method
    cout << "subtract of numbers: " << intAdder.subtract(num1, num2) << endl; // Call subtract() method
    
    // Adding floats using the generic template
    Adder<float> floatAdder; // Instantiate Adder class template with float type
    float float1 = 3.5, float2 = 2;
    cout << "Sum of floats: " << floatAdder.add(float1, float2) << endl; // Call add() method
    cout << "subtract of floats: " << floatAdder.subtract(float1, float2) << endl; // Call subtract() method

    // Adding strings using the specialized template
    Adder<string> stringAdder; // Instantiate Adder class template with string type
    string str1 = "Hello, ", str2 = "world!";
    cout << "Concatenated string: " << stringAdder.add(str1, str2) << endl; // Call add() method
    cout << "String comparison: " << stringAdder.compare(str1, str2) << endl; // Call compare() method

    return 0;
}
