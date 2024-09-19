// Search for a target number in a dynamically allocated array, display array values with their addresses, and print the index and address of the target if found.

#include<iostream>
using namespace std;

int main()
{
  // Declare variables
  int arr_size, target;

  // Get the size of the array from the user
  cout << "Enter the size of the array: ";
  cin >> arr_size;

  // Dynamically allocate an array of integers
  int* arr = new int[arr_size];

  // Get array values from the user
  cout << "Enter " << arr_size << " array values: " << endl;
  for(int i = 0; i < arr_size; i++)
  {
    cout << "(" << i << ") : ";
    cin >> arr[i];
  }

  // Display array values with their addresses
  cout << "\nArray: " << endl;
  for(int i = 0; i < arr_size; i++)
  {
    cout << "(" << i << ") : " << arr[i] << "  " << &arr[i] << endl;
  }

  // Get the target number from the user
  cout << "\nEnter the target number to find index and address: ";
  cin >> target;

  // Search for the target in the array
  for(int i = 0; i < arr_size; i++)
  {
    if(arr[i] == target)
    {
      // Print the index and address of the target if found
      cout << "The target " << target << " is found at index: " << i << ", address: " << &arr[i] << endl;

      // Deallocate the dynamically allocated memory
      delete[] arr;

      // Exit the program
      return 0;
    } 
  }

  // Print a message if the target is not found in the array
  cout << "The target " << target << " is not found in the array" << endl;

  // Deallocate the dynamically allocated memory
  delete[] arr;

  // Exit the program
  return 0;
}
