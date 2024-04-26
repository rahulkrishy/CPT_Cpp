//  merges two given integer arrays (data1 and data2) into a new dynamically allocated array (new_array)
#include <iostream>

void merge_arrays(int data1[], int data2[], unsigned int size1, unsigned int size2);

int main() {
    // Example arrays
    int data1[] = {1, 2, 3, 4, 5, 66, 77};
    int data2[] = {10, 20, 30, 40, 50, 60};

    // Calculate sizes of the arrays
    unsigned int size1 = sizeof(data1) / sizeof(data1[0]);
    unsigned int size2 = sizeof(data2) / sizeof(data2[0]);

    // Call the merge_arrays function
    merge_arrays(data1, data2, size1, size2);

    return 0;
}

void merge_arrays(int data1[], int data2[], unsigned int size1, unsigned int size2) {
    // Dynamically allocate memory for the new merged array
    int *new_array = new int[size1 + size2];

    // Copy elements from the first array to the new array
    for(unsigned int i = 0; i < size1; ++i) {
        new_array[i] = data1[i];
    }

    // Copy elements from the second array to the new array
    for(unsigned int i = 0; i < size2; ++i) {
        new_array[size1 + i] = data2[i];
    }

    // Print the merged array
    std::cout << "Merged Array: ";
    for(unsigned int i = 0; i < (size1 + size2); ++i) {
        std::cout << new_array[i] << " ";
    }

    // Deallocate the dynamically allocated memory
    delete[] new_array; //release
    new_array = nullptr; //reset
    std::cout << std::endl;  // Add a newline for better output formatting
}
