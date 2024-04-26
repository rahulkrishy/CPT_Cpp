/* // Demo example
// If const shows up on the left of * : the data is const
// If const show up on the right of : the pointer is const
// int var1{33};
// int * p_var1 {&var1}; // Non const pointer to int
// const int* p_var1 {&var1}; // Pointer to const
// const int* const p_var1 {&var1 }; // Const pointer to const data
// int * const p_var1 { &var1}; // Const pointer to non const data */

#include<iostream>
using namespace std;

int main()
{
	

	//(1) non const pointer to non const data - can modify both value and pointing location
	cout<<"\n--(1) non const pointer to non const data --"<<endl;
  int var1 {10}; //stored in stack memory

  // Declare a pointer and assign the address of 'var1' to it
	int *ptr1 {nullptr};
	ptr1 = &var1;

	cout<<"var1:   "<<var1<<endl;
	cout<<"&var1:  "<<&var1<<endl;

	cout<<"ptr1:   "<<ptr1<<endl;
	cout<<"&ptr1:  "<<&ptr1<<endl;
	cout<<"*ptr1:  "<<*ptr1<<endl;

	cout<<"--Changing the value of the variable--"<<endl;
	var1 = 20;

	cout<<"var1:   "<<var1<<endl;
	cout<<"&var1:  "<<&var1<<endl;

	cout<<"ptr1:   "<<ptr1<<endl;
	cout<<"&ptr1:  "<<&ptr1<<endl;
	cout<<"*ptr1:  "<<*ptr1<<endl;

	cout<<"--Changing the value by the pointer dereferencing--"<<endl;
	*ptr1 = 30;

	cout<<"var1:   "<<var1<<endl;
	cout<<"&var1:  "<<&var1<<endl;

	cout<<"ptr1:   "<<ptr1<<endl;
	cout<<"&ptr1:  "<<&ptr1<<endl;
	cout<<"*ptr1:  "<<*ptr1<<endl;

	cout<<"--Assing new variable to the same pointer--"<<endl;
	int var2 = 40;
	ptr1 = &var2;

	cout<<"var1:   "<<var1<<endl;
	cout<<"&var1:  "<<&var1<<endl;

	cout<<"var2:   "<<var2<<endl;
	cout<<"&var2:  "<<&var2<<endl;

	cout<<"ptr1:   "<<ptr1<<endl;
	cout<<"&ptr1:  "<<&ptr1<<endl;
	cout<<"*ptr1:  "<<*ptr1<<endl;

 //(2) Pointer to const - can't modify value by pointer but can modify pointing location
	cout<<"\n--(2) Pointer to const--"<<endl;
	
	int var3 = 50;
	const int *ptr2 = &var3;

	cout<<"var3:   "<<var3<<endl;
	cout<<"&var3:  "<<&var3<<endl;

	cout<<"ptr2:   "<<ptr2<<endl;
	cout<<"&ptr2:  "<<&ptr2<<endl;
	cout<<"*ptr2:  "<<*ptr2<<endl;

	// *ptr2 = 60; // Error (can't modify value by pointer), but can change variable value independently
	var3 = 60;

	cout<<"--Assigning to new var--"<<endl;
	int var4 = 60;
	ptr2 = &var4;

	cout<<"var3:   "<<var3<<endl;
	cout<<"&var3:  "<<&var3<<endl;

	cout<<"var4:   "<<var4<<endl;
	cout<<"&var4:  "<<&var4<<endl;

	cout<<"ptr2:   "<<ptr2<<endl;
	cout<<"&ptr2:  "<<&ptr2<<endl;
	cout<<"*ptr2:  "<<*ptr2<<endl;

	//(3) const Pointer - can't modify pointing location but can modify value by pointer 
	cout<<"\n--(3) const Pointer--"<<endl;
	
	int var5 = 70; 
	int* const ptr3 {&var5};

	cout<<"var5:   "<<var5<<endl;
	cout<<"&var5:  "<<&var5<<endl;

	cout<<"ptr3:   "<<ptr3<<endl;
	cout<<"&ptr3:  "<<&ptr3<<endl;
	cout<<"*ptr3:  "<<*ptr3<<endl;

  /*Error (can't modify pointing location), but can change variable value independently
	cout<<"--Assigning to new var--"<<endl;
	int var6 = 80;
	ptr3 = &var6;*/
	
	cout<<"--Changing the value by the pointer dereferencing--"<<endl;
	*ptr3 = 80;

	cout<<"var5:   "<<var5<<endl;
	cout<<"&var5:  "<<&var5<<endl;

	cout<<"ptr3:   "<<ptr3<<endl;
	cout<<"&ptr3:  "<<&ptr3<<endl;
	cout<<"*ptr3:  "<<*ptr3<<endl;

	//(4) const Pointer to const data - can't modify both value by pointer and pointing location  
	cout<<"\n--(4) const Pointer to const data--"<<endl;
	
	const int var6 = 90; // const variable 
	const int* const ptr4 = &var6;

	cout<<"var6:   "<<var6<<endl;
	cout<<"&var6:  "<<&var6<<endl;

	cout<<"ptr4:   "<<ptr4<<endl;
	cout<<"&ptr4:  "<<&ptr4<<endl;
	cout<<"*ptr4:  "<<*ptr4<<endl;

  /*Error (can't modify both value by pointer and pointing location), and also the value by variable
	cout<<"--Changing the value by the pointer dereferencing--"<<endl;
	*ptr4 = 100;
	cout<<"--Assigning to new var--"<<endl;
	int var7 = 90;
	ptr4 = &var7;
	cout<<"--changing the value of var6--"<<endl;
	var6 = 100;*/

	return 0;

}