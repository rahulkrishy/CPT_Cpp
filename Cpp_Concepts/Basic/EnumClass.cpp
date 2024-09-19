// enum class - (represent the range of value) new standard from c++ 11  -> Scoped enumerations(::), Requires explicit casting between the enumeration and underlying type.
// enum - old version (avoided in modern c++) -> Unscoped enumerations, Allows implicit conversion between enumerators and integers.
#include <iostream>
#include <string_view>

//Declare an enum type
//The default type associated with enum classes with C++ is int

enum class Month {
    Jan, January = Jan, Feb, Mar, 
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct, Nov, Dec
};

//unsigned char : 0 ~ 255
// char : -128 ~ 127
enum class Month1 : unsigned char {
    Jan = 1, Feb, Mar, 
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct = 100, Nov, Dec
};

std::string_view month_to_string(Month month){
    switch (month)
    {
        /*
        case Month::Jan : return "January";
        case Month::Feb : return "February";
        case Month::Mar : return "March";
        case Month::Apr : return "April";
        case Month::May : return "May";
        case Month::Jun : return "June";
        case Month::Jul : return "July";
        case Month::Aug : return "August";
        case Month::Sep : return "September";
        case Month::Oct : return "October";
        case Month::Nov : return "November";
        case Month::Dec : return "December";
        default : return "None";
        // instead of in case, we can shorten by using enum 
        */

        using enum Month;                         //'using enum' 
        case Jan : return "January";
        case Feb : return "February";
        case Mar : return "March";
        case Apr : return "April";
        case May : return "May";
        case Jun : return "June";
        case Jul : return "July";
        case Aug : return "August";
        case Sep : return "September";
        case Oct : return "October";
        case Nov : return "November";
        case Dec : return "December";
        default : return "None";
    }

}


int main(){

    Month month01 {Month::Jan};
    std::cout << "month01 : " << static_cast<int>(month01) << std::endl;  //only using static_cast<int> to get as a int
    Month month02 {Month::January};
    std::cout << "month02 : " << static_cast<int>(month02) << std::endl;
    Month month03 {Month::Feb};
    std::cout << "month03 : " << static_cast<int>(month03) << std::endl;

    std::cout << "sizeof(month) : " << sizeof(month01) << std::endl;

    Month1 month001 {Month1::Oct};
    std::cout << "month001 : " << static_cast<int>(month001) << std::endl;
    Month1 month002 {Month1::Nov};
    std::cout << "month002 : " << static_cast<int>(month002) << std::endl;

    Month month {Month::Apr};
    std::cout << "month : " << month_to_string(month) << std::endl;


    return 0;
}