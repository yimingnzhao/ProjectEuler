#include "math.h"
#include "prime.h"
#include "stdlib.h"
#include "string.h"


/**
 * Checks if x is prime
 * 		Returns -1 if x is an invalid argument
 * 		Returns 0 if x is not a prime number
 * 		REturns 1 if x is a prime number
 */
int is_prime( const int x ) {

	// Integers less than 2 are not prime
	if ( x < 2 ) {
		return -1;
	}

	// Integers 2 and 3 are prime
	if ( x < 4 ) {
		return 1;
	}

	// Even integers are not prime
	if ( x % 2 == 0 ) {
		return 0;
	}

	// Checks if x is divisible by integers [3, ceil(sqrt(x))]
	int limit = ceil(sqrt(x));
	for ( int i = 3; i <= limit; i += 2 ) {
		if ( x % i == 0 ) {
			return 0;
		}
	}

	return 1;

}


/**
 * Returns the next prime number
 */
int next_prime( int x ) {

	// Continues to increment x until the next prime is found
	do {
		x++;
	} while ( is_prime( x ) != 1 );
	
	return x;

}


/**
 * Returns the previous prime number
 * Error Case: returns -1 when the previous prime number does not exist
 */
int previous_prime( int x ) {

	// Continues to decrement x until the previous prime is found
	do {
		x--;
		if ( x < 2 ) {
			return -1;
		}
	} while ( is_prime( x ) != 1 );

	return x;
}


/**
 * Gets a list of prime numbers up to the limit
 */
int* sieve_of_eratosthenes( unsigned int limit, int* length ) {

	// Initializes a char array to run the Sieve of Eratosthenes method
	char sieve[ limit + 1 ];
	memset( sieve, '1', (limit + 1) * sizeof(char) );
	sieve[0] = '0';
	sieve[1] = '0';

	// Loops from [2, limit] to run the sieve method
	unsigned int prime_count = 0;
	for ( int i = 2; i <= limit; i++ ) {

		if ( sieve[i] == '0' ) {
			continue;
		}

		prime_count++;
		for ( int j = i*i; j <= limit; j += i ) {
			sieve[j] = '0';
		}

	}

	// Dynamically allocates an array to store the prime numbers from the sieve
	*length = prime_count;
	int* primes = calloc( prime_count, sizeof(int) );

	// Loops through the contents of the sieve to store prime numbers
	int count = 0;
	for ( int i = 0; i <= limit; i++ ) {
		if ( sieve[i] == '1' ) {
			primes[ count ] = i;
			count++;
		}
	}

	return primes;

}
