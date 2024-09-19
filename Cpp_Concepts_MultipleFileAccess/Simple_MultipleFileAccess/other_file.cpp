#include<iostream>
#include "compare.h"

void call_again()
{
  std::cout<< "\nother_file (accessing Compare via main):\n";
  // Maximum
  int maximum = max(70,50);
  std::cout<<"Maximum Number: "<<maximum<<"\n";
}
 


