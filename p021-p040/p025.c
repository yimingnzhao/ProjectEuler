#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// NOTE: TO compile with the math library, run 'gcc p025.c -lm'


/**
 * Gets the index of the first fibonacci number that has 1000 digits
 */
unsigned int _1000_digit_fibonacci_number() {

	// A version of Binet's Formula states that the nth fibonacci number is the integer closest to pow(phi, n)/sqrt(5), where phi is the golden ratio
	// Thus: 
	// 		pow(phi, n)/sqrt(5) >= pow(10, 999)
	//		log(pow(phi, n)) - log(sqrt(5)) >= log(pow(10, 999))
	//		n*log(phi) - log(sqrt(5)) >= 999*log(10)
	//		n = (999*log(10) + log(sqrt(5)) / log(phi)
	//		n = round( (999*log(10) + log(sqrt(5)) / log(phi) )
	double phi = (sqrt(5) + 1) / 2;
	return (unsigned int)( round((999*log(10) + log(sqrt(5))) / (log(phi))) );

}


int main(void) {
	printf("%u\n", _1000_digit_fibonacci_number());	
	return 0;
}
