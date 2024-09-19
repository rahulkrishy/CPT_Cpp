// Fibonacci Series
#include <iostream>
using namespace std;
int main()
{
    int a = 1,b = 1,c,size;
    cout<<"Enter the max number for Fibonacci Series: ";
    cin>>size;
    cout<<"\nFibonacci Series: ";
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<size;i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
 
    return 0;
}