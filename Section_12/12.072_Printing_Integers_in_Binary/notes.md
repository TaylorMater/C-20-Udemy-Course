## Printing Integers in Binary

This chapter focuses on bit manipulation. To be able to see your work, it's useful to be able to print data in it's binary format. 

The output of the accompanying `main.cpp` is the following:

```
data (dec) : 15
data (oct) : 017
data (hex) : 0xf
data (bin) : 0000000000001111
```

The `bitset` library from `#include <bitset>` gives us the ability to call `std::bitset<16>(data)` in that example. Note that you need to specify the number of bits in the type of your `data` variable. 

You could easily do that with `sizeof(data)*8`. 