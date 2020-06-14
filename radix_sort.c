/* Radix sort make use of count sort by applying the count */
/* to each individual digit starting from LSB */

#include <stdio.h>
#include <stdlib.h>

#define RADIX 10


void radix_sort(int arr[], int size);
void count_sort(int arr[], int size, int pos);
void print_array(int arr[], int size);
int find_max(int arr[], int size);


int main()
{
	int arr[] = {62, 90, 61, 92, 74, 70, 90, 61, 82, 61, 71, 74, 61};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Array before sorting:\n");
	print_array(arr, size);
	radix_sort(arr, size);
	printf("Array after sorting:\n");
	print_array(arr, size);
	return 0;
}

void radix_sort(int arr[], int size)
{
	/* No.of iterations is determined by no.of digits of max number */
	int max = find_max(arr, size);

	for (int pos = 1; max/pos > 0; pos *= 10) {
		count_sort(arr, size, pos);
	}	
}

void count_sort(int arr[], int size, int pos)
{
	int count_array_size = RADIX;
	/* Use calloc to 0 initialize the count array */
	int *count = calloc( count_array_size, sizeof(arr[0]));

	/* Count no.of occurances of each digit in arr */
	for (int i = 0; i < size; i++) {
		/* Find number corresponding to number in arr and increment */
		int digit = (arr[i] / pos) % 10;
		count[digit]++;
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
		int digit = (arr[i] / pos) % 10;
		temp[--count[digit]] = arr[i];
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
