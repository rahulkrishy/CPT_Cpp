// Standard Library Functor
/*
Standard Library Functor : Uses standard library functors for arithmetic operations.

Description: This code implements a calculator using standard library functors for arithmetic operations (addition, subtraction, multiplication, division). 
Approach: Standard library functors (std::plus, std::minus, std::multiplies, std::divides) are utilized for arithmetic operations.
Error Handling: Does not include error handling for division by zero. Responsibility for error handling falls on the user if needed.
Pros: More concise and utilizes standard library components, potentially leading to clearer and more familiar code.
Cons: Less control and customization compared to custom functors. No built-in error handling for division by zero.
*/

#include <iostream>
#include <functional>

using namespace std;

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

    // Create instances of standard library functors
    std::plus<int> add_functor;
    std::minus<int> subtract_functor;
    std::multiplies<int> multiply_functor;
    std::divides<double> divide_functor;

    // Perform arithmetic operations using standard functors
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
