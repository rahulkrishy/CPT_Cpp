#include<iostream>
using namespace std;

int main()
{
  int a[] {10,20,30};

  // Range based for loop 
  for(auto value: a) //value- a[index]
  {
    cout<<value<<endl;
  }

  // Modify values in range based for loop:

  int scores[] {1,2,3,4,5,6,7,8,9,10};
    
    //Printing positions
    std::cout << std::endl;
	
	std::cout << "Scores : ";         // we don't able to modify values in range based for loop, if do so only done by pointers or References.
    for ( auto score : scores){
        std::cout << " " << score ;
    }
	std::cout << std::endl;

  // Modifing by pointers
   for ( auto& score : scores){
        score = score * 10;
    }

    //Printing after change
     std::cout << std::endl;
	std::cout << "Scores : ";
    for ( auto score : scores){
        std::cout << " " << score ;
    }
	std::cout << std::endl;
    
    return 0;

}