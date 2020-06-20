#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile, run 'gcc p045.c -lm' 


/**
 * Tests if the input is a pentagon number
 */ 
unsigned int is_pentagon_number(long int num) {
	
	// If num, P(n), is a pentagon number, then 3n^2 - n - 2P(n) = 0
	// We use the quadratic formula to find n using the positive root
	// If n is an integer, then P(n) is a pentagon number
	double n = sqrt((double) (1 + 24*num));
	if (ceilf(n) == n && ((long int) n) % 6 == 5) {
		return 1;
	}
	return 0;

}


/**
 * Finds the next triangle number that is also pentagon and hexagon after T_285 = P_165 = H_143 = 40755
 */
long int triangular_pentagonal_and_hexagonal() {
	
	// Note that all hexagon numbers are also triangular
	// We start iterating through hexagonal numbers starting at n = 144
	// Since all hexagonal numbers are also triangular, we just check if H_n is also pentagonal
	unsigned int n = 143;
	while (1) {
		n++;
		long int h = n * (2*n - 1);
		if (is_pentagon_number(h)) {
			return h;
		}
	}

}


int main(void) {
	printf("%li\n", triangular_pentagonal_and_hexagonal());
	exit(EXIT_SUCCESS);
}
