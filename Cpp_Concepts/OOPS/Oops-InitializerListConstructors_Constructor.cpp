#include <iostream>
#include <cassert> //library to check at run time (assert macro is a debugging aid that helps identify logical errors in a program during development.)

struct Point{
public: 
    Point(std::initializer_list<double> list)      //own initializer list constructor
    {
        //static_assert( (list.size() == 2)); // its only works for static, can't capable to check on runtime
        assert(list.size() == 2); // If the size of the list is not 2, terminate the program with an error (checks at run time/The purpose of using assert is to catch logical errors during development.)
        /*
        std::cout << "Initalizer list constructor called" << std::endl;
        std::cout << "list size : " << list.size() << std::endl;
        
        for(size_t i{} ;  i < list.size(); ++i){
            std::cout << "elt [" << i << "]  :" << *(list.begin() + i) << std::endl;
        }
        */
       x = *(list.begin());
       y = *(list.begin() + 1);
    }

    void print_point() const {
        std::cout << "Point [ x : " << x << ", y : " << y << "]" << std::endl;
    }
 private : 
    double x;
    double y;
};



int main(){

    Point p1{22.4,34.9};
    p1.print_point();
   
    return 0;
}