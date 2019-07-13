#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Gets the max of a and b
 */
int max( int a, int b ) {

	return ( a > b ) ? a : b;

}


/**
 * Gets the maximum path of the triangle by summing the digits from the top to the base
 */
unsigned int maximum_path_sum_I() {

	// Declares the triangle as a string of integers seperated by spaces
	char triangle[] = 
		"75 "
		"95 64 "
		"17 47 82 "
		"18 35 87 10 "
		"20 04 82 47 65 "
		"19 01 23 75 03 34 "
		"88 02 77 73 07 63 67 "
		"99 65 04 28 06 16 70 92 "
		"41 41 26 56 83 40 80 70 33 "
		"41 48 72 33 47 32 37 16 94 29 "
		"53 71 44 65 25 43 91 52 97 51 14 "
		"70 11 33 28 77 73 17 78 39 68 17 57 "
		"91 71 52 38 17 14 91 43 58 50 27 29 48 "
		"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
		"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

	// Declares constants and local variables for string tokenizing and converting string to integers
	const unsigned int triangle_base = 15;
	char* delim = " ";
	char* token;
	const int base = 10;
	char* endptr;

	// Declares the array to store potential maximum values 
	int sum_arr[triangle_base];
	memset( sum_arr, 0, triangle_base*sizeof(int) );

	// Tokenizes the tip of the triangle to begin the summation process
	token = strtok( triangle, delim );
	sum_arr[0] = strtol( token, &endptr, base );

	// Loops through each level of the triangle
	for ( int i = 2; i <= triangle_base; i++ ) {

		// Initializes a temporary array to store the current sums
		int current_arr[i];
		memset( current_arr, 0, i*sizeof(int) );

		// Tokenizes each number at the current triangle level
		for ( int j = 0; j < i; j++ ) {
			endptr = NULL;
			token = strtok( NULL, delim );
			int current_num = strtol( token, &endptr, base );

			// Case 1a: Number is the left-most integer at the triangle level, only one possible path
			// Case 1b: Number is the right-most integer at the triangle level, only one possible path
			// Case 2: Number is not on the edge of the triangle, take the max of the two possible paths
			if ( j == 0 ) {
				current_arr[j] = current_num + sum_arr[0];
			} else if ( j == i - 1 ) {
				current_arr[j] = current_num + sum_arr[j - 1];	
			} else {
				current_arr[j] = max( current_num + sum_arr[j], current_num + sum_arr[j - 1] );
			}

		}

		// Sets the contents of the temporary array to the sum array
		for ( int j = 0; j < i; j++ ) {
			sum_arr[j] = current_arr[j];
		}

	}

	// Finds the max number after reaching the base of the triangle, and returns it
	unsigned int max_sum = *sum_arr;
	for ( int i = 0; i < triangle_base; i++ ) {
		if ( sum_arr[i] > max_sum ) {
			max_sum = sum_arr[i];
		}	
	}

	return max_sum;	

}


int main(void) {
	printf("%u\n", maximum_path_sum_I());
	exit(EXIT_SUCCESS);
}
