#include "main.h"
/**
 * print_from_to - Prints a range of char addresses.
 * @S1: Starting address.
 * @S2: Stopping address.
 * @except: Except address.
 *
 * Return: Number of bytes printed.
 */
int print_from_to(char *S1, char *S2, char *except)
{
	int total = 0;

	while (S1 <= S2)
	{
		if (except != S1)
			total += _putchar(*S1);
		S1++;
	}
	return (total);
}
/**
 * print_rev - Prints a string in reverse.
 * @ap: String.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_rev(va_list ap, parameters_t *parameters)
{
	int len, total = 0;
	char *str = va_arg(ap, char *);
	(void)parameters;
	if (str)
	{
		for (len = 0; *str; str++)
		len++;
		str--;
		for (; len > 0; len--, str--)
		total += _putchar(*str);
	}
	return (total);
}
/**
 * print_rot13 - Prints a string in ROT13.
 * @ap: String.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_rot13(va_list ap, parameters_t *parameters)
{
	int i, index;
	int total = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)parameters;
	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		|| (a[i] >= 'a' && a[i] <= 'z'))
	{
		index = a[i] - 65;
		total += _putchar(arr[index]);
	}
	else
		total += _putchar(a[i]);
	i++;
	}
	return (total);
}

