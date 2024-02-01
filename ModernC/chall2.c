#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double deriv_of_sqrt(double x);

int main(void){

	double var, result;
	printf("Give number to calculate derivative of sqrt(): ");
	scanf("%lf", &var);
	result = deriv_of_sqrt(var);
	printf("The derivative of sqrt(%g) is: %g\n", var, result);

return EXIT_SUCCESS;
}

double deriv_of_sqrt(double x){

	float value=1/(2*sqrt(x));
	
	return value;

}
