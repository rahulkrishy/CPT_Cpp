// Efficient Array Swapping Technique using Pointers (memory swappig >> value swapping)

#include <iostream>
using namespace std;

int main(){

    int arr0[5]{ 1,2,3,4,5 };
    int arr1[5]{ 6,7,8,9,10 };
    int * p_arr0 = arr0; //Not need to add '&' to the array, bcoz array it self points to the its address
	int * p_arr1 = arr1;

    cout<<"\nBefore Swapping:"<<endl;
    cout<<"arr0: "<<arr0<<endl;
    cout<<"arr1: "<<arr1<<endl;
    cout<<"p_arr0: "<<p_arr0<<endl;
    cout<<"p_arr1: "<<p_arr1<<endl<<endl;

    //Print arr0
    std::cout << "arr0 : ";
    for (size_t i{}; i < std::size(arr0); ++i) {
        std::cout << p_arr0[i] << " ";
    }
    std::cout << std::endl;

    //Print arr1
    std::cout << "arr1 : ";
    for (size_t i{}; i < std::size(arr1); ++i) {
        std::cout << p_arr1[i] << " ";
    }
    std::cout << std::endl;

    //Swapping data the hard way
    /*
    int temp[5];

    //Move data from arr1 into temp
    for (size_t i{ 0 }; i < std::size(arr1); ++i) {
        temp[i] = arr1[i];
    }

    //Move data from arr0 to arr1
    for (size_t i{ 0 }; i < std::size(arr0); ++i) {
        arr1[i] = arr0[i];
    }

    //Move data temp to arr0
    for (size_t i{}; i < std::size(temp); ++i) {
        arr0[i] = temp[i];
    }
    */

   /* Error : array directly can't be assigned
    int * temp{nullptr};

    temp = arr1;
    arr1 = arr0;
    */

	std::cout<<"\n----Swapping----"<<std::endl;

    int * temp{nullptr};

		// Use temp pointer to do swapping
    temp = p_arr0;
    p_arr0 = p_arr1;
    p_arr1 = temp;

		// // Swap pointers directly without using a temporary array
    // std::swap(p_arr0, p_arr1);

    cout<<"\nAfter Swapping:"<<endl;
    cout<<"arr0: "<<arr0<<endl;
    cout<<"arr1: "<<arr1<<endl;
    cout<<"p_arr0: "<<p_arr0<<endl;
    cout<<"p_arr1: "<<p_arr1<<endl<<endl;

    //Print arr0
    std::cout << "arr0 : ";
    for (size_t i{}; i < std::size(arr0); ++i) {
        std::cout << p_arr0[i] << " ";
    }
    std::cout << std::endl;

    //Print arr1
    std::cout << "arr1 : ";
    for (size_t i{}; i < std::size(arr1); ++i) {
        std::cout << p_arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;


		// we can use 'swap' feature directly in array by 
		// #include <algorithm>
		// swap_ranges(begin(arr0), end(arr0), begin(arr1));
}