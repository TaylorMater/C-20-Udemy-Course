#include <iostream>
#include <iomanip>
#include <bitset>


int main(){

	const int COLUMN_WIDTH {20};
    
	//Highlight position for bit of interest with a 1
	//Mask other positions with 0
	
    //not really going to see a big difference by using constexpr here, it's 8 1 byte variables. And we are the only user of this program. 

    const unsigned char mask_bit_0 {0b00000001} ;//Bit0
    const unsigned char mask_bit_1 {0b00000010} ;//Bit1
    const unsigned char mask_bit_2 {0b00000100} ;//Bit2
    const unsigned char mask_bit_3 {0b00001000} ;//Bit3
    const unsigned char mask_bit_4 {0b00010000} ;//Bit4
    const unsigned char mask_bit_5 {0b00100000} ;//Bit5
    const unsigned char mask_bit_6 {0b01000000} ;//Bit6
    const unsigned char mask_bit_7 {0b10000000} ;//Bit7
    
    //Sandbox variable
    unsigned char var {0b00000000};// Starts off all bits off
    
    std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;



    //Set a few bits : make them 1's regardless of what's in there

	//SETTING BITS
    //Setting : |= with mask of the bit
    //it's just using the compound logical or operator. This allows us to guarantee a certain bit is a 1 by using a mask with a 1 in that bit. 
	
    //Set bit 1
	std::cout << "Setting bit in position 1" << std::endl;
	var |= mask_bit_1;
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

	//Set bit 5
	std::cout << "Setting bit in position 5" << std::endl;
	var |= mask_bit_5;
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;


	//RESETTING BITS : set to 0
    //Resetting : &= (~mask)
    // The expression above means that we will guarantee that the bit in question becomes a 0, while all of the other values remain the same:
    // If the original char had a 1 in the location of interest, then ~mask will make it so that 1 gets AND'd with a 0, which will become a 0.
    // All of the other bits get AND'd with a 1 (because we negate the mask, which was all 0s elsewhere originally). This has the effect of keeping the other bits the same
    // 1 AND 1 = 1, 0 AND 1 = 0. Anding with a 1 changes nothing about the bit. 
    //So the result of calling var &= (~mask_bit_1); where mask_bit_1 = 0b00000010 and var = 0b10101010 is : 0b10101010 & (~0b00000010) = 0b10101010 & 0b11111101 = 0b10101000
    // which kept the byte exactly the same, but turned off the bit in the 2^1 place, the bit highlighted by the mask_bit_1 constant we defined earlier.  
	
	//Reset bit 1
	std::cout << "Resetting bit in position 1" << std::endl;
    var &= (~mask_bit_1);
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

	//Reset bit 5
	std::cout << "Resetting bit in position 1" << std::endl;
    var &= (~mask_bit_5);
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;


	//Set all bits
	std::cout << "Setting all bits" << std::endl;
    var |= ( mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
             mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7);
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;


	//Reset bits at pos 0,2,4,6
	std::cout << "Reset bits at pos 0,2,4,6" << std::endl;
    var &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6);
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;



	//Check state of a bit
    //because the result of the (var &  mask_bit_x) will be all 0's except for a 1 if there was a 1 in the xth spot in var
    //then we have a number that is either 0 or 2^x. So if we want to see a 1 or 0, we can shift to the left by x bits to divide by 2^x. 
    //if the number is already 0, the bit shifting won't change anything

    //so this helps us see the status of a bit, but it's a little gross because of the magic numbers
    //also, you can see that you can cast a 1 or a 0 to a boolean from this.

	std::cout << std::endl;
	std::cout << "Checking the state of each bit position (on/off)" << std::endl;
	std::cout << "bit0 is " << ((var & mask_bit_0) >> 0 )<< std::endl;
    std::cout << "bit1 is " << ((var & mask_bit_1) >> 1 ) << std::endl;
    std::cout << "bit2 is " << ((var & mask_bit_2) >> 2 ) << std::endl;
    std::cout << "bit3 is " << ((var & mask_bit_3) >> 3 ) << std::endl;
    std::cout << "bit4 is " << ((var & mask_bit_4) >> 4 ) << std::endl;
    std::cout << "bit5 is " << ((var & mask_bit_5) >> 5 ) << std::endl;
	std::cout << std::boolalpha;
    std::cout << "bit6 is " << ((var & mask_bit_6) >> 6 ) << std::endl;
	std::cout << "bit6 is " << static_cast<bool>(var & mask_bit_6) << std::endl;

    std::cout << "bit7 is " << ((var & mask_bit_7) >> 7 ) << std::endl;
    std::cout << "bit7 is " << static_cast<bool>(var & mask_bit_7) << std::endl;


	//Toggle bits
	//Toggle : var ^ mask
	//using the XOR operator. So if the var has a bit with 1 and the mask's respective bit is 1, then the output is 0. 
    // If var has a bit with 1 and the mask's respective bit is 0, then the output is 1. 
    // If var has a bit with 0 and the mask's respective bit is 0, then the output is 0.
    // If var has a bit with 1 and the mask's respective bit is 0, then the output is 1. 

    //notice how because the mask highlights only one bit, then except for the highlighted bit, the mask will have a 0 bit. 
    //XOR with 0 never changes the original value ( 0 XOR 0) is 0 while ( 1 XOR 0) is 1. 
    //so the rest of var is unchanged, but XOR with 1 will toggle, so the highlighted bit will toggle. 


	//Toggle bit 0
	std::cout << std::endl;
	std::cout << "Toggle bit 0" << std::endl;
    var ^= mask_bit_0;
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

    //Toggle bit7 
	std::cout << "Toggle bit 7" << std::endl;
    var ^= mask_bit_7;
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

	//Toggle multiple bits in one go : the 4 higher bits
	std::cout << "Toggle multiple bits in one go : the 4 higher bits" << std::endl;
    var ^= (mask_bit_7 | mask_bit_6 | mask_bit_5 | mask_bit_4);
	std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
		 << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;
   
    return 0;
}