#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header for EXIT_SUCCESS
#include <stddef.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    
		/*
		 * ptrdiff_t == difference between positions of a pointer or an adress
		 */
		ptrdiff_t diff = &arr[1] - &arr[0];
		
    printf("Pointer difference: %td\n", diff);

    return EXIT_SUCCESS; // Use EXIT_SUCCESS to indicate success
}
