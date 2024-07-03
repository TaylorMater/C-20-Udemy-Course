#include <iostream>

// Assignment 003

// Write a program that reads in the length and width and height of a box and computes the base area and volume using the following formulas:

// base_area = width * length
// volume = base_area * height



//this all makes more sense when used with a rectangular prism class, which is an implementation of some 3d shape interface

double getMeasurement(){
    double measurement;
    std::cin >> measurement;
    return measurement;
}

double getBaseArea(double l, double w){
    return (l*w);
}

double getVolume(double l, double w, double h){
    return (l*w*h);
}

void performBoxCalculation(){
    double length, width, height;
    std::cout << "Welcome to the box calculator. " << '\n';
    std::cout << "Enter the box length: ";
    length = getMeasurement();
    std::cout << "Enter the box width: ";
    width = getMeasurement();
    std::cout << "Enter the box height: ";
    height = getMeasurement();
    std::cout << std::endl;
    std::cout << "The box base area is: " << getBaseArea(length, width)  << '\n';
    std::cout << "The box volume is: " << getVolume(length, width, height)  << '\n';
    
}

int main(){
    performBoxCalculation();
    return 0;
}