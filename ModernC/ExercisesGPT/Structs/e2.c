#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_BUFFER 50
typedef struct{
	char name[NAME_BUFFER];
	int age;
	float gpa;
}Student;

Student get_student_info(Student st);
void print_student_info(Student st);
int main(void){

	Student pupil;
	pupil = get_student_info(pupil);
	print_student_info(pupil);

	return EXIT_SUCCESS;
}

Student get_student_info(Student st){
	printf("Give student name: ");
	fgets(st.name, NAME_BUFFER, stdin);
	size_t len = strlen(st.name)-1;
	st.name[len] = '\0';
	
	int c;
	while ((c = getchar() != '\n' && c!= EOF));
	
	printf("Give student age: ");
	scanf("%d", &st.age);
	while ((c = getchar() != '\n' && c!= EOF));
	printf("Give student GPA: ");
	scanf("%f", &st.gpa);
	while ((c = getchar() != '\n' && c!= EOF));
	
	return st;
}

void print_student_info(Student st){
	printf("Name: %s\nAge: %d\nGPA: %.2f\n", st.name, st.age, st.gpa);
}


