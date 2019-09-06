#include "stdio.h"
#include "stdlib.h"
#include "arraylist.h"


/**
 * Constructor for an al_array_list struct
 */
al_array_list* al_constructor() {
	// Dynamically allocates an al_array_list struct and an int array
	al_array_list* al = malloc(sizeof(al_array_list));
	al->size = 0;
	al->capacity = 10;
	int* array = calloc(al->capacity, sizeof(int));
	al->array = array;
	return al;
}


/**
 * Frees the dynamically allocated data of an al_array_list struct
 */
void al_deconstruct(al_array_list* al) {
	// Frees all dynamically allocated data
	free(al->array);
	free(al);
}


/**
 * Doubles the capacity of the array list
 */
void double_capacity(al_array_list* al) {
	// Reallocs more space for the array
	int* temp = realloc(al->array, 2 * al->size * sizeof(int));
	// Tests for errors when reallocating data
	if (temp == NULL) {
		fprintf(stderr, "Error: Memory error when reallocating data");
		al_deconstruct(al);
	}
	al->array = temp;
	al->capacity = 2 * al->size;
}


/**
 * Adds the item to the end of the array
 */
void al_add(al_array_list* al, int item) {
	if (al->size == al->capacity) {
		double_capacity(al);
	}
	al->array[al->size] = item;
	al->size++;
}	


/**
 * Adds the item to the specified index or to the end of the array if the index is out of bounds
 */
void al_add_index( al_array_list* al, int item, int index) {
	if (al->size == al->capacity) {
		double_capacity(al);
	}
	// Tests if index is out of bounds
	if (index > al->size || index < 0) {
		al_add(al, item);
		return;
	}
	// Shifts the rest of the array over
	for (int i = al->size - 1; i >= index; i--) {
		al->array[i+1] = al->array[i];
	}
	al->array[index] = item;
	al->size++;
}


/**
 * Gets the item at the specified index or -1 if the index is out of bounds
 */
int al_get(al_array_list* al, int index) {
	return (index >= al->size || index < 0) ? -1 : al->array[index];
}


/**
 * Gets the index of the first occurance of the item or returns -1 if the item is not found
 */
int al_index_of(al_array_list* al, int item) {
	// Loops through the items in the array
	for (int i = 0; i < al->size; i++) {
		if (*(al->array + i) == item) {
			return i;
		}	
	}
	return -1;
}	


/**
 * Checks if the array contains the item
 */
int al_contains(al_array_list* al, int item) {
	return (al_index_of(al, item) == -1) ? 0 : 1;
}


/**
 * Removes and returns the item at the given index or -1 if the index is out of bounds
 */
int al_remove(al_array_list* al, int index) {
	// Checks if the index is out of bounds
	if (index < 0 || index >= al->size) {
		return -1;
	}
	// Loops through the array to shift values down by one
	int item = al->array[index];
	for (int i = index; i < al->size - 1; i++) {
		*(al->array + i) = *(al->array + i + 1);
	}
	al->size--;
	return item;
}


/**
 * Returns the size of the array
 */
int al_size(al_array_list* al) {
	return al->size;
}



int main(void) {
	al_array_list* al = al_constructor();
	printf("Initial Size: %d\n", al->size);
	printf("Initial Capacity: %d\n", al->capacity);
	al_add(al, 5);
	printf("One Size: %d\n", al->size);
	printf("One Capacity: %d\n", al->capacity);
	printf("One Array %d\n", al->array[0]);	
	for ( int i = 0; i < 10; i++ ) {
		al_add(al, i);
	}
	
	printf("NEXT Size: %d\n", al->size);
	printf("NEXT Capacity: %d\n", al->capacity);
	al_add_index(al, -1, 0);
	printf("NEXT1 Size: %d\n", al->size);
	printf("NEXT1 Capacity: %d\n", al->capacity);
	printf("NEXT1 Array: %d\n", al->array[0]);
	for ( int i = 0; i < al->size; i++ ) {
		printf("ARRAY %d\n", al->array[i]);
	}

	al_remove(al, 0);
	printf("NEXT2 Size: %d\n", al->size);
	printf("NEXT2 Capacity: %d\n", al->capacity);
	printf("NEXT2 Array: %d\n", al->array[0]);
	for ( int i = 0; i < al->size; i++ ) {
		printf("ARRAY %d\n", al->array[i]);
	}

	al_remove(al, 4);
	printf("NEXT2 Size: %d\n", al->size);
	printf("NEXT2 Capacity: %d\n", al->capacity);
	printf("NEXT2 Array: %d\n", al->array[0]);
	for ( int i = 0; i < al->size; i++ ) {
		printf("ARRAY %d\n", al->array[i]);
	}
	al_deconstruct(al);
	return 0;
}
