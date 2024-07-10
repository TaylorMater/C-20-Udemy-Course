## Mask Example

The accompanying `main.cpp` just shows some ways you can use some of the masks we saw earlier to help handled argument handling in functions for very little overhead.

You can feed 8 booleans to a function as argument flags, or you can feed one unsigned char (which can be created by OR-ing a selection of masks that represent the flags of interest, if you'd like) and use bit status extraction to handle the flags instead. 

It just shows the convenience of using masks in some situations. 