#include <iostream>


int main(){
    //Addition
    int number1{2};
    int number2{7};

    int result = number1 + number2;
    std::cout << "result : " << result << std::endl;

    //Subtraction
    result = number2 - number1 ;
    std::cout << "result : " << result << std::endl;

    result = number1 - number2;
    std::cout << "result : " << result << std::endl;

    //Multiplication
    result = number1 * number2;
    std::cout << "result : " << result << std::endl;


    //Division
    result = number2 / number1;
    std::cout << "result : " << result << std::endl;
    //integer division - for n = mq + r with 0 <= r < m. Integer division gives us q. 
    // n / m = q + r / m
    // 7 / 2 = 3 + 1 / 2

    //Modulus
    result = number2 % number1; // 7 % 2
    std::cout << "result : " << result << std::endl; // 1
    //modulus - for n = mq + r with 0 <= r < m. modulus gives us r. 
    // n / m = q + r / m
    // 7 / 2 = 3 + 1 / 2
    // so 7 % 2 = 1

    result = 31 % 10;
    std::cout << "result : " << result << std::endl; // 1
    return 0;
}