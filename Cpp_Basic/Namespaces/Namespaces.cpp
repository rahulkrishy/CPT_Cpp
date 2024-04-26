/*
namespace is a mechanism that allows you to group logically related code elements,
such as variables, functions, and classes, under a unique identifier. 
This helps prevent naming conflicts and organizes the codebase.
*/

#include <iostream>

const double adjustment{0.724};

// Global function
double add(double a, double b){
    return a+b+a+b;
}

double add_adjust(double a, double b){
    return a+b-a-b;
}

// namespace name
namespace No_Adjust
{
    double add(double x, double y){
        return x + y;
    }   

    void do_something(){
        double res1 = add(2,3);     //this will call inside 'add' function
        std::cout << "res1 add: " << res1 << std::endl;
        double res01 = ::add(2,3);   //this will call (::) global 'add' function
        std::cout << "res01 add: " << res01 << std::endl;
    }
} 

// namespace Adjust
namespace Adjust
{
    double add(double x, double y){
        return x+ y - adjustment;
    }  

    void do_something(){
        double res2 = ::add_adjust(2,3);
        std::cout << "res2 add: " << res2 << std::endl;
    }
} 

//Function declaration
namespace No_Adjust
{
    double mult(double x, double y); // Declarations
    double div(double x, double y);
    
} // namespace No_Adjust

namespace Adjust
{
    double mult(double x, double y); // Declarations
    double div(double x, double y);    
} // namespace Adjust



// main
int main(){

  double result1 = No_Adjust::add(2,3);
  std::cout << "result1 add: " << result1 << std::endl;
  No_Adjust::do_something();

  double result2 = Adjust::add(2,3);
  std::cout << "result2 add: " << result2 << std::endl;
  Adjust::do_something();

  double result3 = No_Adjust::mult(2,3);
  std::cout << "result3 mul: " << result3 << std::endl;
  double result4 = Adjust::mult(2,3);
  std::cout << "result4 mul: " << result4 << std::endl;
    
  return 0;
}

//Definition
namespace No_Adjust
{
    double mult(double x, double y){
        return x * y;
    }
    double div(double x, double y){
        return x / y;
    }
    
} // namespace No_Adjust

namespace Adjust
{
    double mult(double x, double y){
        return x * y - adjustment;
    }
    double div(double x, double y){
        return x / y - adjustment;
    }    
} // namespace Adjust