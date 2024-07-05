## constinit

This is a new C++20 keyword. 

- `constinit` says that a variable should be initialized at compile time. It must be initialized with constants or literals
- If you try initialization with something that can't be evaluated at compile time, you get an error
- We say that the variable should be const initialized 
- only applies to variables with with static or thread storage duration - these are outside of the main function scope. We will see more on that later. 
- `constinit` does NOT imply a variable is constant. It only implies that the variable is initialized during compile time. 
    - `const` and `constinit` can be combined to create a constant that is initialized at compile time
    - `constinit` and `constexpr` cannot be combined




Summary:
- `const` means that a variable cannot be modified after initialization, and mandates nothing from the compiler with regards to its evaluation. It can be evaluated at runtime or compile time, as the compiler chooses. However, after it is initialized, it cannot be modified. 
- `constexpr` means that a variable or function can be evaluated at compile time. This encourages the compiler to evaluate it during compile time if possible
    - the "maybe" case for the compiler, i.e. when depending on implementation it might evaluate it at compile time or runtime, can be seen in sitatuations like these:  `constexpr` functions with `constexpr` arguments, but the function result is not necessarily used in a `constexpr`. 
        - it helps to think of `constexpr` as two different meanings - when it affects variables it means it is a core constant expression and initialized at compile time, and thus also `const`, and its initializer must also be a constant expression. When `constexpr` is used on a function, it's just telling the compiler that this function is safe to use at compile time, because you made the arguments `constexpr` as well. But this function might not necessarily be evaluated at compile time. 
        - to force compile-time execution, you can assign the output of a `constexpr` function to a `constexpr` variable
    - `constexpr` also implies that value is a constant (the return value of a function or the variable itself). 
    - `constexpr` applies to the object that is declared, while `const` can apply elsewhere 
- `constinit` ensures that a variable with a static or thread storage duration is initialized at compile time. It is used to avoid "static initialization order fiasco" - https://en.cppreference.com/w/cpp/language/siof
    - essentially when static or thread storage is relevant, variables can be initialized by other variables. Perhaps `int num1 {num2};` and `int num2 {3};` exist at this point. There is ambiguity in these cases as to the order in which these are initialized, so you could have no errors one time, because `num2` is initialized first, or you could have an error because `num1` tried to be initialized and failed. This could happen because of changing the order of parameters to the compiler. 
    - P.S. a translation unit is essentially a `.cpp` file after injecting all of the `include`'s and relevant header information into it. It's useful for understanding the "static initialization order fiasco" mentioned above


__Key Differences:__
- Initialization Time:

    * `const`: The initialization can occur at runtime or compile-time.

    * `constexpr`: Ensures that initialization can occur at compile-time, but also allows runtime usage. Really depends on if it is applied to a function (allows runtime evaluation) or variable (is treated as a const that is initialized at compile time)

    * `constinit`: Ensures that initialization occurs strictly at compile-time.

- Use Cases:

    * `const`: Use when you want a variable to be immutable after initialization.
    * `constexpr`: Use when you want the variable, function, or constructor to be evaluated at compile-time for performance and optimization benefits. You might need to do extra work to guarantee a function or constructor is evaluated at compile-time (like calling the function or constructor somewhere in a compile time evaluation)
    * `constinit`: Use when you want to guarantee that a static or thread-local variable is initialized at compile-time to avoid initialization order issues.


There's also `consteval`, but we will dive into that later. 

Here is a good thread that dives into the differences: https://www.reddit.com/r/cpp_questions/comments/1ap7sx1/const_and_constexpr_detailed/

Quoting from the thread mentioned above: 

*"Now which one do you "choose"? The answer, as always, is: It depends.*

*Do you have C++20? You can choose. [Don't] have C++20? You cant use consteval or constinit anyways. To enfore compile time execution you must use a constexpr function and store the result in a constexpr variable.*

*Do you want to allow compile time usage of your function, but also allow its runtime usage? Then you use a constexpr function.*

*Do you want to enfore compile time execution and only that? Use consteval. The prime example here is the formt string for std::format and friends. Its compile time checked, so it has to be consteval."*