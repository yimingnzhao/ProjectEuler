#include "stdio.h"
#include "string.h"


/**
 * Gets the sum of all prime numbers less than 2000000
 */
long summation_of_primes() {

    int upper_limit = 2000000;

    // Initailizes a char array of size 2000000, and sets all chars to '1'
    char sieve_arr[upper_limit];
    memset( sieve_arr, '1', upper_limit*sizeof(char) );

    // Sets integers 0 and 1 to '0', as they are not prime
    sieve_arr[0] = '0';
    sieve_arr[1] = '0';

    // Using the Sieve of Eratosthenes method, sets all composite indices of the char array to '0'
    for ( int i = 0; i*i <= upper_limit; i++ ) {
        
        if ( sieve_arr[i] == '0' ) {
            continue;
        }

        // If i is prime, the smallest integer that has not yet been marked as composite is i^2
        for ( int j = i*i; j < upper_limit; j += i ) {
            sieve_arr[j] = '0';
        }

    }

    // All prime numbers less than 2000000 have indices of '1' in the char array
    long sum = 0;
    for ( int i = 0; i < upper_limit; i++ ) {
        if ( sieve_arr[i] == '1' ) {
            sum += i;
        }
    }

    return sum;

}


int main(void) {
    printf("%ld\n", summation_of_primes());
    return 0;
}
