#ft_printf by Javier Rodriguez Montero.

# Content

* [Quick review of the printf function in C](#quick-review-of-the-printf-function-in-c)
* [Quick description of my printf version](#quick-description-of-my-printf-version)
* [Installation](#installation)
* [Compilation and how to use it](#compilation-and-how-to-use-it)
* [Conclusion](#conclusion)


## Quick review of the printf function in C
The printf() function is used to print a formatted string
to the stdout output stream. This fuction is also used to 
write the value of different types of variables, such us:
```
- Characters			%c

- Integers			%i %d

- Strings			%s

- Pointer's address		%p

- Unsigned decimal integer	%u

- Hexadecimal values		%x %X

- % character			%
```

There are sub-specifiers that can be contained in the format
specifier. Those sub-specifiers are the ``width``, which
indicates the minimum number of characters to be printed when
the value to be printed is shorter than the number specified on
the width, and this printed characters are blamk spaces.
The other sub-specifier is the ``precision``, which specifies the
minum number of digits to be written, just like the ``width``, but
instead of printting blank spaces, the result is padded width
leading zeros.
The ``width`` is a number that is placed between the ``%`` character
and the specific type of conversion, for example:
```C
printf("\nHello %10s!\n", "World");
```
The ``precision`` is also a number that is placed between the ``.``,
character right after the ``%`` character, and the specific type of
conversionm, for example:
```C
printf("\nHello %.10s!\n", "World);
```
There are also another features of the printf function, like
the flags, that are very useful to use in some specific situations.
Those flags are:
```
- -				left-justify within the given field width.

- +				Forces to proceed the result with a plus sign, for positive numbers.

- (space)			If no sign is going to be written, a blank space is inserted before the value.

- #				Used width o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively
				for values different than zero.
- 0				Left-pads the number with zeroes (0) instead of spaces when padding is specified.
```

You can check more information about this function [here](http://www.cplusplus.com/reference/cstdio/printf/).

## Quick description of my printf version.
My own printf version doesn't do everything that
the original printf C function does.

For example, my printf version, just can manage the following
conversions:
``c s p u x X i d %``
And the following flags:
``- + (space) # 0``
And of course, the width and precision sub-specifiers.
A format specifier follows this prototype:
``
%[Flags][Width][.Precision][Length]<type>
``

## Installation
```
git clone https://github.com/JvRdgz/ft_printf
cd ft_printf
make re
```

## Compilation and how to use it.
Once you've done ``make re``, you have to compile your file with the generated
``libftprintf.a`` by adding this library in your main.c file:
```C
#include "ft_printf.h"
```
The way you have to use it, is just the same way as the original printf function, **but**
instead of invocate the function as ``printf(".....");`` you have to add ``ft_`` right before
the *printf*: ``ft_printf(".....");``.
Practical example of use:
```C
ft_printf("Hello World!");
```
Then you can compile your main with my function with this command:
```
gcc main.c libftprintf.a && ./a.out
```
## Conclusion
This is just a project that I had to do in 42_School and it has been such a long way to finally
finished with everything correct.
