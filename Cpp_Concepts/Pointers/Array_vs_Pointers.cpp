// Array vs Pointer

#include <iostream>

int main(){

	int scores[10] {11,12,13,14,15,16,17,18,19,20};
    
  int * p_score { scores};
  
  //Print the address
  std::cout << "scores : " << scores << std::endl; // give the Array address
  std::cout << "p_score : " << p_score << std::endl;// gives the value of Pointer as the address
  std::cout << "&scores[0]  : " << &scores[0] << std::endl; // give the Array[0] address
  std::cout << "&scores[0]  : " << &scores[1] << std::endl; // give the Array[1] address

    
  //Print the content at that address
	std::cout << std::endl;
	std::cout << "Printing out data at array address : " << std::endl;
  std::cout << "*scores : " << *scores << std::endl;     //points to zeroth index of array
  std::cout << "scores[0] : " << scores[0] << std::endl;
  std::cout << "*p_score : " << *p_score << std::endl;  //points to zeroth index of array
	std::cout << "p_score[0] : " << p_score[0] << std::endl;
	std::cout << "p_score[2] : " << p_score[2] << std::endl; //points to third index of array


    //Differences
    int number {21};
    p_score = &number;
    
    //scores = &number; // The array name is a pointer, but a special pointer that kind of identifies
                       // the entire array. You'll get the error  : incompatible types in assignment
                      // of 'int*' to 'int[10]'
    
    std::cout << "p_score : " << p_score << std::endl;// Pointer	

	//std::size() doesn't work for raw pointers
	std::cout << "size : " << std::size(scores) << std::endl;
	//std::cout << "size : " << std::size(p_score) << std::endl; // Compiler error.
   
    return 0;
}