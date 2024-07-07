## Explicit Data Conversions

Again, this topic is more fully explained here: https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/

But you can use various `cast`s to convert data types explicitly. This is typically a good practice to not run into unintended functionality. 

The most basic and fundamental is the `static_cast<T>()` where `T` represents the data type we want to convert to.

```

    double a {1.2};
    double b (2.4);

    int c = static_cast<int>(a + b);    //3 will be assigned to c

```


Also, old C-style casts exist. They are frowned upon a little, but they do work:

```
    double pi {3.14};
    int newPi = (int)(pi);  //newPi contains 3, this (int)() cast works as expected

```

It is kept in the language because it is backwards compatible. Static cast is more clear with our intentions, and easier to search for. Further, static_cast is checked by the compiler to make sure the types are compatible. 


There are other types of casts as well. 