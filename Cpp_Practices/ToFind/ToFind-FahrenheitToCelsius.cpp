#include<iostream>
using namespace std;

double fahrenheitToCelsius(double fahrenheit);

int main()
{
  double fahrenheit;
  cout<<"\nEnter the Fahrenheit value: ";
  cin>>fahrenheit;

  cout<<"\nfahrenheit To Celsius: "<<fahrenheitToCelsius(fahrenheit);

  return 0;
}

double fahrenheitToCelsius(double fahrenheit)
{
  return ((fahrenheit - 32) * 5/9);
}