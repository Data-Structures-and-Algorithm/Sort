#include <stdio.h>
#include <stdlib.h>

void count_sort(int arr[], int size, int min, int max);
void print_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);


int main()
{
	int arr[] = {62, 90, 61, 92, 74, 70, 90, 61, 82, 61, 71, 74, 61};
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
	int *count = malloc( count_array_size * sizeof(arr[0]));

	/* Count no.of occurances of each number in arr */
	for (int i = 0; i < size; i++) {
		/* Find number corresponding to number in arr and increment */
		count[arr[i] - min]++;
	}

	int j = 0;
	/* Count and update original array with sorted content */
	for (int i = 0; i < count_array_size; i++) {
		while (count[i]--) {
			arr[j++] = i + min;
		}
	}
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
