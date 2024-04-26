// VariableSizesAndAddresses
#include <iostream>
using namespace std;

int main() {
    int a;
    float b;
    double c;
    long int d;
    char e;
    string f;
    
    // Display the Sizeof and address of the variable
    // address stored as stack-based order

    cout << "Size of int       : " << sizeof(a) <<endl; 
    cout << "Address of int    : " << static_cast<void*>(&a) << endl;
    cout << "Size of float     : " << sizeof(b) <<endl; 
    cout << "Address of float  : " << static_cast<void*>(&b) << endl;
    cout << "Size of double    : " << sizeof(c) <<endl;  
    cout << "Address of double : " << static_cast<void*>(&c) << endl;
    cout << "Size of longint   : " << sizeof(d) <<endl;
    cout << "Address of longint: " << static_cast<void*>(&d) << endl;
    cout << "Size of char      : " << sizeof(e) <<endl; 
    cout << "Address of char   : " << static_cast<void*>(&e) << endl;
    cout << "Size of string    : " << sizeof(f) <<endl;
    cout << "Address of string : " << static_cast<void*>(&f) << endl;

    return 0;
}