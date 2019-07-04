#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the difference between the sum of squares of the first 100 integers and the square of the sum of the first 100 integers
 */
unsigned int sum_square_difference() {

    int n = 100;

    // The sum of squares of the first n numbers is given by (n(n+1)(2n+1)/6)
    int sum_of_squares = ( n * (n + 1) * (2 * n + 1) ) / 6;

    // The sum of the first n numbers is given by (n(n+1)/2)
    int square_of_sums = ( (n * (n + 1)) / 2 ) * ( (n * (n + 1)) / 2 );

    return abs( sum_of_squares - square_of_sums );

}


int main(void) {
    printf("%u\n", sum_square_difference() );
    return 0;
}
