#include <iostream>


int main(){

    //Compile Time Error - expected ';' 
    // std::cout << "Hello World" << std::endl


    std::cout << "Hello World!" << std::endl;
    
    //Runtime Error - gives us division by 0 warning
    // int value = 7/0;
    // std::cout << value << std::endl; 

    return 0;
}