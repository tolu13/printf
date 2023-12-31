#ifndef _PRINTF__H
#define _PRINTF__H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE (1024)
#define BUF_FLUSH (-1)

#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"
#define PARAMETERS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 	1
#define CONVERT_UNSIGNED 	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} parameters_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*e)(va_list, parameters_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);


int print_char(va_list ap, parameters_t *parameters);
int print_int(va_list ap, parameters_t *parameters);
int print_string(va_list ap, parameters_t *parameters);
int print_percent(va_list ap, parameters_t *parameters);
int print_S(va_list ap, parameters_t *parameters);


char *convert(long int num, int base, int flags, parameters_t *parameters);
int print_unsigned(va_list ap, parameters_t *parameters);
int print_address(va_list ap, parameters_t *parameters);


int (*get_specifier(char *s))(va_list ap, parameters_t *parameters);
int get_print_func(char *s, va_list ap, parameters_t *parameters);
int get_flag(char *s, parameters_t *parameters);
int get_modifier(char *s, parameters_t *parameters);
char *get_width(char *s, parameters_t *parameters, va_list ap);

int print_hex(va_list ap, parameters_t *parameters);
int print_HEX(va_list ap, parameters_t *parameters);
int print_binary(va_list ap, parameters_t *parameters);
int print_octal(va_list ap, parameters_t *parameters);


int print_from_to(char *S1, char *S2, char *except);
int print_rev(va_list ap, parameters_t *parameters);
int print_rot13(va_list ap, parameters_t *parameters);

int _isdigit(int e);
int _strlen(char *s);
int print_number(char *str, parameters_t *parameters);
int print_number_right_shift(char *str, parameters_t *parameter);
int print_number_left_shift(char *str, parameters_t *parameter);

void init_parameters(parameters_t *parameters, va_list ap);

char *get_precision(char *p, parameters_t *parameters, va_list ap);

int _printf(const char *format, ...);

#endif /*_MAIN_H_*/
