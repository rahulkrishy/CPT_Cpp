// Character manipulation - modifying individual characters in a string
#include<iostream>
// #include<cctype>
using namespace std;

int main(){
  char message[] = {"Hello i am Iron Man 707. "};
  int count{};
  char message1[size(message)];

  // Check count in c String 
  cout<<"Found blank at index ";
  for(size_t i {0}; i<size(message); ++i){
    if(isdigit(message[i])){
      cout<<"["<<i<<"] ";
      ++count;
    }
  }
  cout<<endl;
  cout<<"BlankSpace count: "<<count<<endl;

  // Check upperCase
  count = 0;
  for(auto c: message){
    if(isupper(c)){
      ++count;
    }
  }
  cout<<"Uppercase count: "<<count<<endl;

  // Convert to UpperCase
  for(size_t i{0}; i<size(message); ++i){
    message1[i] = toupper(message[i]);
  }

  cout<<"UPPERCASE: "<<message1<<endl;

}
