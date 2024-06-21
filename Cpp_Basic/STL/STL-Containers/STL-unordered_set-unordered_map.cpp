// std::unordered_set & std::unordered_map
/*
-Internally, they use what is called a hash map to order their elements,
which makes operations on them even faster that their std::set and std::map counterparts,
It is possible to provide your own hash map to control how elements are ordered.

std::unordered_set:
-It is an associative container that contains a collection of unique elements.
-The elements are unordered, meaning they are not stored in any particular order.
-Each element is stored exactly once, and duplicate elements are not allowed.
-The time complexity for most operations, such as insertion, deletion, and search, is O(1) on average.

std::unordered_map:
-It is an associative container that stores key-value pairs.
-The elements are unordered, meaning they are not stored in any particular order.
-Each key is unique, and duplicate keys are not allowed.
-The time complexity for most operations, such as insertion, deletion, and search, is O(1) on average.
*/

#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template<typename T>
void show_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& elt : collection){
        std::cout << " " << elt ;
    }
    std::cout << "]" << std::endl;
    
}

template <typename T>
void show_map_collection( const T& collection){
    
    std::cout << " [" ;
    for(const auto& [key,value ]: collection){
        std::cout << " (" << key << "," << value << ")" ;
    }
    std::cout << "]" << std::endl;
    
}

int main(){

    //std::set<int> collection1 {11,16,2,912,15,6,15,2};
    std::unordered_set<int> collection1 {11,16,2,912,15,6,15,2};

    //std::map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    std::unordered_map<int,int> collection2 {{1,11},{0,12},{4,13},{2,14},{3,15}};
    
    
    std::cout << "collection1 : " ;
    show_collection(collection1);
    
    std::cout << "collection2 : ";
    show_map_collection(collection2);
    
    //The operations are mostly similar to std::set and std::map . The details
    //can be checked in your favorite C++ standard library reference manual
    
    
    return 0;
}

