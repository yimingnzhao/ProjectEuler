#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Checks if a given number is prime
 */
unsigned int is_prime( int num ) {

	// Loops from [2, sqrt(num)]
	for ( int i = 2; i*i <= num; i++ ) {
		if ( num % i == 0 ) {
			return 0;
		}
	}

	return 1;

}


/**
 * Gets an array of primes using Sieve of Eratosthenes method to get primes
 */
int* get_primes( int* arr, int length ) {

	// Initializes an array for the sieve, initially set to all '1' chars
	unsigned int sieve_size = 1000;
	char sieve[sieve_size];
	memset( sieve, '1', sieve_size*sizeof(char) );

	// The numbers 0 and 1 are nonprime
	sieve[0] = '0';
	sieve[1] = '0';

	// Iterates from [2, sqrt(sieve_size)] to run the Sieve of Eratosthenes method
	for ( int i = 2; i*i <= sieve_size; i++ ) {
		if ( sieve[i] == '1' ) {
			for ( int j = i*i; j < sieve_size; j += i ) {
				sieve[j] = '0';
			}
		}
	}

	// Sets the prime numbers from the sieve array to the prime array
	int count = 0;
	for ( int i = 0; i < sieve_size; i++ ) {

		// If the prime array is not large enough, exits with error
		if ( count == length ) {
			free( arr );
			fprintf( stderr, "%s\n", "Error: Array does not have enough memory to fit all primes in the sieve" );
			exit(EXIT_FAILURE);
		}

		// Adds prime numbers to the prime array
		if ( sieve[i] == '1' ) {
			arr[count] = i;
			count++;
		}

	}

	return arr;

}


/**
 * Gets the product of a and b, |a| and |b| <= 1000
 * Given n^2 + a*n + b provides the largest consecutive values of prime for n, starting at n = 0 
 */
int quadratic_primes() {

	int longest = 0, a = 0, b = 0;

	// Gets a list of primes 
	int len_primes = 200;
	int* primes = calloc( len_primes, sizeof(int) );
	primes = get_primes( primes, len_primes );

	// Iterates through prime values of b and all values of a from [-1000, 1000]
	for ( int i = 0; i < len_primes; i++ ) {
		for ( int j = -1000; j <= 1000; j++ ) {
			
			// Continues incrementing n until n does not output a prime number
			int n = 0;
			while ( is_prime(abs(n*n + j*n + primes[i])) ) {
				n++;
			}

			// Checks if n is longer than the current longest consecutive count
			if ( n > longest ) {
				longest = n;
				a = primes[i];
				b = j;
			}

		}
	}

	free( primes );
	return a*b;

}



int main(void) {
	printf("%d\n", quadratic_primes());
	exit(EXIT_SUCCESS);
}
