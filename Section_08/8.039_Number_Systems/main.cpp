#include <iostream>


int main(){
    int num1 = 15;
    int num2 = 017;
    int num3 = 0x0f;
    int num4 = 0b00001111;

    //it prints out 15 every time, I guess by default it writes the number in decimal form. 
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    std::cout << num4 << std::endl;
    return 0;
}