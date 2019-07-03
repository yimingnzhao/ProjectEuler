#include "stdio.h"


/**
 * Gets the sum of the multiples of 3 and 5 in the range (0, 1000)
 */
unsigned int multiples_of_3_and_5() {
    
    unsigned int sum = 0;

    // Loops through the integers from [0, 1000)
    for ( int i = 0; i < 1000; i++ ) {
        
        // Adds multiples of 3 to the sum
        if ( i % 3 == 0 ) {
            sum += i;
        }

        // Adds multiples of 5 to the sum
        if ( i % 5 == 0 ) {
            sum += i;
        }

        // By the Principle of Inclusion Exclusion, multiples of 3 and 5 are double counted
        // Thus, multiples of 3*5 should be removed once
        if ( i % 15 == 0 ) {
            sum -= i;
        }

    }

    return sum;

}


int main(void) {
	printf("%u\n", multiples_of_3_and_5());
	return 0;
}
