#include <stdio.h>

int main(void){

	/*
	 * 0 through 3
	 */
enum corvid { magpie, raven, jay, corvid_num };

/*
 * magpie  		 == 0
 * raven 			 == 1
 * jay				 == 2
 * corvid_num	 == 3
 */
char const* const bird[corvid_num] = {
	[raven]		= "raven",
	[magpie]	= "magpie",
 	[jay]			= "jay",
};

for (size_t i = 0; i < corvid_num; ++i)
	printf("Corvid %zu is the %s\n", i, bird[i]);

return 0;
}
