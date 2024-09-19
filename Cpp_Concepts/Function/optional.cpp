/*
In C++, the term "optional" typically refers to a class template introduced in the C++17 standard library. 
It provides a way to represent optional values: a value that may or may not be present. 
The std::optional container can hold either a value or no value, similar to how pointers work, but with safer and more expressive semantics.
*/

#include <iostream>
#include <optional>

std::optional<size_t> find_character_v2(const std::string & str, char c);
std::optional<size_t> find_character_v3(const std::string & str, std::optional<char> c = std::nullopt); // only assign nullopt in func declaration and not on func definition


int main(){

	//Declare and initialize
  std::optional<int> items{3}; 
  std::optional<std::string> name{"Comali"};
  std::optional<double> weight {77.2};
  std::optional<char> character{'s'};
	
	//Declare and empty initialize
  std::optional<std::string> dog_name {}; // Initializes to std::nullopt
  std::optional<int> age {std::nullopt}; // std::nullopt is the null or zero equivalent for std::optional
	std::optional<char> letter = std::nullopt; 	// Triggers unused warning
	std::optional<double> height = {};		  	//Initializes to std::nullopt , Triggers unused warning.

  //Read from an std::optional variable
	std::cout << "items : " << items.value() << std::endl;
	std::cout << "items : " << *items << std::endl; // Personally find this confusing as it's not a pointer
  
  //std::cout << "items : " << items << std::endl;
	std::cout << "name : " << name.value() << std::endl;
	std::cout << "weight : " << weight.value() << std::endl;
	std::cout << "character : " << character.value() << std::endl;

  //Write stuff
	dog_name = "Fluffy";
	age = 26;
  std::cout << std::endl;
  std::cout << "Writting data in ..." << std::endl;
	std::cout << "dog_name : " << dog_name.value() << std::endl;
	std::cout << "age : " << age.value() << std::endl;

  //Reading bad data
	//std::cout << letter.value() << std::endl; // Throws exception and crashes program
	//std::cout << height.value() << std::endl; // Trhows exception and crashes program

  //has_value()
  std::cout << std::boolalpha;
  std::cout << "letter.has_value() : " << letter.has_value() << std::endl;
  std::cout << "height.has_value() : " << height.has_value() << std::endl;
  std::cout << "dog_name.has_value() : " << dog_name.has_value() << std::endl;

  //Do your checks before you read data

  std::cout << std::endl;
  std::cout << "Conditional reading" << std::endl;
	if(letter.has_value()){
		std::cout << "letter contains a useful value" << std::endl;
	}else{
		std::cout << "letter contains std::nullopt" << std::endl;
	}
	
	//Checking against std::nullopt
	if(letter != std::nullopt){
		std::cout << "letter contains a useful value" << std::endl;
	}else{
		std::cout << "letter contains std::nullopt" << std::endl;
	}

  //Checking against std::nullopt
	if(dog_name != std::nullopt){
		std::cout << "dog_name contains a useful value : " << dog_name.value() << std::endl;
	}else{
		std::cout << "dog_name contains std::nullopt" << std::endl;
	}


  // Optional output to the func with std::optional

  std::string str1 {"Hello World in C++20!"};
	char c{'C'};

  /*
  std::optional<size_t> result = find_character_v2(str1,c);

  if(result.has_value()){
      std::cout << "Found our character at index : " << result.value() << std::endl;
  }else{
      std::cout << "Didn't find our character" << std::endl;
  }
  */

	str1 = "Hello World in C++20!";
	
	auto result1 = find_character_v3(str1); //Will search for 'z' if you don't specify 
											// the character so search for
	if(result1.has_value()){
		std::cout << "Found character 'o' at index " << result1.value() << std::endl;
	}else{
		std::cout << "Could not find character 'o' in the string : " << str1 << std::endl;
	}
   

  return 0;
}

//Specify character to  search for
std::optional<size_t> find_character_v2(const std::string & str, char c){
    //If found set the return index, else return an empty std::optional
    for (size_t i{} ; i < str.size()  ; ++i){
        if(str.c_str()[i] == c){
            return i;
        }
    }
   return {}; //Or std::nullopt
   //std::nullopt;
}


//Specify default character to search for
std::optional<size_t> find_character_v3(const std::string & str, std::optional<char>c){
    //If found set return index, else return empty
    //If c is specified, find it else just find 'z'
    /*
    char char_to_find;
    if(c.has_value()){
        char_to_find = c.value();
    }else{
        char_to_find = 'z'; // Will find z by default
    }
    */
   char char_to_find = c.value_or('z');
    
    for (size_t i{} ; i < str.size()  ; ++i){
        //std::cout << "str[i] : " << str.at(i) << " , c : " << c << std::endl;
        if(str.c_str()[i] == char_to_find){
            return i;
        }
    }
   return {};// Or std::nullopt
}
