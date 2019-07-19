#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Gets the next lexicographic permutation of a string representation of a number
 */
char* get_next_lexicographic_permutation( char* nums, int len ) {

	// Gets the pivot point, defined by the character index right before the longest non-increasing suffix
	int pivot = -1;
	for ( int i = len - 1; i > 0; i-- ) {
		if ( nums[i] > nums[i-1] ) {
			pivot = i - 1;
			break;
		}
	}

	// Checks if the pivot does not exist, that is, nums is already the largest lexicographic permutation
	if ( pivot == -1 ) {
		return NULL;
	}

	// Gets the smallest digit larger than the pivot 
	char min = ':';
	int min_pos = len - 1;
	for ( int i = pivot + 1; i < len; i++ ) {
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
	for ( int i = pivot + 1; i < (len + pivot + 1)/2; i++ ) {
		nums[i] = nums[ len + pivot - i ] ^ nums[i];
		nums[ len + pivot - i ] = nums[ len + pivot - i ] ^ nums[i];
		nums[i] = nums[ len + pivot - i ] ^ nums[i];
	}

	return nums;
		
}


/**
 * Gets the 1000000th lexicographic permutation
 */
long lexicographic_permutations() {
	
	char nums[] = "0123456789";
	int nums_len = 10;

	// Iterates 999999 times, as the first lexicographic permutation is already known
	for ( int i = 1; i < 1000000; i++ ) {
		get_next_lexicographic_permutation(nums, nums_len);
	}

	// Converts the string to a long integer
	char* endptr;
	long result = strtol( nums, &endptr, 10 );	
	return result;

}


int main(void) {
	printf("%ld\n", lexicographic_permutations());
	exit(EXIT_SUCCESS);
}
