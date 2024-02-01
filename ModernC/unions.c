#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef union{

	unsigned val;
unsigned char bytes[sizeof(unsigned)];

}unsignedInspect;
unsignedInspect twofold = {
														.val = 0xAABBCCDD,
													};

int main(void){
	printf("Val: 0x%.08X\n", twofold.val);
	for (size_t i =0; i <sizeof twofold.bytes; ++i)
		printf("Byte[%zu]: 0x%.02hhX\n", i, twofold.bytes[i]);
return EXIT_SUCCESS;
}
