// STL Algorithms
// Doumentation: https://en.cppreference.com/w/cpp/algorithm

// Legacy algorithms - Work on Iterator pairs
// std::all_of | std::none_of | std::any_of
/*
In C++, std::all_of, std::none_of, and std::any_of are part of the <algorithm> header and are used to check conditions on elements in a range. 
1)std::all_of:
    std::all_of checks if a condition holds true for all elements in a given range.
    It returns true if the condition is satisfied for all elements, and false otherwise.
    Syntax: std::all_of(begin, end, predicate), where begin and end define the range, and predicate is a function or function object that defines the condition to be checked.
2)std::none_of:
    std::none_of checks if a condition does not hold true for any element in a given range.
    It returns true if the condition is not satisfied for any element, and false otherwise.
    Syntax: std::none_of(begin, end, predicate), similar to std::all_of.
3)std::any_of:
    std::any_of checks if a condition holds true for at least one element in a given range.
    It returns true if the condition is satisfied for at least one element, and false otherwise.
    Syntax: std::any_of(begin, end, predicate), similar to std::all_of.
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


bool is_odd(int n){
   return n % 2 != 0; 
}


int main(){

    std::vector<int> collection{2,6,8,49,64,71};
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    //std::set<int> collection{2,6,8,40,64,70};
    //int collection[] {2,6,8,40,64,70};

    //1) std::all_of , lambda function predicate
    if (std::all_of(std::begin(collection), std::end(collection), [](int i){ return i % 2 == 0; })) {
        std::cout << "(std::all_of) :  All numbers in collection are even" << std::endl;
    }else{
        std::cout << "(std::all_of) : Not all numbers in collection are even" << std::endl;
    }

    std::cout <<std::endl;

    // Example2: Check if all elements are even
    bool all_even = std::all_of(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All elements are even: " << std::boolalpha << all_even << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;

    //2) std::any_of ,functor as predicate 
    class DivisibleBy
    {
        private : 
            const int d;
        public : 
            DivisibleBy(int n) : d(n) {}
            bool operator()(int n) const { return n % d == 0; }
    };
 
    if (std::any_of(std::begin(collection),std::end(collection), DivisibleBy(7))) {
        std::cout << "(std::any_of) : At least one number is divisible by 7" << std::endl;
    }else{
        std::cout << "(std::any_of) : None of the numbers is divisible by 7" << std::endl;
    }

    std::cout <<std::endl;

    // Example2: Check if none of the elements are negative
    bool none_negative = std::none_of(numbers.begin(), numbers.end(), [](int x) { return x < 0; });
    std::cout << "None of the elements are negative: " << std::boolalpha << none_negative << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;

    //std::none_of , function pointer as predicate
    if (std::none_of(std::begin(collection), std::end(collection), is_odd)) {
        std::cout << "(std::none_of) :  None of the numbers is odd" << std::endl;
    }else{
        std::cout << "(std::none_of) : At least one number is odd" << std::endl;
    }

    std::cout <<std::endl;

    // Example2: Check if any element is greater than 3
    bool any_greater_than_3 = std::any_of(numbers.begin(), numbers.end(), [](int x) { return x > 3; });
    std::cout << "Any element is greater than 3: " << std::boolalpha << any_greater_than_3 << std::endl;

   
    return 0;
}

