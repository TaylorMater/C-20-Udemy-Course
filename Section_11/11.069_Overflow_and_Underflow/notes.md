## Overflow and Underflow

What happens when you increment a variable that is at the maximum value it can contain? 

Well what happens when you have 999 + 1? We get 1000. Let's say we can only see 3 digits in base 10, so 999 is our max value. How would you deal with someone trying to add 1?

Well one solution would be to throw an error. And that's certainly possible. But frankly, I think that prevents some functionality.

Another solution is to change the variable type upon trying to assign it a value large than its range. But that is extremely dubious.

A really neat solution is to utilize overflow and underflow. 

Again in base 10, let's say we can only look at 3 digits. So _ _ _, each with 10 possible digits is 1000 possible numbers, 0-999. When we hit 999, and we add 1, the actual value is 1000. But we can't represent 1000 in our hypothetical data type. Overflow is a solution where you start your counting over from the minimum value when you exceed the maximum value. It's essentially allowing modular arithmetic in the base of the maximum size of your data type. 

So 999+1 -> 0, 999+2->1, 999+3->2. 


Conveniently, this solution works really well with how binary numbers are stored. 

If your binary number is 1111 1111 (assuming an unsigned data type so all of these 1's represent the number itself, not a sign), and your data type has a maximum value of 255 (e.g. a `char`), then when you try to increment it you would get 1111 1111 + 0000 0001 = 0001 0000 0000, but again we can't store that new quadruplet at the front. So instead of doing any magic, we can literally just say the output of this operation is exactly what remains in the 8 bits we have, which is 0000 0000. But this is 0! Which is exactly the functionality expected for overflow. So for unsigned numeric data types, it's actually really simple and reasonable to implement overflow this way. It's like how 999+1 = 1000 = 000 because we can only store the first 3 digits. 


Underflow is the opposite, when you hit the minimum value and try to decrease. Underflow takes you to the maximum value, again looking like modular arithmetic but in the negative case (for example, -1 mod 7 is actually 6, the maximum value you can have in the set of numbers described by mod 7 arithmetic).

The same logic about how the computer implements overflow follows for underflow. 0000 - 1 = 1111.


Unfortunately, in C++ technically the situtations that cause overflow and underflow represent undefined behavior, and they are not reliable. Typically you want to avoid this if at all possible. The compiler can throw warnings for overflow and underflow.

Overflow and underflow happen for integral and floating point types. If the type in unsigned, then you get the expected modular overflow behavior we saw above. See here for more information: https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/. Pretty much: unless your use case demands the use of unsigned, small data types, avoid it so you can avoid overflow and underflow problems.