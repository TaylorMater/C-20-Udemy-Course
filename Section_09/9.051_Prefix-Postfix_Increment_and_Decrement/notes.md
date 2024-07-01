### Increment and Decrement Operations

I like using leetcode's C++ playground feature to test small code snippets. Saves having to rebuild a file locally for such a small snippet. See: https://leetcode.com/playground/

Postfix increment and decrement essentially embed a statement in between the current line and the next statement and increment/decrement a value by 1 only. 

```
    int num {3};
    std::cout << num++ << std::endl; //still prints 3
    std::cout << num << std::endl;  //prints 4 now

```

Gave us:

```
Finished in 0 ms
3
4
```

Prefix increment and decrement immediately applies the value change (again, only by 1) as soon as the expression is evaluated. 

```
    int num {3};
    std::cout << ++num << std::endl; //prints 4!
    std::cout << num << std::endl;  //prints 4 now

```

Gave us:

```
Finished in 0 ms
4
4
```