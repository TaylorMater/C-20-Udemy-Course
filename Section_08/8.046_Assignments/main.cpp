#include <iostream>


int main(){
    //we want to demonstrate how after initialization of a variable, you can assign a value to the variable later:

    //grabbed code from https://github.com/rutura/The-C-20-Masterclass-Source-Code/blob/main/04.VariablesAndDatatypes/4.9Assignments/main.cpp
    //recommended from tutorial/owner

    int var1{123}; // Declare and initialize
    std::cout << "var1 : "  << var1 << std::endl;
    
    var1 = 55; // Assign
    std::cout << "var1 : "  << var1 << std::endl;
    
    std::cout << std::endl;

    std::cout << "----------------" << std::endl;

    double var2 {44.55}; // Declare and initialize
    std::cout << "var2 : " << var2 << std::endl;
    
    var2 = 99.99; // Assign
    std::cout << "var2 : " << var2 << std::endl;
    
    std::cout << std::endl;

    std::cout << "----------------" << std::endl;

    std::cout << std::endl;
    bool state{false}; // Declare and initialize
    std::cout << std::boolalpha;
    std::cout << "state : " << state << std::endl;
    
    state = true; // Assign
    
    std::cout << "state : " << state << std::endl;


    //Auto type deduction
    //Careful about auto assignments
    auto var3 {333u}; // Declare and initialize with type deduction
    
    var3 = -22; // Assign negative number. DANGER!
    
    std::cout << "var3 : " << var3 << std::endl;
    //we now go the reverse direction - 21 less than the maximum unsigned integer value: 4294967274 (max value is 4294967295)

    //no compiler error (perhaps warnings, but didn't see any) for initializing an unsigned integer this way
    unsigned int var4 {-1u};
    std::cout << var4 << std::endl;
    //but you see this: 4294967295, the max value. 0 is the minimum, -1 becomes the max, and -22 becomes the max value -21.
    //in general, -x = max_value - (x-1) = max_value -x + 1

    return 0;
}