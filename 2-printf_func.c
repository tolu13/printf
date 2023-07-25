#include "main.h"

/**
 * print_hex - Prints unsigned hexadecimal numbers in lowercase.
 * @ap: The argument pointer.
 * @parameters: The parameters of struct.
 *
 * Return: Number of bytes printed out.
 */
int print_hex(va_list ap, parameters_t *parameters)
{
	unsigned long l;
	int e = 0;
	char *str;

	if (parameters->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (parameters->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameters);
	if (parameters->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	parameters->unsign = 1;
	return (e += print_number(str, parameters));
}

/**
 * print_HEX - Prints unsigned hexadecimal numbers in uppercase.
 * @ap: The argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_HEX(va_list ap, parameters_t *parameters)
{
	unsigned long l;
	int e = 0;
	char *str;

	if (parameters->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (parameters->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, parameters);
	if (parameters->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	parameters->unsign = 1;
	return (e += print_number(str, parameters));
}

/**
 * print_binary - Prints unsigned binary number.
 * @ap: The argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_binary(va_list ap, parameters_t *parameters)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, parameters);
	int e = 0;

	if (parameters->hashtag_flag && n)
	{
		*--str = '0';
	}
	parameters->unsign = 1;
	return (e += print_number(str, parameters));
}

/**
 * print_octal - Prints unsigned octal numbers.
 * @ap: The argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_octal(va_list ap, parameters_t *parameters)
{
	unsigned long l;
	char *str;
	int e = 0;

	if (parameters->l_modifier)
	{
		l = (unsigned long)va_arg(ap, unsigned long);
	}
	else if (parameters->h_modifier)
	{
		l = (unsigned short int)va_arg(ap, unsigned int);
	}
	else
	{
		l = (unsigned int)va_arg(ap, unsigned int);
	}
	str = convert(l, 8, CONVERT_UNSIGNED, parameters);

	if (parameters->hashtag_flag && l)
		*--str = '0';
	parameters->unsign = 1;
	return (e += print_number(str, parameters));
}

