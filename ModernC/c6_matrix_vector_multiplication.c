#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void allocate_memory(int32_t***, int32_t**, int64_t**, int16_t, int16_t);
void free_memory(int32_t***, int32_t**, int64_t**, int16_t);
void get_rows_and_columns(int16_t*, int16_t*);
void matrix_vector_multiplication(int32_t**, int32_t*, int64_t*, int16_t, int16_t);
void print_result(int64_t*, int16_t);
void get_values(int32_t***, int32_t**, int16_t, int16_t);
int main(void){
	int32_t** source_matrix;
	int32_t* source_vector;
	int64_t* result_vector;
	int16_t rows, cols;

	get_rows_and_columns(&rows, &cols);
	allocate_memory(&source_matrix, &source_vector, &result_vector, rows, cols);
	
	get_values(&source_matrix, &source_vector, rows, cols);
	matrix_vector_multiplication(source_matrix, source_vector, result_vector, rows, cols);
	print_result(result_vector, rows);

	free_memory(&source_matrix, &source_vector, &result_vector, rows);
return EXIT_SUCCESS;
}

void allocate_memory(int32_t*** source_matrix, int32_t** source_vector, int64_t** result_vector, int16_t rows, int16_t cols){

	*source_matrix = (int32_t** )malloc(sizeof(int32_t*) * rows);
	if (*source_matrix == NULL){
		perror("Failed to allocate memory for source matrix");
		exit(EXIT_FAILURE);
	}
	*result_vector = (int64_t* )malloc(sizeof(int64_t) * rows);
	if(*result_vector == NULL){
		perror("Failed to allocate memory for result matrix");
		free(*source_matrix);
		exit(EXIT_FAILURE);
	}
	
	for(int16_t i = 0; i < rows; ++i){
		(*source_matrix)[i] = (int32_t* )malloc(sizeof(int32_t) * cols);
		if ((*source_matrix)[i] == NULL){
			fprintf(stderr, "Failed to allocate memory for source_matrix[%hd]", i);
			for(;i >= 0; --i){
				free((*source_matrix)[i]);	
			}
		free(*result_vector);
		free(*source_matrix);
		exit(EXIT_FAILURE);
		}	
	}

	*source_vector = (int32_t*)malloc(sizeof(int32_t) * cols);
	if (*source_vector == NULL){
		perror("Failed to allocate memory for source vector");	
			for(int16_t i=0; i < rows; ++i){
				free((*source_matrix)[i]);
		}
		free(*result_vector);
		free(*source_matrix);
		exit(EXIT_FAILURE);
	}
}

void get_rows_and_columns(int16_t* rows, int16_t* cols){
	printf("Give size for rows: ");
	scanf("%hd", rows);
	printf("Give size for cols: ");
	scanf("%hd", cols);
}


void free_memory(int32_t*** source_matrix, int32_t** source_vector, int64_t** result_vector, int16_t rows){
	for(int16_t i = 0; i < rows; ++i) free((*source_matrix)[i]);
	free(*source_matrix);
	free(*result_vector);
	free(*source_vector);
}
void matrix_vector_multiplication(int32_t** source_matrix, int32_t* source_vector, int64_t* result_vector, int16_t rows, int16_t cols){
	for(int16_t i = 0; i < rows; ++i){
		result_vector[i] = 0;
		for(int16_t j = 0; j < cols; ++j){
			result_vector[i] += source_matrix[i][j] * source_vector[j];	
		}
	}	
}

void print_result(int64_t* result_vector, int16_t rows){
	printf("RESULT MATRIX\n");
	for(int16_t i = 0; i < rows; ++i){
			printf("%ld", result_vector[i]);
			printf("\n");
	}	
}
void get_values(int32_t*** source_matrix, int32_t** source_vector, int16_t rows, int16_t cols){
	for(int16_t i = 0; i < rows; ++i){
		for(int16_t j = 0; j < cols; ++j){
				printf("Give value of source matrix[%hd][%hd]: ", i, j);
				scanf("%d", &(*source_matrix)[i][j]);
		}
}
	for(int16_t j = 0; j < cols; ++j){
				printf("Give value of source vector[%hd]: ", j);
				scanf("%d", &(*source_vector)[j]);
		}
}
