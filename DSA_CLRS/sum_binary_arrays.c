#include <stdio.h>
#include <stdlib.h>
#define N 5
void add_binary_integers(int const a[N],int const  b[N], int c[N+1]);
int main(void){

	int a[N] = {1, 1, 1, 1, 1};
	int b[N] = {1, 1, 1, 1, 1};
	int c[N+1] = { 0, };

	add_binary_integers(&a[0], &b[0], &c[0]);
	for( int i = N; i >= 0; --i){
		printf("%d", c[i]);
	}
	puts("");
return EXIT_SUCCESS;
}
void add_binary_integers(int const a[N], int const b[N], int c[N+1]){

	for(int i = 0; i < N; ++i){
		c[i] = a[i] + b[i] + c[i];
		if (c[i] > 1){
			c[i] = c[i] - 2;
			c[i+1] += 1;
		}
	}

}
