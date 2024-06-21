// Custom Iterator

/*
A custom iterator is an iterator that you define yourself to traverse elements of a custom data structure or container. 
It allows you to control how the elements of your data structure are accessed and iterated over.

Custom Iterator Requirements:
- Your container class needs to be a class template
- The container class has to model iterator types
- Your container needs begin () and end () methods that return those iterators
- The iterators have to model the operators needed by your algorithms

Iterator Type
-Needs to provide the type aliases expected by the standard template library
-These type traits help algorithms work better

*/

#include <iostream>
#include <iterator>

// Define a custom container called MyContainer
class MyContainer {
private:
    int data[5] = {1, 2, 3, 4, 5};

public:
    // Define a custom iterator for MyContainer
    class iterator {
    private:
        int* ptr;

    public:
        // Constructor
        iterator(int* p) : ptr(p) {}

        // Dereference operator
        int& operator*() const {
            return *ptr;
        }

        // Increment operator (prefix)
        iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Equality operator
        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        // Inequality operator
        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

    // Iterator begin and end functions
    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + 5);
    }
};

int main() {
    // Create an instance of MyContainer
    MyContainer container;

    // Use a range-based for loop to iterate over elements of the container
    for (int num : container) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
We define a custom container MyContainer with a simple integer array data.
Inside MyContainer, we define a nested iterator class iterator, which implements the necessary iterator functionalities (operator*, operator++, operator==, and operator!=).
We also provide begin() and end() member functions in MyContainer to obtain iterators representing the beginning and end of the container.
In the main() function, we create an instance of MyContainer and use a range-based for loop to iterate over its elements. The loop internally uses the custom iterators provided by MyContainer.
*/