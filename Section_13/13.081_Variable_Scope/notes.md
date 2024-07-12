## Variable Scope

- scope: A region in your code where a variable name can be mentioned. You may be reading from it, writing into it, basically using it in any conceivable way.

Trying to use a variable when it is out of scope will result in a compiler error.

A variable with local scope (like defined in a function block or a specific code block), you can't then use that variable outside of that scope. 


Here's a good resource on this: https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/

To be honest, that resource goes into much more depth and covers adjacent topics we haven't quite seen in this tutorial yet. But it is critical information, as is most everything from learncpp.com. 

A lot of this you will learn more about over time, but know that there is a lot of depth to naming convetions, linkages, storage duration, and scope. 


Note, there is a difference between a variable with global scope and a static variable. Scope != duration. 

A static variable can be initialized in a function, but because it is static and its duration lasts for the whole program, then the variable will not be reinitialized. 

See this example from https://www.learncpp.com/cpp-tutorial/static-local-variables/:

```
#include <iostream>

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
```

The output is: 
```
2
3
4
```

This is because it is a `static` local variable. While you cannot reference that variable outside of its scope, the variable and its value is not destroyed upon reaching the end of scope, because its duration is static. 

A static local variable is like a global variable except with limited scope. 