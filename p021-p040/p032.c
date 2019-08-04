#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../DataStructures/hashtable.h"

// NOTE: To compile, run 'gcc p032.c ../DataStructures/hashtable.c ../DataStructures/prime.c -lm'


/**
 * Gets the next lexigraphic permutation of a string representation of an integer
 */
char* get_next_lexigraphic_permutation( char* num, int length ) {

	// Gets pivot point
	int pivot_pos = -1;
	for ( int i = length - 1; i > 0; i-- ) {
		if ( num[i] > num[i-1] ) {
			pivot_pos = i - 1;
			break;
		}
	}
	if ( pivot_pos == -1 ) {
		return NULL;
	}

	// Gets the rightmost digit larger than the pivot
	int swap_index = length - 1;
	char min = ':';
	for ( int i = pivot_pos + 1; i < length; i++ ) {
		if ( num[i] > num[ pivot_pos ] && min > num[i] ) {
			swap_index = i;
			min = num[i];
		}
	}

	// Swaps the pivot_pos and swap_index
	num[ pivot_pos ] = num[ pivot_pos ] ^ num[ swap_index ];
	num[ swap_index ] = num[ pivot_pos ] ^ num[ swap_index ];
	num[ pivot_pos ] = num[ pivot_pos ] ^ num[ swap_index ];

	// Reverses the substring past the pivot_pos
	for ( int i = pivot_pos + 1; i < (length + pivot_pos + 1) / 2; i++ ) {
		num[i] = num[ length + pivot_pos - i ] ^ num[i];
		num[ length + pivot_pos - i ] = num[ length + pivot_pos - i ] ^ num[i];
		num[i] = num[ length + pivot_pos - i ] ^ num[i];
	}

	return num;

}


/**
 * Gets the sum of all products whose (multiplicand, multiplier, product) triplet can be written as a 1 through 9 pandigital
 */
unsigned int pandigital_products() {

	// Defines necessary local variables
	unsigned int sum = 0;
	unsigned int base = 10;
	char* endptr = NULL;
	unsigned int num_len = 9;

	// Initializes a hashtable to ensure no duplicates are added
	ht_hash_table* ht = ht_constructor();

	// Initializes a string to represent the lowest integer of digits 1 through 9
	char* num = calloc( num_len + 1, sizeof(char) );
	strcpy( num, "123456789" );

	// Loops through all possible combinations of (multiplicand, multiplier, product) triplets of num
	// Then, the next lexigraphic permutation of num is computed
	do {
		for ( int i = 1; i < num_len - 1; i++ ) {
			for ( int j = i + 1; j < num_len; j++ ) {
				
				// Defines the string representations of the triplet (multiplicand, multiplier, product)
				char a_str[i + 1];
				memcpy( a_str, num, i );
				a_str[i] = '\0';
				char b_str[j - i + 1];
				memcpy( b_str, &num[i], j - i );
				b_str[j - i] = '\0';
				char c_str[num_len - j];
				memcpy( c_str, &num[j], num_len - j );
				c_str[num_len - j] = '\0';

				// Defines the integer representations
				endptr = NULL;
				int a = strtol( a_str, &endptr, base );
				endptr = NULL;
				int b = strtol( b_str, &endptr, base );
				endptr = NULL;
				int c = strtol( c_str, &endptr, base );

				// Checks if a * b = c and that c is not in the hashtable
				if ( a * b == c && ht_search( ht, c ) == -1 ) {
					sum += c;
					ht_insert( ht, c, 1 );
				}

			}
		}
	} while ( get_next_lexigraphic_permutation( num, num_len ) != NULL );

	ht_deconstruct( ht );
	free( num );
	return sum;

}


int main(void) {
	printf("%u\n", pandigital_products());
	exit(EXIT_SUCCESS);
}
