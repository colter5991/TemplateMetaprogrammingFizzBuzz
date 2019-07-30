# TemplateMetaprogrammingFizzBuzz
FizzBuzz at compile time with C++ template metaprogramming

## What?
"FizzBuzz" is a common toy programming example that involves 
printing the numbers 1 to 100 but with the following caveats:
- If a number is divisible by 3, print "Fizz" instead
- If a number is divisible by 5, print "Buzz" instead
- If a number is divisible by both 3 and 5, print "FizzBuzz"

This example uses C++ template metaprogramming to create a "FizzBuzz"
string literal at compile time.  At run time, the main function only needs
to print this string literal.

## Why?
Despite horrible compile times and hard to read code, this
has much less cost at runtime to compute the FizzBuzz string.

## How?
Run `make && ./FizzBuzz` and be amazed.