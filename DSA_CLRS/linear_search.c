#include <stdio.h>
#include <stdlib.h>

int main(void){

	int key;
	int index = -1;
	int arr[10] = {4, 36, 7465, 32, -34, 0 ,234, 654, 45, 45};

	printf("Give key: ");
	scanf("%d" ,&key);

	for (int i = 0; i < 10; ++i){
		if (key == arr[i])	index = i;
	}
	if (-1 != index){
		printf("Key %d was found at index %d\n", key, index);
	}
	else{
		puts("Key wasn't found");
	}


return EXIT_SUCCESS;
}
