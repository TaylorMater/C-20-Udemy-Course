#include <iostream>
#include <string>
#include <limits>


/*
ASSIGNMENT 1

Write a C++ program that asks which country the user lives in, lets the user type in the country and  and prints out a message

I've heard great things about [Country]. I'd like to go there sometime.


Example run :

Program prints : Where do you live?

User types : Finland

Program prints : I've heard great things about Finland. I'd like to go sometime.
*/



//#############################################################################################################################################################
//useful if we want to get input extracted from cin previously, because there could be a return character left in the buffer that will terminate a getline() call
//if not doing any other input extraction, then this is useless
void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}




//#############################################################################################################################################################
int main(){
    std::string country;
    std::cout << "Where do you live?" << std::endl;
    //using getline because some countries have spaces in their name - United States of America for example. std::cin breaks on whitespace
    std::getline(std::cin, country);
    std::cout << "I've heard great things about " << country << ". I'd like to go sometime." << std::endl;

    return 0;
}