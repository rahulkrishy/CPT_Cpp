/*
Utility types are auxiliary classes and functions provided by the Standard Template Library (STL) to support various common programming tasks. 
These types are not full-fledged containers but are often used to facilitate operations involving containers and algorithms, or to provide commonly needed functionalities.

Common Utility Types in C++
    - std::pair
    - std::tuple
    - std::optional
    - std::variant
    - std::any
    - std::reference_wrapper
    - std::function
    - std::bind
    - std::allocator
*/

// std::pair
/*
-std::pair is a simple and widely-used template class provided by the C++ Standard Library in the <utility> header. 
-It represents a pair of values, typically a key-value pair, where each value can be of a different type.
-std::pair is used to stores two data components as a single entity
-it provides facilities to manipulate the components through the first and second data members
*/

#include <iostream>
#include <vector>
#include <utility> // For std::pair


int main(){

    //Code1 : Create pair
    std::cout << "creating pairs:" << std::endl;
    std::pair<int,std::string> pair1{0,"Book shelf"};
    
    auto pair2 = std::make_pair(1,"Table"); // Deduces the template arguments

    //std::cout << "pair1 : " << pair1 << std::endl; //dont have a output stream operator for the std::pair

    std::cout << " pair1 : (" << pair1.first << "," << pair1.second << ")" << std::endl;
    std::cout << " pair2 : (" << pair2.first << "," << pair2.second << ")" << std::endl;

    //Code2 : auto[] syntax - collect components of a pair into variables.
    std::cout << std::endl;
    std::cout << "auto[] syntax - collect components of a pair into variables : " << std::endl;
    auto [int_var, string_var] = pair1;
    std::cout << "pair1 (auto[] syntax) : (" << int_var << "," << string_var << ")" << std::endl;
    
    

    //Code3 : template argument deduction (C++17)
    std::cout << std::endl;
    std::cout << "template argument deduction : " << std::endl;
    
    std::pair student(33165, std::string("John Snow"));// Deducing the template arguments
    
    std::cout << "student ID : " << student.first << std::endl;
    std::cout << "Student name : " << student.second << std::endl;


    //Code4 : collection of pairs
    std::cout << std::endl;
    std::cout << "collection of pairs : " << std::endl;
    
    std::vector<std::pair<int,std::string>> collection {{10,"Earth"},{20,"Spins"},
                                                        {30,"From"},{40,"Left"},
                                                        {50,"To"},{60,"Right"}};
    //Traverse : syntax1
    std::cout << std::endl;
    std::cout << "syntax1 : " << std::endl;
    std::cout << "collection : [";
    for(const auto& elt : collection){
        std::cout << " (" << elt.first << "," << elt.second << ")";
    }
    std::cout << "]" << std::endl;


    //Traverse : syntax2
    std::cout << std::endl;
    std::cout << "syntax2 : " << std::endl;
    std::cout << "collection : [";
    for( auto[key,value] : collection){
        std::cout << " (" << key << "," << value << ")";
    }
    std::cout << "]" << std::endl;
   
    return 0;
}