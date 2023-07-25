#include "main.h"

/**
 * get_specifier - Find the format function based on specifier.
 * @s: String of the format specifiers.
 *
 * Return: Pointer to the corresponding format function or NULL if not found.
 */
int (*get_specifier(char *s))(va_list ap, parameters_t *parameters)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].e);
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - Find the format function based on format string.
 * @s: String of the format.
 * @ap: Argument pointer.
 * @parameters: Pointer to the parameters struct.
 *
 * Return: The number of bytes printed.
 */
int get_print_func(char *s, va_list ap, parameters_t *parameters)
{
	int (*f)(va_list, parameters_t *) = get_specifier(s);

	if (f)
		return (f(ap, parameters));
	return (0);
}

/**
 * get_flag - Find and set the specified flag.
 * @s: The format string.
 * @parameters: Pointer to the parameters struct.
 *
 * Return: 1 if the flag was valid and processed, otherwise 0.
 */
int get_flag(char *s, parameters_t *parameters)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = parameters->plus_flag = 1;
			break;
		case ' ':
			i = parameters->space_flag = 1;
			break;
		case '#':
			i = parameters->hashtag_flag = 1;
			break;
		case '-':
			i = parameters->minus_flag = 1;
			break;
		case '0':
			i = parameters->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - Find and set the specified modifier.
 * @s: The format string.
 * @parameters: Pointer to the parameters struct.
 *
 * Return: 1 if the modifier was valid and processed, otherwise 0.
 */
int get_modifier(char *s, parameters_t *parameters)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = parameters->h_modifier = 1;
			break;
		case 'l':
			i = parameters->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - Extract and set the width from the format string.
 * @s: The format string.
 * @parameters: Pointer to the parameters struct.
 * @ap: The argument pointer.
 *
 * Return: A new pointer to the format string after processing the width.
 */
char *get_width(char *s, parameters_t *parameters, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	parameters->width = d;
	return (s);
}

