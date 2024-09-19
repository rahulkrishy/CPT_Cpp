// concepts
/* 
A mechanism to place constraints on your template type parameters
Concepts provide a way to define requirements on template parameters, 
allowing for more precise and expressive constraints on template arguments.
*/

#include <iostream>
#include <type_traits>
#include <concepts>

// (1) standard build in concepts:

//Syntax1

template <typename T>
requires std::integral<T>                  
T add( T a, T b){
    return a + b;
}

//Syntax2
/*
template <std::integral T>
T add( T a, T b){
    return a + b;
}
*/

//Syntax3
/*
auto add(std::integral auto a , std::integral auto b){
    return a + b;
}
*/

//Syntax4  //for floating point contraints check
/*
template <typename T>
T add( T a, T b) requires std::floating_point<T>{
    return a + b;
}
*/

// (2) custom concepts

template <typename T>
concept MyIntegral = std::is_integral_v<T>;

MyIntegral auto sum( MyIntegral auto a, MyIntegral auto b) {
    return a + b;
}

// template <typename T>
// concept Multipliable =  requires(T a, T b) {
// 	a * b; // Just makes sure the syntax is valid
// };

// template <typename T>
// concept Incrementable = requires (T a) {
// 	a+=1;
// 	++a;
// 	a++;
// };

// template <typename T>
// requires Incrementable<T>
// T add (T a, T b){
//     return a + b;
// }



int main(){

	// (1) standard build in concepts:
  //  syntax 1 to 3 works fine, 4 won't
	char a_0{10};
	char a_1{20};
	
	auto result_a = add(a_0,a_1);
	std::cout << "result_a : " << static_cast<int>(result_a) << std::endl;
	
	int b_0{11};
	int b_1{5};
	auto result_b = add(b_0,b_1);
	std::cout << "result_b : " << result_b << std::endl;


  // syntax 4 works fine, 1 to 3 won't
	// double c_0 {11.1};                  // double type can't vaild here, bcoz of constraits made by concepts only to get interal type
	// double c_1 {1.9};
	// auto result_c = add(c_0,c_1);
  // std::cout << "result_c : " << result_c << std::endl;

	// (2) custom concepts
	auto result_b2 = sum(b_0,b_1);
	std::cout << "result_b2 : " << static_cast<int>(result_b2) << std::endl;

  
    return 0;
}