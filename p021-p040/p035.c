#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../DataStructures/prime.h"

// NOTE: To compile, run 'gcc p035.c ../DataStructures/prime.c -lm'


/**
 * Gets the number of digits of a number
 */
unsigned int get_num_digits( unsigned int num ) {

	unsigned int count = 0;
	
	// Continuously divides num by 10 to get the number of digits
	while ( num > 0 ) {
		num /= 10;
		count++;
	}

	return count;

}


/**
 * Gets the number of primes below 1000000 that are circular, in terms that all rotations of that number is also prime
 */
unsigned int circular_primes() {

	unsigned int count = 0;
	unsigned int num = 2;

	// Loops through all prime numbers below 1000000
	while ( num < 1000000 ) {

		unsigned int current_num = num;
		unsigned int digits = get_num_digits( current_num );
		int is_circular_prime = 1;

		// Loops through all rotations of the prime number
		for ( int i = 0; i < digits; i++ ) {
			if ( is_prime( current_num ) != 1 ) {
				is_circular_prime = 0;
				break;
			}
			int ones_position = current_num % 10;
			current_num /= 10;
			current_num += ones_position * (int)pow(10, digits - 1);
		}

		// Increments the count if the current num is a circular prime
		if ( is_circular_prime ) {
			count++;
		}

		// Gets the next prime
		num = next_prime( num );

	}

	return count;

}


int main(void) {
	printf("%u\n", circular_primes());
	exit(EXIT_SUCCESS);
}
