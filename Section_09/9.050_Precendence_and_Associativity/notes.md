### Precedence and Associativity:

In C++, multiplication and division are executed before addition/subtraction. This is defined in precedence - essentially which operations take priority.

For more info: https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/

Quoting that article:

Operator associativity

Consider a compound expression like 7 - 4 - 1. Should this be grouped as (7 - 4) - 1 which evaluates to 2, or 7 - (4 - 1), which evaluates to 4? Since both subtraction operators have the same precedence level, the compiler can not use precedence alone to determine how this should be grouped.

If two operators with the same precedence level are adjacent to each other in an expression, the operator’s associativity tells the compiler whether to evaluate the operators from left to right or from right to left. Subtraction has precedence level 6, and the operators in precedence level 6 have an associativity of left to right. So this expression is grouped from left to right: (7 - 4) - 1.


Operations with "higher" (numerically lower in this case - it depends on the labels given to the table you reference, but the relative positions are the same) precdence have their operands grouped first.

Associativity defined how operands are grouped within the same level of precedence. Depending on the precedence, the associativity can be Left to Right or Right to Left. Most precedence levels (and those for basic mathematical operations) are Left to Right associativity, but the increment operator, Logical Not, C-style cast, and other operations have Right to Left associativity. Check a precedence table if you are ever unsure how an expression will be evaluated, but more so, just use paratheses. They inherently have the highest precedence outside of a scope operator `::`, so if you use them, they help you explicitly tell the compiler how to group operands and operations. 

So if we had:

 $3 + 8 - 8 * 4 + 3 - 8 / 4 + 2 - 1$: 

Multiplication and Division have operator precedence 5. This is a higher precedence than addition and subtraction, which are in tier 6. Both are Left to Right associativity. 

So we then assign operands like this:

$3 + 8 - (8 * 4) + 3 - 8 / 4 + 2 - 1$

We found no operations of precdence higher than 5 (numerically lower than 5 implies higher precdence in this case, but just reference a table and common sense precedence for mathematical operations).
We grouped the left most operands connected to an operation from precedence tier 5. Continuing:

$3 + 8 - (8 * 4) + 3 - (8 / 4) + 2 - 1$

We ran out of operations in tier 5. We find several in tier 6, and they are also associatively grouped left to right.

$((((((3 + 8) - (8 * 4)) + 3) - (8 / 4)) + 2) - 1)$

This gives us an equivalent final expression of what would be computed, although I am certain the implementation is more tricky than what I've shown here. 


However, expressions might be evaluated in any order. For example:

```

#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

    return 0;
}

```


The three getValue() expressions inside the printCalculation() statement are grouped properly and the compiler knows to start evaluating the values inside so it can finish processing the statement. But let's say the user types in `1 2 3`. 

The problem here is not really with any of the logic, but that the compiler might evaluate a different getValue() first than you expected - it is compiler dependent (gcc and clang differ, clang is left to right, gcc is right to left). So using the gcc compiler, the computer will try to evaluate the right most getValue() first, which receives the `1` from the user. Then when printCalculation() is called, technically it will have `z=1`, `y=2`, and `x=3`. So the output would be `5`. 

If you used the clang compiler, you would evaluate the left most getValue() first. So then you would get `x=1`, `y=2`, `z=3`, and your output would be `7`. 

So it is highly recommended that you structure your code so that this doesn't happen - spread out your input over several statements that initialize variables in an order that is unambiguous, and then use them as you will. 

Here's an example of the same code sample above, but without ambiguity:

```
#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    printCalculation(a, b, c); // this line is now unambiguous

    return 0;
}
```