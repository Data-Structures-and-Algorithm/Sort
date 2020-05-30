#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void merge_sort(int a[], int start, int end);
void merge(int arr[], int start, int mid, int end);


int main(void) {

	int size = 5;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 10, 5, 2, 1};
	
	printf("\nElements befor sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	merge_sort(arr, 0, size - 1);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}


void merge_sort(int a[], int start, int end)
{
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	merge_sort(a, start, mid);
	merge_sort(a, mid + 1, end);
	merge(a, start, mid, end);	
}



void merge(int arr[], int start, int mid, int end)
{
	int *temp = (int *)malloc(((end - start) + 1) * sizeof(int));
	

	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	
	
	while (i <= mid) {
			temp[k++] = arr[i++];
	}

	while (j <= end) {
			temp[k++] = arr[j++];
	}
	
	for (i = start; i < k; i++) {
		arr[i] = temp[i];
	}

}
