## Implicit Data Conversions

A much better resource than my notes: https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/

We sometimes run into instances where we might have a `int` initializing a `double` value, or a `long` adding a `float` value. Typically, you want to avoid situations like these by explicitly converting data as much as possible, but sometimes it is messy, redundant, or unavoidable. 

So it's best to understand what precisely happens to data types in specific cases.

For one thing, technically all variables in an expression are of the same type, ideally. But when the compiler notices that we have different types in an expression or if we expect some other data type from an expression, the compiler will apply implicit conversions.

Implicit conversions are done by the compiler without any code specifying it. It happens when the compiler knows it can safely change a data type without data loss potential, to avoid narrowing. So if you have situations where an `int` is added to a `double`, the result will have type `double`. It chooses the data type that has a larger memory size to be the new type.

You can run into implicit conversions that do cause narrowing, due to assignments.

```
    double y {4.5};
    int x {y}; 
    std::cout << x;

```
The output will be: `4`. This is because of implicit conversion during an assignment, that caused narrowing.

You should also know, when you have mathematical operations involving `int`s, you need only change one to a `double` and the operations will treat everything like a `double`.

```
    int a, b = 1;
    double c = 2.0;
    a + b + c;//we don't do anything with this, but technically the evaluation will have type double

```