#include <iostream>

int static_var{80};//static duration, dies when program ends. 

void some_function(){
    int local_var3 {30}; //local (automatic) duration. created at this line. dies at the end of the code block defined by the brackets, essentially is destroyed at the end of function execution
    static int static_var_1 {40}; //static duration. created when function is first called, dies when the program ends
    //dynamic duration is usually specified using the `new` keyword. We sort of need to have more tools to understand that - OOP sort of. But you have to handle the destruction of these variables from memory. Memory management is a concern in C++
}

int main(int argc, char **argv){
    int local_var1 {10};
    
    {
        int local_var2 {2}; //local duration, created at this line, dies at the end of this block. The block need not be used for defining a function. Once we know the variable has local duration, it dies at the end of whatever codeblock within which it resides. 
    }
    
}