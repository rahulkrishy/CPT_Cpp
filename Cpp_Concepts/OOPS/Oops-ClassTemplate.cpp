// class template
/*
A class template is a blueprint for creating classes that can work with different data types.
It allows you to define a class without specifying the data type for its members or methods.
You define a class template using the template keyword followed by <typename T>, where T is a placeholder for the data type.
Inside the class template, you can use T as the data type for member variables, member functions, and parameters.
*/

#include <iostream>
using namespace std;

// Define a class template for a generic Pair
template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    // Constructor to initialize the pair
    Pair(T f, T s) : first(f), second(s) {}

    // Function to get the first element of the pair
    T getFirst() const {
        return first;
    }

    // Function to get the second element of the pair
    T getSecond() const {
        return second;
    }

    // Function to set the first element of the pair
    void setFirst(T f) {
        first = f;
    }

    // Function to set the second element of the pair
    void setSecond(T s) {
        second = s;
    }
};

int main() {
    // Creating an integer pair
    Pair<int> intPair(5, 10);

    // Creating a double pair
    Pair<double> doublePair(3.5, 7.8);

    // Printing the integer pair
    cout << "Integer Pair: (" << intPair.getFirst() << ", " << intPair.getSecond() << ")" << endl;

    // Printing the double pair
    cout << "Double Pair: (" << doublePair.getFirst() << ", " << doublePair.getSecond() << ")" << endl;

    return 0;
}
