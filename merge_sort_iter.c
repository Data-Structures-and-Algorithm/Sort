#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void merge_sort(int a[], int size);
void merge(int arr[], int start, int mid, int end);


int main(void) {

	int size = 10; 
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	
	printf("\nElements befor sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	merge_sort(arr, size);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}


void merge_sort(int a[], int size)
{

	for (int inc = 1; inc < size; inc *= 2) {
		for (int i = 0; i < (size - inc); i = i + (inc * 2)) {
			int mid = i + inc - 1;
			int end = i + (inc * 2) - 1;

			if (end > size - 1) {
				end = size - 1;
			}
			merge(a, i, mid, end);	
		}
	}
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
