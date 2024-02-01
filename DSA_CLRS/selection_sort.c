#include <stdio.h>
#include <stdlib.h>

int main(void){
	int arr[10] = { 34, 6, 85, 63, 6, 0, 4, 5467, 34, 54 };

	for (int i = 0; i < 9; ++i){
		int min = i;
		for (int j = i+1; j < 10; ++j){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		int temp = arr[i];
	 	arr[i] = arr[min];
		arr[min] = temp;	
	}

	for(int i = 0; i < 10; ++i)
		printf("%d\n", arr[i]);
return EXIT_SUCCESS;
}
