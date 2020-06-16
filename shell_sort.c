/* Shell sort is a modified insertion sort with a higher gap value */

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void shell_sort(int* a, int size);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 4, -1, 22, 3, 0};
	
	printf("\nElements before sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	shell_sort(arr, size);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}



void shell_sort(int* a, int size)
{	
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int j = i - gap;
			int temp = a[i];
			while ((j >= 0) && (a[j] > temp)) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = temp;	
		}
	}
}

