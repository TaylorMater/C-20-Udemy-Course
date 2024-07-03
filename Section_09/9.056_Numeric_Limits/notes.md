### Numeric Limits

- floating point limits:
    - lowest is the least value: essentially the maxiumum negative number you can have
    - max is the maxiumum positive number you can have
    - min is the smallest positive number you can have - essentially the smallest fraction you can represent
    - for floats, you can reach ~-3.4e+38 to ~+3.4e+38, and then ~1.2e-38 is the smallest fraction you can represent.



- for ints, the limits are:
    - 16 bits gives you (2^15)-1 for the max, which is 32767
    - for 16 bits, the min is -2^15 which is -32768
    - if it's unsigned, then the min is 0 and the max is 2^16-1, which is 65535.



- `#include <limits>` helps us grab these ranges to play with for various data types
    - when you see it in the `main.cpp` code accompanying, you'll notice it's the first example of a template we can see
    - a template is code that does the same thing, but changes types. `std::numeric_limits<long>min()` and `std::numeric_limits<int>min()` 
        - we will see more of this later