## Logical Bitwise Operators

- AND (&)
- OR (|)
- XOR (^)
- NOT (~)
    - note the difference to ! here


Truth tables for these operators: https://bob.cs.sonoma.edu/IntroCompOrg-RPi/sec-Cbitshift.html (and a good explanation of truth tables as well. It's a good resource.)

Use `std::bitset<num>(<expression>)` to see the affects of these operators, where `num` is the size of the binary number in question (8 for unsigned char), and `expression` is some expression using binary numbers of the specified size, and potentially using operators seen above. For example:

```
unsigned char val1 {0x0A}; //       10 = 0000 1010
unsigned char val2 {0x03}; //       3  = 0000 0011

//expectation for val1 & val2 (AND):     0000 0010
//expectation for val1 | val2 (OR) :     0000 1011
//expectation for val1 ^ val2 (XOR):     0000 1001
//expectation for ~val1       (NOT):     1111 0101

std::cout << std::bitset<(sizeof(unsigned char)*8)>(val1 ^ val2) << '\n';

```

The output will be:
```
Finished in 0 ms
00001001
```

Which is exactly as predicted for XOR. 


You can use these operators on binary and hex literals as well. The `std::bitset` is what does the work to present the actual binary form of these. 