#include "stdio.h"
#include "stdlib.h"
#include "../DataStructures/prime.h"

// NOTE: To compile, run 'gcc p047.c ../DataStructures/prime.c -lm'


/**
 * Finds the first four consecutive integers to have four distinct prime factors each, and returns the first one
 */
unsigned int distinct_prime_factors() {

	// The lowest positive integer with four distinct prime factors is 2*3*5*7
	unsigned int result = 2 * 3 * 5 * 7;

	// Starts testing the number of prime factors of consecutive results
	while (1) {
		int cnt1 = num_prime_factors(result);
		int cnt2 = num_prime_factors(result + 1);
		int cnt3 = num_prime_factors(result + 2);
		int cnt4 = num_prime_factors(result + 3);
		if (cnt1 == 4 && cnt2 == 4 && cnt3 == 4 && cnt4 == 4) {
			return result;
		}
		result++;
	}

}


int main(void) {
	printf("%u\n", distinct_prime_factors());
	exit(EXIT_SUCCESS);
}
