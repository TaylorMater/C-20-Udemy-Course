#include <iostream>


int main(){

    //booleans (bool) data type stores true and false information
    //a lot of variables can implicitly convert to booleans if you don't cast them properly, for example non 0 integers evaluate to 1, and 0 goes to 0.

    bool red_light {true};
    bool green_light {false};

    bool other_light {1};
    bool crazy_light {0};

    if (red_light == true){
        std::cout << "Stop! There is a red light" << std::endl;
    }
    else{
        std::cout << "You can go" << std::endl;
    }
    //but technically if statements automatically evaluate the expression inside to a boolean value, so we don't need to compare a boolean against anything. We can just check the boolean value:

    if (red_light){
        std::cout << "Stop! There is a red light (but not checking == this time)" << std::endl;
    }


    //normally when you print a bool value, it shows 1 for true and 0 for false

    //can use std::boolalpha to force boolean values to be output as true or false:

    std::cout << "Green light: " << green_light << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Green light again: " << green_light << std::endl;

    //booleans occupy 1 byte, 8 bits, which is a bit wasteful, but there are special ways to pack more data in that. 

    std::cout << sizeof(bool) << std::endl;


    return 0;
}