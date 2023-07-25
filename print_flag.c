#include "main.h"
/**
 * init_parameters - this initializes struct to default values
 * @parameters: pointer to the parameters struct
 * @ap: arguement pointer (unused in this function)
 * Return: void
 */
void init_parameters(parameters_t *parameters, va_list ap)
{
	parameters->unsign = 0;

	parameters->plus_flag = 0;
	parameters->space_flag = 0;
	parameters->hashtag_flag = 0;
	parameters->zero_flag = 0;
	parameters->minus_flag = 0;

	parameters->width  = 0;
	parameters->precision = UINT_MAX;

	parameters->h_modifier = 0;
	parameters->l_modifier = 0;
	(void)ap;
}
