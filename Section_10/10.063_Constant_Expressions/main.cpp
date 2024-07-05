#include <iostream>


int main(){

    constexpr int SOME_LIB_MAJOR_VERSION {1237};

    constexpr int eye_count {2};

    constexpr double PI {3.14};

    //eye_count = 4;

    std::cout << "eye count : " << eye_count << std::endl;
    std::cout << "PI : " << PI << std::endl;


    //int leg_count {2}; // Non constexpr
    // leg_count is not guaranteed to be known at compile time
    //constexpr int arm_count{leg_count}; // Error 


    constexpr int room_count{10};
    constexpr int door_count{room_count};// OK

    const int table_count{5};
    constexpr int chair_count{ table_count * 5};// Works

    //compile time check
    // static_assert( SOME_LIB_MAJOR_VERSION == 123);
    //if the static assertion fails, compilation will throw an error, to help validate that something is a specific value

    

    //cannot use static_assert on a non constant variable. This is because static_assert is a compile time check, so it can't validate runtime variables
    // int age = 5;
    // static_assert( age == 5);

    std::cout << "App doing its thing..." << std::endl;



    return 0;
}