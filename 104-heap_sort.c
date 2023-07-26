#include <stddef.h>
#include "sort.h"

/**
 * swapInt - swapInt two integers
 *
 * @a: The first integer
 * @b: The second integer
 */
void swapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Brings the biggest element in the array to the top
 * (the array is treated as a binary tree)
 *
 * @array: The array
 * @start: Start index of creating the max heap
 * @size: Size of the unsorted portion of the array
 * @actualSize: Size of the array (for printing)
 * Return: int - index of greater sibling, -1 when past the array size
 */
int sift_down(int *array, int start, long size, size_t actualSize)
{
	int i, j, k;

	if (start >= size)
		return (-1);
	i = sift_down(array, 2 * start + 1, size, actualSize);
	j = sift_down(array, 2 * start + 2, size, actualSize);
	if (i == -1)
		return (start);
	else if (j == -1)
		k = i;
	else
		k = (array[i] > array[j] ? i : j);
	if (array[start] < array[k])
	{
		swapInt(&array[k], &array[start]);
		print_array(array, actualSize);
		sift_down(array, start, size, actualSize);
	}
	return (start);
}

/**
 * heap_sort - This is a function that sorts an array of integers
 * in ascending order using the heap sort algorithm
 *
 * The array is printed each time a swap occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void heap_sort(int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size - 1; i++)
	{
		sift_down(array, 0, size - i, size);
		swapInt(&array[0], &array[size - i - 1]);
		print_array(array, size);
	}
}
