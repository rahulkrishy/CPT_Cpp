// Write an algorithm to analyze a text file, listing all the unique alphabetic characters and their corresponding occurrences in the file. The algorithm should ignore case sensitivity and handle punctuation and other non-alphabetic characters.

#include <iostream>
#include <fstream>
using namespace std;

// This program analyzes a text file and outputs the unique letters and their occurrences.

int main() {
  // Open the file for reading
  ifstream readfile("D:/Zout/Tech/CodeX/Cpp/Cpp_aData/input.txt");

  // Initialize arrays for storing letters and their occurrences
  char letters[26];
  int occurrences[26];

  // Set all occurrences counts to 0
  for (int i = 0; i < 26; i++) {
    occurrences[i] = 0;
  }

  // Initialize variables to track unique letters and read characters
  char nextChr;
  int k = 0;

  // Read the first character
  readfile.get(nextChr);

  // Loop until the end of the file
  while (!readfile.eof()) {
    // Check if the character is alphabetic
    if (isalpha(nextChr)) {
      // Assume the letter hasn't been found yet
      bool letterAlreadyExits = false;

      // Check for existing occurrences of the lowercase version of the character
      for (int i = 0; i < k; i++) {
        if (tolower(nextChr) == letters[i]) {
          letterAlreadyExits = true;
          break; // Stop iterating if found
        }
      }

      // If the letter is new, add it to the list and increment its count
      if (!letterAlreadyExits) {
        letters[k] = tolower(nextChr); // Convert to lowercase for consistent indexing
        k++;                      // Increment the number of unique letters
      }

      // Increment the occurrences count for the lowercase character
      occurrences[tolower(nextChr) - 'a']++; // Use lowercase for accurate indexing
    }

    // Read the next character
    readfile.get(nextChr);
  }

  // Close the file
  readfile.close();

  // Print the header for the output
  cout << "Letters\toccurrences\n";

  // Print the list of unique letters and their occurrences
  for (int i = 0; i < k; i++) {
    cout << letters[i] << "\t" << occurrences[letters[i] - 'a'] << endl;
  }

  return 0;
}
