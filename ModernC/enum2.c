#include <stdio.h>

int main(void){

	/*
	 * 0 through 4 
	 */
enum corvid { magpie, raven, jay, chough, corvid_num };

/*
 * magpie  		 == 0
 * raven 			 == 1
 * jay				 == 2
 * chough			 == 3
 * corvid_num	 == 4
 */
char const* const bird[corvid_num] = {
	[raven]		= "raven",
	[magpie]	= "magpie",
 	[jay]			= "jay",
	[chough]	= "chough"
};

for (size_t i = 0; i < corvid_num; ++i)
	printf("Corvid %zu is the %s\n", i, bird[i]);

return 0;
}

/*
 * Compared to enum.c, I just had to add chough on enum corvid,
 * (thus chough == 3) and on the array declaration [chough] (so basically 3) = "chough"
 * Since for is i < corvid_num
 */
