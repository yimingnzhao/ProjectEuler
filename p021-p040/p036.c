#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p036.c -lm'


/**
 * Gets the number of digits in a positive number
 */
unsigned int num_digits( unsigned int num ) {

	unsigned int digits = 0;

	// Continues to divide num by 10 until num reaches 0
	while ( num != 0 ) {
		num /= 10;
		digits++;
	}

	return digits;

}


/**
 * Checks if a number is a palindrome number in base 10
 */
unsigned int is_palindrome_base10( unsigned int num ) {

	// Gets the reverse of num
	int reverse = 0;
	int original = num;
	unsigned int digits = num_digits( num );
	for ( int i = 0; i < digits; i++ ) {
		reverse += num / (int)pow(10, digits-1-i) * (int)pow(10, i);
		num %= (int)pow(10, digits-1-i);
	}

	// Checks if num and its reverse are equal
	return (reverse == original) ? 1 : 0;
	
}


/**
 * Checks if a number is a palindrome number in base 2
 */
unsigned int is_palindrome_base2( unsigned int num, unsigned int digits ) {
	
	// Base Case: If num has less than two binary digits, it is a palindrome
	if ( digits < 2 ) {
		return 1;
	}

	// Gets the first and last bits using bit operations
	unsigned int mask = (unsigned int)pow( 2, digits - 1 );
	int most_significant_digit = num & mask;
	int least_significant_digit = num & 1;
	most_significant_digit = (int)((unsigned int)most_significant_digit) >> (digits - 1);
	
	// If the first and last bits are equal, then remove the first and last bits
	if ( most_significant_digit == least_significant_digit ) {
		mask = ~mask;
		num = num & mask;
		num = ((unsigned int)(num)) >> 1;
		return is_palindrome_base2( num, digits - 2 );
	}

	// Else, the number is not a palindrome in base 2
	return 0;

}


/**
 * Gets the sum of the numbers that are palindrome in both decimal and binary in the range [1, 1000000)
 */
unsigned int double_base_palindromes() {

	unsigned int sum = 0;

	// Loops through the numbers in range [1, 1000000)
	for ( int i = 1; i < 1000000; i++ ) {
		int digits_base2 = (int)floor( log(i) / log(2) ) + 1;
		if ( is_palindrome_base10(i) && is_palindrome_base2(i, digits_base2) ) {
			sum += i;
		}
	}

	return sum;

}


int main(void) {
	printf("%u\n", double_base_palindromes());
	exit(EXIT_SUCCESS);
}
