#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void insertion_sort(int* a, int size);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 4, -1, 22, 3, 0};
	
	printf("\nElements before sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	insertion_sort(arr, size);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}



void insertion_sort(int* a, int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int temp = a[i];
		while ((j >= 0) && (a[j] > temp)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;	
	}
}

