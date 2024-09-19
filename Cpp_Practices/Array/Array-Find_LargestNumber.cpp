// program prompts the user to enter a sequence of numbers. 
// It then processes the input, storing integers in an array until a non-numeric input is encountered ('Q' or any non-digit). 
// Finally, it calculates and displays the entered array, finds the maximum number, and calculates the average of the entered integers.

#include<iostream>
#include<string>
using namespace std;

int main() {
    // Initialize variables
    int a[100], count = 0, i;

    // String to store user input
    string input;

    // Prompt the user to enter numbers
    cout << "\n*Enter Numbers to continue \n*Enter 'Q' to end:\n";

    // Use a loop to continuously read input until a non-digit is encountered
    while (true) {
        cout << "Input:  ";
        cin >> input;

        // Check if the input is a digit (checking the first character)
        if (isdigit(input[0])) {
            a[count] = stoi(input);  // Convert the string to an integer
            count++;
        } else {
            break;  // Exit the loop if a non-digit is encountered
        }
    }

    // Display the entered array
    cout << "Entered Array: ";
    for (i = 0; i < count; i++) {
        cout << a[i] << " ";
    }

    // Find the maximum number in the array
    int max = a[0];
    for (i = 0; i < count; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    // Display the maximum number if there is more than one element in the array
    if (count > 1) {
        cout << "\nMax Number in array: " << max;
    }

    // Calculate and display the average of the entered numbers
    float avg;
    int sum = 0;
    for (i = 0; i < count; i++) {
        sum += a[i];
    }
    avg = static_cast<float>(sum) / count;  // Ensure floating-point division
    cout << "\nAverage: " << avg;

    return 0;
}
