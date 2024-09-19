// std::find
/*
std::find allows you to search for a specific value within a range defined by two iterators. 
It is commonly used with containers like vectors, arrays, lists, and others.

Function Signature: std::find(first, last, value)
first: Iterator pointing to the beginning of the range.
last: Iterator pointing to the end of the range (exclusive).
value: Value to search for within the range.

Return Value: 
It returns an iterator pointing to the first occurrence of value within the range [first, last). 
If the value is not found, it returns last.
*/

#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm library for std::find

int main() {
    // std::find
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Search for the value 3 in the vector
    auto it = std::find(numbers.begin(), numbers.end(), 3);

    // Check if the value was found
    if (it != numbers.end()) {
        std::cout << "Found " << *it << " at position " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    // std::find_if
    std::cout << "------------" << std::endl;

    std::vector<int> collection{14, 24,72, 7, 98, 112};

    auto odd = [](int x){
        if( (x%2) != 0)
            return true;
        return false;
    };
    
    auto odd_n_position = std::find_if(std::begin(collection),std::end(collection),odd);
    
    if (odd_n_position != std::end(collection)) {
        std::cout << "collection contains at least one odd number : " << *odd_n_position  << std::endl;
    } else {
        std::cout << "collection does not contain any odd number" << std::endl;
    }

    return 0;
}

/*
In this example, std::find is used to search for the value 3 within the numbers vector. 
If the value is found, it prints the value and its position. Otherwise, it prints a message indicating that the value was not found.

std::find is a versatile function that provides a convenient way to search for values in various containers without having to manually iterate over the elements
*/
