# rationalize

Version 0.1

## What is this?

`rationalize` is a simple C program for converting real numbers to
fractions, with a specified level of precision. For example

    rationalize 0.1428
    1 / 7

The code demonstrates some interesting features of 
_continued fractions_.
For a detailed description of the mathematics used in this utility,
see https://kevinboone.me/rationalize.html.


## In the bundle 

There are two implementations of the rationalization method in the code
bundle: `rationalize.1.c` and `rationalize.2.c`. The first of these 
uses a floating-point method, the second an all-integer algorithm.
I've tried to keep the two implementations as similar as possible, so they
can be compared.

## Usage

    rationalizei {options} { _number_ | - }

If "-" is given rather than a number, the number is read from standard input.

`-i, --improper`

Output an improper ("top-heavy") fraction if the number converted is
greater than 1.

`-o, --order=N`

Specify the order of precision required. That is, provide the closest
fraction to the input that can be achieved by considering `order` figures
of the original number. The default is 3 figures, which typically outputs
fractions with up to three digits in the numerator and denominator.

Orders 0 and 1 are unlikely to be useful. Orders greater than 9 are
silently limited to 9 -- the data types used cannot accommodate larger
orders than this.

`-v, --version`

Show the version and copyright.

## Note

The conversion always succeeds. If there is no conversion of the input
number that lies within the specified precision, the program outputs the
fraction with the nearest value it can find.

## Legal and copyright

This code is copyright (c)2022 Kevin Boone, and is released under the terms
of the GNU Public Licence, v3.0. There is no warranty of any kind.

