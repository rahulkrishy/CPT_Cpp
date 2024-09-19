#include <iostream>
#include <type_traits>

//(1) Marking a function as constexpr gives it the potential 
//to be evaluated at compile time
constexpr int get_value(int multiplier){
    return 3 * multiplier;
}

//(2) Evaluate this function at compile time. If you can't 
//do that throw a compiler error
consteval int get_value1(int multiplier){
    return 3 * multiplier;
}

//(3) Function Template Constexpr      (visit: https://cppinsights.io/ to check at compile time)
void func_floating_point  (double d) {
	std::cout << "func_floating_point called..." << std::endl;
} 
void func_integral(int i) { 
	std::cout << "func_integral called..." << std::endl;
} 

// Function Template 
template <typename T>
void func(T t)
{
    if constexpr(std::is_integral_v<T>)            //compile time check 
        func_integral(t);
    else if constexpr(std::is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
			"Argument must be integral or floating point");
}

int main(){

    //(1) constexpr
    /*
        For the evaluation to take place at compile time, we have 
        to remember to store the return value in a constexpr result variable
    */

    // Compile time
    constexpr int result = get_value(4); // Compile time
    std::cout << "result : " << result << std::endl;

    // Run time
    int some_var{5}; // Run time variable
    int result1 = get_value(some_var); // Run time
    std::cout << "result1 : " << result1 << std::endl;


    //(2) consteval
    int result2 = get_value1(6);
    std::cout << "result1 : " << result2 << std::endl;

    // int some_var{5};
    // result2 = get_value1(some_var); //Error: some_var throw an error, bcoz its a run time var
    
   
   //(3) Function Template Constexpr
   func(12);

    return 0;
}