#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum { size_buffer = 50, };

typedef struct{
	char make[size_buffer];
	char model[size_buffer];
	size_t year;
	size_t mileage;
}Car;

void update_mileage(size_t* );
void print_details(Car* );

int main(void){
	size_t con;
	int c;
	Car my_car = {
		.make = "Toyota",
		.model = "Prius",
		.year = 2017,
		.mileage = 0,
	};
	puts("Press '1' to update mileage on car,\nPress '2' to show car details,");
	puts("Press any other key to do both");
	scanf("%zu", &con);
	while ((c = getchar()) != '\n' && c != EOF);
	switch(con){
		case 1:
			update_mileage(&my_car.mileage);
			break;
		case 2:
			print_details(&my_car);
		break;
		default:
			update_mileage(&my_car.mileage);
			print_details(&my_car);
	}
return 0;
}

void print_details(Car* car){
	printf("Manufacturer: %s\n", car->make);
	printf("Model: %s\n", car->model);
	printf("Year: %zu\n", car->year);
	printf("Mileage: %zu\n", car->mileage);
}

void update_mileage(size_t* mileage){
	size_t add;
	int c;
	printf("Enter extra miles: ");
	scanf("%zu", &add);
	while ((c = getchar()) != '\n' && c != EOF);
	*mileage += add;
}
