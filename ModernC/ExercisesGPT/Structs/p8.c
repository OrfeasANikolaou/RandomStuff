#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
size_t h;
size_t m;
size_t s;
}Time;
Time diference(Time, Time);

int main(void){
	Time const t1 = {
		.h = 3,
		.m = 40,
		.s = 24,
	};
	Time const t2 = {
		.h = 5,
		.m = 21,
		.s = 19,
	};
	Time const t3 = diference(t1, t2);
	printf("H: %zu\nM: %zu\nS: %zu\n", t3.h, t3.m, t3.s);

return EXIT_SUCCESS;
}
Time diference(Time const t1, Time const t2){

	size_t dif, s1, s2;
	Time t3;
	s1 = t1.s+t1.m*60+t1.h*3600;
	s2 = t2.s+t2.m*60+t2.h*3600;
	if (s1 > s2)
		dif = s1 - s2; 
	else
		dif = s2 - s1;
	t3.h = dif / 3600;
	dif -= t3.h * 3600;
	t3.m = dif / 60;
	dif -= t3.m * 60;
	t3.s = dif;
return t3;
}
