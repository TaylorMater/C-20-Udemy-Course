### Relational Operators


learncpp.com article for this: https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/

We have >, < , >=, <=, ==, and !=. 

They correspond to greater than, less than, greater than or equal to, less than or equal to, is equal to, and is not equal to.


They return booleans based on the expression, taking operands before and after it. 


Oh also apparently there's a compiler error when you use some of these operations nested in between insertion operators. This is because the insertion operator (which is actually an overloaded operator - technically it is also the bitwise shift operator to the left, and extraction is bitwise shift to the right) has higher precedence than the relational operators, so it wants to insert the expression it has not yet evaluated. 

Typically, if you aren't going to evaluate your expressions in previous lines or standalone statements, then you want to surround them in parentheses. 

