# printf

The printf project is a collaboration project by Tolulope Olanrewaju and Paul Iyiade, students of the ALX Software Engineering Programme organized by Holberton School, in which a function named "_printf" imitates the actual "printf" command located in the stdio.h library. It contains some of the basic features and functions found in the manual 3 of "printf".

`_printf` is a function that performs formatted output conversion and prints data.

The printf function sends formatted output to stdout. _printf function format string is a character string, beginning and ending in its initial shift state, if any. These arguments are placed using the percentage '%' operator

## Resources

https://www.academia.edu/10297206/Secrets_of_printf_

## Authorized functions and macros

write (man 2 write) 
malloc (man 3 malloc) 
free (man 3 free) 
va_start (man 3 va_start) 
va_end (man 3 va_end) 
va_copy (man 3 va_copy) 
va_arg (man 3 va_arg)

The main files will include your main header file (main.h): #include main.h

## Format Tags Prototype

The format tags prototype is the following:

```
%[flags][length]specifier
```

If the program runs successfully, the return value is the amount of chars printed.

## Specifiers and Outputs

| Specifier | Output                      |
|-----------|-------------------------------|
| `c`       | Character                    |
| `d` or `i`| Signed decimal integer       |
| `s`       | String of characters         |
| `b`       | Signed binary                |
| `o`       | Signed octal                 |
| `u`       | Unsigned integer             |
| `x`       | Unsigned hexadecimal         |
| `X`       | Unsigned hexadecimal (uppercase)|
| `p`       | Pointer address              |
| `r`       | Reverse string of characters |
| `R`       | ROT13 translation of string  |
| `S`       | String with special chars replaced by their ASCII value |
| `%`       | Character                    |

## Flags and Specifiers

| Flags   | Description                              | Specifiers   |
|---------|------------------------------------------|--------------|
| `+`     | Prints a plus sign (+) when the argument is a positive number. In other case, prints a minus sign (-). | `i`, `d` |
| `(space)`| Prints a blank space if the argument is a positive number | `i`, `d`   |
| `#`     | Prints 0, 0x, and 0X for o, x, and X specifiers, respectively. It doesn't print anything if the argument is zero. | `o`, `x`, `X` |

## Length and Specifiers

| Length  | Description                             | Specifiers  |
|---------|-----------------------------------------|-------------|
| `l`     | Prints a long int or unsigned long int  | `i`, `d`, `o`, `u`, `x`, `X` |
| `h`     | Prints a short int or unsigned short int| `i`, `d`, `o`, `u`, `x`, `X` |

## Examples

Printing the string of chars "Hello, Holberton":
```c
Use: _printf("Hello Hol%s.", "berton");
Output: Hello Holberton.
```

Printing an integer number:
```c
Use: _printf("10 + 10 is equal to %d.", 20);
Output: 10 + 10 is equal to 20.
```

Printing a binary, octal and hexadecimal:
```c
Use: _printf("10 in binary is [%b], in octal is [%o] and in hexadecimal is [%x]", 5, 5, 5);
Output: 10 in binary is [1010], in octal is [12] and in hexadecimal is [A]
```

Printing a string codified in ROT13:
```c
Use: _printf("Hello in ROT13 is %R", "Hello");
Output: Hello in ROT13 is Urybb
```

## Using Flags and Length Tags

Printing the string of chars "Hello, Holberton":
```c
Use: _printf("2 * 2 = %+d and 5 * -5 = %+i", 4, -25);
Output: 2 * 2 = +4 and 5 * -5 = -25
```

Printing a long integer number and short integer number:
```c
Use: _printf("1 million as a long int is %ld, but as a short int is %hd", 1000000, 1000000);
Output: 1 million as a long int is 1000000, but as a short int is 16960
```

## Tasks

0. Write a function that produces output according to a format. Handle the following conversion specifiers:
   - `%c`: Character
   - `%s`: String of characters
   - `%%`: Character (percent sign)

1. Handle the following conversion specifiers:
   - `%d` or `%i`: Signed decimal integer

2. Create a man page for the function.

3. Handle the following conversion specifier:
   - `%b`: Signed binary

4. Handle the following conversion specifiers:
   - `%u`: Unsigned integer
   - `%x`: Unsigned hexadecimal
   - `%o`: Unsigned octal
   - `%x`: Unsigned hexadecimal (uppercase)
   - `%X`: Unsigned hexadecimal (uppercase)

5. Use a local buffer of 1024 chars in order to call write as little as possible.

6. Handle the following custom conversion specifier:
   - `%S`: Prints the string.
     Non-printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (uppercase - always 2 characters).

7. Handle the following conversion specifier:
   - `%p`: Pointer address

8. Handle the following flag characters for non-custom conversion specifiers:
   - `+`: Prints a plus sign (+) when the argument is a positive number. In other cases, prints a minus sign (-).
   - `(space)`: If no sign is going to be written, a blank space is inserted before the value.
   - `#`: Used with o, x, or X specifiers, the value is preceded with 0, 0x, or 0X respectively for values different than zero.

9. Handle the following length modifiers for non-custom conversion specifiers:
    - `l`: Prints a long int or unsigned long int.
    - `h`: Prints a short int or unsigned short int.

10. Handle the field width for non-custom conversion specifiers.
    - `(number)`: Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces.

11. Handle the precision for non-custom conversion specifiers.
    - `.(number)`: For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s: this is the maximum number of characters to be printed. By default, all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed.

12.

 Handle the 0 flag character for non-custom conversion specifiers.
    - `0`: Left-pads the number with zeroes (0) instead of spaces when padding is specified.

13. Handle the - flag character for non-custom conversion specifiers.
    - `-`: Left-justifies the output within the field width.

14. Handle the following custom conversion specifier:
    - `%r`: Prints the reversed string.

15. Handle the following custom conversion specifier:
    - `%R`: Prints the ROT13'ed string.

16. All the above options work well together and should be correctly implemented to achieve the complete functionality of the custom `_printf` function.

## Authors

- Tolulope Olanrewaju
- Paul Iyiade
