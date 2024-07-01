### Logical Operators

* AND     is coded by &&
* OR      is coded by ||
* NOT     is coded by !

They follow the basic logic of AND, OR, and NOT operations on boolean values. a AND b is 3 false unless a and b are both true. a OR b is true unless a and b are both false. 

Technically !(a OR b) = (!a AND !b)

These are called De Morgan's laws:

*   not (A or B) = (not A) and (not B)
*   not (A and B) = (not A) or (not B) 

Read more here: https://en.wikipedia.org/wiki/De_Morgan%27s_laws


You can see the boolean truth tables to understand more about how these operations work. 

You can use these operations with operands that evaluate to booleans, so expressions with the comparison operators can be injected into expressions with these logical operators quite easily. But also, some types implicitly convert to booleans, so you can do something like:

```    
int main() {
    int num {};
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;

    if (num && (3 < 5)){
        //do something
        std::cout << "You entered a non zero integer!" << std::endl;
    }
    else{
        std::cout << "You entered 0!" << std::endl;
    }

    return 0;
}

```

If `num` is 0, then the if statement fails. Otherwise, it should always pass, because `(3 < 5)` evaluates to true and a non zero integer (including negatives) implicitly converts to a true boolean value, so the `&&` operation returns true. 


