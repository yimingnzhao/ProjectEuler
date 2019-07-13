#include "stdio.h"
#include "math.h"

// NOTE: To compile with the math library, run 'gcc p003.c -lm'


/**
 * Checks if the parameter (num) is a prime number 
 */
unsigned int is_prime( int num ) {

    // Sets the greatest possible factor, ceil(sqrt(num)), as the upper limit
    int limit = (int)ceil(sqrt(num));

    // Iterates from [2, limit] to check if i divides num
    for ( int i = 2; i <= limit; i++ ) {
        if ( num % i == 0 ) {
           return 0;
        } 
    }

    return 1;

}


/**
 * Gets the largest prime factor of 600851475143
 */
unsigned int largest_prime_factor() {

    long num = 600851475143;
    
    // Sets the variable largest_prime to the smallest possible prime number
    unsigned int largest_prime = 2;

    // Sets the greatest possible factor, ceil(sqrt(num)), as the upper limit
    int limit = (int)ceil(sqrt(num));

    // Iterates from [3, limit] to check if i divides num and i is prime
    for ( int i = 3; i <= limit; i++ ) {
        if ( num % i == 0 && is_prime(i) == 1 ) {
            largest_prime = i;
        }
    }

    return largest_prime;

}


int main(void) {
    printf("%u\n", largest_prime_factor() );
    return 0;
}
