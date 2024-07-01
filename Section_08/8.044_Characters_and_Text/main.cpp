#include <iostream>

void printChar(char alpha){
    std::cout << "character is " << alpha << std::endl;
}


int main(){

    //chars occupy 1 byte in memory
    // only allows for 256 char values
    //ascii however is a 7 bit encoding, so only 128 values are dedicated to ascii values, and only like 95 are printable
    //more details: https://en.cppreference.com/w/cpp/language/ascii





    //can be initialized like we have previously seen:

    char character_1 {'r'};
    char character_2 = 'p';
    char character_3 ('.');
    char character_4 {70};

    printChar(character_1); //prints 'r'
    printChar(character_2); //prints 'p'
    printChar(character_3); //prints '.'
    printChar(character_4); //prints 'F' because 'F' is the character at ASCII value 70. 

    //see the table below - the comparison and addition operators work as if you were operating on their numeric value
    //you can static_cast between chars and int easily

    //from the link above
    std::cout << "Printable ASCII [32..126]:\n";
    for (char c{' '}; c <= '~'; ++c) {
        //nice look at a useful way to apply a ternary operator to quickly choose when to write a newline character or not
        std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
    }


    return 0;
}