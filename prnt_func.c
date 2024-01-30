#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of characters
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, total = 0, ch = va_arg(ap, int);

	if (params->minusFlag)
		total += _putchar(ch);
	while (pad++ < params->width)
		total += _putchar(pad_char);
	if (!params->minusFlag)
		total += _putchar(ch);
	return (total);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of characters
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->lModifier)
		l = va_arg(ap, long);
	else if (params->hModifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, total = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minusFlag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	while (j++ < params->width)
		total += _putchar(pad_char);
	if (!params->minusFlag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	return (total);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of vharacters
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int total = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				total += _putchar('0');
			total += _puts(hex);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
