// Without Array implementation 
// This program takes input from the user(Negative int) until a positive integer is entered and sum it. 

#include<iostream>
using namespace std;

int main() {

    int i, n, sum = 0;

    // Input loop: Continue taking input until a positive integer is entered.
    while (true) {
        cout << "Enter input: ";
        cin >> n;

        // If the input is negative, then sum it
        if (n < 0) {
            sum +=n;
        } 
        // If the input is positive, exit the loop.
        else if (n > 0) {
            break;
        }
    }

    // Output the result (sum of negative integers).
    cout << "\nThe Sum of Negative Numbers: " << sum;

    return 0;
}
