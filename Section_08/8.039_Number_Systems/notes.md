## Number Systems

- Decimal system is base 10, essentially numbers are a sum of powers of the base. 
- Same is obviously true for other base systems, like binary (base 2), octal (base 8), and hexadecimal (base 16)

- For binary, the key is if you have n digits, then you can capture 2^n numbers in that representation. But you start at 0, so the maximum is not 2^n, but (2^n)-1.

- For n = 5, maximum binary number is (2^5)-1 = 32-1 = 31.
- For n=8, maximum binary number is (2^8)-1 = 256-1 = 255. You see this number still because 8 bit number storage is still prevalent in certain use cases (like RGB colors and how basic images store color information).


- Same philosophy for hexadecimal, but you use A, B, C, D, E, F for values 10, 11, 12, 13, 14, 15 respectively. For n=2, you can store 255 as the maximum value ((16^2) - 1) = FF = 15*16 + 15 = 255. 

- Neat thing when converting between binary, octal, and hexadecimal:

Consider the following binary number: 
1011 0011 1001 

When we inspect this, we recognize that the first 4 digits, 1001, tell us the digits less than 16. This is because for all the digits after 1001, n>3, so 2^n > 16. This means that we can map the total of the first 4 digits in binary to the "ones" digit in hexadecimal, as the describe the same number. 1001 is 9 in binary, and it is also 9 in hexadecimal. If we had 1101 in binary, we get 13. But 13 in hexadecimal is D. So 1001 <-> D when you switch between them.

But more interestingly, it continues if you continute in segments. Since 16 = 2^4, every four digits of binary maps exactly to the range of values of a corresponding hexadecimal digit. So our number 1011 0011 1001 in binary becomes:

1011 is 10 in decimal which is B in hexadecimal. 0011 is 3 in decimal which is 3 in hexadecimal. 1001 is 9 in decimal which is 9 in hexadecimal. Thus 1011 0011 1001 in hexadecimal is B39. There is always 4 times as many binary digits for a given hexadecimal number. 

For octal it's the same, but we work in chunks of 3 binary digits, not 4, because 8 = 2^3. It's neat that you don't need to expand the number into decimal, it's a nice shortcut. 


Here's a good resource for it: https://math.stackexchange.com/questions/597019/in-plain-english-why-does-conversion-from-hexadecimal-to-binary-work-so-cleanly

I like the math formalism that shows that a number is just a summation of digits and powers, and in hexadecimal, those digits range from 0-15. Well then we know that we can write each digit in binary, and then write the powers of 16 in binary, and you get the exact same number. But we need 4 binary digits to represent a single hexadecimal digit. 

We use 0x in front of hexadecimal numbers to signal that it is hexadecimal. So 0x0f is 15 in hexadecimal. For octal, we just place a leading 0 on the number. So 017 is octal for 15. For binary, we use 0b. So 0b00001111 is 15. 

Also, keep in mind padding, which is useful for conversion from binary to hexadecimal - we can append 0's to the front of a binary number so that the total number of digits is divisible by 4, and then the mapping above will always work. 

