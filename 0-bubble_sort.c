#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - This is a function that sorts an array of integers
 * in ascending order using the bubble sort algorithm
 *
 * The array is printed each time a swap occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
