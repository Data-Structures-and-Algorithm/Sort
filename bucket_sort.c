#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node_t;

void bucket_sort(int arr[], int size, int min, int max);
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
	bucket_sort(arr, size, min, max);
	printf("Array after sorting:\n");
	print_array(arr, size);
	return 0;
}

void bucket_sort(int arr[], int size, int min, int max)
{
	/* Ocuurances of elements are stored as array of linked list */
	int bucket_array_size = max - min + 1;
	Node_t **bucket = (Node_t **)malloc(bucket_array_size * sizeof(Node_t *));

	/* Count no.of occurances of each number in arr */
	for (int i = 0; i < size; i++) {
		Node_t *temp = malloc(1 * sizeof(Node_t));
		temp->value = arr[i];
		temp-> next = NULL;
		
		if (bucket[arr[i] - min] == NULL) {
			bucket[arr[i] - min] = temp;	
		} else {
			temp->next = bucket[arr[i] - min];
			bucket[arr[i] - min] = temp;
		}
	}

	int j = 0;
	/* Count and update original array with sorted content */
	for (int i = 0; i < bucket_array_size; i++) {
		Node_t *temp = bucket[i];

		while (temp) {
			arr[j++] = temp->value;
			temp = temp->next;
		}
	}

	for (int i = 0; i < bucket_array_size; i++) {
		if (bucket[i]) {
			free(bucket[i]);
		}
	}
	free(bucket);
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
