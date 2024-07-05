## Constants

Can use the `const` keyword to specify that the variable can be set during initialization, but cannot be changed later. 


The protection is at the program level, not the memory level. If you can have another variable access the memory which stores the `const` variable, you in theory can make changes to it, but C++ protects you from this because it doesn't allow another variable to access the same place in memory. 


We use `const` to guarantee that the variable will not change during the lifetime of our program. You have to initialize any variable that you decare with `const` immediately, because you can't modify it later. 

We can read the value from a `const` variable, but we can't change it.

Use `const` as much as possible for variables that won't change, variables that you don't intend on modifying. 


This relates to the concept of lvalues. A `const` is an lvalue, but it is not a modifiable lvalue after initialization/declaration. 


You get compiler errors when you try to modify a `const`.