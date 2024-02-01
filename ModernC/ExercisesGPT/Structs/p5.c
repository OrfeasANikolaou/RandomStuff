#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{

	float x;
	float y;

}Point;
typedef struct{

	Point top_left;
	Point bot_right;

}Rectangle;

float calc_area(Rectangle*);
int main(void){

	Rectangle my_rectangle = {
		.top_left  = {6, 9},
		.bot_right = {4, 20},
	};
	
	float area = calc_area(&my_rectangle);

	printf("Area %.3f\n", area);

	
		

return EXIT_SUCCESS;
}

float calc_area(Rectangle* my_r){

	float height = fabsf(my_r->top_left.x - my_r->bot_right.x);
	float width	 = fabsf(my_r->top_left.y - my_r->bot_right.y);

	return height*width;

}
