#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - This is a function that sorts an array of integers
 * in ascending order using the selection sort algorithm
 *
 * The array is printed each time a swap occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, selected;
	int temp;

	for (i = 0; i < size; i++)
	{
		selected = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[selected])
			{
				selected = j;
			}
		}
		if (array[i] > array[selected])
		{
			temp = array[i];
			array[i] = array[selected];
			array[selected] = temp;
			print_array(array, size);
		}
	}
}
