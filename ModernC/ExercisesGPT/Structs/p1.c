#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef struct{
	char first_name[50];
	char last_name[50];
 	uint16_t age;	
}Person;

int main(void){
	char c;
	Person person;
  Person	*me = &person; 
	printf("First name: ");
	fgets(me->first_name, 50, stdin);
	me->first_name[strlen(me->first_name)-1] = '\0';
	printf("Last name: ");
	fgets(me->last_name, 50, stdin);
	me->last_name[strlen(me->last_name)-1] = '\0';
	printf("Age: ");
	scanf("%hu", &me->age);
	while((c=getchar()) != '\n' && c != EOF);
	printf("Name: %s %s\nAge: %hu\n", me->first_name, me->last_name, me->age);
return EXIT_SUCCESS;
}
