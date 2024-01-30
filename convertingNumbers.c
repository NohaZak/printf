#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->lModifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hModifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONV_UNSIGNED | CONV_LOWER, params);
	if (params->hashtagFlag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unSign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->lModifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hModifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONV_UNSIGNED, params);
	if (params->hashtagFlag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unSign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONV_UNSIGNED, params);
	int c = 0;

	if (params->hashtagFlag && n)
		*--str = '0';
	params->unSign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->lModifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->hModifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONV_UNSIGNED, params);

	if (params->hashtagFlag && l)
		*--str = '0';
	params->unSign = 1;
	return (c += print_number(str, params));
}
