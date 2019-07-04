#include "stdio.h"


/**
 * Gets the smallest integer that can be divided by all integers [1, 20]
 */
unsigned int smallest_multiple() {
    
    unsigned int num = 20;

    // Continues iterating through numbers until the condition is met
    while ( 1 ) {

        // Declares a boolean to ensure all integers [1, 20] divides num
        int is_smallest_multiple = 1;

        // Loops through the integers [1, 20]
        // The boolean value is set to false if any integer does not divide num
        for ( int i = 1; i <= 20; i++ ) {
            if ( num % i != 0 ) {
                is_smallest_multiple = 0;
                break;
            }
        }

        // Returns num if all integers [1, 20] divide num
        // Else, num is incremented
        if ( is_smallest_multiple ) {
            return num;
        }
        num++;
    }

}


int main(void) {
    printf("%u\n", smallest_multiple() );
    return 0;
}
