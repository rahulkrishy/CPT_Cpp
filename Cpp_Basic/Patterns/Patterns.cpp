#include <bits/stdc++.h>
using namespace std;

// *****
// *****
// *****
// *****
// *****
void pattern1(int n){
    for(int i=0;i<n;i++){        //Outer Loop: Rows
        for(int j=0;j<n;j++){    //Inner Loop: Columns
           cout<<"*";
        }
        cout<<endl;
    }
}

// *
// **
// ***
// ****
// *****
void pattern2(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
           cout<<"*";
        }
        cout<<endl;
    }
}

// 1
// 12
// 123
// 1234
// 12345
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           cout<<j;
        }
        cout<<endl;
    }
}

// 1
// 22
// 333
// 4444
// 55555
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           cout<<i;
        }
        cout<<endl;
    }
}

// *****
// ****
// ***
// **
// *
void pattern5(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
           cout<<"*";
        }
        cout<<endl;
    }
}

// 54321
// 4321
// 321
// 21
// 1
void pattern6(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
           cout<<j;
        }
        cout<<endl;
    }
}

//     *        // (4spaces,1star,4spaces) : [n-i-1] spaces, [2*i+1] stars, [n-i-1] spaces
//    ***       // (3spaces,3star,3spaces)
//   *****      // (2spaces,5star,2spaces)
//  *******     // (1spaces,7star,1spaces)
// *********    // (0spaces,9star,0spaces)
void pattern7(int n){
    for(int i=0;i<n;i++){
        // space
        for(int j=0;j<(n-i-1);j++){ //Formula: n-i-1 (Inner Loop Starting spaces)
            cout<<" ";} 

        // star
        for(int j=0;j<(2*i+1);j++){ //Formula: 2*i+1 (Inner Loop Stars)
            cout<<"*";}

        // space
        for(int j=0;j<(n-i-1);j++){ //Optional Ending spaces
            cout<<" ";} 

        cout<<endl;
    } 
}

// *********
//  *******
//   *****
//    ***
//     *
void pattern8(int n){
    // --- Formula wise calculation
    for(int i=0; i<n; i++){
        // space
        for(int j=0; j<i; j++)
            cout<<" ";

        // star
        for(int j=0; j<(2*n-(2*i+1)); j++)
            cout<<"*";

        // space
        for(int j=0; j<i; j++)
            cout<<" ";

        cout<<endl;
    } 
    // --- Pattern7 Reverse
    // for(int i=n-1;i>=0;i--){
    //     // space
    //     for(int j=(n-i+1);j>0;j--)
    //         cout<<" ";

    //     // star
    //     for(int j=(2*i+1);j>0;j--)
    //         cout<<"*";

    //     // space
    //     for(int j=(n-i+1);j>0;j--)
    //         cout<<" ";
            
    //     cout<<endl;
    // } 
}

//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *
void pattern9(int n) {
    // First Half Pattern
    for(int i = 0; i < n; i++) {
        // Print leading spaces
        for(int j = 0; j < (n-i-1); j++) {
            cout << " ";}

        // Print stars
        for(int j = 0; j < (2*i+1); j++) {
            cout << "*";}

        cout << endl;
    }
    
    // Second Half Pattern
    for(int i = n - 1; i >= 0; i--) {
        // Print leading spaces
        for(int j = 0; j < (n-i-1); j++) {
            cout << " ";
        }

        // Print stars
        for(int j = 0; j < (2*i+1); j++) {
            cout << "*";
        }

        cout << endl;
    } 
}

// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
void pattern10(int n){
    for(int i=1;i<=(2*n-1);i++){
        int stars = i;
        if(i>n)             //after symmetry point, we need to do in decreasing order
            stars = 2*n-i;
        for(int j=1;j<=stars;j++){
              cout<<"*";
        }
        cout<<"\n";
    }
}

// 1
// 01
// 101
// 0101
// 10101
void pattern11(int n){
    int start = 1;
    for(int i=0;i<n;i++){
        if (i%2==0) start = 1;
        else start = 0;
        for(int j=0;j<=i;j++){
            cout<<start;
            start = 1-start;
        }
        cout<<endl;
    }
}

// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321
void pattern12(int n){
    int spaces = 2*(n-1);
    for(int i=1;i<=n;i++){  
        // numbers
        for(int j=1;j<=i;j++){   
           cout<<j; }

        // spaces
        for(int j=1;j<=spaces;j++){   
           cout<<" "; }

        // numbers
        for(int j=i;j>0;j--){   
           cout<<j; }

        spaces -= 2;
        cout<<endl;
    }
}

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
void pattern13(int n){
    int num =1;
    for(int i=0;i<n;i++){        
        for(int j=0;j<=i;j++){    
           cout<<num<<" ";
           num++;
        }
        cout<<endl;
    }
}

// A
// A B
// A B C
// A B C D
// A B C D E
void pattern14(int n){
    for(int i=0;i<n;i++){        
        for(char cha ='A';cha<='A'+i;cha++){    
           cout<<cha<<" ";
        }
        cout<<endl;
    }
}

// A B C D E
// A B C D
// A B C
// A B
// A
void pattern15(int n){
    for(int i=0;i<n;i++){        
        for(char cha ='A';cha<='A'+(n-1-i);cha++){    
           cout<<cha<<" ";
        }
        cout<<endl;
    }
}

// A
// B B
// C C C
// D D D D
// E E E E E
void pattern16(int n){
    char start = 'A';
    for(int i=0;i<n;i++){        
        for(int j=0;j<=i;j++){    
           cout<<start<<" ";
        //    start++;
        }
        start++;
        cout<<endl;
    }
}

// A
// B C
// D E F
// G H I J
// K L M N O
void pattern17(int n){
    char start = 'A';
    for(int i=0;i<n;i++){        
        for(int j=0;j<=i;j++){    
           cout<<start<<" ";
           start++;
        }
        cout<<endl;
    }
}

//     A
//    ABC
//   ABCDE
//  ABCDEFG
// ABCDEFGHI
void pattern18(int n){
    for(int i=0;i<n;i++){   

        // Spaces  
        for(int j=0;j<(n-i-1);j++){    
           cout<<" ";
        }

        // character
        for(char ch ='A';ch<'A' + (2*i+1); ch++){    
           cout<<ch;
        }
        cout<<endl;
    }
}

//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
void pattern19(int n){
    for(int i=0;i<n;i++){   
        char ch = 'A';
        int breakpoint = (2*i+1)/2;  //after this symmetry point, we need to decrease the character

        // Spaces  
        for(int j=0;j<(n-i-1);j++){    
           cout<<" ";
        }

        // character
        for(int j=1;j<=(2*i+1);j++){    
           cout<<ch;
           if(j<=breakpoint) ch++; //before the point, just increment the character
           else ch--;             //after the point, decrement the character
        }
        cout<<endl;
    }
}

// E
// DE
// CDE
// BCDE
// ABCDE
void pattern20(int n){
    for(int i=0;i<n;i++){   
        for(char ch='E'-i ;ch<='E';ch++){    
            cout<<ch;
        } 
        cout<<endl;           
    }
        
}

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
void pattern21(int n){
    // Upper Half
    int UpSpaces = 0;
    for(int i=0;i<n;i++){
        //stars
        for(int j=0;j<(n-i);j++){
            cout<<"*";
        }
        //spaces
        for(int j=0;j<UpSpaces;j++){
            cout<<" ";
        }
        //stars
        for(int j=0;j<(n-i);j++){
            cout<<"*";
        }

        UpSpaces +=2;
        cout<<endl;
    }

    // Lower Half
    int DownSpaces = (2*n-2);
    for(int i=0;i<n;i++){
        //stars
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        //spaces
        for(int j=0;j<DownSpaces;j++){
            cout<<" ";
        }
        //stars
        for(int j=0;j<=i;j++){
            cout<<"*";
        }

        DownSpaces -=2;
        cout<<endl;
    }
}

// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
void pattern22(int n){
    int spaces = 2*n-2; //for n=5, spaces=8 (2*5-2=8)
    for(int i=1;i<=2*n-1;i++){
        int stars = i;
        if (i>n) stars = 2*n-i; // stars breakpoint
        
        // stars
        for(int j=1;j<=stars;j++)
            cout<<"*";
        // spaces
        for(int j=1;j<=spaces;j++)
            cout<<" ";
              
        // stars
        for(int j=1;j<=stars;j++)
            cout<<"*";  

        cout<<endl; 
        if(i<n) spaces -= 2; //spaces breakpoint
        else spaces += 2;
    }
}

// *****
// *   *
// *   *
// *   *
// *****  //only at boundaries stars = 0 or n-1
void pattern23(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j ==n-1)
                cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}

// 5 5 5 5 5 5 5 5 5
// 5 4 4 4 4 4 4 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 2 1 2 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 4 4 4 4 4 4 5
// 5 5 5 5 5 5 5 5 5
void pattern24(int n){
    // Calculate the size of the matrix (if n=5, size=9)
    int size = 2 * n - 1;

    // Initialize the matrix with the calculated size (2D array)
    vector<vector<int>> pattern(size, vector<int>(size));

    // Fill the matrix with the appropriate values
    // Top Border Distance(The distance to the top border is simply the row index): distance to top = i
    // Left Border Distance(The distance to the left border is the column index): distance to left = j
    // Bottom Border Distance(The distance to the bottom border is the distance from the last row): distance to bottom = (size - 1) - i
    // Right Border Distance(The distance to the right border is the distance from the last column): distance to right = (size - 1) - j

    for (int i = 0; i < size; ++i) {                                                   
        for (int j = 0; j < size; ++j) {
            pattern[i][j] =  n - min(min(i, j), min(size - 1 - i, size - 1 - j));    // min(i, j) gives the minimum distance to the top or left border.
                                                                                    // min(size - 1 - i, size - 1 - j) gives the minimum distance to the bottom or right border.
                                                                                    // min(min(i, j), min(size - 1 - i, size - 1 - j)) gives the smallest distance to any border.
                                                                                    // Subtracting this minimum distance from 'n' ensures that the value decreases as you move inward from the borders towards the center.
        }
    }
    // Above Inside the for loop, pattern[i][j] = n(5) -  0 0 0 0 0 0 0 0 0  => 5 5 5 5 5 5 5 5 5
    //                                                    0 1 1 1 1 1 1 1 0     5 4 4 4 4 4 4 4 5  
    //                                                    0 1 2 2 2 2 2 1 0     5 4 3 3 3 3 3 4 5  
    //                                                    0 1 2 3 3 3 2 1 0     5 4 3 2 2 2 3 4 5  
    //                                                    0 1 2 3 4 3 2 1 0     5 4 3 2 1 2 3 4 5  
    //                                                    0 1 2 3 3 3 2 1 0     5 4 3 2 2 2 3 4 5  
    //                                                    0 1 2 2 2 2 2 1 0     5 4 3 3 3 3 3 4 5  
    //                                                    0 1 1 1 1 1 1 1 0     5 4 4 4 4 4 4 4 5  
    //                                                    0 0 0 0 0 0 0 0 0     5 5 5 5 5 5 5 5 5 

    // Print the matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << pattern[i][j] << " ";
        }
        cout << endl;
    } 
}

// 4 3 2 1 2 3 4
// 3 3 2 1 2 3 3
// 2 2 2 1 2 2 2
// 1 1 1 1 1 1 1
// 2 2 2 1 2 2 2
// 3 3 2 1 2 3 3
// 4 3 2 1 2 3 4
void pattern25(int n) {
    int size = 2 * n - 1;  // Calculate the size of the matrix
    // Initialize a 2D vector to store the pattern
    vector<vector<int>> pattern(size, vector<int>(size, 0));

    // Fill the upper part of the pattern
    for (int i = 0; i < n - 1; ++i) {
        int start_value = n - i;  // Starting value for this row
        int end_index = n - start_value + 1;  // End index for filling increasing values

        // Fill increasing values from start_value to 1
        for (int j = 0; j < end_index; ++j) {
            pattern[i][j] = start_value;
        }

        // Fill decreasing values after the increasing sequence
        while (start_value > 0) {
            pattern[i][end_index++] = --start_value;
        }
    }
    // At this stage output be:
    // 4 3 2 1 0 0 0
    // 3 3 2 1 0 0 0
    // 2 2 2 1 0 0 0
    // 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0

    // Fill the middle row with 1s
    for (int j = 0; j < size; ++j) {
        pattern[n - 1][j] = 1;
    }

    // Mirror the upper part to generate the right part of the pattern
    int mid = (size) / 2;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n; j < size; ++j) {
            pattern[i][j] = pattern[i][mid - (j - mid)];
        }
    }
    // At this stage output be:
    // 4 3 2 1 2 3 4
    // 3 3 2 1 2 3 3
    // 2 2 2 1 2 2 2
    // 1 1 1 1 1 1 1
    // 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0

    // Mirror the left part to generate the lower part of the pattern
    for (int j = 0; j < size; ++j) {
        for (int i = n; i < size; ++i) {
            pattern[i][j] = pattern[mid - (i - mid)][j];
        }
    }

    // Output the pattern: Final output
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << pattern[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    cout<<"\n";
    int n=4;

    pattern1(n);
    cout<<"----------------\n";
    pattern2(n);
    cout<<"----------------\n";
    pattern3(n);
    cout<<"----------------\n";
    pattern4(n);
    cout<<"----------------\n";
    pattern5(n);
    cout<<"----------------\n";
    pattern6(n);
    cout<<"----------------\n";
    pattern7(n);
    cout<<"----------------\n";
    pattern8(n);    
    cout<<"----------------\n";
    pattern9(n);   
    cout<<"----------------\n";
    pattern10(n);
    cout<<"----------------\n";
    pattern11(n); 
    cout<<"----------------\n";
    pattern12(n);
    cout<<"----------------\n";
    pattern13(n);
    cout<<"----------------\n";
    pattern14(n);
    cout<<"----------------\n";
    pattern15(n);
    cout<<"----------------\n";
    pattern16(n);
    cout<<"----------------\n";
    pattern17(n);
    cout<<"----------------\n";
    pattern18(n);
    cout<<"----------------\n";
    pattern19(n);
    cout<<"----------------\n";
    pattern20(n);
    cout<<"----------------\n";
    pattern21(n);
    cout<<"----------------\n";
    pattern22(n);
    cout<<"----------------\n";
    pattern23(n);
    cout<<"----------------\n";
    pattern24(n);
    cout<<"----------------\n";
    pattern25(n);
}





