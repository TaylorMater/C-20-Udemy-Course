## Data Input and Output

### Resources:

https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/

That is likely the best non-interactive C++ tutorial out there. Combined with this udemy course, you can master the fundamentals. Integration with network infrastructure, web design, and GUI stuff is something that will come later. 

### Basic io stream objects 

The following gloabl objects are readily used to control input and output to a stream buffer. Not really sure what a stream buffer is exactly, but consider it more or less what is left to be processed in the console/terminal when your program runs. We'll learn more about it later.

- `std::cout` can be thought of something that receives data from your code and sends it to the console output
- other types of input and output handling:
    - `std::cin` - reads data in from console
    - `std::cerr` - printing errors to console
    - `std::clog` - printing log messages to console

- Use `<< ` for `std::cout` for dividing elements that should be sent/printed to the console. Use `>>` for `std::cin` for dividing how we read the stream from the console and assign to variables. Examlple:

```
int age;
std::string name;

std::cout << "Please enter your name" <<  std::endl;
std::cin >> name;

std::cout << "Please enter your age" << std::endl;
std::cin >> age;

std::cout << "You are " << name << " and you are " << age << " years old." << std::endl;

```

The console would look something like:
```
Please enter your name
<name_typed>
Please enter your age
<age_typed>
You are <name_typed> and you are <age_typed> years old.

```

- There would be errors of course if the user did not type in input that was relevant to the data types we expect: for example, a user writing `twenty-one` as their age would cause a run time error, because `twenty-one` is not of type `int`, it's a `std::string`, and we would process that differently and the logic later would run into problems. It might not even break the program at first - see the learncpp.com site posted at the start of this file to see more. Also see [here](https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/).



### Chaining inputs 

Another thing we can do with `std::cin` is chain multiple inputs in a row. I guess it uses whitespace to specify the breaks. 

```
int age;
std::string name;

std::cout << "Type in your last name and age, separated by spaces: << std::endl;
std::cin >> name >> age;

```

If you need the user to input data which we want to extract that includes spaces, we want to use `std::getline(std::cin, var)` where `var` is the variable name which has been defined already. Example:

```
std::string fullName;
std::cout << "Enter your full name: ";
std::getline(std::cin, fullName);

std::cout << fullName << std::endl;

```

The output of that code will be the text entered for your full name, including the spaces between your names. 



Final note - `std::endl` is inefficient because it not only represents a new line character (`'\n'`) but it also flushes the buffer. We typically don't need to flush the buffer every line. If speed is important, you can default to just using `'\n'`, it is the preferred option from learncpp.com.