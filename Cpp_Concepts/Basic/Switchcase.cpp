#include<iostream>
using namespace std;

// global variable
const int pen {1};
const int pencil {2};
const int eraser {3};

int main()
{
  // Block 1
  {
    cout<<"Block 1:\n";
    char grade;
    cout<<"Enter student Grade: ";
    cin>>grade;

    switch(grade)
    {
      case 'A':
      case 'a':
        cout<<"Excellent";
        break;

      case 'B':
      case 'b':
        cout<<"Good";
        break;

      case 'C':
      case 'c':
        cout<<"Satisfactory";
        break;

      case 'D':
      case 'd':
      case 'F':
      case 'f':
        cout<<"Needs Improvement";
        break;

      default:
        cout<<"\nInvalid grade";
    }
  }

  // Block 2
  {
    int tool {pen};
    cout << "\nBlock 2:\n";

    switch (tool)
    {
    case pen:
      cout<<"pen";
      break;
    case pencil:
      cout<<"pencil";
      break;
    case eraser:
      cout<<"eraser";
      break;
    default:
      cout<<"invalid";
      break;
    }
  }

  return 0;
}