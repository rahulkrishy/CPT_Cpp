#include<iostream>
using namespace std;

int main()
{
  // Dynamic pointer variables - allocates memory space on the heap.
  // Dynamically allocates memory for two integer variables, 
  // assigns values to them, and then prints their addresses and values. 
  // Finally, it deallocates the memory using the delete operator to avoid memory leaks
  
  // Allocate memory for an integer and assign a value using pointer p1
  int* p1 = new int; //'new' operator to dynamically allocate memory on heap for a nameless variable using pointer

  // Allocate memory for another integer and assign a value using pointer p2
  int* p2 = new int;

  // Assign values to the dynamically allocated memory
  *p1 = 3;
  *p2 = 4;

  cout << "-Dynamic pointer-"<< endl; 
  // Print the memory address, address of the pointer, and the value of the variable pointed by p1
  cout << "memory address of p1: " << p1 << endl;
  cout << "address of the pointer &p1: " << &p1 << endl;
  cout << "value *p1: " << *p1 << endl;

  // Print the memory address, address of the pointer, and the value of the variable pointed by p2
  cout << "memory address of p2: " << p2 << endl;
  cout << "address of the pointer &p2: " << &p2 << endl;
  cout << "value *p2: " << *p2 << endl<< endl;

  cout << "-Dynamic pointer after assigning pointer p1 to p2-"<< endl; 
  // Assign the value of p1 to p2, making them point to the same memory block
  p2 = p1; // Now both p1 and p2 point to the same memory block, but the original memory for p2 is not leaked.

  // Print the memory address, address of the pointer, and the value of the variable pointed by p1
  cout << "memory address of p1: " << p1 << endl;
  cout << "address of the pointer &p1: " << &p1 << endl;
  cout << "value *p1: " << *p1 << endl;

  // Print the memory address, address of the pointer, and the value of the variable pointed by p2
  cout << "memory address of p2: " << p2 << endl;
  cout << "address of the pointer &p2: " << &p2 << endl;
  cout << "value *p2: " << *p2 << endl<< endl;

  // Deallocate the allocated memory for p1(release the memory)
  delete p1;

  cout << "-Dynamic pointer after Deallocate p1-"<< endl; 
  // Accessing p1 after deallocation is undefined behavior (dangling pointer)
  cout << "memory address of p1: " << p1 << endl; // p1 is now a dangling pointer (points to deallocated memory), accessing it is undefined behavior
  cout << "address of the pointer &p1: " << &p1 << endl<< endl;

  // No need to delete p2 since it points to the same memory block as p1
  // delete p2; // This line is unnecessary and can lead to undefined behavior

  // Assign both p1 and p2 to nullptr to avoid using dangling pointers
  p1 = nullptr;
  p2 = nullptr;

  cout << "-Dynamic pointer after setting p1 and p2 to nullptr-"<< endl; 
  // Print the memory address and address of the pointer for p1
  cout << "memory address of p1: " << p1 << endl;
  cout << "address of the pointer &p1: " << &p1 << endl;

  // Print the memory address and address of the pointer for p2
  cout << "memory address of p2: " << p2 << endl;
  cout << "address of the pointer &p2: " << &p2 << endl<< endl;

  return 0;
}
