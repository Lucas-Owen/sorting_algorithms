#include <stddef.h>
#include "sort.h"

/**
 * shell_sort - This is a function that sorts an array of integers
 * in ascending order using the shell sort algorithm
 * The sort uses the Knuth sequence n * 3 + 1 => {1, 4, 13...}
 *
 * The array is printed each time the sequence decreases
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void shell_sort(int *array, size_t size)
{
	size_t step, i, j;
	int temp;

	if (!array)
		return;
	/* Compute the Knuth sequence */
	for (step = 1; step < size; step = step * 3 + 1)
	;
	for (step = (step - 1) / 3; step > 0; step = (step - 1) / 3)
	{
		for (i = step; i < size; i++)
		{
			j = i;
			while (j > step - 1 && array[j] < array[j - step])
			{
				temp = array[j];
				array[j] = array[j - step];
				array[j - step] = temp;
				j -= step;
			}
		}
		print_array(array, size);
	}
}
