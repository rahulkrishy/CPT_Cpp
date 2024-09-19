#include<iostream>
#include "compare.h"         //inclue Preprocessor directive //First header file
#include "incr_operation.h"  //Second header file

using namespace std;

int main(){

  cout<<"\nmain File:\n";
  // Maximum
  int maximum = max(10,20);                       //max Func declared in compare.h , definition in compare.cpp 
  cout<<"Maximum Number: "<<maximum<<"\n";

  // Minimum
  int minimum = min(10,20);                       //max Func declared in compare.h , definition in compare.cpp (but in some_other_file.cpp)
  cout<<"Minimum Number: "<<minimum<<"\n";

  // Maximum Func call again by other file        //max Func declared in compare.h , definition in other_file.cpp 
  call_again();

  // Increment Opeation Call from other header    //incr Func declared in incr_operation.h , definition in incr_operation.cpp 
  int x = 1, y = 2;
  cout<<"\nmain File:\n";
  cout<<"Increment Result: "<<incr(x,y)<<"\n\n";

}