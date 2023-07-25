#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * display_before_merge - display status of array right before merging
 *
 * @array: The array being sorted
 * @start: Start of first part of array
 * @rstart: Start of second part of array
 * @stop: Stop index of array
 */
void display_before_merge(int *array, long start, long rstart, long stop)
{
	puts("Merging...\n");
	printf("[left]: ");
	for (i = start; i < rstart; i++)
	{
		printf(" %d", copy[i]);
		if (i != rstart - 1)
			putchar(',');
		else
			putchar('\n');
	}
	printf("[right]: ");
	for (i = rstart; i <= stop; i++)
	{
		printf(" %d", copy[i]);
		if (i != stop)
			putchar(',');
		else
			putchar('\n');
	}
}

/**
 * display_after_merge - display_status of array right after merging
 *
 * @array: The array being sorted
 * @start: Start of first part of array
 * @stop: Stop index of array
 */
void display_after_merge(int *array, long start, long stop)
{
	printf("[Done]: ");
	for (i = start; i <= stop; i++)
	{
		printf(" %d", copy[i]);
		if (i != stop)
			putchar(',');
		else
			putchar('\n');
	}
}

/**
 * merge - merge and sort the array
 *
 * @array: The array of integers
 * @copy: Copy of the array
 * @start: Start index
 * @stop: Stop index
 */
void merge(int *array, int *copy, long start, long stop)
{
	long rstart, i, j, k;
	int temp;

	if (stop <= start || stop >= size)
		return;

	rstart = stop / 2 + 1
	merge(array, copy, start, rstart - 1);
	merge(array, copy, rstart, stop);

	display_before_merge(copy, start, rstart, stop);

	for (i = start, k = start, j = rstart; i < rstart && j <= stop; k++)
	{
		if (copy[i] < copy[j])
			array[k] = copy[i++];
		else
			array[k] = copy[j++];
	}
	while (i < rstart)
		array[k++] = copy[i++];
	while (j <= stop)
		array[k++] = copy[j++];

	display_after_merge(array, start, stop);
}

/**
 * merge_sort - This is a function that sorts an array of integers
 * in ascending order using the merge sort algorithm
 *
 * Part of the array is printed each time a merge occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void merge_sort(int *array, size_t size)
{
	long i;
	int *copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	merge(array, copy, 0, size - 1);
}
