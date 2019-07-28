#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p029.c -lm'



/**
 * Returns the base of the n-th root of num, where n is the exp param
 */
int is_power( unsigned int num, unsigned int exp ) {

	// The largest possible base is when exp = 2
	unsigned int current_base = ceil(sqrt(num));

	// Loops through the possible bases of base^exp = num
	while ( current_base > 1 ) {
		if ( pow(current_base, exp) == num ) {
			return current_base;
		}
		current_base--;
	}

	// Returns -1 if the base does not exist
	return -1;

}


/**
 * Gets the count of distinct integer combinations of a^b, where a and b are in range [2, 100] 
 */
unsigned int distinct_powers() {

	// Defines the boundaries of a and b
	const unsigned int max = 100;
	const unsigned int min = 2;

	// If all integers in the combination of a^b are unique, then the total count would be the Cartesian product
	unsigned int total = (max + 1 - min) * (max + 1 - min);

	// Gets the max possible power less than or equal to max 
	unsigned int max_power = 1;
	while( pow(min, max_power) <= max ) {
		max_power++;
	}
	max_power--;

	// Finds double counts and removes them from total
	// Loops through the possible values in range [min, max]
	for ( int i = min; i <= max; i++ ) {

		// Loops through the powers from [min, max+power]
		for ( int j = min; j <= max_power; j++ ) {

			// Checks if a base exists for the current num and exp
			int base = is_power( i, j );

			// Checks if a base doesn't exist
			if ( base == -1 ) {
				continue;
			}

			// Checks if a base is not the base with the highest exponent
			int is_power_of_power = 0;
			for ( int k = min; k <= max_power; k++ ) {
				if ( is_power(base, k) != -1 ) {
					is_power_of_power = 1;
					break;
				}
			}
			if ( is_power_of_power ) {
				continue;
			}

			// Loops through the possible values of [min, max] to find double counts
			for ( int k = min; k <= max; k++ ) {

				// Checks if base^(exp*k) has been counted before
				int has_occured = 0;
				for ( int l = 1; l < j; l++ ) {
					if ( (j*k) % l == 0 && j*k / l <= max ) {
						has_occured = 1;
						break;
					}
				}
				if ( has_occured ) {
					total--;
				}

			}

		}

	}

	return total;

}


int main(void) {
	printf("%u\n", distinct_powers());
	exit(EXIT_SUCCESS);
}
