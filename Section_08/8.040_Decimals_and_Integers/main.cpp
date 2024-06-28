#include <iostream>


int main(){
    
    
    // int num;            //either gives a random garbage value, or 0. Compiler dependent. 
    // int animals {15};   //initializes to 15
    // int houses {};      //initializes to 0
    // int houses_and_animals {houses + animals};  //initializes via expression, in this case 0+15=15


    // int bad_number {2.9}; //we should get a warning or error here, because 2.9 is a floating point/double, and not an int. It likely will implictly cast to 2, dropping the fractional part, and then warn us of data loss. But it doesn't technically break unless we choose to treat warnings as errors.

//#############################################################################################################################################################



    // int animals (3);    //inits to 3
    // int houses ();      //inits to 1 actually
    // int houses_and_animals (houses + animals);      //inits to 3+0 =3
    // int bad_number (2.9); //this might not raise a warning, and again we have implicit conversion from double to int with data loss. That's why braced initialization is preferred, as you get more information after the fact. 




//#############################################################################################################################################################

    int bikes = 3;
    int cars = 4;
    int travel_options = bikes + cars; //inits to 7
    int bad_num = 2.9;  //implictly casts to 2 again, we drop the fractional component

//#############################################################################################################################################################


    int trucks = 2;
    std::cout << "sizeof int: " << sizeof(int) << std::endl;    
    std::cout << "sizeof trucks: " << sizeof(trucks) << std::endl;
    //we saw that int stores 4 bytes, so 32 bits. Because it is signed, that doesn't actually give us too massive of a range of values. There are other integer data types that use more bytes if needed, and you can define your own if long long doesn't cut it for you (64 bits of integer, wowza that's about 9.2e+18 max value).

    return 0;
}