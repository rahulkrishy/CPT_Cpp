// constexpr check the condition and executed at complie time than in runtime 
// hence boost in overall execution time of the code
#include <iostream>
using namespace std;

int main() {
    
    constexpr bool input {true};

    if constexpr (input)
        cout<<"Constexpr-check this condition at compiled time"<<endl;
    else
        cout<<"end"<<endl;
    return 0;
}
