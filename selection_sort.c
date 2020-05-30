#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void selection_sort(int a[], int size);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){11, 4, 2, 1, 0, -2};
	
	printf("\nElements befor sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	selection_sort(arr, size);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}



void selection_sort(int a[], int size)
{
	for (int i = 0; i < size - 1 ; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j] > a[max]) {
				max = j;
			}
		}
		if (i != max) {
			int temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}
}

