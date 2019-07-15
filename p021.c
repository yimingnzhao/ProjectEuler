#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the proper divisor sum of parameter num
 */
unsigned int proper_divisor_sum( int num ) {

	unsigned int sum = 0;

	// Loops from the range [1, sqrt(num)]
	for ( int i = 1; i*i <= num; i++ ) {
		
		// Checks if i is a proper divisor
		if ( num % i == 0 ) {

			// Case 1: i is the square root of num, so only i is added
			// Case 2: i is a divisor, so i and num/i are added
			if ( i*i == num ) {
				sum += i;
			} else {
				sum += i;
				sum += (num / i);
			}

		}

	}

	// Removes num from the sum
	sum -= num;
	return sum;

}


/**
 * Gets the sum of amicable numbers less than 10000
 */
unsigned int amicable_numbers() {

	unsigned int sum = 0;

	// Loops through the range (1, 10000)
	for ( int i = 1; i < 10000; i++ ) {

		// Checks if the pair (i, proper_divisor_sum(i)) form an amicable pair
		int a = i;
		int proper_divisor_sum_a = proper_divisor_sum( a );
		int b = proper_divisor_sum_a;
		int proper_divisor_sum_b = proper_divisor_sum( b );
		if ( a != b && a == proper_divisor_sum_b && b == proper_divisor_sum_a ) {
			sum += i;
		}

	}

	return sum;

}


int main(void) {
	printf("%u\n", amicable_numbers());
	exit(EXIT_SUCCESS);
}
