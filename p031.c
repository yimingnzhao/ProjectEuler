#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Gets all possible ways to create 2 English pounds (200p) with the following coins:
 * 		1p, 2p, 5p, 10p, 20p, 50p, 100p, 200p
 */
unsigned int coin_sums() {

	// Defines the target and array of coins 
	unsigned int target = 200;
	unsigned int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	unsigned int coins_len = 8;

	// Initializes an array of target + 1 elements, filled with 0, except with the first element
	unsigned int num_ways[target+1];
	memset(num_ways, 0, (target + 1)*sizeof(unsigned int));
	num_ways[0] = 1;

	// Uses dynamic programming to get the next combination of coins from 1 to target
	// 		Iterates through the types of coins
	// 		Gets the combination of coins from 1 to target only using coins of the iterative value or lower
	// 		After iterating through the 200p coin, the value of num_ways[target] is the result
	for ( int i = 0; i < coins_len; i++ ) {
		for ( int j = coins[i]; j <= target; j++ ) {
			num_ways[j] += num_ways[ j - coins[i] ];
		}
	}

	return num_ways[target];

}


int main(void) {
	printf("%u\n", coin_sums());
	exit(EXIT_SUCCESS);
}
