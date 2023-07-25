#include "main.h"
/**
 * print_char - Prints a character
 * @ap: Argument pointer
 * @parameters: The parameters struct
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap, parameters_t *parameters)
{
	char pad_char = ' ';
	unsigned int pad = 1, total = 0, ch = va_arg(ap, int);

	if (parameters->minus_flag)
		total += _putchar(ch);
	while (pad++ < parameters->width)
		total += _putchar(pad_char);
	if (!parameters->minus_flag)
		total += _putchar(ch);
	return (total);
}
/**
 * print_int - Prints an integer
 * @ap: Argument pointer
 * @parameters: The parameters struct
 *
 * Return: Number of characters printed
 */
int print_int(va_list ap, parameters_t *parameters)
{
	long l;

	if (parameters->l_modifier)
		l = va_arg(ap, long);
	else if (parameters->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, parameters), parameters));
}
/**
 * print_string - Prints a string
 * @ap: Argument pointer
 * @parameters: The parameters struct
 *
 * Return: Number of characters printed
 */
int print_string(va_list ap, parameters_t *parameters)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, total = 0, i = 0, j;
	(void)parameters;
	switch ((int)(!str))
	{
	case 1:
		str = NULL_STRING;
	}
	j = pad = _strlen(str);
	if (parameters->precision < pad)
		j = pad = parameters->precision;
	if (parameters->minus_flag)
	{
		if (parameters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	while (j++ < parameters->width)
		total += _putchar(pad_char);
	if (!parameters->minus_flag)
	{
		if (parameters->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	return (total);
}
/**
 * print_percent - Prints a percent character
 * @ap: Argument pointer
 * @parameters: The parameters struct
 *
 * Return: Number of characters printed
 */
int print_percent(va_list ap, parameters_t *parameters)
{
	(void)ap;
	(void)parameters;
	return (_putchar('%'));
}
/**
 * print_S - Custom format specifier for non-printable characters
 * @ap: Argument pointer
 * @parameters: The parameters struct
 *
 * Return: Number of characters printed
 */
int print_S(va_list ap, parameters_t *parameters)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int total = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			hex = convert(*str, 16, 0, parameters);
			if (!hex[1])
				total += _putchar('0');
			total += _puts(hex);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
