#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the greatest common denominator of two positive integers using the Euclidian Algorithm
 */
unsigned int gcd( unsigned int a, unsigned int b ) {

	// If a is zero, then the gcd is b
	if ( a == 0 ) {
		return b;
	}

	// If b is zero, then the gcd is a
	if ( b == 0 ) {
		return a;
	}

	// Base Case: If a and b are equal, then the gcd is that number
	if ( a == b ) {
		return a;
	}

	//By the Euclidean Algorithm, the gcd of two numbers can be calculated by repeatedly subtracting the smaller number from the larger one
	if ( a > b ) {
		return gcd( a - b, b );
	}
	return gcd( a, b - a );

}


/**
 * Gets the reduced fraction form of the numerator and denominator
 */
void reduce_fraction( unsigned int numerator, unsigned int denominator, int* reduced_numerator, int* reduced_denominator ) {

	// Gets the gcd to divide the numerator and denominator by
	int divisor = gcd( numerator, denominator );
	numerator /= divisor;
	denominator /= divisor;

	// Assigns the reduced numerator and denominator to pointers
	*reduced_numerator = numerator;
	*reduced_denominator = denominator;

}


/**
 * Returns the denominator of the product of the two digit fractions that are digit cancelling, in lowest terms
 */
unsigned int digit_cancelling_fractions() {

	// The range for two digit denominator
	unsigned int min_denominator = 12;
	unsigned int max_denominator = 99;

	// Local variables to store results
	unsigned int numerator_result = 1;
	unsigned int denominator_result = 1;
	int numerator1;
	int numerator2;
	int denominator1;
	int denominator2;

	// Loops through all possible denominators
	for ( int i = min_denominator; i <= max_denominator; i++ ) {
		
		// Skips through trivial denominators (denominators that are divisible by 10)
		if ( i % 10 == 0 ) {
			continue;
		}

		// Gets each digit of the denominator
		int ones_digit = i % 10;
		int tens_digit = i / 10;

		// Loops through all possible two digit numerators that create a fraction less than 1
		for ( int j = min_denominator - 1; j < i; j++ ) {

			// Gets each digit of the numerator
			int numerator_ones = j % 10;
			int numerator_tens = j / 10;

			// Checks all four possibilities if the two digit fraction is digit cancelling
			if ( numerator_ones == ones_digit ) {
				reduce_fraction( j, i, &numerator1, &denominator1 );
				reduce_fraction( j/10, i/10, &numerator2, &denominator2 );
				if ( numerator1 == numerator2 && denominator1 == denominator2 ) {
					numerator_result *= numerator1;
					denominator_result *= denominator1;
				}
			}
			if ( numerator_ones == tens_digit ) {
				reduce_fraction( j, i, &numerator1, &denominator1 );
				reduce_fraction( j/10, i%10, &numerator2, &denominator2 );
				if ( numerator1 == numerator2 && denominator1 == denominator2 ) {
					numerator_result *= numerator1;
					denominator_result *= denominator1;
				}
			}
			if ( numerator_tens == ones_digit ) {
				reduce_fraction( j, i, &numerator1, &denominator1 );
				reduce_fraction( j%10, i/10, &numerator2, &denominator2 );
				if ( numerator1 == numerator2 && denominator1 == denominator2 ) {
					numerator_result *= numerator1;
					denominator_result *= denominator1;
				}
			}
			if ( numerator_tens == tens_digit ) {
				reduce_fraction( j, i, &numerator1, &denominator1 );
				reduce_fraction( j%10, i%10, &numerator2, &denominator2 );
				if ( numerator1 == numerator2 && denominator1 == denominator2 ) {
					numerator_result *= numerator1;
					denominator_result *= denominator1;
				}
			}

		}

	}

	// Reduces the resulting fraction into lowest terms and returns the denominator
	reduce_fraction( numerator_result, denominator_result, &numerator1, &denominator1 );
	return (unsigned int)denominator1;

}


int main(void) {
	printf("%u\n", digit_cancelling_fractions());
	exit(EXIT_SUCCESS);
}
