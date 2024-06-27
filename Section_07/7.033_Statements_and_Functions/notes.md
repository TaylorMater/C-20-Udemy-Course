## Functions and Statements

### Statements

- A statement is a basic unit of computation in C++
- Statements end with a ';'
- Statements are executed in order, top to bottom
- Execution continues until end of program or a termination condition



### Fucntions

- Collection of statements we want to repeat, usually that takes inputs and generates an output
- Requires a return type, function name, parameter list, and then function definition/body. 
- A function must be defined before it is used. It cannot be called before it is defined. 
- If I remember correctly, that means you want all of your functions to at least be defined in a header file that is linked to your program, so that the program can find your function definition. For example, I could define a function below the int main() which references it, and we would get an error because it was not defined before it is used? Let me check.
    - Correct, it seems that we get a compilation error: `{function_name} "was not declared in this scope"`
- You want to write functions when you want to simplify how a source file looks to make it more readable, or if a selection of code will be repeated a lot.