## Weird Integral Types

- Note, integral types under 4 bytes in size don't support arithmetic operations. 
    - this includes char, short int 
        - for information on the minimum default sizes in the C++ standard, see here: https://eel.is/c++draft/tab:basic.fundamental.width
            - note, `sizeof` is critical, because platform and compiler specific differences might change how much memory is allocated for these.
            - a 4 byte signed int has a maxiumum of around 2.1 billion that it can store. 
    - note that compilers are smart enough, and implicitly convert these types so that the operation can be done