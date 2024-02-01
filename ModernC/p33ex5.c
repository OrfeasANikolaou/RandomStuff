#include <stdio.h>
#include <stdlib.h>

int main(void){
/*
 *
 * 0x1P+-01 is just 0.5
 *
 *
 */
static double const eps1m01 = 0.5 - 0x1P-01;
static double const eps1p01 = 0.5 + 0x1P-01;

printf("Minus: %g\nPlus: %g\n", eps1m01, eps1p01);

return EXIT_SUCCESS;
}
