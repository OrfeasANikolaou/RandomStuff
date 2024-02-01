#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef union{

	double* val;
unsigned char bytes[sizeof(double* )];

}unsignedInspect;
double x = -99999.999;
unsignedInspect twofold = {
														.val = &x,
													};

int main(void){
	printf("Val in hex: %p\n", (void *)twofold.val);
	for (size_t i =0; i < sizeof(twofold.bytes); ++i)
		printf("Byte[%zu]: 0x%.02hhX\n", i, twofold.bytes[i]);
	for (size_t i =0; i < sizeof(twofold.bytes); ++i)
		printf("Adress of byte[%zu]: %p\n", i, &twofold.bytes[i]);
return EXIT_SUCCESS;
}
