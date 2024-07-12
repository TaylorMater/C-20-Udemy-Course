## Packing Color Information

This is an example of using masks to pack information in very small variables. 

We create masks for each color and for the alpha for the typical 4 byte integer that stores color information. 

The same principles essentially apply as when we used bit manipulation masks, but because we are working with hexadecimal, the details are slightly different. 

Recall that every hex digit represents 4 bits. So shifting a single hex digit requires bit shifting by 4. 

What's happening under the hood for the example `main.cpp`:


```
unsigned int my_color {0xAABCDE00};
```

In binary, this is: 1010 1010 1011 1100 1101 1110 0000 0000.

Our red mask is: 

```
const unsigned int red_mask {0xFF000000};
``` 

In binary, that is: 1111 1111 0000 0000 0000 0000 0000 0000.

When we compare with the above `my_color`, see what the result of the AND operation will be with our `red_mask`. 

Starting from the left, we get: 1 & 1 = 1, 0 & 1 = 0, 1 & 1 = 1, 0 & 1 = 0, ... Notice how when we AND with a 1, we get whatever the original bit was. Also notice that if we AND with a 0, we always get 0. So in this way, our `red_mask` can help us extract precisely the component bits of `my_color` that correspond to the bytes we care about.

So `my_color & red_mask` evaluates to: 1010 1010 0000 0000 0000 0000 0000 0000. 

In fact, we don't even need to keep playing with binary do we - because of the way we defined our mask, this will exactly grab the first byte of `my_color` and assign 0's elsewhere. See how `my_color & red_mask` in hex = {0xAA000000}. 

Then, if we want to extract the value of that byte, we have to do right bit shifting. How many spots? Well, we have to shift over 6 hex digits, which is 24 bits. So we would then say that:

```
    std::cout << ((my_color & red_mask) >> 24) << '\n';
```

Would yield this output: 170.

Recall that 0xAA = 0b10101010 = 128 + 32 + 8 + 2 = 170. We could change the preferred base that std::cout displays if we wanted to, but we can see that this checks out.

The accompanying `main.cpp` shows this for all masks for a particular color unsigned int.