#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../DataStructures/arraylist.h"

// NOTE: The problem file was modified with the following command to ease reading: sed -i -e 's/,/\n/g' -e 's/"//g' ProblemFiles/p042_words.txt 
// NOTE: To compile, run 'gcc p042.c ../DataStructures/arraylist.c'


/**
 * Gets the word value (sum of the numerical values of the letters) of a string of capital letters
 */
int get_word_value( char* word, int length ) {

	int word_value = 0;
	for ( int i = 0; i < length; i++ ) {
		word_value += (int)*(word + i) - ((int)'A' - 1);
	}
	return word_value;

}


/**
 * Gets the n-th triangle number
 */
int get_nth_triangle_number( int n ) {
	return n * (n + 1) / 2;
}


/**
 * Comparing function for integers a and b:
 * 		Returns positive integer if a > b
 * 		Returns negative integer if a < b
 * 		Returns 0 if a = b
 */
int compare_to( const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}


/**
 * Gets the number of word values that are also triangle numbers from a text file of words
 */
unsigned int coded_triangle_numbers() {

	const char* filename = "ProblemFiles/p042_words.txt";
	al_array_list* word_values = al_constructor();
	al_array_list* triangle_numbers = al_constructor();

	// Reads the text file and adds the word values to an arraylist 
	FILE* file = fopen( filename, "r" );
	char word[BUFSIZ];
	int max_word_value = 0;
	while ( 1 ) {
		if ( fgets( word, BUFSIZ, file ) == NULL ) {
			break;
		}
		int word_value = get_word_value( word, strlen(word) - 1);
		max_word_value = ( max_word_value < word_value ) ? word_value : max_word_value;
		al_add( word_values, word_value );
	}
	fclose( file );

	// Adds all necessary triangle numbers into another arraylist in sorted order
	int n = 1;
	int current_triangle_number = 0;
	do {
		current_triangle_number = get_nth_triangle_number( n++ );
		al_add( triangle_numbers, current_triangle_number );
	} while ( current_triangle_number < max_word_value );

	// Uses binary search to check if each word value is also a triangle number
	int count = 0;
	int* item;
	int* word_values_array = word_values->array;
	int* triangle_numbers_array = triangle_numbers->array;
	for ( int i = 0; i < al_size( word_values ); i++ ) {
		item = (int*) bsearch( &(*(word_values_array + i)), triangle_numbers_array, al_size(triangle_numbers), sizeof(int), compare_to );
		if ( item != NULL ) {
			count++;
		}
	}

	// Frees all dynamically allocated memory and returns the result
	al_deconstruct( word_values );
	al_deconstruct( triangle_numbers );
	return count;

}


int main(void) {
	printf("%u\n", coded_triangle_numbers());
	exit(EXIT_SUCCESS);
}
