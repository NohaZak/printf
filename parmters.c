#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unSign = 0;

	params->plusFlag = 0;
	params->spaceFlag = 0;
	params->hashtagFlag = 0;
	params->zeroFlag = 0;
	params->minusFlag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->hModifier = 0;
	params->lModifier = 0;
	(void)ap;
}
