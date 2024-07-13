## Else If

Let's say you want to solve something where you want to check

You could do something like: 

```
if (expression){
    //do A
}
if (!expression && otherExpression){
    //do B
}
if (! expression && !otherExpression && newExpression){
    //do C
}
...

```

But you can see how this can quickly get out of hand. Having to specify that you don't want to run code for boolean expressions that you already evaluated can get annoying.

Instead, we use the `else if` statement:

```
if (expression){
    //do A
}
else if (otherExpression){
    //do B
}
else if (newExpression){
    //do C
}
...

```

See how much cleaner and easier to track it has become! 

There are several other reasons for to use `else if`. Here is a good source: https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/.

```
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";

    return 0;
}

```

The example above is very demonstrative of what `else if` does. 