#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../DataStructures/prime.h"

// NOTE: To compile, run 'gcc p046.c ../DataStructures/prime.c -lm'


/**
 * Tests if the input is a two times a square
 */
unsigned int is_doubled_square( unsigned int num ) {

	// To be two times a square, num must be even
	if ( num % 2 == 0 ) {
		// Takes the square root of half of num and checks if the result is an integer
		double sqrt_num = sqrt((double) (num / 2));
		if (ceilf(sqrt_num) == sqrt_num) {
			return 1;
		}
	}

	return 0;

}


/**
 * Goldberg's other conjecture states that every odd composite number is the sum of a prime and twice a square
 * This method finds the smallest integer that this conjecture fails to hold for
 */
unsigned int goldbachs_other_conjecture() {

	// Get a list of all primes less than 1,000,000
	int length = 0;
	int* primes = sieve_of_eratosthenes(1000000, &length);

	// Starts searching from the first composite odd number
	unsigned int result = 9;

	while (1) {
		// Tests all primes less than the current target result
		int i = 0;
		int found = 0;
		while ( i < length && result > primes[i] ) {
			// Goldbach's other conjecture holds for the current target if 'result - primes[i]' is a doubled square
			if ( result - primes[i] > 0 && is_doubled_square(result - primes[i]) ) {
				found = 1;
				break;
			}
			i++;
		}
		// Goldbach's other conjecture does not hold does not hold if no primes and square work
		if ( !found ) {
			break;
		}
		// Gets the next composite odd to test
		do {
			result += 2;
		} while ( is_prime((int) result) );
	}

	// Frees dynamically allocated data and returns the result
	free(primes);
	return result;

}


int main(void) {
	printf("%u\n", goldbachs_other_conjecture());
	exit(EXIT_SUCCESS);
}
