## Literals


- a __literal__ is some data that is directly represented in code without going through some other variable stored in memory. 
    - example: the `3.0` in `thisFunction(3.0)`. Instead of having `3.0` live in a variable, we are literally sending `3.0` to that function. But it still has to be handled by memory in some way. 
    - example: the `5` in the declaration `int num = 5;` That 5 is created in memory to then get assigned to `num`. 

- a literal is stored directly in the program binary code
- variables are stored in memory locations and are assigned variable names


With literals, you might have to apply suffixes to specify exactly the type that you want when initializing variables. 

For example, an `unsigned long` literal is specified via `12345UL`, but with any number as an example. You can also use the lower case versions, but the upper case vesions leave less room for confusion with numbers like 1, so prefer them.

You can also check more on this here: https://www.learncpp.com/cpp-tutorial/literals/


In C++14 and onwards, we can use `'` to make the literal more readable. `1'500'00'0u` for example. It doesn't affect the value or printing of the number in any way. 

Recall that possible narrowing errors (when the range of the literal type assigned to the lvalue exceeds the range of the lvalue type, you could have data loss due to narrowing of the range) occur when using assignment and functional initialization. Bracket initialization will throw an error and is preferred for this reason. 


These suffixes can combine with prefixes to specify a literal - for example, `0x` for hex and `UL` for unsigned long: `0x12BFUL` ( = $4799_{10}$). 

Hex prefixes are often used with colors. 

Recall you can use I/O manipulators to display the numerical base of your preference to the console. 

Careful with octal literals, as they are merely prepended with a 0. A lot of people will ignore the 0 or think it is just redundant specificity about the number, but if you add a 0 before a number, it will be treated as base 8.


You can have `char` literals and other numeric literals, as you would expect. You can also have string literals, which is what happens when you type `std::cout << "Hello World!";` - the "Hellow World" is a string literal. 


Literals connect to something called "magic numbers" in your code - unexplained literal values that make it hard to understand the purpose/why it's there/why it's that value. You want to limit those as much as possible, which is why you typically want to inject constants, setup, and config information into the code, rather than coding it explicitly. 
