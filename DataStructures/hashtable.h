#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
	int key;
	int value;
} ht_item;

typedef struct {
	int size;
	int capacity;
	int capacity_index; 
	ht_item** items;
} ht_hash_table;

ht_hash_table* ht_constructor();
void ht_deconstruct( ht_hash_table* ht );
void ht_insert( ht_hash_table* ht, int key, int value );
int ht_search( ht_hash_table* ht, int key );
void ht_delete( ht_hash_table* ht, int key );
int ht_size( ht_hash_table* ht );

#endif 
