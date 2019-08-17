#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the perimeter (p), p <= 1000, that the number of solutions of the right triangle is maximized
 */
unsigned int integer_right_triangles() {
	
	unsigned int max = 0;
	unsigned int result = 0;

	// Loops through the perimeters (p <= 1000) 
	for ( int p = 0; p <= 1000; p++ ) {

		// Solves the system:
		// 		a^2 + b^2 = c^2		(1)
		// 		a + b + c = p		(2)
		//
		//		--> a^2 + b^2 = (p - a - b)^2
		//		--> a^2 + b^2 = p^2 + a^2 + b^2 - 2pa - 2pb + 2ab
		//		--> b(2p - 2a) = p^2 - 2pa
		// 		--> b = (p^2 - 2pa)/(2p - 2a)
		//
		// 	Checks if an integer value of b exists for input pair (p, a)
		unsigned int count = 0;
		for ( int i = 2; i < p; i++ ) {
			if ( (p*(p-2*i)) % (2*(p-i)) == 0 ) {
				count++;
			}
		}

		if ( count > max ) {
			max = count;
			result = p;
		}

	}	
	
	return result;

}


int main(void) {
	printf("%u\n", integer_right_triangles());
	exit(EXIT_SUCCESS);
}
