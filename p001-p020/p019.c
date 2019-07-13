#include "stdio.h"
#include "stdlib.h"

#define DAYS_IN_LEAP_YEAR 366
#define DAYS_IN_YEAR 365
#define MONTHS_IN_YEAR 12
#define DAYS_IN_WEEK 7


/**
 * Checks if a given year is a leap year
 */
unsigned int is_leap_year( unsigned int year ) {

	// Given: Definition of a leap year
	return ( year % 100 == 0 ) ? ( (year % 400 == 0) ? 1 : 0 ) : ( (year % 4 == 0) ? 1 : 0 );

}


/**
 * Gets the number of Sundays that occur on the first of the month in the 20th century (1 Jan 1901 to 31 Dec 2000)
 */
unsigned int counting_sundays() {
	
	unsigned int sunday_count = 0;

	// Given: 1 Jan 1900 was a Monday
	// Let Monday -> 1, Tuesday -> 2, ..., Sunday -> 0
	unsigned int day = 1;
	unsigned int year = 1900;

	// Given: The number of days in each month
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
	// Gets the day of 1 Jan 1901
	day += ( is_leap_year(year) ) ? DAYS_IN_LEAP_YEAR : DAYS_IN_YEAR;
	day %= DAYS_IN_WEEK;
	year++;

	// Checks if 1 Jan 1901 is a Sunday
	if ( day == 0 ) {
		sunday_count++;
	}

	// Loops through the years [1901, 2000], and loops through each month of the year
	while ( year < 2001 ) {
		for ( int i = 0; i < MONTHS_IN_YEAR; i++ ) {

			// Checks for leap years and then modifies the days in February
			if ( i == 1 && is_leap_year(year) ) {
				day += days_in_month[i] + 1;
			} else {
				day += days_in_month[i];
			}

			// Mods the day variable by the days in a week to get the first day of each month
			day %= DAYS_IN_WEEK;
			if ( day == 0 ) {
				sunday_count++;
			}

		}
		year++;
	}

	return sunday_count;

}


int main(void) {
	printf("%u\n", counting_sundays());
	exit(EXIT_SUCCESS);
}
