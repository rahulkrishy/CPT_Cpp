// std::transform
/* 
It applies a given operation to each element of a specified range and stores the result in another range.
Syntax:
    std::transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op)
Parameters:
    first1: Iterator pointing to the first element in the input range.
    last1: Iterator pointing to one past the last element in the input range.
    result: Iterator pointing to the start of the output range where the results will be stored.
    op: Unary operation function or function object. It will be applied to each element in the input range.
Returns:
    An iterator pointing to the element past the last element written in the output range.
*/

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void print_collection( const T& collection){
    
    std::cout << " Collection [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}

int square(int x) {
    return x * x;
}


int main(){

    //Original collection
    std::vector<int> input = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3,11,45,6,23}; 
    std::vector<int> output{11,22,33};
    std::cout << "output size : " << output.size() << std::endl;
    std::cout << "output capacity : " << output.capacity() << std::endl;

    print_collection(input);
    print_collection(output);

    //Uses whatever space is there, doesn't extend the capacity
    // std::transform(input.begin(),input.end(),output.begin(),[](int n){return n*2;}); //Lookout: maybe runtime error

    //std::back_inserter_iterator : appends to the back, extends capacity if necessary.
    std::transform(input.begin(),input.end(),std::back_inserter(output),[](int n){return n*2;});

    print_collection(output);
    std::cout << "output size : " << output.size() << std::endl;
    std::cout << "output capacity : " << output.capacity() << std::endl;

    std::cout << "---------------------------" << std::endl;

    // Example 2
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> squared_nums;

    // Square each element in nums and store the result in squared_nums
    std::transform(nums.begin(), nums.end(), std::back_inserter(squared_nums), square);

    print_collection(squared_nums);




    std::cout << "Done!" << std::endl;
    
    return 0;
}