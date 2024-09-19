//Iterators
/*
Iterators in the C++ Standard Library (STL) are objects that provide a way to traverse through the elements of containers. 
They act as a 'generalized pointer' that can be used to access elements of various containers, including arrays, vectors, lists, sets, maps, and more. 
Iterators abstract the details of how elements are stored and accessed within containers, allowing for uniform traversal regardless of the underlying data structure.

Iterator types are hierarchical: a forward iterators is also an input iterator, a bidirectional iterator is also a forward iterator, a random access iterator is also a bidirectional iterator.
An algorithm that works for forward iterators, should also work with bidirectional iterators. Similarly, an algorithm that works with bidirectional iterators, should also work with random access iterators.

Input Iterator         - std::find()   
Output Iterator        - std::copy()   
Forward Iterator       - std::fill(), std::replace  
Bidirectional Iterator - std:reverse() 
Random Access Iterator - Std::sort()   
*/

#include <iostream>
#include <vector>
#include <array>

// Function template to print elements of a collection using iterators
template <typename T>
void print_collection(const T& collection){
    // Obtain an iterator to the beginning of the collection
    auto it = collection.begin();
    
    // Print the opening bracket
    std::cout << " [";
    
    // Iterate over the elements of the collection using the iterator
    while(it != collection.end()){
        // Print the current element pointed to by the iterator
        std::cout << " " << *it ;
        // Move the iterator to the next element
        ++it;
    }
    
    // Print the closing bracket and a new line
    std::cout << "]" << std::endl;
}

int main(){
    // Creating a vector and an array with some elements
    std::vector<int> ints1{ 11,22,33,44 };               //vector
    std::array<int,4> ints2 {100,200,300,400};           //array

    // Creating iterators for the vector
    std::vector<int>::iterator it_begin = ints1.begin(); // Iterator pointing to the beginning of ints1
    std::vector<int>::iterator it_end = ints1.end();     // Iterator pointing to the end of ints1. its will point to after the last element

    // Print the first element and check if the iterator is at the end
    std::cout << std::boolalpha;
    std::cout << "first elt : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    // Move the iterator to the next element and print it
    ++it_begin;
    std::cout << "second elt : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    // Move the iterator to the next element and print it
    ++it_begin;
    std::cout << "third elt : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    // Move the iterator to the next element and print it
    ++it_begin;
    std::cout << "fourth elt : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl;

    // Move the iterator beyond the end of the vector and try to access the element
    ++it_begin;
    std::cout << "junk elt : " << *it_begin << std::endl;
    std::cout << "it == end_it : " << (it_begin == it_end) << std::endl; // true

    // Print the elements of the vector and the array using the print_collection function
    std::cout << "--------" << std::endl;
    std::cout << "ints1 : " ;
    print_collection(ints1);

    std::cout << "ints2 :";
    print_collection(ints2);

    std::cout << "--------" << std::endl;

    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};
    
    //Trying out reverse iterators
    // rbegin is points to start , rend is point to end
    //auto it = numbers.rbegin(); // A reverse iterator increments backwards from the end.
    std::vector<int>::reverse_iterator it= numbers.rbegin();
    // *it = 34; //non const iterators
    std::cout << "Numbers : [";
    while(it != numbers.rend()){
        std::cout << " " << *it ;
        ++it;
    }
    std::cout << "] " << std::endl;

    /*
    // Compiler error: when compare iterators of different types
    auto it_rev = numbers.rbegin();
    
    if( it_rev != numbers.end()){ // Compiler error.
        std::cout << "Do something..." << std::endl;
    }
    */

   std::cout << "--------" << std::endl;

    // Creating a vector of integers named "num"
    std::vector<int> num{ 11,22,33,44,55,66,77};

    // Printing the elements of the vector
    std::cout << "num : ";
    print_collection(num);

    // Creating a constant iterator for the vector
    //std::vector<int>::const_iterator c_it = num.cbegin();
    auto c_it = num.cbegin();

    // Iterating through the vector without modifying its elements
    while( c_it != num.end()){
      //  *c_it = 100;  //Compiler error: can't modify the value of const vector
        ++c_it;
    }

    // Creating a constant reverse iterator for the vector
    auto it1 = num.crbegin();
    //std::vector<int>::const_reverse_iterator it1= num.crbegin();

    std::cout<<"reverse: ";
    while(it1 != num.crend()){
      //*it1 = 600; // Compiler error, it1 is a const iterator, we can't modify 
                    // container data through it.
      std::cout << *it1<<" " ;
      ++it1;
    }
    std::cout<<std::endl;
    std::cout << "--------" << std::endl;
    // For Normal Array-Std::begin , Std::end

    //std::vector<int> vi {1,2,3,4,5,6,7,8,9}; //vector type
    int vi[] {1,2,3,4,5,6,7,8,9};              //array type (normal)
    

    /* 
    // its only work for vector , not for array, bcoz its not a object
    std::cout << " Collection : " ;
    for(auto it = vi.begin(); it!= vi.end(); ++it){
        std::cout << *it  << " ";
    }

    */

    // to work on to normal array, use std::begin(array), std::end(array)

    std::cout << " Collection : " ;
    for(auto it = std::begin(vi); it!= std::end(vi); ++it){
        std::cout << *it  << " ";
    }
    std::cout<<std::endl;
    std::cout << "--------" << std::endl;

   

    return 0;
}
