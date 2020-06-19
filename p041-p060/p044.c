#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile, run 'gcc p044.c -lm' 


/**
 * Tests if the input is a pentagon number
 */ 
unsigned int is_pentagon_number(unsigned int num) {
	
	// If num, P(n), is a pentagon number, then 3n^2 - n - 2P(n) = 0
	// We use the quadratic formula to find n using the positive root
	// If n is an integer, then P(n) is a pentagon number
	double n = sqrt((double) (1 + 24*num));
	if ( ceilf(n) == n && ((int) n) % 6 == 5) {
		return 1;
	}
	return 0;

}


/**
 * Gets the smallest absolute difference of pentagon numbers Pj and Pk, with Pj > Pk, such that:
 *		(Pj + Pk) is a pentagon number
 *		(Pj - Pk) is a pentagon number
 */
unsigned int pentagon_numbers() {

	unsigned int result = 0;
	unsigned int i = 1;

	// Loops through pentagon numbers for p_j starting with the smallest
	while (1) {
		
		i++;
		unsigned int p_j = i * (3*i - 1) / 2;

		// Loops through pentagon numbers for p_k starting with the largest p_k < p_j
		for (unsigned int j = i - 1; j > 0; j--) {
			unsigned int p_k = j * (3*j - 1) / 2;

			// Checks the requirements of p_j and p_k
			if (is_pentagon_number(p_j - p_k) && is_pentagon_number(p_j + p_k)) {
				result = p_j - p_k;
				return result;
			}

		}

	}

}


int main(void) {
	printf("%u\n", pentagon_numbers());
	exit(EXIT_SUCCESS);
}
