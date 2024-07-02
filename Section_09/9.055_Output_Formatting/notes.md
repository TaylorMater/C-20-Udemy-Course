## Output Formatting


This is mainly a reference document, it is unlikely that you ought to memorize any of this. Just be aware that it exists should you need it. Check https://en.cppreference.com/w/cpp/io/manip for more information if needed.

If you don't know where a particular manipulator lives, you can look up the documentation and find the appropriate header/library it lives in. 


### ostream, iomanip, and ios libraries


### ostream library

We have already seen one output formatter in `std::endl`
- std::endl
    - prints a new line
    - does what '\n' does, but also flushes the buffer. This is slower and usually doesn't need to be done, so '\n' is usually preferred
    - see [here](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/) for more details

Similarly, we can flush with:
- std::flush
    - sends whatever is in the output buffer to the terminal
    - buffer is sort of a storage for data before it goes to the terminal

### iomanip library

The `iomanip` library adds a lot of other functionality. Below are some manipulators.  

- std::setw()
    - specifies the width for whatever text you want to print

```
    std::cout << std::setw(10) << "Mark" << << std::setw(10) << "Sanchez"'\n';
    std::cout << std::setw(10) << "Tom" << << std::setw(10) << "Brady"'\n';
```

we get the following output:

```
      Mark   Sanchez
       Tom     Brady
_|_|_|_|_|_|_|_|_|_|
```

the gridlines at the bottom help you see what's really happening here. Mark is prepended with 6 space characters to create text that is 10 characters wide. Sanchez gets 3 characters. What happens when we exceed the width?

```
    std::cout << std::setw(10) << "Mark" << std::setw(10) << "Sanchez" << '\n';
    std::cout << std::setw(10) << "Tom" << std::setw(10) << "Brady" << '\n';
    std::cout << std::setw(10) << "NameIsTooLong" << std::setw(10) << "Jones" << '\n';
```

We get:

```
      Mark   Sanchez
       Tom     Brady
NameIsTooLong     Jones
_|_|_|_|_|_|_|_|_|_|
```

in that case, we don't get data loss, we just exceed the 10 characters we specified, so the next 10 characters is slightly offset. 


We can also specify the fill character with `std::setfill()` (above it was spaces, but we can make it whatever we want - dashes often enhance readability in the terminal for example).


`std::setprecision` lets you define how many digits to display in an output, useful for scientific and mathematical calculations. 


### ios library

You can also use justification via `std::right`, `std::left`, `std::internal` depending on what you want. 


We have already seen `std::boolalpha`, which has the affect of changing boolean output from `1` or `0` in the terminal to `true` or `false`. `std::noboolalpha` will turn off this functionality. 

These are all called via `std::cout << std::<command_name>`, where `<command_name>` is something like `right` or `boolalpha` or `setw(20)`. 

`std::showpos` shows the positive sign for positive numbers. Can be turned off with `std::noshowpos`.

We also have manipulators to control the base in which data is shown:

`std::dec`, `std::hex`, `std::oct`. These work as you expect. Floating point numbers don't change when you adjust the number system. 

If you have any questions please see the accompanying main.cpp, as it is copied from the tutorial source repo and can demonstrate more examples.



`std::showbase` tells us the base of the output. This adds a 0x for hex and a 0 for octal to the front of a number. 

`std::uppercase` will make the output all uppercase 

Values printed default to scientific/fixed depending on the number. You can use `std::fixed` to change that to just show fully expanded values, or `std::scientific` to specify scientific notation. Note, there's not really an easy way to convert back to the defaults, although there are some workarounds. 

`std::showpoint` forces the decimals to be visible for floating point numbers (so 12 -> 12.0000). To go back to the default, use `std::noshowpoint`. 



