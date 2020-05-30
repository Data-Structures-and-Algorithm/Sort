#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

void q_sort(int* a, int start, int end);
int partition(int* a, int start, int end);
void swap(int *a, int i, int j);

int main(void) {

	int size = 6;
	int *arr = (int *)malloc(size * sizeof(int)); 
    arr = (int[]){1, 4, -1, 22, 3, 0};
	
	printf("\nElements befor sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	
	
	q_sort(arr, 0, size - 1);
	
	printf("\nElements after sorting...\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
    return 0;
}






void q_sort(int* a, int start, int end)
{
    if (start >= end) {
        return;
    }
    
    int pivot = partition(a, start, end);
    q_sort(a, start, pivot - 1);
    q_sort(a, pivot + 1, end);
}



int partition(int* a, int start, int end)
{
    int pivot = a[end];
    int pivot_index = start;
    for (int i =start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(a, i, pivot_index);
            pivot_index++;
        }
    }
    
    swap(a, pivot_index, end);
     
	return pivot_index;
}

void swap(int *a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
