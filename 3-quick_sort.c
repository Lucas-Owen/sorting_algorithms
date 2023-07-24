#include <stddef.h>
#include "sort.h"

/**
 * partition - Uses the Lomuto partioning scheme in sorting sections
 * of an array in-place
 *
 * @array: The array of integers
 * @start: Start index
 * @stop: Stop index
 * @size: Size of the array (for printing)
 */
void partition(int *array, long start, long stop, size_t size)
{
	long pivot = stop;
	long i = start, j = start;
	int temp;

	if (stop <= start)
		return;
	while (array[i] < array[pivot] && i < pivot)
		i++;
	j = i + 1;
	while (j <= stop)
	{
		while (array[i] < array[pivot] && i < pivot)
			i++;
		while (array[j] >= array[pivot] && j <= stop)
			j++;
		if (j <= stop)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
	if (array[i] > array[pivot])
	{
		temp = array[i];
		array[i] = array[pivot];
		array[pivot] = temp;
		print_array(array, size);
		pivot = i;
	}

	partition(array, start, pivot - 1, size);
	partition(array, pivot + 1, stop, size);
}

/**
 * quick_sort - This is a function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 *
 * The array is printed each time a swap occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}
