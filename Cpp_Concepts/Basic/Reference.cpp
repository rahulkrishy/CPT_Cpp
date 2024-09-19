// Reference Basic


#include<iostream>
using namespace std;

int main()
{
  
  int OrgData {3};
  cout<<"Original Data: "<<OrgData<<endl;

  int& refData {OrgData};
  cout<<"Reference Data: "<<refData<<endl;

  cout<<"------------------------"<<endl;

  // Modifing Original data
  OrgData = 7;
  cout<<"Original Data: "<<OrgData<<endl;
  cout<<"Reference Data: "<<refData<<endl;
  
  cout<<"------------------------"<<endl;

  // Modifing Reference data
  refData = 14;
  cout<<"Original Data: "<<OrgData<<endl;
  cout<<"Reference Data: "<<refData<<endl;

  cout<<"------------------------"<<endl;

  // New Const Reference variable declaration
  int newOrgData {5};
  const int& newRefData {newOrgData};

  cout<<"New Original Data: "<<newOrgData<<endl;
  cout<<"New Reference Data: "<<newOrgData<<endl;

  cout<<"------------------------"<<endl;

  // Note: New Reference var can't be modified but the New Original can be modified directly

  // newRefData = 9; //Error

  newOrgData = 9;
  cout<<"New Original Data: "<<newOrgData<<endl;
  cout<<"New Reference Data: "<<newOrgData<<endl;



  return 0;
}