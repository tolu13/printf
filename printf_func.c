#include "main.h"

/**
 * _printf - Prints formatted data to the standard output (stdout).
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings). On error, it returns -1.
 */
int _printf(const char *format, ...)
{
	int total = 0;
	va_list ap;
	parameters_t params, start;

	params = PARAMS_INIT;
	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (start = params; *format; format++)
	{
		init_parameters(&params, ap);

		if (*format != '%')
		{
			total += _putchar(*format);
			continue;
		}

		start = format;
		format = handle_format_specifier(format, &params, &total, ap);
	}

	_putchar(BUF_FLUSH);

	va_end(ap);
	return (total);
}

/**
 * handle_format_specifier - Handles and print the format specifier.
 * @format: The format specifier.
 * @params: The parameters_t struct containing format information.
 * @total: A pointer to the total number of characters printed.
 * @ap: The va_list of arguments.
 *
 * Return: A pointer to the next character after the format specifier.
 */
const char *handle_format_specifier(const char *format,
				    parameters_t *params, int *total,
				    va_list ap)
{
	format++;
	while (get_flag(format, params))
		format++;

	format = get_width(format, params, ap);
	format = get_precision(format, params, ap);

	if (get_modifier(format, params))
		format++;

	if (!get_specifier(format))
		*total += print_from_to(start, format,
				       params->l_modifier || params->h_modifier ?
				       format - 1 : 0);
	else
		*total += get_print_func(format, ap, params);

	return (format);
}

