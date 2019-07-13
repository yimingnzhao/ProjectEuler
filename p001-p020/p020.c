#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Reverses the string
 */
char* reverse( char* str ) {

	int len = strlen( str );
	
	// Swaps the char at position i with the char at position len-1-i
	for ( int i = 0; i < len/2; i++ ) {
		str[i] = str[i] ^ str[ len-1-i ];
		str[len-1-i] = str[i] ^ str[ len-1-i ];
		str[i] = str[i] ^ str[ len-1-i ];
	}

	return str;

}


/**
 * Multiplies the string, product (digits in reverse order), by the factor
 */
char* multiply( int factor, char* product ) {

	int product_len = strlen(product);

	// Multiplies the factor by each digit in product
	int carry = 0;
	for ( int i = 0; i < product_len; i++ ) {
		int positional_product = (int)(product[i] - '0') * factor + carry;
		product[i] = (char)(positional_product % 10 + '0');
		carry = positional_product / 10;
	}

	// Sets the carry chars to the end of the product
	while ( carry != 0 ) {

		// Reallocs more space for the carry chars
		char* temp = realloc(product, (product_len + 2)*sizeof(char));
		
		// Checks for memory errors
		if ( temp == NULL ) {
			fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
			free( product );
			exit(EXIT_FAILURE);
		}

		// Sets the null terminating character at the end
		product = temp;
		product[product_len + 1] = '\0';

		// Assigns the least significant digit of carry to the end of product
		product[product_len] = (char)(carry % 10 + '0');
		carry = carry / 10;
		product_len = strlen( product );

	}

	return product;

}


/**
 * Gets the factorial of num, and sets the solution to the result string
 */
char* factorial( unsigned int num, char* result ) {
	
	int result_len = strlen( result );
	
	// Checks if result is a nonempty string
	if ( result_len == 0 ) {

		// Reallocs space for one character
		char* temp = realloc(result, 2*sizeof(char));

		// Checks for memory errors
		if ( temp == NULL ) {
			fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
			free( result );
			exit(EXIT_FAILURE);
		}

		// Sets the null terminating character at the end
		result = temp;
		result[result_len + 1] = '\0';
		result_len = strlen( result );
	}

	// Sets all chars to '0', except for the first character, which is set to '1'
	memset( result, '0', result_len*sizeof(char) );
	result[0] = '1';

	// Continuously multiplies to compute the factorial 
	for ( int i = 2; i <= num; i++ ) {
		result = multiply( i, result );
	}

	result = reverse( result );
	return result;

}


/**
 * Calculates the sum of the digits in 100 factorials (100!)
 */
unsigned int factorial_digit_sum() {

	unsigned int num = 100;
	
	// Dynamically allocates data for the result of 100!
	char* result = malloc( sizeof(char) );
	*result = '\0';

	// Gets the factorial 
	result = factorial( 100, result );

	// Loops through the digits of the result 
	unsigned int sum = 0;
	int result_len = strlen( result );
	for ( int i = 0; i < result_len; i++ ) {
		sum += (int)(result[i] - '0');
	}

	free( result );
	return sum;

}


int main(void) {
	printf("%u\n", factorial_digit_sum());
	exit(EXIT_SUCCESS);
}
