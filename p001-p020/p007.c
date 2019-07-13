#include "stdio.h"


/**
 * Checks the primality of an integer
 */
unsigned int is_prime( int num ) {

    // Edge cases: 1 is not prime, 2 and 3 are prime
    if ( num <= 1 ) {
        return 0;
    }
    if ( num <= 3 ) {
        return 1;
    }

    // Numbers divisible by 2 or 3 are not prime
    if ( num % 2 == 0 || num % 3 == 0 ) {
        return 0;
    }

    // All numbers are in the form 6n+i, i = {0, 1, 2, 3, 4, 5}
    // 2 divides (6n+0), (6n+2), (6n+4) and 3 divides (6n+3)
    // Thus, all prime numbers are in the form 6n+1 or 6n+5
    // To check primality, check that i and i+2 do not divide num
    for ( int i = 5; i*i <= num; i+=6 ) {
        if ( num % i == 0 || num % (i + 2) == 0 ) {
            return 0;
        }
    }

    return 1;

}


/**
 * Gets the 10001st prime number
 */
unsigned int _10001st_prime() {    
    
    int count = 0;
    int num = 2;
    
    // Continues looping through integers until the 10001st prime is reached
    while ( 1 ) {

        // Increments the count of prime numbers if num is prime
        if ( is_prime(num) ) {
            count++;
        }

        // Returns the 10001st prime number
        if ( count == 10001 ) {
            return num;
        }

        num++;
    }

}


int main(void) {
    printf("%u\n", _10001st_prime());
    return 0;
}
