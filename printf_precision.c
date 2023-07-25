#include "main.h"
/**
 * get_precision - Extracts the precision value from the format string.
 * @s: The format string to parse.
 * @parameters: Pointer to the parameters struct.
 * @ap: The argument pointer for variable arguments (va_list).
 *
 * Return: A new pointer to the format string after processing the precision.
 *
 * Description:
 * This function extracts the precision value from the format string 's' and
 * stores it in the 'precision' field of the 'parameters' struct for later use
 * during printing. The precision specifies the maximum number of characters
 * to be printed for strings or the number of digits to be displayed for
 * numeric types. The precision is indicated by the '.' character followed by
 * either a numeric value or a '*' (asterisk) that denotes the value should be
 * retrieved from a variable argument. The function returns a new pointer to
 * the format string after processing the precision, allowing the caller to
 * continue parsing the format string for other format options.
 */
char *get_precision(char *s, parameters_t *parameters, va_list ap)
{
	int precision = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		precision = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			precision = precision * 10 + (*s++ - '0');
	}
	parameters->precision = precision;
	return (s);
}
