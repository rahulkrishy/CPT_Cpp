// Program to input and display a 2D array with user-defined dimensions
// showcasing row and column indices

#include<iostream>
using namespace std;

int main()
{
  // // Prompt the user to enter the number of rows and columns

  // cout<<"Array 1"<<endl;
  // int row, col, i, j;
  // cout << "Enter num of rows and columns: ";
  // cin >> row >> col;

  // // Declare a 2D array with the specified number of rows and columns
  // int arr[row][col];

  // // Input Array elements
  // cout << "\nEnter " << row * col << " inputs: ";
  // for (i = 0; i < row; i++)
  // {
  //   for (j = 0; j < col; j++)
  //   {
  //     cin >> arr[i][j];
  //   }
  // }

  // // Display the 2D Array with row and column indices
  // cout << "\nThe 2D Array:\n";
  // for (i = 0; i < row; i++)
  // {
  //   for (j = 0; j < col; j++)
  //   {
  //     cout << "arr[" << i << "][" << j << "]: " << arr[i][j] << "\t";
  //   }
  //   cout << "\n";
  // }


  // Detect the size of 2D array
  cout<<"Array 2"<<endl;
  
  int arr1[3][2];

  // input arr1 values
  cout<<"Enter array2 value:"<<endl;
  for(size_t i {0}; i<size(arr1); ++i){     //size function to detect the size of first index(1D-row)
    for(size_t j {0}; j<size(arr1[i]); ++j){  //size function to detect the size of second index(2D-col)
      cout<<"{"<<i<<"}{"<<j<<"}: ";
      cin>>arr1[i][j];
    }
  }

  // Display the 2D array
  cout<<"array2:"<<endl;
  for(size_t i {0}; i<size(arr1); ++i){
    for(size_t j {0}; j<size(arr1[i]); ++j){
      cout<<"{"<<i<<"}{"<<j<<"}: "<<arr1[i][j]<<" ";
    }
    cout<<endl;
  }

}
