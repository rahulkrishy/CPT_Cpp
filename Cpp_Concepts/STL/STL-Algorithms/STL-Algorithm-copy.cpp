// std::copy
/*
std::copy is a standard algorithm in the C++ Standard Library that copies elements from one container (or range) to another. 
It is used to copy elements from a source range defined by two iterators to a destination range defined by another pair of iterators.
Syntax: 
    std::copy(InputIt first, InputIt last, OutputIt d_first);
Parameters:
    first: Iterator pointing to the first element in the source range.
    last: Iterator pointing to one past the last element in the source range.
    d_first: Iterator pointing to the beginning of the destination range where elements will be copied.
Returns:
    An iterator pointing to the element past the last element copied into the destination range.
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



int main(){

    //std::vector<int> source {1,2,3,4,5,6,7,8,9};
    int source[] {1,2,3,4,5,6,7,8,9};   

    std::vector<int> dest {15,21,12,53,30,40};
    
    std::cout << "source : ";
    print_collection(source);
    
    std::cout << "dest : ";
    print_collection(dest);
    
    //Copy from source to dest
    //Copy elements from source in the range [std::begin(source),std::begin(source) + 4 ) 
    //to dest, starging from iterator std::begin(dest)
    //Make sure you are copying from valid ranges either in dest or source.
    std::copy(std::begin(source),std::begin(source) + 4,std::begin(dest));  //while copy, result will replace at the destination
    
    std::cout << "source(after copy) : ";
    print_collection(source);
    
    std::cout << "dest(after copy) : ";
    print_collection(dest);                   

    std::cout << "---------------------------" << std::endl;
 
    std::vector<int> dest1{100,200,300,400,500,600};
    
    std::cout << "source : ";
    print_collection(source);
    
    std::cout << "dest1 : " ;
    print_collection(dest1);
    
    auto odd = [](int n){
        return ((n%2)!=0);
    };
    //If there are more elements in source than the space available in dest,
    //surplus elements will just be ignored.
    std::copy_if(std::begin(source),std::end(source),std::begin(dest1),odd);
    
    std::cout << "source(after copy) : ";
    print_collection(source);
    
    std::cout << "dest1(after copy) : " ;
    print_collection(dest1);
   
    return 0;
}