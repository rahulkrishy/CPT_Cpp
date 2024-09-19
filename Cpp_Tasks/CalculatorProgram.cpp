// Calculator App: with input validation and an interactive menu, providing a simple calculator functionality.

#include<iostream>
#include<limits>
using namespace std;

// Calculator class for performing basic arithmetic operations
class Calculator
{
public:
  // Member variables for storing numbers, operation, results, decision
  float number1, number2, operation, sum, difference, product, division;
  char decision;

  // Constructor for initializing and executing calculator operations
  Calculator()
  {
    // Display initial message
    cout << "_Calculator_(Two Number Operation)" << endl;

    // Main loop for calculator operations
    while (1)
    {
      // Input: Get two numbers from the user
      cout << "Enter two numbers: " << endl;
      cin >> number1 >> number2;

      // Input validation
      while (!cin)
      {
          cin.clear();
          cout << "Invalid inputs. Please enter two numbers: ";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cin >> number1 >> number2;
      }

      // Display menu options
      cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit" << endl;
      cout << "Enter your choice number: ";

      // Label for re-entering choice in case of invalid input
      chooseAgain:

      cin >> operation;

      // Perform selected operation based on user's choice
      if (operation == 1)
          calculateAddition();
      else if (operation == 2)
          calculateSubtraction();
      else if (operation == 3)
          calculateMultiplication();
      else if (operation == 4)
          calculateDivision();
      else if (operation == 5)
      {
          // Exit the loop and terminate the program
          cout << "Exiting...\nHappy day!!";
          break;
      }
      else
      {
          // Invalid choice, prompt user to re-enter
          cout << "\nInvalid choice number Operation..\nPlease enter your choice number: ";
          goto chooseAgain;
      }

      // Ask user if they want to continue
      cout << "Do you want to continue: Y/N? ";
      cin >> decision;

      // If user decides not to continue, exit the loop
      if (decision == 'N' || decision == 'n')
      {
          cout << "Exiting...\nHappy day!!";
          break;
      }
    }
  }

  // Function to calculate and display the addition result
  void calculateAddition()
  {
      sum = number1 + number2;
      cout << "Addition      : " << number1 << " + " << number2 << " = " << sum << endl;
  }

  // Function to calculate and display the subtraction result
  void calculateSubtraction()
  {
      difference = number1 - number2;
      cout << "Subtraction   : " << number1 << " - " << number2 << " = " << difference << endl;
  }

  // Function to calculate and display the multiplication result
  void calculateMultiplication()
  {
      product = number1 * number2;
      cout << "Multiplication: " << number1 << " * " << number2 << " = " << product << endl;
  }

  // Function to calculate and display the division result, handling division by zero
  void calculateDivision()
  {
    if (number2 != 0)
    {
        division = number1 / number2;
        cout << "Division      : " << number1 << " / " << number2 << " = " << division << endl;
    }
    else
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }
  }
};

// Main function to create and run the Calculator object
int main()
{
    // Create an instance of the Calculator class
    Calculator calculator;
    return 0;
}
