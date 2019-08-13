#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p038.c -lm'


/**
 * Checks if a number is pandigital, that is, it contains the integers {1, 2, 3, 4, 5, 6, 7, 8, 9}
 */
unsigned int is_pandigital( unsigned int num ) {

	// Initializes an array to indicate the 9 digits, initially each set to '0'
	char digits[9];
	int digits_len = 9;
	memset( digits, '0', digits_len * sizeof(char) );

	// Loops through the digits of num and marks the corresponding index in the array
	while ( num > 0 ) {
		int digit = num % 10;
		digits[ digit - 1 ] = '1';
		num /= 10;	
	}

	// Checks that the array now only contains '1'
	for ( int i = 0; i < digits_len; i++ ) {
		if ( digits[i] == '0' ) {
			return 0;
		}
	}

	return 1;

}


/**
 * Gets the number of digits in num
 */
unsigned int get_num_digits( unsigned int num ) {

	// The number 0 has 1 digit
	if ( num == 0 ) {
		return 1;
	}

	// Continuously divides num by 10 and increments the count until num is 0
	unsigned int count = 0;
	while ( num > 0 ) {
		num /= 10;
		count++;
	}

	return count;
}


/**
 * Gets the largest pandigital contatenated product that is generated from an integer multiplied by {1, 2,..., n}, where n > 1
 */
unsigned int pandigital_multiples() {

	// The first digit in the contatenated product must be a 9, so the integer must begin with 9
	// A two digit integer that begins with 9 cannot result in a concatenated product of 9 digits
	// A three digit integer that begins with 9 also cannot result in a concatenated product of 9 digits
	// Thus, the integer must be in the range [9123, 9876]
	for ( int i = 9876; i >= 9123; i-- ) {

		// With four digits, the value of n must be 2
		unsigned int num_one = i * 1;
		unsigned int num_two = i * 2;

		// Gets the concatenated product and checks if it is pandigital
		unsigned int num = i * (int)pow(10, get_num_digits(num_two)) + num_two;
		if ( get_num_digits(num) != 9 ) {
			continue;
		}
		if ( is_pandigital(num) ) {
			return num;
		}

	}

	return 0;
}


int main(void) {
	printf("%u\n", pandigital_multiples());
	exit(EXIT_SUCCESS);
}
