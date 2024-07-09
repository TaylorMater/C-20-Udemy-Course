## Compound Bitwise and Assignment Operators

Just like how you can do `num += 10;` for a variable `int num` that has a value, you can combine operations and assignment using the bitwise operators.

Make a variable equal to the result of bitshifting itself 4 bits to the left? Here:
```
num <<= 4;
```

AND a binary number with a variable and assign the result to the variable? Here:
```
num &= 0b00001111;  //I think type conversion is allowed 
```

The other bitwise operators work in the same way, see the accompanying `main.cpp` as an example. 

Practically identical to the compound arithmetic assignment operations. 