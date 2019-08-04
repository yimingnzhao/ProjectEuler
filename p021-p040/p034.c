#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the sum of all numbers that are equal to the sum of the factorials of their digits
 */
unsigned int digit_factorials() {
	
	// Gets the factorial of the 10 digits
	unsigned int factorials[10];
	*factorials = 1;
	for ( int i = 1; i < 10; i++ ) {
		factorials[i] = factorials[i - 1] * i;
	}
	
	// Gets the upper limit for digit factorials:
	// 		9! = 362880 -> 6 digit number
	// 		6 * 9! = 2177280 -> 7 digit number
	// 		7 * 9! = 2540160 -> 7 digit number
	// 		Thus, the upper bound is 7 * 9!
	unsigned int upper_limit = 7 * factorials[9];

	// Initializes a local variable to store the total sum
	unsigned int total = 0;

	// Iterates through all possible numbers that have the digit factorial property
	for ( int i = 3; i <= upper_limit; i++ ) {
		int num = i;
		int sum = 0;
		while ( num != 0 ) {
			int current_num  = num % 10;
			sum += factorials[ current_num ];
			num /= 10;
		}
		if ( sum == i ) {
			total += sum;
		}
	}

	return total;
	
}


int main(void) {
	printf("%d\n", digit_factorials());
	exit(EXIT_SUCCESS);
}
