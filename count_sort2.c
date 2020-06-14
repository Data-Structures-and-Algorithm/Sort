/* Stable version of count_sort by updating count array */
/* Reference: https://www.youtube.com/watch?v=pEJiGC-ObQE */

#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void count_sort(int arr[], int size, int min, int max);
void print_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);


int main()
{
	int arr[] = {62, 90, 61, 92, 74, 70, 90, 61, 82, 61, 71, 74, 61};
	// Test Array2 int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};	
	int size = sizeof(arr) / sizeof(arr[0]);
	int min = find_min(arr, size);
	int max = find_max(arr, size);
	
	printf("Array before sorting:\n");
	print_array(arr, size);
	count_sort(arr, size, min, max);
	printf("Array after sorting:\n");
	print_array(arr, size);
	return 0;
}

void count_sort(int arr[], int size, int min, int max)
{
	int count_array_size = max - min + 1;
	/* Use calloc to 0 initialize the count array */
	int *count = calloc( count_array_size, sizeof(arr[0]));

	/* Count no.of occurances of each number in arr */
	for (int i = 0; i < size; i++) {
		/* Find number corresponding to number in arr and increment */
		count[arr[i] - min]++;
	}


#ifdef DEBUG
	printf("\nCount array before udating:\n");
	for (int i = 0; i < count_array_size; i++) {
		printf("%d ", count[i]);
	}
	printf("\n");
#endif

	/* Update count array */
	for (int i = 1; i < count_array_size; i++) {
			count[i] += count[i - 1];
	}

#ifdef DEBUG
	printf("\nCount array after udating:\n");
	for (int i = 0; i < count_array_size; i++) {
		printf("%d ", count[i]);
	}
	printf("\n");
#endif

	/* Update pseudo array with actual position for sorting */
	int *temp = malloc(size * sizeof(arr[0]));
	for (int i = size - 1; i >= 0; i--) {
		temp[--count[arr[i] - min]] = arr[i];
	}
	
	/* Copy pseudo array to original array */
	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}

	free(count);
	free(temp);
}


void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int find_max(int arr[], int size)
{
	int max = arr[0];
    
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;

}

int find_min(int arr[], int size)
{
	int min = arr[0];
    
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;

}
