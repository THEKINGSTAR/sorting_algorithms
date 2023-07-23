#include "sort.h"


/**
 * bubble_sort - implementation bubble sort algorithm
 *
 * @array: input array
 * @size: size of the array
 *
 * Return: FUNCTION DO NOT RETURN
 */
void bubble_sort(int *array, size_t size)
{
	size_t o_itr, i_itr;
	int tmp;

	for (o_itr = 0; o_itr < size; o_itr++)
	{
		for (i_itr = 0; i_itr < size - 1; i_itr++)
		{
			if (array[i_itr] > array[i_itr + 1])
			{
				tmp = array[i_itr];
				array[i_itr] = array[i_itr + 1];
				array[i_itr + 1] = tmp;
				print_array(array, size);
			}
		}
	}

}
