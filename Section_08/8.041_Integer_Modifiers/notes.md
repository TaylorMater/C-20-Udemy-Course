## Integer Modifiers

- `int` defaults to a signed integer. `signed` is a modifer you can add as well, but C++ will receive it the same as `int` due to the default. 
- You can use the `unsigned` modifier if you want only positive integers. You would get a compiler error with a negative number
- The range for a signed integer is $ -(2^{n-1})  $ to $ 2^{n-1} -1 $, while the range for an unsigned integer is $0$ to $2^n -1$.

- you can also flag your integer as `short`, `long` or `long long`. 
- I don't believe you need to specify `int` when using one of these, `long long int` and `long long` mean the same thing. 

- typically, a `short` is 2 bytes, `int` is 4 bytes, `long` is 4 or 8 bytes, and `long long` is 8 bytes, but depending on platforms it could change, and I believe C++ only mandates a minimum size. So remember to use `std::sizeof` on a data type to get the specific number of bytes allocated in memory for a data type. 

- these modifiers only work on integer types. 