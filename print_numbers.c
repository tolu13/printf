#include "main.h"
/**
 * _isdigit - Checks if a character is a digit (0-9).
 * @e: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int e)
{
	return (e >= '0' && e <= '9');
}
/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: The integer length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_number - Prints a number with formatting options.
 * @str: The base number as a string.
 * @parameters: The parameter struct containing formatting options.
 *
 * Return: The number of characters printed.
 */
int print_number(char *str, parameters_t *parameters)
{
	unsigned int i = _strlen(str);
	int neg = (!parameters->unsign && *str == '-');

	if (!parameters->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (parameters->precision != UINT_MAX)
		while (i++ < parameters->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!parameters->minus_flag)
		return (print_number_right_shift(str, parameters));
	else
		return (print_number_left_shift(str, parameters));
}
/**
 * print_number_right_shift - Prints a number with right alignment.
 * @str: The base number as a string.
 * @parameter: The parameter struct containing formatting options.
 * Return: The number of characters printed.
 */
int print_number_right_shift(char *str, parameters_t *parameter)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (parameter->zero_flag && !parameter->minus_flag)
		pad_char = '0';
	neg = neg2 = (!parameter->unsign && *str == '-');
	if (neg && i < parameter->width && pad_char == '0' && !parameter->minus_flag)
		str++;
	else
		neg = 0;
	if ((parameter->plus_flag && !neg2) ||
		(!parameter->plus_flag && parameter->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (parameter->plus_flag && !neg2 && pad_char == '0' && !parameter->unsign)
		n += _putchar('+');
	else if (!parameter->plus_flag && parameter->space_flag && !neg2 &&
		!parameter->unsign && parameter->zero_flag)
		n += _putchar(' ');
	while (i++ < parameter->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (parameter->plus_flag && !neg2 && pad_char == ' ' && !parameter->unsign)
		n += _putchar('+');
	else if (!parameter->plus_flag && parameter->space_flag && !neg2 &&
		!parameter->unsign && !parameter->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_number_left_shift - Prints a number with left alignment.
 * @str: The base number as a string.
 * @parameter: The parameter struct containing formatting options.
 *
 * Return: The number of characters printed.
 */
int print_number_left_shift(char *str, parameters_t *parameter)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (parameter->zero_flag && !parameter->minus_flag)
		pad_char = '0';
	neg = neg2 = (!parameter->unsign && *str == '-');
	if (neg && i < parameter->width && pad_char == '0' && !parameter->minus_flag)
		str++;
	else
		neg = 0;
	if (parameter->plus_flag && !neg2 && !parameter->unsign)
		n += _putchar('+'), i++;
	else if (parameter->space_flag && !neg2 && !parameter->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < parameter->width)
		n += _putchar(pad_char);
	return (n);
}

