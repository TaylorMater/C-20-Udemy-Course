## Shift Operators

So I don't love the source code for this section of the chapter. He clearly could use `sizeof(short int)` instead of the magic number `16` when using the `bitset<16>(data)` operation. But it gets the point across. Just know that you absolutely can inject a function for the `bitset`'s number of bits. Better yet, you could define a `constexpr dataSize {sizeof(short int)};` and use that instead of 16. 

When shifting left or right, any data that leaves the range of bits assigned to the variable/value we are bit shifting will be lost. We cannot shift left a `1` out of our scope and "bring it back" by shifting right. All "new" values will be 0. If you bit shift to the left for the entire number of bits of the value you are operating with, it will turn into all 0's, and shifting left or right won't change anything, because all new bits will still be 0. 

You can shift to the left by 1 via `value = static_cast<unsigned short int>(value << 1);`, assuming `value` is a variable of type `unsigned short int`. You have to cast the result fo the bit shifting, which is done by `(value << 1)`, because bit shifting is not supported for types shorter than an `int`. So the computer will implicitly cast `value` to an `int` in order to perform the bit shifting operation, and then afterwards we are casting back to the original type. 

You can shift by more than 1 by just addjusting the value after the bit shift operator. 


Bit shifting is only supported for integral types. 


Shifting right by n bits is the equivalent of dividing by 2^n, but the fractional component will be lost because this operation is only valid for integral types (e.g. if you had `int val = 1;` and then later tried the expression `val = (val >> 2);`, `val` would be 0, because the only `1` in the binary representation of `val` will have been lost, and the values brought in will be 0.)

Shifting left by n bits is the equivalent of multiplying by 2^n, but if the new value exceeds the range of values, then you might encounter strange behavior - an unsigned char `val` might have value 128 in decimal, with bit representation `1000 0000`. Obviously a shift to the left by 1 bit would give us `0000 0000`, which breaks this rule. But if `val` was 64, then shifting to the left by once would be: `0100 0000` => `1000 0000` which is precisely multiplying it by 2! It makes sense - in decimal you could seen an analog via digit shifting when we multiply or divide by powers of 10. It's the exact same principle at work, just with upper/lower limits before we lose information, and no fractional components. 