#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
int16_t get_vector_size();
void free_memory(int32_t** , int32_t** , int64_t** );
void memory_allocation(int32_t**, int32_t** , int64_t** , uint16_t);
void get_vectors_values(int32_t**, int32_t**, uint16_t);
int main(void){

	//	printf("Min: %ld\nMax: %ld\n", INT64_MIN, INT64_MAX);
	// <stdint.h>
	
	int32_t* col_vector;
	int32_t* row_vector;
	int64_t* result_vector;
	uint16_t  size;
	
	size = get_vector_size();	
	memory_allocation(&row_vector, &col_vector, &result_vector, size);
	get_vectors_values(&row_vector, &col_vector, size);

		for(uint16_t i = 0; i < size; ++i){
			result_vector[i] = row_vector[i] * col_vector[i];
		}
		
		for(uint16_t i = 0; i < size; ++i){
			printf("Result of index(%hd): %ld\n", i, result_vector[i]);
		}

		free_memory(&row_vector, &col_vector, &result_vector);
return EXIT_SUCCESS;
}


//////////////////////////
int16_t get_vector_size(){
		
	int16_t size;
	
		do{
			printf("Give index size for vectors: ");
			scanf("%hd", &size);
		}while (size > 20 || 
					 	 size < 1);
return size;
}


///////////////////////////
void memory_allocation(int32_t** row_vector, int32_t** col_vector, int64_t** result_vector, uint16_t size){
		*row_vector 		= (int32_t* )malloc(sizeof(int32_t) * size);
		if (*row_vector == NULL){
			perror("Failed to allocate memory for row_vector");
			exit(EXIT_FAILURE);
		}
		*col_vector 		= (int32_t* )malloc(sizeof(int32_t) * size);
		if (*col_vector == NULL){
			perror("Failed to allocate memory for col_vector");
			free(*row_vector);
			exit(EXIT_FAILURE);t
		}
		*result_vector = (int64_t* )malloc(sizeof(int64_t) * size);
		if (*result_vector == NULL){
			perror("Failed to allocate memory for result_vector");
			free(*row_vector);
			free(*col_vector);
			exit(EXIT_FAILURE);
		}
}

void free_memory(int32_t** row_vector, int32_t** col_vector, int64_t** result_vector){
	free(*row_vector);
	free(*col_vector);
	free(*result_vector);

}

void get_vectors_values(int32_t** row_vector, int32_t** col_vector, uint16_t size){

	for(uint16_t i = 0; i < size; ++i){
			printf("Give value for row value %hd: ", i);
			scanf("%d",&(*row_vector)[i]);
	}


	for(uint16_t i = 0; i < size; ++i){
			printf("Give value for col value %hd: ", i);
			scanf("%d",&(*col_vector)[i]);
	}

}
