#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {size_buffer = 50, };
typedef struct{
	char name[size_buffer];
	size_t age;
 	float GPA;
}Student;
void get_student_name(size_t len, char str[len]);
size_t get_student_age(void);
float get_student_gpa(void);
Student* get_student_info(void);
void print_student_info(Student* );
int main(void){
	Student* student = get_student_info();
	print_student_info(student);
	free(student);
	return EXIT_SUCCESS;
}

Student* get_student_info(void){
	Student* ret = (Student* )malloc(sizeof(Student));	
	get_student_name(size_buffer, ret->name);
	ret->age = get_student_age();
	ret->GPA = get_student_gpa();
	return ret;
}

void get_student_name(size_t len, char str[len]){

	printf("Enter name of student: ");
	fgets(str, size_buffer, stdin);
	for (size_t i = 0; i < strlen(str); ++i){
		if (str[i] == '\n'){
			str[i] = '\0';
		}
	}
}

size_t get_student_age(void){
	size_t ret;
	int c;
	printf("Enter student age: ");
	scanf("%zu", &ret);
	while ((c = getchar()) != '\n' && c != EOF);
	return ret;
}

float get_student_gpa(void){
	float ret;
	int c;
	printf("Enter student GPA: ");
	scanf("%f", &ret);
	while ((c = getchar()) != '\n' && c != EOF);

	return ret;
}

void print_student_info(Student* st){
	printf("Name: %s\n", st->name);
	printf("Age: %zu\n", st->age);
	printf("GPA: %.2f\n",st->GPA);
}
