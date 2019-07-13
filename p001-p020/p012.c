#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * Generates a sieve of prime numbers with a given size, starting with a specified start_index
 */
char* sieve_of_eratosthenes( char* sieve_arr, size_t size, int start_index ) {

	// Sets 0 and 1 to '0', as they are not prime
	sieve_arr[0] = '0';
	sieve_arr[1] = '0';

	// Using the Sieve of Eratosthenes method, loops from 2 to ceil(sqrt(size)) to find primes
	for ( int i = 2; i*i <= size; i++ ) {
		if ( sieve_arr[i] == '0' ) {
			continue;
		}
		int start = ( i*i > start_index ) ? i*i : start_index;
		for ( int j = start; j < size; j+=i ) {
			sieve_arr[j] = '0';
		}
	}

	// The char array now has prime indices as '1' and composite indices as '0' 
	return sieve_arr;

}


/**
 * Gets the number of divisors of a number
 */
unsigned int num_divisors( char* sieve_arr, int num ) {
	
	unsigned int divisors = 1;

	// Gets the prime factorization of num from the prime number sieve
	// From the prime factorization, num = (p0^a0)*(p1^a1)*...*(pn^an), where 'p' represents the prime number and 'a' represents the power
	// The number of divisors of num is given by (a0+1)*(a1+1)*...*(an+1)
	for ( int i = 2; i <= num; i++ ) {
		if ( sieve_arr[i] == '1' ) {
			int count = 0;
			while ( num % i == 0 ) {
				count++;
				num /= i;
			}
			divisors *= (count + 1);
		}
	}

	return divisors;

}


/**
 * Gets the first triangular number that has at least 500 divisors
 */
unsigned int highly_divisible_triangular_number() {
	
	int triangle_num = 0;
	int num = 1;
	size_t current_sieve_size = 50;
	
	// Dynamically allocates a char array to represent the prime number sieve
	char* sieve_arr = (char*)calloc(current_sieve_size, sizeof(char));
	memset( sieve_arr, '1', current_sieve_size*sizeof(char) );
	sieve_arr = sieve_of_eratosthenes( sieve_arr, current_sieve_size, 2 );	

	// Continues getting the next triangular number while the triangular number has less than 500 divisors
	do {
		triangle_num += num;
		num++;

		// Increases the size of the char array if the triangular number reaches the size of the array
		if ( triangle_num >= current_sieve_size ) {
			current_sieve_size *= 2;
			char* temp = (char*)realloc( sieve_arr, current_sieve_size*sizeof(char) );

			// Exits if realloc fails
			if ( temp == NULL ) {
				free( sieve_arr );
				fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
				return 0;

			}

			// Sets all newly added chars to the array to '1' and runs the Sieve of Eratosthenes method on the array
			memset( temp + (current_sieve_size/2), '1', (current_sieve_size/2)*sizeof(char) );
			sieve_arr = sieve_of_eratosthenes( temp, current_sieve_size, current_sieve_size/2 );
		}
	} while ( num_divisors( sieve_arr, triangle_num ) < 500 );

	// Frees the dynamically allocated char array and returns the result
	free( sieve_arr );
	return triangle_num;

}


int main(void) {
	printf("%u\n", highly_divisible_triangular_number());
	return 0;
}
