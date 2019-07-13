#include "stdio.h"
#include "string.h"


/**
 * Sets the dest string as a substring of the src string
 */
char* substring( const char* src, int begin, int end, char* dest ) {

    // Gets the length of both strings
    int src_len = strlen(src);
    int dest_len = end - begin;

    // Checks for error conditions
    if ( begin < 0 || end > src_len || dest_len < 0 || src_len < dest_len ) {
        return NULL;
    }
    
    // Uses string copy to get the chars of the src string from [begin, end-begin)
    strncpy( dest, src + begin, dest_len );

    // Null terminates the dest string
    dest[dest_len] = '\0';
    return dest;

}


/**
 * Recursively checks if a string is a palindrome
 */
int is_palindrome( char* str ) {

    int len = strlen(str);
    
    // Base case: a string with length less than 2 is a palindrome
    if ( len < 2 ) {
        return 1;
    }

    // Checks if the beginning and end chars are equal
    if ( str[0] != str[len-1] ) {
        return 0;
    }

    // Generates a substring with the first and last chars removed
    char dest[BUFSIZ];
    substring( str, 1, strlen(str) - 1, dest);
    str = dest;

    // Recursively calls is_palindrome for the substring
    return is_palindrome( str );
}


/**
 * Gets the largest palindrome that is a product of two three-digit integers
 */
int largest_palindrome_product() {

    int largest_palindrome = 0;

    // Gets the Cartesian product of two sets of three-digit integers  
    for ( int i = 100; i < 1000; i++ ) {
        for ( int j = 100; j < 1000; j++ ) {

            // Gets the product of each pair
            int num = i * j;

            // Converts the number into a string with sprintf
            char num_as_str[BUFSIZ];
            sprintf( num_as_str, "%d", num );

            // Checks if the number is a palindrome larger than the current largest palindrome
            if ( num > largest_palindrome && is_palindrome(num_as_str) ) {
                largest_palindrome = num;
            }

        }
    }

    return largest_palindrome;

}



int main(void) {
    printf("%d\n", largest_palindrome_product() );
    return 0;
}

