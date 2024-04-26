// Program takes five integers as input from the user, stores them in an array
// and then prints the original array and its Reverse.

// Unsigned int & size_t are the same.

#include<iostream>
using namespace std;

int main() {
    // Declare an array 'a' of size 5 to store integers
    int a[5];

    // Prompt the user to input 5 integers into the array
    cout << "\nEnter 5 Array inputs: ";
    for (unsigned int i = 0; i < 5; i++)
        cin >> a[i];

    // Display the original array
    cout << "\nArray: ";
    for (size_t i = 0; i < 5; i++)  
        cout << a[i] << " ";

    // Display the array in reverse order
    cout << "\nReverse_Array: ";
    for (size_t i = 4; i >= 0; i--)
        cout << a[i] << " ";

    return 0;
}