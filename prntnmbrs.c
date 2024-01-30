#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int a)
{
	return (a >= '0' && a <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int o = 0;

	while (*s++)
		o++;
	return (o);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unSign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minusFlag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zeroFlag && !params->minusFlag)
		pad_char = '0';
	neg = neg2 = (!params->unSign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minusFlag)
		str++;
	else
		neg = 0;
	if ((params->plusFlag && !neg2) ||
		(!params->plusFlag && params->spaceFlag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plusFlag && !neg2 && pad_char == '0' && !params->unSign)
		n += _putchar('+');
	else if (!params->plusFlag && params->spaceFlag && !neg2 &&
		!params->unSign && params->zeroFlag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plusFlag && !neg2 && pad_char == ' ' && !params->unSign)
		n += _putchar('+');
	else if (!params->plusFlag && params->spaceFlag && !neg2 &&
		!params->unSign && !params->zeroFlag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zeroFlag && !params->minusFlag)
		pad_char = '0';
	neg = neg2 = (!params->unSign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minusFlag)
		str++;
	else
		neg = 0;

	if (params->plusFlag && !neg2 && !params->unSign)
		n += _putchar('+'), i++;
	else if (params->spaceFlag && !neg2 && !params->unSign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
