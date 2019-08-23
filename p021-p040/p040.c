#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p040.c -lm'



/**
 * Gets the nth digit of num, where:
 * 		 (n = 0) -> most significant digit 
 * 		 (n = digits - 1) -> least significant digit
 */
int get_nth_digit( int num, int n, int digits ) {

	// Sets the desired digit to the least significant digit
	num /= (int)pow(10, digits - n - 1);

	// Takes the modulus to get the least significant digit
	return num % 10;

}


/**
 * Gets the nth decimal digit of champernowne's constant, starting from n = 1
 */
int nth_champernowne_constant( int n ) {

	// Determines the range of numbers with the same number of digits that n fits into
	// e.g:
	// 		- the first decimal digit in champernowne's constant is a one digit number in the range [1, 9]
	// 		- the tenth decimal digit in champernowne's constant is a two digit number in the range [10, 189]
	// 		- the one thousandths decimal digit in champernowne's constant is a three digit number in the range [190, 2889]
	int min = 1;
	int max = 9;
	int previous_max = 0;
	int digits = 1;
	while ( !(n >= min && n <= max) ) {
		min = max + 1;
		previous_max = max;
		max = 9 * (int)pow(10, digits) * (digits+1) + previous_max;
		digits++;
	}

	// Adjusts n to represent the nth (digits)-digit number, beginning with n = 0
	// e.g:
	// 		- If n was in range [1, 9]: (n = 0) -> 1, (n = 1) -> 2
	// 		- If n was in range [10, 189]: (n = 0 && n = 1) -> 10, (n = 2 && n = 3) -> 11 
	n -= (previous_max + 1);
	int position = n / digits;

	// Gets the complete number that corresponds to n
	int number = (int)pow(10, digits-1) + position;

	// Gets the digit of the number that corresponds to n
	return get_nth_digit( number, n % digits, digits );

}	


/**
 * Gets the product of the 1st, 10th, 100th, 1000th, 10000th, 100000th, and 1000000th decimal digits of champernowne's constant
 */
unsigned int champernowne_constant() {

	unsigned int ans = 1;

	// Iterates through the range [0, 7) to get the powers of 10
	for ( int i = 0; i < 7; i++ ) {
		ans *= nth_champernowne_constant( (int)pow(10, i) );
	}

	return ans;

}


int main(void) {
	printf("%u\n", champernowne_constant());	
	exit(EXIT_SUCCESS);
}
