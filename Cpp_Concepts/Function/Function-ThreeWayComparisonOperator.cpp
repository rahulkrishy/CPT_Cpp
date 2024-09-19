// Three Way Comparison Operator <=>
/*
Spaceship operator:
• The <= > operator embodies the result of a comparison in C++ 20
• It returns a type whose value is comparable to literal 0, not an int whose value is 0
It is meant to be used by the compiler to generate other operators (>,>=, <,<=), and
it is rarely used in user facing code. Although it is possible to do so.
• The type of the return type describes the kind of comparison we support for our type.
Options are strong_ordering, weak_ordering and partial _ordering
• The <=> operator will mostly be set up as a member function, and the compiler will
put in the magic necessary to make generated comparison operators work with
implicit conversions as much as possible

Spaceship operator return values:
(1) std::strong_ordering
A type that can be used to describe absolute equality in comparisons. 
For example for the fundamental type "int" we can have absolute equality.
(2) std::weak_ordering
A type that can be used to describe NON absolute equality(equivalence) in comparisons.
For example two strings "Hello" and "HELLO" may be considered equivalent but not equal
(3) std::partial_ordering
A type that can be used to describe incomparable values for a certain type.

*/


#include <iostream>
#include <string>
#include <limits>

// Default Ordering With Spaceship
class Item {
private:
    int a{ 1 };
    int b{ 2 };
    int c{ 3 };

public : 
		Item() = default;               //default constructor
    Item(int n) : Item(n,n,n){}     //one param constructor
		Item ( int a_param, int b_param, int c_param) :    
		 a(a_param), b(b_param), c(c_param){}   //three param initialer list constructor

		//Ordering : compiler generates >, < , >=, <= and also puts in the == operator
		auto operator<=> (const Item& right_operand) const = default;

};


int main(){


  /*
  std::string m1{"Hello"};
  std::string m2{"World"}; // World comes after Hello in alphabetical order so it's
                           // considered to be greater.

  auto result = m1.compare(m2);
  if(result > 0){
    std::cout << "m1 > m2" << std::endl;
  }else if(result == 0){
    std::cout << "m1 == m2" << std::endl;
  }else{
    std::cout << "m1 < m2" << std::endl;
  }
  */

  //Three way comparison operator : spaceship operator <=>
    // /*
    int n1{5};
    int n2{5};
    //int n3{0};

    auto result = ( n1 <=> n2);

    std::cout << std::boolalpha;
    std::cout << "n1 > n2 : " << ((n1 <=> n2) > 0) << std::endl; // true
    std::cout << "n1 >= n2 : "<< ((n1 <=> n2) >= 0) << std::endl;
    std::cout << "n1 == n2 : " << ((n1 <=> n2) == 0) << std::endl;
    std::cout << "n1 < n2 : " << ((n1 <=> n2) < 0) << std::endl;
    std::cout << "n1 <= n2 : " << ((n1 <=> n2) <= 0) << std::endl;
    // */


   //Strong ordering
   /*
    int n4{5};
    int n5{5};

    std::cout << std::boolalpha;
    std::cout << "n4 > n5 : " << (n4 > n5) << std::endl; // false
    std::cout << "n4 == n5 : " << (n4 == n5) << std::endl; //true :  Absolute equality
    std::cout << "n4 < n5 : " << (n4 < n5) << std::endl; // false
    */

   //Weak ordering
   /*
    std::string m1{"Hello"};
    std::string m2{"HELLO"};

    std::cout << std::boolalpha;
    std::cout << "m1 > m2 : " << (m1 > m2) << std::endl; // 
    std::cout << "m1 == m2 : " << (m1 == m2) << std::endl; // equivalence
    std::cout << "m1 < m2 : " << (m1 < m2) << std::endl; //
    */

    //Partial ordering
    /*
    double d1{33.9};
    double d2{std::numeric_limits<double>::quiet_NaN()};

    std::cout << std::boolalpha;
    std::cout << "d1 > d2 : " << (d1 > d2) << std::endl; // false
    std::cout << "d1 == d2 : " << (d1 == d2) << std::endl; //false
    std::cout << "d1 < d2 : " << (d1 < d2) << std::endl; //false
    */

    std::cout<<"----------"<<std::endl;
    
    // Default Ordering With Spaceship

    Item i1{1,2,5};
    Item i2{1,2,4};
    

   
    //auto result1 = (i1 > i2);
    auto result1 = ( (i1 <=> i2) > 0); // A possible option for the compiler magic
    std::cout << " i1 > i2 : " << result1 << std::endl;

    //auto result2 = (i1 >= i2);
    auto result2 = ( (i1 <=> i2) >= 0); // A possible option for the compiler magic
    std::cout << " i1 >= i2 : " << result2 << std::endl;
 
    auto result3 = (i1 == i2);
    std::cout << " i1 == i2 : " << result3 << std::endl;

    auto result4 = (i1 != i2);
    std::cout << " i1 != i2 : " << result4 << std::endl;
 
    //auto result5 = (i1 < i2);
    auto result5 = ( (i1 <=> i2) < 0); // A possible option for the compiler magic
    std::cout << " i1 < i2 : " << result5 << std::endl;

    //auto result6 = (i1 <= i2);
    auto result6 = ( (i1 <=> i2) <= 0); // A possible option for the compiler magic
    std::cout << " i1 <= i2 : " << result6 << std::endl;




    //Implicit conversions
   
    auto result7 = (i1 > 20);
    auto result8 = (20 < i1);  // ( 20 <=> i1) < 0
    auto result9 = (i2 != 12);
    auto result10 =(12 != i2);

    return 0;
}