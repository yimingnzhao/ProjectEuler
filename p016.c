#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Reverses the string 
 */
char* reverse( char* string ) {

	int len = strlen( string );

	// Swaps the character at index i with the character at index len-1-i
	for ( int i = 0; i < len/2; i++ ) {
		string[i] = string[len-1-i] ^ string[i];
		string[len-1-i] = string[len-1-i] ^ string[i];
		string[i] = string[len-1-i] ^ string[i];
	}

	return string;

}


/**
 * Multiplies the product string by 2 and returns the new product string
 */
char* multiply_by_2( char* product ) {

	int product_len = strlen( product );
	int overflow = 0;

	// Iterates through the characters of the product and multiplies it by 2
	// Note that product[0] is the least significant digit
	for ( int i = 0; i < product_len; i++ ) {
		int positional_product = (int)(product[i]-'0') * 2 + overflow;
		product[i] = (char)((positional_product%10) + '0');
		overflow = positional_product / 10;
	}

	// If there is overflow, dynamic memory is reallocated
	if ( overflow ) {
		char* temp = (char*)realloc( product, (product_len + 2)*sizeof(char));

		// Checks for reallocation error
		if ( temp == NULL ) {
			free( product );
			fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
			exit(EXIT_FAILURE);
		}

		// Sets the overflow digit and null terminates the string
		product = temp;
		product[product_len] = (char)(overflow+'0');
		product[product_len+1] = '\0';
	}

	return product;

}


/**
 * Gets the sum of the digits in 2^1000
 */
unsigned int power_digit_sum() {

	int exponent = 1000;	

	// Dynamically allocates a char array to represent the product
	char* product = (char*)calloc(2, sizeof(char));
	product[0] = '1';
	product[1] = '\0';

	// Gets the power through continuous multiplication
	// Note that the product string digits are in reverse proder
	for ( int i = 0; i < exponent; i++ ) {
		product = multiply_by_2( product );
	}

	// Reverses the chars in the string to get the real representation
	product = reverse( product );	

	// Gets the sum of the digits
	unsigned int sum = 0;
	char* ptr = product;
	do {
		char addend = *ptr++;
		sum += (int)(addend - '0');
	} while ( *ptr != '\0' );

	free(product);
	return sum;

}


int main(void) {
	printf("%u\n", power_digit_sum());
	exit(EXIT_SUCCESS);
}
