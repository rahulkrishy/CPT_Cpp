// Use Case: This program takes input from the user until a positive integer is entered. 
// It then stores the entered negative integers in an array and calculates their sum.

#include<iostream>
using namespace std;

int main() {

    int i, n, count = 0, a[100], sum = 0;

    // Input loop: Continue taking input until a positive integer is entered.
    while (true) {
        cout << "Enter input: ";
        cin >> n;

        // If the input is negative, store it in the array.
        if (n < 0) {
            a[count] = n;
            count++;
        } 
        // If the input is positive, exit the loop.
        else if (n > 0) {
            break;
        }
    }

    // Output array elements:
    cout << "\nArray elements:\n";
    for (i = 0; i < count; i++) {
        cout << a[i] << " ";
    }

    // Calculate the sum only if there are more than 1 element in the array.
    if (count > 1) {
        for (i = 0; i < count; i++) {
            sum += a[i];
        }
    }

    // Output the result (sum of negative integers).
    cout << "\nThe Sum of Negative Numbers: " << sum;

    return 0;
}
