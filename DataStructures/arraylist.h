#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
	int size;
	int capacity;
	int* array;
} al_array_list;

al_array_list* al_constructor();
void al_deconstruct( al_array_list* al );
void al_add( al_array_list* al, int item );
void al_add_index( al_array_list* al, int item, int index );
int al_get( al_array_list* al, int index );
int al_contains( al_array_list* al, int item );
int al_index_of( al_array_list* al, int item );
int al_remove( al_array_list*, int index );
int al_size( al_array_list* al );

#endif
