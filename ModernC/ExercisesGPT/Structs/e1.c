#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int x;
	int y;

}Point;

int main(void){

	Point p1;

	printf("Give coordinates of X: ");
	scanf("%d", &p1.x);
	printf("Give coordinates of Y: ");
	scanf("%d", &p1.y);

	printf("Coordinates of p1 = (%d,%d)\n", p1.x, p1.y);

	return EXIT_SUCCESS;
}
