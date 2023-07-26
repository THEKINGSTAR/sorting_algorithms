#include "sort.h"

void quick_sort_recursion(int *array, int low, int high, size_t size);
int lomuto_partitio(int *array, int low, int high, size_t size);

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


/**
 * quick_sort - implementation quick sort algorithm
 *
 * @array: input array
 * @size: size of the array
 *
 * Return: FUNCTION DO NOT RETURN
 */
void quick_sort(int *array, size_t size)
{
	/* printf("ARRAY SIZE IS : %ld\n", size); */
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - implementation quick sort algorithm
 *
 * @array: input array
 * @size: size of the array
 * @high: last index of the array
 * @low: frist index of the array
 *
 * Return: FUNCTION DO NOT RETURN value
 */

void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_idx - 1, size);
		quick_sort_recursion(array, pivot_idx + 1, high, size);
	}
}

/**
 * lomuto_partition - implementation lomuto_partition scheme
 *
 * @array: input array
 * @high: last index of the array
 * @low: frist index of the array
 * @size: size of the array
 *
 * Return: index for the new pivot elment
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}
