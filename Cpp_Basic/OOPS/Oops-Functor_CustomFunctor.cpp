// Custom Functor
/*
Custom Functor : Utilizes custom functors for arithmetic operations.

Description: This code implements a calculator using custom functor classes for arithmetic operations (addition, subtraction, multiplication, division).
Approach: Custom functor classes (Add, Subtract, Multiply, Divide) are defined, each with an overloaded operator() for the respective arithmetic operation.
Error Handling: Includes error handling for division by zero within the Divide functor.
Pros: Offers more control and customization. Error handling is included within the code.
Cons: More verbose compared to using standard library functors.
*/
#include <iostream>
#include <functional>

using namespace std;

// Functor class for addition
class Add {
public:
    // Overloaded operator () for addition
    int operator()(int a, int b) const {
        return a + b;
    }
};

// Functor class for subtraction
class Subtract {
public:
    // Overloaded operator () for subtraction
    int operator()(int a, int b) const {
        return a - b;
    }
};

// Functor class for multiplication
class Multiply {
public:
    // Overloaded operator () for multiplication
    int operator()(int a, int b) const {
        return a * b;
    }
};

// Functor class for division
class Divide {
public:
    // Overloaded operator () for division
    double operator()(int a, int b) const {
        if (b == 0) {
            cerr << "Error: Division by zero!" << endl;
            return 0; // Returning 0 to avoid undefined behavior
        }
        return static_cast<double>(a) / b;
    }
};

// Calculator class using functors
class Calculator {
public:
    // Function to perform arithmetic operation using a functor
    template <typename Func>
    int operate(int a, int b, Func func) const {
        return func(a, b);
    }
};

int main() {
    // Create an instance of the Calculator class
    Calculator calc;

    // Define operands
    int num1 = 10, num2 = 20;

    // Create instances of functors
    Add add_functor;
    Subtract subtract_functor;
    Multiply multiply_functor;
    Divide divide_functor;

    // Perform arithmetic operations using functors
    int sum = calc.operate(num1, num2, add_functor);
    int difference = calc.operate(num1, num2, subtract_functor);
    int product = calc.operate(num1, num2, multiply_functor);
    double quotient = calc.operate(num1, num2, divide_functor);

    // Output results
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    return 0;
}
