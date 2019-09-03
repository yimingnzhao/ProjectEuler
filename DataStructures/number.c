#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "number.h"


/**
 * Checks if num is pandigital for digits [1, limit]
 * Error Case: returns -1 when limit is not a single digit number
 */
int is_pandigital( int num, int limit ) {

	// Error when limit is not a one digit number
	if ( limit > 9 ) {
		return -1;
	}

	// Gets the sum of digits in range [1, limit]
	int total = (limit * (limit + 1)) / 2;
	int count = 0;

	// Continuously subtracts the least significant digit from total
	while ( num > 0 ) {
		total -= (num % 10);
		num /= 10;
		count++;
	}

	return (total == 0 && count == limit) ? 1 : 0;

}


/**
 * Returns the number of digits in num
 */
int num_digits( int num ) {

	// Edge Case: num is 0
	if ( num == 0 ) {
		return 1;
	}

	// Continuously divides num by 10 to count digits
	int count = 0;
	while ( num > 0 ) {
		num /= 10;
		count++;
	}

	return count;

}


/**
 * Gets the next lexigraphical permutation of a number
 */
int next_permutation( int num ) {

	// Converts the int into a string
	int digits = num_digits( num );
	char nums[digits + 1];
	snprintf( nums, digits + 1, "%d", num );

	// Gets the pivot point, defined by the character index right before the longest non-increasing suffix
	int pivot = -1;
	for ( int i = digits - 1; i > 0; i-- ) {
		if ( nums[i] > nums[i-1] ) {
			pivot = i - 1;
			break;
		}
	}

	// Checks if the pivot does not exist, that is, nums is already the largest lexicographic permutation
	if ( pivot == -1 ) {
		return -1;
	}

	// Gets the smallest digit larger than the pivot 
	char min = ':';
	int min_pos = digits - 1;
	for ( int i = pivot + 1; i < digits; i++ ) {
		if ( nums[i] > nums[ pivot ] && min > nums[i] ) {
			min = nums[i];
			min_pos = i;
		}
	}

	// Swaps min_pos and the pivot characters
	char* ptr = nums;	
	*(ptr + pivot) = nums[ pivot ] ^ nums[ min_pos ];
	*(ptr + min_pos) = nums[ pivot ] ^ nums[ min_pos ];
	*(ptr + pivot) = nums[ pivot ] ^ nums[ min_pos ]; 

	// Reverses the characters greater than pivot 
	for ( int i = pivot + 1; i < (digits + pivot + 1)/2; i++ ) {
		nums[i] = nums[ digits + pivot - i ] ^ nums[i];
		nums[ digits + pivot - i ] = nums[ digits + pivot - i ] ^ nums[i];
		nums[i] = nums[ digits + pivot - i ] ^ nums[i];
	}

	// Converts the string to int
	char* endptr;
	int result = (int)strtol( nums, &endptr, 10 ); 
	return result;

}
