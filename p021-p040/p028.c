#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the sum of the diagonals of a 1001 x 1001 square spiral 
 * The spiral is constructed with incrementing numbers in a clockwise rotation starting with 1 in the middle
 */
unsigned int number_spiral_diagonals() {

	// Starting in the middle, the first number is 1, making the count = 1
	unsigned int count = 1;
	int decrement = 2;

	// With each box, going outwards, the largest number in that box happens to be on the diagonal 
	// This number is the next odd number squared, that is, the largest number in the i-th box is (2*i - 1)^2
	// The other three diagonal numbers on the i-th box are (2*i - 1)^2 - j(2*i - 2), 0 < j < 4
	// Thus, the four diagonal numbers on the i-th box are given by:
	// 		(2*i - 1)^2
	// 		(2*i - 1)^2 - 2*i - 2
	// 		(2*i - 1)^2 - 4*i - 4
	// 		(2*i - 1)^2 - 6*i - 6
	// Thus, the sum of diagonals of the i-th box is 4*((2*i - 1)^2) - 6*(2*i - 2)		
	for ( int i = 3; i <= 1001; i += 2 ) {
		int square = i*i;
		count += 4*square - 6*decrement;
		decrement += 2;
	}

	return count;

}


int main(void) {
	printf("%u\n", number_spiral_diagonals());
	exit(EXIT_SUCCESS);
}
