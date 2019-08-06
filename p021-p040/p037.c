#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../DataStructures/prime.h"

// NOTE: To compile, run 'gcc p037.c ../DataStructures/prime.c -lm'


/**
 * Gets the number of digits in num
 */
unsigned int num_digits( int num ) {

	int count = 0;

	// Continuously divides num by 10
	while ( num != 0 ) {
		num /= 10;
		count++;
	}

	return count;

}


/**
 * Checks if a number is two sided prime truncatable 
 */
unsigned int is_truncatable( int prime ) {

	unsigned int digits = num_digits( prime );
	
	// Checks if the prime number is truncatable from left to right
	int num = prime;
	while ( num != 0 ) {
		if ( is_prime( num ) != 1 ) {
			return 0;
		}
		num %= (int)pow( 10, digits - 1 );
		digits--;
	}

	// Checks if the prime number is truncatable from right to left
	num = prime;
	while ( num != 0 ) {
		if ( is_prime( num ) != 1 ) {
			return 0;
		}
		num /= 10;
	}

	return 1;

}



/**
 * Gets the sum of the eleven two sided prime truncatable numbers
 */
unsigned int truncatable_primes() {

	const int NUM_TRUNCATED_PRIMES = 11;
	unsigned int sum = 0;
	unsigned int count = 0;
	int prime = 11;
		
	// Continues to check for truncatable primes until eleven are found
	while ( count < NUM_TRUNCATED_PRIMES ) {
		if ( is_truncatable( prime ) ) {
			sum += prime;
			count++;
		}
		prime = next_prime( prime );
	}

	return sum;

}


int main(void) {
	printf("%u\n", truncatable_primes());
	exit(EXIT_SUCCESS);
}
