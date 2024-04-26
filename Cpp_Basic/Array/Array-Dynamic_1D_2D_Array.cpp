// Dynamically allocated array don't work with (1) range based for loop (2) size operator 
#include<iostream>
using namespace std;

int main()
{
  // (1) Array Pointer Basic

  int a[6]; //Array always called by call by reference in default
  int* x = a;
  x++;
  x--;
  int* y = a;
  x = a+3;
  y = a+4;
  cout <<y-x<<endl; 

  int j;
  // Declare a pointer to an integer and assign the address of j to it
  int* p1;
  p1 = &j;

  // Output the address of x and the value of p1
  cout << "&j  : " << &j << endl;
  cout << "p   : " << p1 << endl;

  // Declare a pointer to a pointer to an integer and assign the address of p1 to it
  int** p2;
  p2 = &p1; //pointer pointing to address of another pointer 

  // Output the value at the address stored in p2 (which is the address of p1)
  cout << "*p2 : " << *p2 << endl;

  // Output the address stored in p2 and the address of p2 itself
  cout << "p2  : " << p2 << endl;
  cout << "&p2 :" << &p2 << endl;


  // (2) Array Dynamic Pointer 

  int size;
  cout<<"\n Enter the size of the array: ";
  cin>>size;

  // int* aPtr = new int[size]; //correct way of array dynamic allocation, by assignment notation
  int* aPtr { new int[size] };  //also correct way of array dynamic allocation, by braced initialization

  for(int i=0;i<size;i++)
  {
    cout<<"("<<i<<") :";
    cin>>aPtr[i];
  } 
  
  for(int i=0;i<size;i++)
    cout<<i<<" : "<<aPtr[i]<< endl;
  
  delete[] aPtr; //delete dynamic array


  // (3) Pointer to Pointer addressing

  int k;
  // Declare a pointer to an integer and assign the address of k to it
  int* q1;
  q1 = &k;

  // Output the address of k and the value of q1
  cout << "&k  : " << &k << endl;
  cout << "p   : " << q1 << endl;

  // Declare a pointer to a pointer to an integer and assign the address of q1 to it
  int** q2;
  q2 = &q1; //pointer pointing to address of another pointer 

  // Output the value at the address stored in q2 (which is the address of q1)
  cout << "*q2 : " << *q2 << endl;

  // Output the address stored in q2 and the address of q2 itself
  cout << "q2  : " << q2 << endl;
  cout << "&q2 :" << &q2 << endl;


  // (4) Dynamic 2D array approach using pointers


  // size: 3x4 (Cpp_data/2D_Dynamic_array.jpg)

  // Dynamic Allocation of Rows
  // Creates a pointer that points to a dynamic array of pointers
  int** tdArray = new int*[3]; // 3 represents rows

  // Dynamic Allocation of Columns (Arrays for Each Row)
  // Creates dynamic arrays of integers for each row
  for(int i = 0; i < 3; i++)
    tdArray[i] = new int[4]; // 4 represents columns

  // Initialize the 2D array with user input
  cout << "Enter values for the 3x4 2D array:" << endl;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      cout << "Enter value for element at position (" << i << ", " << j << "): ";
      cin >> tdArray[i][j];
    }
  }

  // Display the initialized 2D array
  cout << "Initialized 2D Array Contents:" << endl;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      cout << tdArray[i][j] << "  ";
    }
    cout << endl;
  }

  // Deallocate memory for each row
  for(int i = 0; i < 3; i++) {
    delete[] tdArray[i];
  }

  // Deallocate memory for the array of pointers
  delete[] tdArray;

  return 0;

}
  