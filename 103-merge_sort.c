#include "sort.h"

/**
 * merge - merge the sorted array
 *
 * @arr: input array
 * @mid: the middle of the array
 * @end: last index of the array
 * @start: frist index of the array
 *
 * Return: FUNCTION DO NOT RETURN value
 */

void merge(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 1;
	int size2 = end - mid;       
    int LeftArray[size1];
    int rightArray[size2];
    int i, j, k = start;

    
    for (i = 0; i < size1; i++)
    {
        LeftArray[i] = arr[start + i];
    }

    for (j = 0; j < size2; j++)
    {
        rightArray[j] = arr[mid+1+j];
    }

    /* merge arrys sorted */
    while (i < size1 && j < size2)
    {
        if (LeftArray[i] < rightArray[j])
        {
            arr[k] = LeftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* copy remaining elemnt in left arry */
    while(i < size1)
    {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }
    /* copy remaining elemnt in right arry */
    while (j < size2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

}

/**
 * mergeSrot - implementation merge Srot algorithm
 *
 * @arr: input array
 * @end: last index of the array
 * @start: frist index of the array
 *
 * Return: FUNCTION DO NOT RETURN value
 */
void mergeSrot(int arr[], int start , int end)
{
    int mid = start + ( end - start ) / 2;

    if (start == end)
        return;

    mergeSrot(arr, start, mid);
    mergeSrot(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

/**
 * merge_sort - implementation merge sort algorithm
 *
 * @array: input array
 * @size: size of the array
 *
 * Return: FUNCTION DO NOT RETURN value
 */
void merge_sort(int *array, size_t size)
{
        mergeSrot(array, 0, size);
}
