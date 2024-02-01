#include <stdio.h>
#include <stdlib.h>
void matrix_multiplication(int len, int m1[len][len], 
																		int m2[len][len], 
																		int ret[len][len]);
void print_matrix(int len, int matrix[len][len]);
int main(void){

	int m1[5][5] = {{54, 65,  2, 634,  0,},
							 		{54,  5, 75,  76, 76,},
							 		{43,  0, 34,   1,  1,},
							 		{43, 54, 65,  56,  65},
							 		{43, 54, 65,  76,   8} };
	int m2[5][5] = {{65,  6,  0,  56, 345},
									{1,   3,  5,  45,   1},
									{35,  5,  2,   2,   1},
									{ 1, 43, 10,   1,   9},
									{43, 54, 45,   2,  43} };


	int matrix[5][5]= { 0 };
	matrix_multiplication(5, &m1[0], &m2[0], &matrix[0]);
	print_matrix(5, &matrix[0]);


	return EXIT_SUCCESS;
}
void matrix_multiplication(int len, int m1[len][len], 
																		int m2[len][len], 
																		int ret[len][len]){

	for (int i = 0; i < len; ++i){
		for (int j = 0; j < len; ++j){
			ret[i][j] = 0;
			for (int k = 0; k < len; ++k){
				ret[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

}

void print_matrix(int len, int matrix[len][len]){

	for (int i = 0; i < len; ++i){
		for (int j = 0; j < len; ++j){
			printf("%6d\t", matrix[i][j]); 
		}
		puts("");
	}	

}
