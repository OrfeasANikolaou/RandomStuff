#include <stdio.h>
#include <stdlib.h>

int main(void){
/*
 * Read-only array of strings
 */
char const* const bird[3] = {
	"raven",
	"magpie",
	"jay"
};

char const* const ordinal[3] = { "first", "second", "third" };

for (size_t i = 0; i < 3; ++i)
	printf("Corvid %zu is the %s\n", i, bird[i]);

for (size_t i = 0; i < 3; ++i)
	printf("%zust place is %s\n", i, ordinal[i]);

return EXIT_SUCCESS;
}
