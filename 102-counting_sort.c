#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - This is a function that sorts an array of integers
 * in ascending order using the counting sort algorithm
 *
 * The counting array is printed once it is set up
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted and copied to the original)
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array;
	int i, j, k, max = -1;

	if (size <= 1 || !array)
		return;
	for (i = 0; i < (long) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < (long) size; i++)
		counting_array[array[i]]++;
	for (i = 0; i < max; i++)
		counting_array[i + 1] += counting_array[i];
	print_array(counting_array, max + 1);
	k = 0;
	for (i = 0; i <= max; i++)
	{
		j = counting_array[i] - (i > 0 ? counting_array[i - 1] : 0);
		for (; j > 0; j--)
		{
			array[k] = i;
			k++;
		}
	}
	free(counting_array);
}
