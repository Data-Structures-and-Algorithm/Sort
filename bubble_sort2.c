#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void b_sort(int* a, int size);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 4, -1, 22, 3, 0};
	
	printf("\nElements befor sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	b_sort(arr, size);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
    return 0;
}



void b_sort(int* a, int size)
{
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

