#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{

	float const radius;

}Circle;

double area_calc(const Circle * const circle);

int main(void){

	Circle const my_circle = {
		.radius = 6.942
	};

printf("%lf\n", area_calc(&my_circle));
return EXIT_SUCCESS;
}

double area_calc(const Circle * const circle){
 return M_PI * circle->radius * circle->radius;
}



