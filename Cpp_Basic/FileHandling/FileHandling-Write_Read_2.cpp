// File handling - write file from the keyboard and read file to display in the console

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Function prototypes
void fileWrite(string filename);
void fileRead(string filename);

int main()
{
  // Get filename
  string filename;
  cout << "Enter the file name: ";
  getline(cin, filename);

  // Writing into the file
  fileWrite(filename);

  // Reading from the file
  fileRead(filename);

  return 0;
}

// Function to write into the file
void fileWrite(string filename)
{
  // Create an output file stream
  ofstream writeFile(filename);

  // Check if the file is successfully opened
  if(writeFile.is_open())
  {
    string line;
    cout << "\nWrite (enter empty line to exit):\n";

    // Read lines from the console and write them to the file
    while(getline(cin, line) && !line.empty())
      writeFile << line << endl;

    // Close the file after writing
    writeFile.close();
  }
  else
  {
    cout << "\nUnable to open the file";
  }
}

// Function to read from the file
void fileRead(string filename)
{
  // Create an input file stream
  ifstream readFile(filename);

  // Check if the file is successfully opened
  if(readFile.is_open())
  {
    string line;
    cout << "\nRead :\n";

    // Read lines from the file and display them in the console
    while(getline(readFile, line))
      cout << line << endl;

    // Close the file after reading
    readFile.close();
  }
  else
  {
    cout << "\nUnable to open the file";
  }
}
