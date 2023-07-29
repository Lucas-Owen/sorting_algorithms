#include <stdlib.h>
#include "sort.h"

/**
 * fill_2Darray - Fills a 2D (10 * size) array with -1
 * @array: The array
 * @size: Size of arrays in *array
 * Return: void
 */
void fill_2Darray(int **array, size_t size)
{
	size_t i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < size && array[i][j] != -1; j++)
		{
			array[i][j] = -1;
		}
	}
}

/**
 * free_array - Free memory for a 2D array
 * @array: Malloced 2D array
 * @size: Size
 * Return: void
 */
void free_array(int **array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**
 * allocate_array - Allocate memory for a 2D array
 * @m: Size
 * @size: Size
 * Return: int**
 */
int **allocate_array(size_t m, size_t size)
{
	int **count_array = malloc(sizeof(int *) * m);
	size_t i;

	if (!count_array)
		return (NULL);
	for (i = 0; i < m; i++)
	{
		count_array[i] = malloc(sizeof(int) * size);
		if (!count_array[i])
		{
			while (i > 0)
			{
				i--;
				free(count_array[i]);
			}
			free(count_array);
			return (NULL);
		}
	}
	return (count_array);
}

/**
 * radix_sort - This is a function that sorts an array of integers
 * in ascending order using the radix sort algorithm
 *
 * The array is printed each time a swap occurs
 *
 * @array: Input array of integers
 * @size: Size of the array of integers
 * Returns: void (the array is sorted in-place)
 */
void radix_sort(int *array, size_t size)
{
	int **count_array;
	size_t i, j, k, significant_digit = 1, val;
	int finished = 0;

	if (!array || size <= 1)
		return;
	count_array = allocate_array(10, size);
	if (!count_array)
		return;
	fill_2Darray(count_array, size);
	while (!finished)
	{
		finished = 1;
		for (i = 0; i < size; i++)
		{
			val = (array[i] / significant_digit) % 10;
			if (array[i] / significant_digit * 10 > 0)
				finished = 0;
			for (j = 0; count_array[val][j] != -1; j++)
				;
			count_array[val][j] = array[i];
		}
		if (finished)
			break;
		k = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; k < size && count_array[i][j] != -1; j++)
			{
				array[k++] = count_array[i][j];
			}
		}
		fill_2Darray(count_array, size);
		print_array(array, size);
		significant_digit *= 10;
	}
	free_array(count_array, 10);
}
