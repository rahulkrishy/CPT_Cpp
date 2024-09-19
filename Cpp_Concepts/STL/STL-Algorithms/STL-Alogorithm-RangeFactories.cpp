// Range factories
/*
Range factories in C++ are functions or constructs that generate ranges or views based on certain criteria or input parameters. 
They provide a convenient way to create ranges that represent sequences of elements meeting specific conditions or derived from existing data structures.

Some common range factories include:

std::views::filter: This factory creates a view that filters elements from an input range based on a predicate function. It retains only those elements for which the predicate evaluates to true.
std::views::transform: This factory creates a view that transforms each element of an input range using a transformation function. It applies the function to each element and produces a new range with the transformed values.
std::views::take: This factory creates a view that represents the first n elements of an input range. It limits the size of the range to the specified number of elements.
std::views::drop: This factory creates a view that skips the first n elements of an input range and represents the remaining elements. It effectively removes the specified number of elements from the beginning of the range.
std::views::iota: This factory creates a view that represents a sequence of consecutive integer values starting from a specified initial value and incrementing by a specified step size. It is useful for generating sequences of numbers.
std::views::single: This factory creates a view that contains a single element specified as an argument. It is useful when you need to create a range containing only one element.
*/

// std::views::iota

#include <iostream>
#include <vector>
#include <ranges>


int main(){

    /*
    //Generate an infinite sequence of numbers
    auto infinite_view = std::views::iota(1); // Stores the compuation
    //Numbers are generated lazily, on the fly, as we need them in each iteration
    for (auto i : infinite_view){
    std:: cout << i << std::endl;
    }
    */
    /*
    for (auto i : std::views::iota(1))
    {
      std:: cout << i << std::endl;
    }
    */

    //Limit the range : provide an upper limit, upper limit not included.
    for(auto i : std::views::iota(1,20))
    {
    std:: cout << i << std::endl;           //print 1 to 19
    }

    /*
    //Limit the range : Use view composition with | operator
    for(auto i :std::views::iota(1) | std::views::take(20)){
        std::cout << i << std::endl;
    }

    std::cout<<"------------"<<std::endl;

    //Raw function composition
    for(auto i : std::views::take(std::views::iota(1) , 20)){
        std::cout << i << std::endl;
    }

    */

    

  
    return 0;
}