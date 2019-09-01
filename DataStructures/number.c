#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "number.h"


/**
 * Checks if num is pandigital for digits [1, limit]
 * Error Case: returns -1 when limit is not a single digit number
 */
int is_pandigital( int num, int limit ) {

	// Error when limit is not a one digit number
	if ( limit > 9 ) {
		return -1;
	}

	// Gets the sum of digits in range [1, limit]
	int total = (limit * (limit + 1)) / 2;
	int count = 0;

	// Continuously subtracts the least significant digit from total
	while ( num > 0 ) {
		total -= (num % 10);
		num /= 10;
		count++;
	}

	return (total == 0 && count == limit) ? 1 : 0;

}


/**
 * Returns the number of digits in num
 */
int num_digits( int num ) {

	// Edge Case: num is 0
	if ( num == 0 ) {
		return 1;
	}

	// Continuously divides num by 10 to count digits
	int count = 0;
	while ( num > 0 ) {
		num /= 10;
		count++;
	}

	return count;

}
