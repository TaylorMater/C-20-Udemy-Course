#include <iostream>


int main(){

    //auto keyword lets the compiler deduce the type based on the evaluation or input type
    //examples:

    auto var1 {12};     //int
    auto var2 {13.0};   //double    
    auto var3 {14.0f};  //float
    auto var4 {15.0l};  //long double
    auto var5 {'e'};    //char

    //int modifier suffixes
    auto var6 {123u};   //unsigned
    auto var7 {123ul};  //unsigned long
    auto var8 {123ll};  //long long

    //you can see from the results that they are stored in appropriately deduced sizes
    std::cout << "size: " << sizeof(var1) << std::endl;
    std::cout << "size: " << sizeof(var2) << std::endl;
    std::cout << "size: " << sizeof(var3) << std::endl;
    std::cout << "size: " << sizeof(var4) << std::endl;
    std::cout << "size: " << sizeof(var5) << std::endl;
    std::cout << "size: " << sizeof(var6) << std::endl;
    std::cout << "size: " << sizeof(var7) << std::endl;
    std::cout << "size: " << sizeof(var8) << std::endl;

    return 0;
}