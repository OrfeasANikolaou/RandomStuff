#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int front, int mid, int rear);
void merge_sort(int *arr, int front, int rear);
int main(void){
	int arr[] = { 45, 0 , 54, 45};

	merge_sort(&arr[0], 0, 3);

	for (int i = 0; i < 4; ++i){
		printf("%d\n", arr[i]);
	}

	return EXIT_SUCCESS;
}
void merge_sort(int *arr, int front, int rear){
	if (front >= rear) return;
	int mid = front + (rear - front) / 2;
		merge_sort(arr, front, mid);                 // Sort left half
    merge_sort(arr, mid + 1, rear);             // Sort right half
    merge(arr, front, mid, rear);     
}
void merge(int *arr, int front, int mid, int rear){

	int size_left = mid - front + 1;
	int size_right = rear - mid;

	int* arr_l = malloc(sizeof(int) * size_left);
	int* arr_r = malloc(sizeof(int) * size_right);
	for (int i = 0; i < size_left; ++i){
		arr_l[i] = arr[front + i];
	}
	for (int j = 0; j < size_right; ++j){
		arr_r[j] = arr[mid + j + 1];
	}

	int i = 0;
	int j = 0;
	int k = front;
	
	while (i < size_left 
			&& j < size_right){
		if (arr_l[i] < arr_r[j]){
					arr[k++] = arr_l[i++];
		}
		else{
			arr[k++] = arr_r[j++];
		}
	}
	
	while (i < size_left){
		arr[k++] = arr_l[i++];
	}
	while (j < size_right){
		arr[k++] = arr_r[j++];
	}

	free(arr_l);
	free(arr_r);
}
