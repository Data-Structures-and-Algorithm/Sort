#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void insertion_sort(int* a, int size);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 4, -1, 22, 3, 0};
	
	printf("\nElements befor sorting...\n");
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
	int i, j;

	for (i = 1; i < size; i++) {
		int temp = a[i];
		for (j = i - 1; (j >= 0) && (a[j] > temp); j--) {
			a[j + 1] = a[j];
		}
		
		a[j + 1] = temp;	
	}
}

