#include "stdio.h"
#include "stdlib.h"


/**
 * Struct for an array of ints 
 */
typedef struct IntArray {

	unsigned int size;
	unsigned int capacity;
	int* array;

} IntArray;


/**
 * Constructs a struct IntArray with dynamically allocated data
 */
IntArray* constructor() {
	
	// Dynamically allocates space for the int array and the IntArray struct
	IntArray* arr = malloc( sizeof(IntArray) );
	arr->array = calloc( 10, sizeof(int) );
	arr->size = 0;
	arr->capacity = 10;

	return arr;

}


/**
 * Frees all dynamically allocated daya
 */
void destructor( IntArray* arr ) {

	free( arr->array );
	free( arr );

}


/**
 * Increases the capacity of the int array by a factor of 2
 */
IntArray* increase_capacity( IntArray* arr ) {

	// Reallocates data to double the capacity of the array
	int* temp = realloc( arr->array, (2 * arr->capacity) * sizeof(int) );

	// Checks for realloc errors
	if ( temp == NULL ) {
		destructor( arr );
		fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
		exit(EXIT_FAILURE);
	}

	// Updates the parameters of the IntArray
	arr->array = temp;
	arr->capacity *= 2;
	return arr;

}


/**
 * Appends the int, num, to the end of the int array
 */
void add( IntArray* arr, int num ) {

	// Checks if the size of the array is equal to its capacity
	if ( arr->size + 1 == arr->capacity ) {
		arr = increase_capacity( arr );
	}

	// Adds num to the end of the array
	arr->array[ arr->size ] = num;
	arr->size += 1;

}


/**
 * Function to compare two ints
 */
int compare_ints( const void* a, const void* b ) {
	
	return *(int*)a - *(int*)b;

}


/**
 * Checks if num is an abundant number, that is, the sum of its proper divisors is greater than itself
 */
unsigned int is_abundant( int num ) {

	unsigned int sum = 0;

	// Iterates through the numbers [1, sqrt(num)]
	for ( int i = 1; i*i <= num; i++ ) {

		// Checks if i is a proper divisor of num
		if ( num % i == 0 ) {
			if ( i*i == num ) {
				sum += i;
			} else {
				sum += i;
				sum += num / i;
			}
		}

	}

	// Subtracts sum by num, as a number is not a proper divisor of itself
	sum -= num;
	return ( sum > num ) ? 1 : 0;

}


/**
 * Gets the sum of all positive integers that cannot be written as the sum of two abundant numbers
 */
long non_abundant_sums() {

	// All integers greater than 28123 can be written as a sum of two abundant numbers
	unsigned int max = 28123;

	IntArray* arr = constructor();
	long sum = 0;

	// Iterates through positive numbers [1, 28123]
	for ( int i = 1; i <= max; i++ ) {

		// Adds abundant numbers to an array
		if ( is_abundant(i) ) {
			add( arr, i );
		}

		// Checks if the current iteration, i, has an abundant sum
		// This is done by iterating through the current array of abundant numbers and checking if i - j is also in the array
		int has_abundant_sum = 0;
		for ( int j = 0; j < arr->size; j++ ) {
			int target = i - arr->array[j];
			int* index = (int*)bsearch( &target, arr->array, arr->size, sizeof(int), compare_ints );
			if ( index != NULL ) {
				has_abundant_sum = 1;
				break;
			}
		}

		// The sum is incremented if i does not have an abundant sum 
		if ( !has_abundant_sum ) {
			sum += i;
		}

	}

	destructor( arr );
	return sum;

}


int main(void) {
	printf("%ld\n", non_abundant_sums());
	exit(EXIT_SUCCESS);
}

