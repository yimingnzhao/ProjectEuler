#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * Struct for an array of strings 
 */
typedef struct StringArray {
	
	unsigned int capacity;
	unsigned int size;
	char** strings;

} StringArray;


/**
 * Constructs a StringArray with an initial capacity of 10
 */
StringArray* constructor() {

	// Dynamically allocates a StringArray struct and an array of strings
	StringArray* arr = malloc( sizeof(StringArray) );
	arr->strings = calloc( 10, sizeof(char*) );
	arr->size = 0;
	arr->capacity = 10;
	return arr;

}


/**
 * Frees all dynamically allocated memory of a StringArray struct
 */
void destructor( StringArray* arr ) {

	// Frees all dynamically allocated strings
	for ( int i = 0; i < arr->size; i++ ) {
		free( arr->strings[i] );
	}

	// Frees the array of strings and the StringArray struct
	free( arr->strings );
	free( arr );

}


/**
 * Increases the capacity of the array of strings by a multiplier of 2
 */
StringArray* increase_capacity( StringArray* arr ) {

	// Dynamically allocates more memory for the string array
	char** temp = realloc( arr->strings, (2 * arr->capacity)*sizeof(char*) );

	// Checks for memory errors
	if ( temp == NULL ) {
		destructor( arr );
		fprintf( stderr, "%s\n", "Error: Memory error when reallocing data" );
		exit(EXIT_FAILURE);
	}

	// Updates the parameters of the StringArray
	arr->strings = temp;
	arr->capacity = 2 * arr->capacity;
	return arr;

}


/**
 * Appends the string to the end of the string array
 */
void add( StringArray* arr, char* string ) {

	// Checks if the size reaches the capacity
	if ( arr->size + 1 == arr->capacity ) {
		arr = increase_capacity( arr );
	}
	
	// Adds the string to the string array
	arr->strings[ arr->size ] = string;
	arr->size += 1;
}


/**
 * Function to compare strings for qsort 
 */
int compare_strings( const void* a, const void* b ) {

	// Uses strcmp to compare strings
	int cmp = strcmp( *(char**)a, *(char**)b );
	
	// Returns an integer based on the comparison of strings a and b 
	if ( cmp == 0 ) {
		return 0;
	}
	return ( cmp > 0 ) ? 1 : -1;

}


/**
 * Gets the name score of a txt file of names 
 */
unsigned int names_scores() {
	
	// Constructs a StringArray struct
	StringArray* arr = constructor();

	// Defines the file to open
	char filename[] = "ProblemFiles/p022_names.txt";
	FILE* file;

	// Opens the file and checks for a file error
	file = fopen( filename, "r" );
	if ( file == NULL ) {
		fprintf( stderr, "Error: Error opening file %s\n", filename );
		exit(EXIT_FAILURE);
	}

	// Defines variables for getting names from the file
	char name[BUFSIZ] = "";
	memset( name, '\0', BUFSIZ*sizeof(char) );
	char c;
	int char_in_name = 0;
	int name_char_count = 0;
	c = fgetc( file );

	// Loops through characters until the End of File
	while ( c != EOF ) {
		
		// Checks if the current char is a char in the name
		if ( c != '"' && char_in_name == 1 ) {
			name[ name_char_count ] = c;
			name_char_count += 1;
		}

		// Checks if the current char is a quotation 
		if ( c == '"' ) {

			// Resets the name string and adds the name to the string array 
			if ( char_in_name == 0 ) {
				char_in_name = 1;
				name_char_count = 0;
				memset( name, '\0', BUFSIZ*sizeof(char) );
			} else {
				char_in_name = 0;
				int len = strlen( name );
				char* saved_name = calloc( len + 1, sizeof(char) );
				strncpy( saved_name, name, len );
				add( arr, saved_name );	
			}

		}

		c = fgetc( file );

	}

	fclose( file );

	// Sorts the array of names
	qsort( arr->strings, arr->size, sizeof(char*), compare_strings );

	// Gets the sum of the names scores of each name
	unsigned int count = 0;
	for ( int i = 0; i < arr->size; i++ ) {
		int name_position = i + 1;
		int name_count = 0;
		int name_len = strlen(arr->strings[i]);
		for ( int j = 0; j < name_len; j++ ) {
			name_count += (int)(arr->strings[i][j] - 'A' + 1);
		}
		count += name_count * name_position;
	}

	// Frees the struct StringArray and all dynamically allocated memory
	destructor( arr );
	return count;

}


int main(void) {
	printf("%u\n", names_scores());
	exit(EXIT_SUCCESS);
}
