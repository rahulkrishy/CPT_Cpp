// File handling - write into input text file and read input text file to write to output text file.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Function prototypes
void fileWrite(string inputFile);
void fileRead(string inputFile, string outputFile);

int main()
{
  // Get filename
  string inputFile = "z_input.txt";
  string outputFile = "z_output.txt";

  // Writing into input text file
  fileWrite(inputFile);

  // Reading from the input text file and write to output text file
  fileRead(inputFile, outputFile);

  return 0;
}

// Function to write into the file
void fileWrite(string inputFile)
{
  // Create an output file stream
  ofstream writeFile;
  writeFile.open(inputFile);

  // Check if the file is successfully opened
  if (writeFile.is_open())
  {
    string line;
    cout << "\nWrite (enter empty line to exit):\n";

    writeFile<<"Hello World\n";
    // Read lines from the console and write them to the file
    while (getline(cin, line) && !line.empty())
      writeFile << line << endl;

    // Close the file after writing
    writeFile.close();
  }
  else
  {
    cout << "\nUnable to open the file";
  }
}

// Function to read from the file and write to another file
void fileRead(string inputFile, string outputFile)
{
  // Create an input file stream to read
  ifstream readFile(inputFile);

  // Create an output file stream to write
  ofstream writeFile(outputFile);

  // Check if the input file is successfully opened
  if (readFile.is_open())
  {
    string line;
    cout << "\nRead from input file and write to output file:\n";

    // Read lines from the input file
    while (getline(readFile, line))
    {
      // Display the line in the console
      cout << line << endl;

      // Write the line to the output file
      writeFile << line << endl;
    }

    // Close the input file after reading
    readFile.close();
    // Close the output file after writing
    writeFile.close();
  }
  else
  {
    cout << "\nUnable to open the file";
  }
}
