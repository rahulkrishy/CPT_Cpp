// STL_Algorithm
// RangeBasedAlgorithm - Works on Containers Directly
// std::ranges::all_of() | std::ranges::for_each | std::ranges::sort | std::ranges::find_if | std::ranges::copy
/*
Range-based algorithm encapsulates a certain operation that needs to be performed on each element within a range, such as applying a function, searching for a specific value, or sorting elements. 
The algorithm iterates through the range using iterators and applies the specified operation to each element, providing a concise and expressive way to work with container data.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> // Include the <iterator> header for std::ostream_iterator


template<typename T>
void print_collection( const T& collection){
    
    std::cout << " Collection [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
}


int main(){

	  std::vector<int> numbers {11,2,6,4,8,3,17,9};
    print_collection(numbers);

        //std::ranges::all_of()
    std::cout << std::endl;
    std::cout << "std::ranges::all_of() : " << std::endl;

    auto odd = [](int n){
        return n%2 !=0;
    };
    
    auto result = std::ranges::all_of(numbers,odd);

    if(result){
        std::cout << "All elements in numbers are odd" << std::endl;
    }else{
        std::cout << "Not all elements in numbers are odd" << std::endl;
    }


    //For each
    std::cout << std::endl;
    std::cout << "std::ranges::for_each() : " << std::endl;
    print_collection(numbers);
    std::ranges::for_each(numbers,[](int& n){n*=2;});
    print_collection(numbers);


    //Sort
    std::cout << std::endl;
    std::cout << "std::ranges::sort() : " << std::endl;
    print_collection(numbers);
    std::ranges::sort(numbers);
    print_collection(numbers);


    //Find
    std::cout << std::endl;
    std::cout << "std::ranges::find() : " << std::endl;
    auto odd_n_position = std::ranges::find_if(numbers,odd);
    
    if (odd_n_position != std::end(numbers)) {
        std::cout << "numbers contains at least one odd number : " << *odd_n_position  << std::endl;
    } else {
        std::cout << "numbers does not contain any odd number" << std::endl;
    }

    // std::ranges::copy
    //Important, copying into outputstream on the fly
    std::cout << std::endl;
    std::cout << "numbers : " ;
    std::ranges::copy(numbers,std::ostream_iterator<int>(std::cout, " "));
    // std::ranges::copy(numbers.begin(),numbers.end(),std::ostream_iterator<int>(std::cout, " ")); //also supports iterators pairs
    
   
    return 0;
}