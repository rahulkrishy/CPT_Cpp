#include <iostream>
// using namespace std;

void common_elements(int array_1[], int array_2[]){

  int count{0}, common_num[10];
  
  for(size_t i {0}; i<10; ++i){
    for(size_t j {0}; j<10; ++j){
      if(array_1[i] == array_2[j]){
        common_num[count++] = array_1[i];
      }
    }
  }
  
  if(count>0){
    std::cout<<"There are "<<count<<" common elements they are :";
    for(size_t k{0}; k<count; ++k){
			std::cout<<common_num[k]<<" ";
    }  
  }
	else{
		std::cout<<"There are "<<count<<" common elements";
	}

}

int main(){
  int arr1 [10] {11,2,3,4,5,6,7,8,9,10}, arr2[10] {11,2,3,44,55,66,77,88,99,100};
  common_elements(arr1,arr2);

  return 0;
}