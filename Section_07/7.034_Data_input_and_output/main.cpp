#include <iostream>
#include <string>
#include <limits>

int main(){

    // std::cout << "Hello C++20" << std::endl;
    // int age {21};
    // std::cout << "Age : " << age << std::endl;

    // std::cerr << "Error message: Something is wrong" << std::endl;
    // std::clog << "Log message: information here" << std::endl;
    int option;
    std::cout << "Enter option: " << std::endl;
    std::cin >> option;

    int age1;    
    //needed to import string library, see import statements above
    std::string name;


    switch(option){
    
    //basic i/o
    case 1:
        std::cout << "Please type your name and age: " << std::endl;
        std::cin >> name;
        std::cin >> age1;
        std::cout << "Hello " << name << " you are " << age1 << " years old. " << std::endl;
        break;
    case 2:
    //now let's consider chaining inputs
        std::cout << "Please type your name and age: " << std::endl;
        std::cin >> name >> age1;
        std::cout << "Hello " << name << " you are " << age1 << " years old. " << std::endl;
        //But this won't work as expected if we put two names in for our name!
        //notice, if you type "name1 name2 21" then we get "Hello name1 you are 0 years old". See the learncpp section on handling invalid input for more info.
        break;
    case 3:
    //using the std::getline() function
        std::cout << "Please enter your full name" << std::endl;

        //note that std::getline() does not ignore leading whitespace. So it just reads the return character left from a previous std::cin extraction, and stops there. If we want to read more, we need to use the command std::cin.ignore() to flush that return character, or make a dummy getline() call before the one we are interested in. 

        //this statement allows us to ignore all characters left in the stream, all the way to the max size of the stream, until we hit a return character, and then we extract that return and move on. This line allows us to clear space. Typically, we would want to add this to a utils file as a function called ignoreLine() or something, so we don't have to add this messy code all over the place. 
        //Requires the limits library to be included
    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::getline(std::cin, name);
        std::cout << "Your full name is " << name << std::endl;
        break;
    default:
        break;
    }








    return 0;
}