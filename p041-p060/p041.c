#include "stdio.h"
#include "stdlib.h"
#include "../DataStructures/prime.h"
#include "../DataStructures/number.h"

// NOTE: To compile, run 'gcc p041.c ../DataStructures/prime.c ../DataStructures/number.c -lm'

unsigned int pandigital_prime() {

	// One Digit Pandigitals: Contains the set {1}, which has no prime numbers
	// Two Digit Pandigitals: Contains the set {12, 21}, which has no prime numbers
	// Three Digit Pandigitals: All are divisible by 3, so there are no prime numbers
	// Four Digit Pandigitals: Need to be checked
	// Five Digit Pandigitals: All are divisible by 3, so there are no prime numbers
	// Six Digit Pandigitals: All are divisible by 3, so there are no prime numbers
	// Seven Digit Pandigitals: Need to be checked
	// Eight Digit Pandigitals: All are divisible by 3, so there are no prime numbers
	// Nine Digit Pandigitals: All are divisible by 3, so there are no prime numbers
	
	unsigned int largest = 0;
	
	// Checks all four digit pandigitals for primality
	int num = 1234;
	do {
		if ( is_prime(num) == 1 ) {
			largest = ( num > largest ) ? num : largest;
		}
		num = next_permutation( num );
	} while ( num != -1 );

	// Checks all seven digit pandigitals for primality
	num = 1234567;
	do {
		if ( is_prime(num) == 1 ) {
			largest = ( num > largest ) ? num : largest;
		}
		num = next_permutation( num );
	} while ( num != -1 );

	return largest;

}


int main(void) {
	printf("%u\n", pandigital_prime());
	exit(EXIT_SUCCESS);
}
