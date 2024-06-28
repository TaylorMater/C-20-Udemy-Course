## Decimals and Integers



### Varieties of Numerical Data Types
- int
    - Stores integers
    - Typically occupies 4 bytes (32 bits) in memory. Various versions though, check the learncpp.com link for details: https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/

- floats, doubles, longs are other common numerical data types. Also technically bool and maybe char if I remember correctly, but that's more complicated. 


### Initialization methods:

- can initialize variables with braces {}, called variable braced initialization:

```
    int num;            //either gives a random garbage value, or 0. Compiler dependent. 
    int animals {15};   //initializes to 15
    int houses {};      //initializes to 0
    int houses_and_animals {houses + animals};  //initializes via expression, in this case 0+15=15


    int bad_number {2.9}; //we should get a warning or error here, because 2.9 is a floating point/double, and not an int. It likely will implictly cast to 2, dropping the fractional part, and then warn us of data loss. But it doesn't technically break unless we choose to treat warnings as errors.

```


- can initalize with parentheses as well (), called functional variable initialization:

```
    int animals (3);    //inits to 3
    int houses ();      //inits to 1 actually
    int houses_and_animals (houses + animals);      //inits to 3+0 =3
    int bad_number (2.9); //this might not raise a warning, and again we have implicit conversion from double to int with data loss. That's why braced initialization is preferred, as you get more information after the fact. 


```


- can initialize with assigment =, called assignment initialization:

```
    int bikes = 3;
    int cars = 4;
    int travel_options = bikes + cars; //inits to 7
    int bad_num = 2.9;  //implictly casts to 2 again, we drop the fractional component

```


### Size of Variable


```
int trucks = 2;
std::cout << "sizeof int: " << sizeof(int) << std::endl;    

std::cout << "sizeof trucks: " << sizeof(trucks) << std::endl;
```

- both of the above uses of sizeof gives us the ability to see how big a specific data type is stored in memory. sizeof returns the size in bytes.




- note, variables cannot start with a number, have to start with a letter or underscore.