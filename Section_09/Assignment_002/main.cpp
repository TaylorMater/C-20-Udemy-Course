#include <iostream>

// Assignment 002

// Write a C++ program that reads in Celsius degree data from the terminal with std::cin and stores that in a double variable. The program then converts that to Fahrenheit and prints out a message like 50.2 Celsius is 122.36 Fahrenheit . The formula to convert from Celsius to Fahrenheit is fahrenheit = (9.0 / 5) * celsius + 32 .

// Please note that we are doing (9.0 / 5)  and not (9/ 5) . (9 / 5) would do integer division and we would loose fractional data that we need for the conversion to work properly.

//we probably need to do a lot of bounds checking and verification
double getDegreesCelsius(){
    double degrees;
    std::cout << "Enter a temperature in celsius: " << '\n'; 
    std::cin >> degrees;
    return degrees;
}

double convertCelsiusToFahrenheit(double c){
    return ((9.0/5) * c + 32.0);
}

int main(){
    std::cout << convertCelsiusToFahrenheit(getDegreesCelsius()) << std::endl;
    return 0;
}