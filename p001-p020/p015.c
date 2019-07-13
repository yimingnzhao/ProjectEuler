#include "stdio.h"
#include "stdlib.h"


/**
 * Calculates the combinatorical formula n Choose k 
 */
long n_choose_k( unsigned int n, unsigned int k ) {

	long result = 1;

	// Iterates from [1, k], performing multiplication and divison in the same loop to prevent overflow
	for ( int i = 1; i <= k; i++ ) {
		result *= ( n - k + i );
		result /= i;
	}

	return result;

}


/**
 * Gets the number of paths to travel from the top-left to the bottom-right of a 20x20 grid
 * Note that only down and left movements can be made
 */
long lattice_paths() {

	unsigned int rows = 20;
	unsigned int cols = 20;

	// Getting the number of paths is the same as considering all 40 necessary movements, and choosing 20 down movements
	// Thus, we find 40 choose 20, as it takes 40 movements to reach the bottom-right, and 20 of them are down movements
	return n_choose_k( rows + cols, cols );

}


int main(void) {
	printf("%ld\n", lattice_paths());
	exit(EXIT_SUCCESS);
}
