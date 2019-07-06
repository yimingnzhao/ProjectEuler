#include "stdio.h"


/**
 * Gets the product of the pythagorean triple such that a + b + c = 1000
 */
unsigned int special_pythagorean_product() {

    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;

    // According to Euclid's formula, given m > n > 0, and positive integer k:
    // There exists a = k*(m^2 - n^2), b = 2*k*m*n, c = k*(m^2 + n^2) such that a^2 + b^2 = c^2
    unsigned int k = 1;
    unsigned int m = 2;
    unsigned int n = 1;

    // Continues iteration of all m until the valid pythagorean triple is found
    while ( 1 ) {

        // Continues iteration of all n < m
        while ( n < m ) {
            a = m*m - n*n;
            b = 2*m*n;
            c = m*m + n*n;

            // Continues iteration until k causes a + b + c >= 1000
            while ( a + b + c < 1000 ) {
                a *= k;
                b *= k;
                c *= k;
                k++;
            }

            // Checks if the current pythagorean triple is valid
            if ( a + b + c == 1000 ) {
                return a*b*c;
            }

            n++;
        }

        m++;
        n = 1;
    }

}


int main(void) {
    printf("%u\n", special_pythagorean_product());
    return 0;
}
