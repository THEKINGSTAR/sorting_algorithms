#include "sort.h"


/**
 * selection_sort - implementation bubble sort algorithm
 *
 * @array: input array
 * @size: size of the array
 *
 * Return: FUNCTION DO NOT RETURN
 */
void selection_sort(int *array, size_t size)
{
	size_t o_itr, i_itr;
	size_t tmp, min;

	for (o_itr = 0; o_itr < size - 1; o_itr++)
	{
		min = o_itr;
		for (i_itr = o_itr + 1; i_itr < size; i_itr++)
		{
			if (array[i_itr] < array[min])
			{
				min = i_itr;
			}
		}
		if (min != o_itr)
		{
			tmp = array[o_itr];
			array[o_itr] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}

}
