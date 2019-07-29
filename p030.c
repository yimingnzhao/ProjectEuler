#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p030.c -lm'


/**
 * Gets the sum of all numbers that can be written as a sum of the fifth powers of their digits
 */
unsigned int digit_fifth_powers() {

	// Finding the upper limit
	// 		9^5 = 59049, is a 5 digit number. Thus, we need at least 5 digits.
	// 		5*(9^5) = 295245, is a 6 digit number, so we know 6 digit numbers can be made.
	// 		6*(9^5) = 354294, which is still a 6 digit number
	// 		Thus, the upper bound is 6*(9^5)

	// Creates an array to get each fifth power digit
	int powers_of_5[10];
	for ( int i = 0; i < 10; i++ ) {
		powers_of_5[i] = pow(i, 5);
	}

	unsigned int total = 0;
	unsigned int max = 6 * pow(9, 5);

	// Checks if each number in the range [2, max] can be written as a sum of the fifth powers of their digits
	for ( int i = 2; i <= max; i++ ) {

		int num = i, count = 0;

		// Gets the sum of the number's fifth power digits
		while ( num != 0 ) {
			count += powers_of_5[ num % 10 ];
			num /= 10;
		}

		// Adds the number to the total if the number can be written as a sum of the fifth powers of their digits
		if ( count == i ) {
			total += count;
		}

	}

	return total;

}


int main(void) {
	printf("%u\n", digit_fifth_powers());
	exit(EXIT_SUCCESS);
}
