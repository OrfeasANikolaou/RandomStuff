#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main(void){

  int arr[10] = { -34, -32, -1, 0, 12, 213, 3245, 34536, 3455545, 34534534 };
	int front = 0;
	int rear = 9;
	int key;
	bool found = 0;
	int pos;
	printf("Enter key: ");
	scanf("%d", &key);
	
	while (!found && front <= rear ){
		pos = front + (rear - front) / 2;
	  if (arr[pos] == key){
			found = true;
		}
		else if (arr[pos] > key){
			rear = pos-1;
		}
		else { //if arr[pos] < key
			front = pos+1;
		}
	}

	if (found){
		printf("key \"%d\" was found at index [%d]\n", key, pos);
	}
	else{
		printf("key \"%d\" was not found\n", key);
	}

return EXIT_SUCCESS;
}

