#include "stdio.h"


/**
 * Gets the sum of the even finonacci numbers in the range (0, 4000000)
 */
unsigned int even_fibonacci_numbers() {
    
    // Assigns the values of the first two fibonacci numbers
    unsigned int f0 = 1;
    unsigned int f1 = 2;
    unsigned int sum = 0;

    // While the larger fibonacci number is less than 4000000, the next fibonacci number is calculated
    while ( f1 < 4000000 ) {

        // Adds the larger fibonacci number to sum if the larger fibonacci number is even
        if ( f1 % 2 == 0 ) {
            sum += f1;
        }
        
        // Calculates the next fibonacci number by first swapping the two fibonacci numbers, such that f0 > f1
        // Next, f1 is assigned to the sum of f0 and f1, thus getting the next fibonacci number while maintaining f0 as the fibonacci number before f1
        f0 = f0 ^ f1;
        f1 = f0 ^ f1;
        f0 = f0 ^ f1;
        f1 = f0 + f1;

    }

    return sum;

}


int main(void) {
    printf("%u\n", even_fibonacci_numbers());
    return 0;
}
