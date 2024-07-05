## Constant Expressions


Another keyword: `constexpr`

Emphasis in C++: try to move heavy calculations to compile time, so that during run time users don't have to brace that cost. 

`constexpr` does two things:
- it flags a variable as constant, so it stops becomming modifiable after initialization
- expression is required to be evaluated at compile time

It is heavily recommended that you use `constexpr` and `const` as much as possible to avoid extra cost during runtime.

You can't initialize a compile time variable with a run time variable. So try to use `constexpr` everywhere it can be used to avoid running into this.

Even basic variable declarations like: `int num {3+4};` can be evaluated at runtime! A huge advantage to a compiler based language is in optimization, and by feeding expressions like these to the compiler, runtime is enhanced. 
- It should be noted that modern compilers might choose to evaluate these at compile time, but it's a best practice to always decalre `constexpr` if appropriate. The compiler is only forced to evaluate at compile time with this keyword. 


I might have some of the specifics wrong, but https://www.learncpp.com/cpp-tutorial/constant-expressions-and-compile-time-optimization/ is a good source on the matter. 

