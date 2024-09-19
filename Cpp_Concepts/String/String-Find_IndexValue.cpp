// string::npos (string not found position) is a constant in C++ that represents the maximum possible value for the size_t type

#include <iostream>
#include <string>

using namespace std;

int main() {
    string myString = "Hello, World!";

    // case_1:
    // Search for the position of 'd' in the string, if found Return index as postion 'or' return string::npos 
    size_t position = myString.find('d');

    cout<<"\nCase_1: \n";
    cout<<"\nStart: \n";
    cout<<string::npos<<endl;
    cout<<position<<endl;

    // Check if 'd' was found or not
    if (position != string::npos) 
    {
      cout<<"\nLoop1: \n";
      cout<<string::npos<<endl;
      cout<<position<<endl;
      cout << "Found at position: " << position << endl;
    } 
    
    else 
    {
      cout<<"\nLoop2: \n";
      cout<<string::npos<<endl;
      cout<<position<<endl;
      cout << "'d' not found in the string." << endl;
    }
    
    // case_2:
    // Search for the position2 of 'x' in the string, if found Return index as postion 'or' return string::npos 
    size_t position2 = myString.find('x');

    cout<<"\nCase_2: \n";
    cout<<"\nStart: \n";
    cout<<string::npos<<endl;
    cout<<position2<<endl;

    // Check if 'x' was found or not
    if (position2 != string::npos) 
    {
      cout<<"\nLoop1: \n";
      cout<<string::npos<<endl;
      cout<<position2<<endl;
      cout << "Found at position2: " << position2 << endl;
    } 
    
    else 
    {
      cout<<"\nLoop2: \n";
      cout<<string::npos<<endl;
      cout<<position2<<endl;
      cout << "Position Not found in the string." << endl;
    }

    return 0;
}
