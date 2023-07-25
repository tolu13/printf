#include "main.h"
/**
 * _printf - Prints formatted data to the standard output.
 * @format: The format string.
 * Return: The number of characters printed (excluding the null byte.
 */
int _printf(const char *format, ...)
{
	int total = 0;
	va_list ap;
	char *s, *start;

	parameters_t params = PARAMETERS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (s = (char *)format; *s; s++)
	{
		init_parameters(&params, ap);
		if (*s != '%')
		{
			total += _putchar(*s);
			continue;
		}
		start = s;
		s++;
		while (get_flag(s, &params))
		{
			s++;
		}
			s = get_width(s, &params, ap);
			s = get_precision(s, &params, ap);
		if (get_modifier(s, &params))
			s++;
		if (!get_specifier(s))
			total += print_from_to(start, s,
					params->l_modifier || params->h_modifier ?
					s - 1 : 0);
		else
			total += get_print_func(s, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (total);
}
