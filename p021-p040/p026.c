#include "stdio.h"
#include "stdlib.h"


/**
 * Makes num coprime to 10
 */
unsigned int make_coprime_to_10( unsigned int num ) {

	// Removes factors of 2
	while ( num % 2 == 0 ) {
		num /= 2;
	}

	// Removes factors of 5
	while ( num % 5 == 0 ) {
		num /= 5;
	}

	return num;

}


/**
 * Gets the integer, d (0 < d < 1001), such that 1/d has the longest recurring cycle
 */
unsigned int reciprocal_cycles() {

	unsigned int largest_reciprocal = 0;

	// Loops through all possible values of d
	for ( int i = 1; i <= 1000; i++ ) {

		// Ensures that d is coprime to 10, so that 10^k % d does not loop forever with incrementing values of k 
		int current_reciprocal = make_coprime_to_10( i );
		if ( current_reciprocal != 1 ) {

			// When (10^k - 1) % d = 0, k is the length of the recurring cycle
			// Thus, we can check for when 10^k % d = 1
			int current_mod = 10 % current_reciprocal;
			unsigned int k = 1;
			while ( current_mod != 1 ) {

				// Using modular arithmetic, 10^k % d = (10^(k-1) % d * 10) % d
				current_mod = ( current_mod * 10 ) % current_reciprocal;
				k++;

			}

			if ( k > largest_reciprocal ) {
				largest_reciprocal = current_reciprocal;	
			}

		}
	
	}

	return largest_reciprocal;

}


int main(void) {
	printf( "%u\n", reciprocal_cycles() );
	exit(EXIT_SUCCESS);
}
