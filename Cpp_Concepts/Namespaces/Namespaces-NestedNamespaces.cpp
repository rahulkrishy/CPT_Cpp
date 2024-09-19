#include <iostream>

namespace Hello{
    unsigned int age{23};
    
    namespace World{
        int local_var{44};
        
        void say_something(){
            std::cout << "Hello there " << std::endl;
            std::cout << "The age is : " << age << std::endl;
        }
    }
    
    void do_something(){
        //Here we don't have direct access to local_var, we have to go 
        //through the namespace.
        std::cout << "Using local_var : " << World::local_var << std::endl;
    }
}

namespace Level1{
    namespace Level2{
        namespace Level3{
            const double weight{33.33};
        }
    }
}



int main(){
    Hello::World::say_something();
    Hello::do_something();

    std::cout<<"----"<<std::endl;

    //Namespace aliases
    namespace Data = Level1::Level2::Level3;

    //std::cout << "weight : " << Level1::Level2::Level3::weight << std::endl;
    std::cout << "weight : " << Data::weight << std::endl;

    return 0;
}