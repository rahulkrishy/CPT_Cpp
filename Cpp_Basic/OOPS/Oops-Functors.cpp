/*
 functor, short for "function object," refers to an object that can be used as if it were a function. 
 Functors are instances of classes or structures that overload the function call operator operator(). 
 This allows objects to be invoked or called like functions.
 Functors are often useful in scenarios where you want to encapsulate behavior within an object and pass it around like a function. 
 They are commonly used as arguments to algorithms or standard library functions that expect callable entities. 
 Functors provide a way to achieve more flexibility and customization compared to regular functions.
*/

#include <iostream>
#include <string>

class Print{
    public : 
    void operator()(const std::string& name) const          //void operator '()' is functor(function object) 
    {
        std::cout << "The name is : " << name << std::endl;
    }

    std::string operator()(const std::string& last_name,
                            const std::string& first_name) const {
        return (last_name + " " + first_name);
    }
};

void do_something(const Print& printer){
    printer("ray");
}


int main(){

    Print print;
    print("Green"); // calls first void operator() function
    do_something(print);
    std::cout << print("Greet","ray") << std::endl; // calls first void operator() function
   
    return 0;
}
