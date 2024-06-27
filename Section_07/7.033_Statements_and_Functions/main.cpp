#include <iostream>



int incrementByTwo(int a){
    return a+2;
}

int main(){
    //sequence of statements
    int firstNumber {3};

    //function incrementByTwo is called here, taking the variable firstNumber as a parameter. We expect this line to print 5 because firstNumber is initalized to 3. 
    std::cout<< incrementByTwo(firstNumber) << std::endl;
    
    int secondNumber {5};
    std::cout<< incrementByTwo(secondNumber) << std::endl;

    return 0;
}

