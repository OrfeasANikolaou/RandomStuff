#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
int main(void){

printf("MAXES\nU8 : %u\nU16: %u\nU32: %u\nU64: %lu\nI8 : %d\nI16: %d\nI32: %d\nI64: %ld\nMINIMUMS\nI8 : %d\nI16: %d\nI32: %d\nI64: %ld\n\n\n",UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX, INT8_MAX, INT16_MAX, INT32_MAX, INT64_MAX, INT8_MIN, INT16_MIN, INT32_MIN, INT64_MIN);

printf("PMin: %lf\n\nPMax: %lf\n\nNMin:%lf\n\nNMax:%lf\n\n", DBL_MIN, DBL_MAX, -DBL_MIN, -DBL_MAX);
return EXIT_SUCCESS;
}
