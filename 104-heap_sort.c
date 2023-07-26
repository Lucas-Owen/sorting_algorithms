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
 * heapify - Maintain array as heap (as binary tree)
 * @array: The array
 * @start: start index
 * @size: Size of the array
 * @actualSize: Size of the array
 */
void heapify(int *array, long start, long size, long actualSize)
{
	int leftChild, rightChild, i;

	leftChild = 2 * start + 1;
	rightChild = 2 * start + 2;
	if (leftChild >= size)
		return;
	i = leftChild;
	if (rightChild < size)
		i = (array[leftChild] < array[rightChild] ? rightChild : leftChild);
	if (array[start] < array[i])
	{
		swapInt(&array[i], &array[start]);
		print_array(array, actualSize);
		heapify(array, i, size, actualSize);
	}
	return;
}

/**
 * sift_down - Brings the biggest element in the array to the top
 * (the array is treated as a binary tree)
 *
 * @array: The array
 * @size: Size of the unsorted part of the array
 * @actualSize: Size of the array
 * Return: void
 */
void sift_down(int *array, long size, long actualSize)
{
	int parent, k;
	int leftChild = -1, rightChild = -1;
	int start = size - 1;

	if (start % 2)
		leftChild = start;
	else
		rightChild = start;
	if (leftChild == -1)
		leftChild = rightChild - 1;
	else
		rightChild = leftChild + 1;
	for (; leftChild > 0; leftChild -= 2, rightChild -=2)
	{
		if (rightChild < size)
			k = (array[leftChild] > array[rightChild] ? leftChild : rightChild);
		else
			k = leftChild;
		parent = (leftChild - 1) / 2;
		if (array[parent] < array[k])
		{
			swapInt(&array[k], &array[parent]);
			print_array(array, actualSize);
			heapify(array, k, size, actualSize);
		}
	}
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

	if (size <= 1 || !array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sift_down(array, size - i, size);
		swapInt(&array[0], &array[size - i - 1]);
		print_array(array, size);
	}
}
