/*
  This C++ program demonstrates logical bitwise operators (AND, OR, NOT, XOR) using bitset.
  It prints the binary representations of the operands and results with proper formatting.
*/
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main() {
    // Set the column width for formatting output
    int COLUMN_WIDTH{20};

    // Define two 8-bit unsigned char values
    unsigned char value1{0x3}; // Binary: 0000 0011
    unsigned char value2{0x5}; // Binary: 0000 0101

    // Display the header for the logical bitwise operators section
    cout << "Logical Bitwise Operator" << endl << endl;

    // Display the binary representation of value1
    cout << setw(COLUMN_WIDTH) << "value1 : "
         << setw(COLUMN_WIDTH) << bitset<8>(value1) << endl;

    // Display the binary representation of value2
    cout << setw(COLUMN_WIDTH) << "value2 : "
         << setw(COLUMN_WIDTH) << bitset<8>(value2) << endl;

    // Bitwise AND operation
    cout << endl;
    cout << "Bitwise AND :  " << endl;
    cout << setw(COLUMN_WIDTH) << "value1 & value2 : "
         << setw(COLUMN_WIDTH) << bitset<8>(value1 & value2) << endl;
    cout << endl;

    // Bitwise OR operation
    cout << endl;
    cout << "Bitwise OR :  " << endl;
    cout << setw(COLUMN_WIDTH) << "value1 | value2 : "
         << setw(COLUMN_WIDTH) << bitset<8>(value1 | value2) << endl;
    cout << endl;

    // Bitwise NOT operation
    cout << endl;
    cout << "Bitwise NOT " << endl;
    cout << setw(COLUMN_WIDTH) << "~value1 : "
         << setw(COLUMN_WIDTH) << bitset<8>(~value1) << endl;

    cout << setw(COLUMN_WIDTH) << "~value2 : "
         << setw(COLUMN_WIDTH) << bitset<8>(~value2) << endl;

    cout << setw(COLUMN_WIDTH) << "~01011001 : "
         << setw(COLUMN_WIDTH) << bitset<8>(~0b01011001) << endl; // Using binary literal

    cout << setw(COLUMN_WIDTH) << "~01011001 : "
         << setw(COLUMN_WIDTH) << bitset<8>(~0x59) << endl; // Using hexadecimal literal
    cout << endl;

    // Bitwise XOR operation
    cout << endl;
    cout << "Bitwise XOR :  " << endl;
    cout << setw(COLUMN_WIDTH) << "value1 ^ value2 : "
         << setw(COLUMN_WIDTH) << bitset<8>(value1 ^ value2) << endl;
    cout << endl;

    return 0;
}
