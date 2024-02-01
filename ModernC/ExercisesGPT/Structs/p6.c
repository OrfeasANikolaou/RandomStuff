#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER 50
typedef struct{
	size_t ID;
	char name[BUFFER];
	size_t salary;
}Employee;

Employee** memory_allocation(size_t size);
void free_memory(Employee** employee, size_t size);
Employee* get_employee_data(Employee* employee, size_t i);
void print_employee_data(Employee* employee, size_t i);

int main(void){
	size_t size = 3;
	Employee** employee = memory_allocation(size);
	
	for(size_t i = 0; i < size; ++i){
		employee[i] = get_employee_data(employee[i], i);
	}	
	
	for(size_t i = 0; i < size; ++i){
		print_employee_data(employee[i], i);	
	}	

	free_memory(employee, size);
return EXIT_SUCCESS;

}

Employee** memory_allocation(size_t size){

	Employee** employee = (Employee** )malloc(sizeof(Employee* )*size);
	if (!employee){
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	for(size_t i = 0; i < size; ++i){
		employee[i] = (Employee* )malloc(sizeof(Employee));
		if (!employee[i]){
			fprintf(stderr,"Malloc for employee[%zu] failed\n", i);
			while(employee[--i]){
				free(employee[i]);
			}
			free(employee);
			exit(EXIT_FAILURE);
		}
	}

	return employee;
}
void free_memory(Employee** employee, size_t size){

	for(size_t i = 0; i < size; ++i){
		free(employee[i]);
	}
	free(employee);

}
Employee* get_employee_data(Employee* employee, size_t i){
	int c;
		printf("Give employee[%zu] ID:", i);	
		scanf("%zu", &employee->ID);
		while((c = getchar()) != EOF && c != '\n');
		printf("Give employee[%zu] name:", i);	
		fgets(employee->name, BUFFER, stdin);
		size_t name_size = strlen(employee->name)-1;
		employee->name[name_size] = '\0';
		printf("Give employee[%zu] salary:", i);	
		scanf("%zu", &employee->salary);
		while((c = getchar()) != EOF && c != '\n');
	return employee;
}

void print_employee_data(Employee* employee, size_t i){
	printf("|----------|\n");
	printf("|EMPLOYEE %zu|\n", i);
	printf("|----------|\n");
	printf("ID: \t%zu\n", employee->ID);
	printf("Name: \t%s\n", employee->name);
	printf("Salary: %zu\n", employee->salary);
}
