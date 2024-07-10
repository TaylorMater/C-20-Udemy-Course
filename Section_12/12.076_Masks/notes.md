## Masks

Masks are just a useful construct where you defined constant binary numbers with only one bit as a 1, the highlighted bit. Then you can use these masks to check the status, reset to 0, set to 1, or toggle the value of that bit in other numbers of variables.

We use the logical operators AND (&), OR (|), NOT (~), and XOR (^) to do this. Also recall the bitshifting operators, << and >> for left and right bit shifting respectively.  

The details are seen in the accompanying `main.cpp`. 

But really:

Assume you have:
```
    unsigned char var {0b00001010};
    const unsigned char mask_bit_0 {0b00000001} ;//Bit0
    const unsigned char mask_bit_1 {0b00000010} ;//Bit1
    const unsigned char mask_bit_2 {0b00000100} ;//Bit2
    const unsigned char mask_bit_3 {0b00001000} ;//Bit3
    const unsigned char mask_bit_4 {0b00010000} ;//Bit4
    const unsigned char mask_bit_5 {0b00100000} ;//Bit5
    const unsigned char mask_bit_6 {0b01000000} ;//Bit6
    const unsigned char mask_bit_7 {0b10000000} ;//Bit7


    var |= mask_bit_0;      //sets the 0th bit in var to 1
    var &= (~mask_bit_0);   //sets the 0th bit in var to 0 (negate mask_bit_0: 11111110, then AND with a 0 is always 0, while AND with a 1 is just whatever the orginal bit was)
    std::cout<< ((var & mask_bit_3) >> 3 ) << std::endl;    //inner parentheses will be either 00000000 or 00001000, depending on if 3rd bit is a 0 or 1 respectively. Then bit shifting right turns those to either 00000000 or 00000001. So in the end we get either 0 or 1, with a 1 only if the bit in question was 1, and 0 if it was a 0. 

    var ^= mask_bit_0;      //XOR with a mask means highlighted bit in var is toggled, while every other bit in var stays the same. See main.cpp for more details

```


Pretty much all we need to know about this for now. 