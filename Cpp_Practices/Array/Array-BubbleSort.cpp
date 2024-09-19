//  Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
// program takes user-inputted array numbers, sort them, and searches for a specified number, providing its index if found.

#include<iostream>
using namespace std;

// Function prototypes
int arrayEntry(int a[]);
void arrayDisplay(int a[], int count);
void arraySort(int a[], int count);
void arraySearch(int a[], int count);
int searchNum(int a[], int count, int findNum, int& index);

int main()
{
  // Initialize variables
  int a[100], count;

  // array entry
  cout << "Enter the Array elements";
  count = arrayEntry(a);

  if (count > 1)
  {
    // Display the entered array
    arrayDisplay(a, count);

    // Sort the array
    arraySort(a, count);

    // Display the entered array
    arrayDisplay(a, count);

    // Search in array
    arraySearch(a, count);
  }

  return 0;
}


int arrayEntry(int a[])
{
  // String to store user input
  string input;
  int count = 0;

  // Prompt the user to enter numbers
  cout << "\n*Enter 'Number' to continue | 'Q' to Quit:\n";

  // Use a loop to continuously read input until a non-digit is encountered
  while (true)
  {
    cout << "->  ";
    cin >> input;
    // Check if the input is a digit (checking the first character)
    if (isdigit(input[0]))
    {
      a[count] = stoi(input);  // Convert the string to an integer
      count++;
    }
    else
      break;  // Exit the loop if a non-digit is encountered
  }

  return count;
}

void arrayDisplay(int a[], int count)
{
  cout << "\nArray: [ ";
  for (int i = 0; i < count; i++)
  {
    cout << a[i] << " ";
  }
  cout << "]";
}

void arraySort(int a[], int count)
{
  for (int i = 0; i < count; i++)
  {
    for (int j = i + 1; j < count; j++)
    {
      if (a[i] > a[j])
      {
        // Swap elements if they are in the wrong order
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

void arraySearch(int a[], int count)
{
  int findNum, numFlag, index;

  cout << "\nEnter the number to search in array: ";
  cin >> findNum;

  numFlag = searchNum(a, count, findNum, index);

  if (numFlag == 1)
    cout << "\nSearch Number " << findNum << " found at index " << index << " in the array.";
  else
    cout << "\nSearch Number " << findNum << " Not found in the array.";
}

int searchNum(int a[], int count, int findNum, int& index) // here index is passed as address, to update directly(instead of passing)
{
  for (int i = 0; i < count; i++)
  {
    if (a[i] == findNum)
    {
      index = i;
      return 1;
    }
  }
  return 0;
}
