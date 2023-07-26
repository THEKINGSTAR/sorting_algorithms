#include "sort.h"


/**
 * swap - function to swap tow elemnt in array
 *
 * @fe: the first ilment
 * @se: the elemet to swap with
 *
 * Return: fucntion has no return value
 */
void swap(int *fe, int *se)
{
	int tmp;

	tmp = *fe;
	*fe  = *se;
	*se  = tmp;
}
