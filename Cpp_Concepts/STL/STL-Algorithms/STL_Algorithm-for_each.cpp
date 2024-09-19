// Range-based STL algorithm
// std::for_each
/*
std::for_each is an algorithm provided by the <algorithm> header. 
It is used to apply a given function to each element in a specified range.

std::for_each:
  std::for_each applies a specified unary function to each element in the specified range.
  It does not return any value.
  Syntax: std::for_each(begin, end, function), where begin and end define the range, and function is a unary function or function object to be applied to each element.
  The function can modify the elements if necessary.
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

auto print = [](const int& n) {
        std::cout << " " << n;
    };


int main(){

    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    //int nums[]{3, 4, 2, 8, 15, 267};
    //std::set<int> nums{3, 4, 2, 8, 15, 267};

 
    //Print each elt in the collection : lambda function predicate
    std::for_each(std::begin(nums), std::end(nums), print);
    std::cout << std::endl;

    std::cout << "---------------------------------" << std::endl;
    
    //Predicate that modifies elements in place
    std::for_each(std::begin(nums), std::end(nums), [](int& n){ n++; });
    
    //Print
    std::for_each(std::begin(nums), std::end(nums), print);
    std::cout << std::endl;
    
    
    std::cout << "---------------------------------" << std::endl;

    //Capturing result through stateful functor that's returned
    // calls Sum::operator() for each number
    Sum s;
    s = std::for_each(std::begin(nums), std::end(nums), s);
    std::cout << "result : " << s.sum << std::endl;
    
    std::cout << "---------------------------------" << std::endl;

    //Using a lambda that captures a local variables by ref and modifies it.
    int our_result{0};
    std::for_each(std::begin(nums), std::end(nums),[&our_result](int n) { our_result += n; });
    std::cout << "result : " << our_result << std::endl;
    
    return 0;
}