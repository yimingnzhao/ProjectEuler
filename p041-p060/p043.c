#include "stdio.h"
#include "stdlib.h"


/**
 * Gets the sum of all 0-9 pandigital numbers with the following properties
 * 	(d2 || d3 || d4) is divisible by 2
 * 	(d3 || d4 || d5) is divisible by 3
 * 	(d4 || d5 || d6) is divisible by 5
 * 	(d5 || d6 || d7) is divisible by 7
 * 	(d6 || d7 || d8) is divisible by 11
 * 	(d7 || d8 || d9) is divisible by 13
 * 	(d8 || d9 || d10) is divisible by 17
 * where the || symbol is number concatenation
 */
unsigned long int sub_string_divisibility() {
	
	/**
	 * Fact 1: d6 must be in the set {0, 5} for (d4 || d5 || d6) to be divisible by 5
	 *
	 * Fact 2: d6 must be 5 because if d6 was 0, then no unique d7 and d8 will satisfy (d6 || d7 || d8) % 11 == 0
	 *
	 * Fact 3: (d6 || d7 || d8) is limited to the following possibilities to be divisible by 11: {506, 517, 528, 539, 561, 572, 583, 594}
	 *
	 * Fact 4: Since we limited d7 and d8, (d7 || d8 || d9) is limited to the following to be divisible by 13: {286, 390, 728, 832}
	 *
	 * Fact 5: Since we limited d8, and d9, (d8 || d9 || d10) is limited to the following to be divisible by 17: {867, 901, 289}
	 *
	 * Fact 6: Now we have the following possible (d6 || d7 || d8 || d9 || d10): {52867, 53901, 57289}
	 *
	 * Fact 7: Since d6 and d7 are limited, (d5 || d6 || d7) is limited to the following to be divisible by 7: {952, 357}
	 *
	 * Fact 8: Now we have the following possibilities for (d5 || d6 || d7 || d8 || d9 || d10): {952867, 357289}
	 *
	 * Fact 9: We know that d4 is even, since (d2 || d3 || d4) is divisible by 2, and d5 is in set {3, 9}. 
	 *         Considering the digits we have left, if d5 = 3, d4 could be {0, 4, 6}, so (d3 || d4 || d5) could be: {603, 063}
   *				 Considering the digits we have left, if d5 = 9, d4 could be {0, 4}, so (d3 || d4 || d5) could be: {309}
	 *				 Thus, (d3 || d4 || d5) could be: {603, 309}
	 *
	 * Fact 10: Now, we have the following possibilities for (d3 || d4 || d5 || d6 || d7 || d8 || d9 || d10) = {06357289, 60357289, 30952867}
	 * 
	 * Fact 11: We will now fill in the other possibile values. For each of the three numbers, the missing digits are in set {1, 4}. 
	 *
	 * Fact 12: Thus, the set of numbers satisfying the conditions are {1406357289, 4106357289, 1460357289, 4160357289, 1430952867, 4130952867}
	 *
	 */

	 unsigned long int result = 1406357289 + 4106357289 + 1460357289 + 4160357289 + 1430952867 + 4130952867;
	 return result;
}



int main(void) {
	printf("%li\n", sub_string_divisibility());
	exit(EXIT_SUCCESS);
}
