/*
- function templates aren't real C++ code, they're bleprints the compiler uses to generate actual C++ code in template instances.
- Real function declarations and definitions, aka template instances are created when you call the function with arguments
- If the template parameters are of the same type (T,T), then the arguments you call the function with must also match, otherwise you get a compiler error
- The arguments passed to a function template must support the operations that are done in the body of the function
- it is used in the place of function overloading to reduce the same overloading loops, by creating common template irrespective of data types
- if the program has both normal overloading and template type, the complier first go for overloading type bcoz it don't need to create a new instances to run it.
- if template used in multiple files, the templates are added to headed file
*/


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// (1) common function template for overloading
template <typename T>
T maximum(T a , T b){
    return (a > b)? a : b; 
}

//
template <typename T> const T& minimum(const T& val5 , const T& val6);

//(4) Template specialization
template <>
const char * maximum<const char*> (const char* a, const char* b);

//
template <typename ReturnType, typename T , typename P>  //we can also defaultly assign type to ReturnType by (=) assignment operator
ReturnType largeMaximum( T val7, P val8);

// Decltype And Trailing Return Types
template <typename T, typename P>
auto largeMaximum2( T val7, P val8) -> decltype((val7 > val8)? val7 : val8) ;

//(7) Auto Function Templates
auto func_add (auto a , auto b){
    return a + b;
}


// main
int main(){

  // (1) common function template for overloading
  int x{5};
  int y{7};

  auto result = maximum(x,y);
  std::cout << "result : " << result << std::endl;

  double a{5.5};
  double b{7.5};

  auto result1 = maximum(a,b);
  std::cout << "result1 : " << result1 << std::endl;


  int val1{10};
	int val2{23};
	double val3{34.7};
	double val4{23.4};
	std::string e{"hello"};
	std::string f{"world"};

  //(2) Explicit template arguments
  auto max = maximum<double>(val1,val4);
  std::cout << "max : " << max << std::endl;

  //(3) Template parameter by reference
  double val5 {51.2};
  double val6 {20.1};

  cout<<"In: val5: "<<val5<<" &val: "<<&val5<<endl;
  auto result2 = minimum(val5,val6);               // if we use explicit type conversion, passing by reference won't work as expected 
  cout<<"In: val5: "<<val5<<" &val: "<<&val5<<endl;

  //(4) Pointer to const type template
  const char* g{"wild"};
	const char* h{"animal"};
	
  const char* result3 = maximum(g,h);
	std::cout << "max(const char*) : " << result3 << std::endl;
   

  //(5) Function Templates With Multiple Parameters
  int val7 {5};
  double val8 {6.7};

  auto result4 = largeMaximum <int>(val7,val8);                    //int type is mentioned as returnType
  std::cout << "sizeof(result4) : " << sizeof(result4) << std::endl; 

  //(6) Decltype And Trailing Return Types
  auto result5 = largeMaximum2(val7,val8);
  std::cout << "result5 : " << result5 << std::endl;
  std::cout << "sizeof(result5) :" << sizeof(result5) << std::endl;


  //(7) Auto Function Templates

  auto result6 = func_add(a,b);
  std::cout << "result6 : " << result6 << std::endl;
  std::cout << "sizeof(result6) : " << sizeof(result6) << std::endl;


  return 0;

}




template <typename T> const T& minimum(const T& val5 , const T& val6){
  cout<<"out: val5: "<<val5<<" &val: "<<&val5<<endl;
  return (val5 < val6)? val5 : val6;
}

//(4) Template specialization
template <>
const char * maximum<const char*> (const char* a, const char* b){
    return ( std::strcmp(a,b) > 0) ? a : b;
}

// (5) Function Templates With Multiple Parameters

/*
//Problematic : return depends on the order of the template arguments : BAD!
template <typename T , typename P> 
P  largeMaximum( T a, P b){
    return ((a > b) ? a : b);
}
*/

template <typename ReturnType, typename T , typename P> 
//template < typename T,typename ReturnType , typename P> 
//template < typename T, typename P,typename ReturnType > 
ReturnType largeMaximum( T val7, P val8)                   // auto return type also works- will deduce largest type(only works - the func definition above main, to solve this we need to use decltype(6))
{
    return ((val7 > val8) ? val7 : val8);
}

//(6) Decltype And Trailing Return Types
template <typename T, typename P>
auto largeMaximum2( T val7, P val8) -> decltype((val7 > val8)? val7 : val8) {
    return (val7 > val8)? val7 : val8;
}