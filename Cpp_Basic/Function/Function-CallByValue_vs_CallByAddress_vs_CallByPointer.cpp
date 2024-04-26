// Function-CallByValue_vs_CallByAddress_vs_CallByPointer
/*
Declaration introduces the name in a file, a definition says what that name is or what it does.
*/

#include<iostream>
using namespace std;

void CV_swap(int n1, int n2); // Func Parameter
void CA_swap(int &n1, int &n2);
void say_age(int* age);

int main()
{
    int var1=3, var2=7;

    // call by Value swapping
    cout<<"Call by Value swapping:";
    cout<<"\nBefore Swapping var1: "<<var1<<" | var2: "<<var2;
    CV_swap(var1,var2);                                           // Func Arguments
    cout<<"\n After Swapping var1: "<<var1<<" | var2: "<<var2;

    // call by Address swapping
    cout<<"\n\ncall by Address swapping:";
    cout<<"\nBefore Swapping var1: "<<var1<<" | var2: "<<var2;
    CA_swap(var1,var2);
    cout<<"\n After Swapping var1: "<<var1<<" | var2: "<<var2;

    // call by Pointer
    int age{23}; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl; //23
    say_age(&age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age <<  std::endl; //24
    

    return 0;
}

void CV_swap(int n1,int n2) // Parameters
{
    int t;
    t=n1;
    n1=n2;
    n2=t;
}

void CA_swap(int &n1, int &n2)   //& - address of operator
{
    int t;
    t=n1;
    n1=n2;
    n2=t;
}

void say_age(int* age){ // Pointer
    ++(*age); 
    std::cout <<  "Hello , you are " << *age << " years old! &age : " << &age <<  std::endl;//24
}
