#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define BUFFER 50
typedef struct{

	uint16_t age;
	char name[BUFFER];

}Student;
uint16_t get_number();
Student**  memory_allocation(uint16_t size);
void get_student_info(Student** student, uint16_t size);
void print_student_info(Student** student, uint16_t size);
void memory_free(uint16_t size, Student** student);
int main(void){
	uint16_t size;
	size = get_number();
	Student** student = memory_allocation(size);	
	get_student_info(student, size);
	memory_free(size,student);
return EXIT_SUCCESS;
}

uint16_t get_number(){
	uint16_t num;
	int c;
	printf("Number of students: ");
	scanf("%hu", &num);
	while ((c = getchar()) != EOF && c != '\n');
	return num;
}

 Student** memory_allocation(uint16_t size){

	 Student** student = (Student**)malloc(size * sizeof(Student*));
	if(!(student)){
		perror("Faield to malloc");	
		exit(EXIT_FAILURE);
		}
	for(uint16_t i = 0; i < size; ++i){
		student[i] = (Student*)malloc(sizeof(Student));
		if(!student[i]){
			perror("Malloc failed");
			exit(EXIT_FAILURE);
		}
	}
return student;	
}

void get_student_info(Student** student, uint16_t size){

	for(uint16_t i = 0; i < size; ++i){
		int c;
		printf("Give student %hu age: ", i);
		scanf("%hu", &student[i]->age);
		while((c = getchar()) != '\n' && c != EOF);
		printf("Give student %hu name: ", i);
		fgets(student[i]->name, BUFFER, stdin);
		student[i]->name[strlen(student[i]->name)-1] = '\0';
	}	
}

void print_student_info(Student** student, uint16_t size){

	for(uint16_t i = 0; i < size; ++i){
		printf("Student %hu Age: %hu\n", i, student[i]->age);
		printf("Student %hu Name: %s\n", i, student[i]->name);
	}

}

void memory_free(uint16_t size, Student** student){

	for(uint16_t i = 0; i < size; ++i){
		free(student[i]);
	}

	free(student);

}
