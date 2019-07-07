#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the length of the Collatz sequence of integer num
 */
unsigned int get_collatz_count( unsigned int num ) {

	// Base Case: the chain length from 1 -> 1 is 0 
	if ( num == 1 ) {
		return 0;
	}

	// If num is even, the chain length increases by 1
	if ( num % 2 == 0 ) {
		return 1 + get_collatz_count( num / 2 );
	}

	// If num is odd, 3n+1 is guarenteed to be even
	// Thus, there are 2 steps from num to (3n+1)/2
	return 2 + get_collatz_count( (3*num + 1)/2 );

}


/**
 * Gets the number, under 1000000, that produces the longest Collatz chain
 */
unsigned int longest_collatz_sequence() {

	unsigned int longest_sequence = 0;
	unsigned int num = 1;

	// Loops through all integers [1, 1000000) to find the number with the longest chain
	for ( int i = 1; i < 1000000; i++ ) {
		unsigned int collatz_count = get_collatz_count( i );
		if ( collatz_count > longest_sequence ) {
			longest_sequence = collatz_count;
			num = i;
		}
	}

	return num;

}


int main(void) {
	printf("%u\n", longest_collatz_sequence());	
	exit(EXIT_SUCCESS);
}
