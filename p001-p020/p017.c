#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the number of letters needed to spell out num
 */
unsigned int num_characters( int num, int* letter_counts ) {

	// Base Case 1: Since only positive numbers are considered, 0 letters are needed for num = 0
	if ( num == 0 ) {
		return 0;
	}

	// Base Case 2a: Numbers [1, 9] are the least significant digits, thus, will require no further recursive calls
	// Base Case 2b: Numbers [10, 19] do not follow the regular pattern of spelling
	if ( num > 0 && num < 20 ) {
		return letter_counts[num];
	}

	// Recursive Case 1: Numbers [20, 99] have two digits, and the one's place is still needed to be calculated
	if ( num >= 20 && num < 100 ) {
		return letter_counts[ 20 + num/10 - 2] + num_characters( num % 10, letter_counts );
	}

	// Recursive Case 2a: Numbers [100, 999] have three digits and the ten's place still need to be calculated, so the word "and" is needed
	// Recursive Case 2b: Numbers {100, 200, 300,..., 900} do not need any more place values to be calculated, so the word "and" is not needed
	if ( num >= 100 && num < 1000 ) {
		if ( num % 100 > 0 ) {
			return letter_counts[ num / 100 ] + letter_counts[28] + 3 + num_characters( num % 100, letter_counts );
		}
		return letter_counts[ num / 100 ] + letter_counts[28];
	}

	// Base Case 3: The number 1000 is the largest number that is necessary, and does not need any more place values to be calculated
	return letter_counts[1] + letter_counts[29];

}


/**
 * Gets the sum of the letters needed to spell out all numbers from range [1, 1000]
 */
unsigned int number_letter_counts() {

	// Allocates memory to store the number of letters for necessary numbers
	int arr_size = 30;
	int* letter_counts = malloc( arr_size*sizeof(int) );

	letter_counts[0] = 0;	// Zero
	letter_counts[1] = 3;	// One
	letter_counts[2] = 3;	// Two
	letter_counts[3] = 5;	// Three
	letter_counts[4] = 4;	// Four
	letter_counts[5] = 4;	// Five
	letter_counts[6] = 3;	// Six
	letter_counts[7] = 5;	// Seven
	letter_counts[8] = 5;	// Eight
	letter_counts[9] = 4;	// Nine
	letter_counts[10] = 3;	// Ten
	letter_counts[11] = 6;	// Eleven
	letter_counts[12] = 6;	// Twelve
	letter_counts[13] = 8;	// Thirteen
	letter_counts[14] = 8;	// Fourteen
	letter_counts[15] = 7;	// Fifteen
	letter_counts[16] = 7;	// Sixteen
	letter_counts[17] = 9;	// Seventeen
	letter_counts[18] = 8;	// Eighteen
	letter_counts[19] = 8;	// Nineteen
	letter_counts[20] = 6;	// Twenty
	letter_counts[21] = 6; 	// Thirty
	letter_counts[22] = 5; 	// Forty
	letter_counts[23] = 5; 	// Fifty
	letter_counts[24] = 5; 	// Sixty
	letter_counts[25] = 7; 	// Seventy
	letter_counts[26] = 6; 	// Eighty
	letter_counts[27] = 6;	// Ninety
	letter_counts[28] = 7; 	// Hundred
	letter_counts[29] = 8;	// Thousand

	unsigned int count = 0;

	// Iterates through all integers [1, 1000] and adds up the count of letters
	for ( int i = 0; i <= 1000; i++ ) {
		count += num_characters( i, letter_counts );
	}

	free( letter_counts );
	return count;

}



int main(void) {
	printf("%u\n", number_letter_counts());
	exit(EXIT_SUCCESS);
}
