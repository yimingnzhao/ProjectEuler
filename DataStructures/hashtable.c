#include "math.h"
#include "stdlib.h"
#include "hashtable.h"
#include "prime.h"


static ht_item HT_DELETED_ITEM = {-1, -1};
static const int MIN_LOAD = 10;
static const int MAX_LOAD = 70;
static const int INITIAL_BASE_SIZE = 10;


/**
 * Initializes a new item containing the key-value pair
 */
static ht_item* ht_new_item(const int key, const int value) {
    // Dynamically allocates an ht_item struct
	ht_item* item = malloc(sizeof(ht_item));
    item->key = key;
    item->value = value;
    return item;
}


/**
 * Deletes the ht_item struct
 */
static void ht_del_item( ht_item* item ) {
	//Frees the ht_item struct
	free(item);
}


/**
 * Initializes a new empty hash table using a particular size index
 */
static ht_hash_table* ht_new_size(const int capacity_index) {
    // Dynamically allocates an ht_hash_table struct
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->capacity_index = capacity_index;

	// Sets the capacity to a prime number
    const int base_size = INITIAL_BASE_SIZE << ht->capacity_index;
    ht->capacity = next_prime(base_size);

	// Dynamically allocates space for the ht_item array
    ht->size = 0;
    ht->items = calloc((size_t)ht->capacity, sizeof(ht_item*));
    return ht;
}


/**
 * Initializes a new empty hash table
 */
ht_hash_table* ht_constructor() {
	// Constructs an ht_hash_table with initial capacity_index of 0
    return ht_new_size(0);
}


/**
 * Deletes the hash table
 */
void ht_deconstruct(ht_hash_table* ht) {
    // Iterate through items and delete any that are found
    for (int i = 0; i < ht->capacity; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM) {
            ht_del_item(item);
        }
    }
	// Deletes the ht_item array and the ht_hash_table struct
    free(ht->items);
    free(ht);
}


/**
 * Resizes the hash table
 */
static void ht_resize(ht_hash_table* ht, const int direction) {
    const int new_capacity_index = ht->capacity_index + direction;
    
	// Don't resize down the smallest hash table
	if (new_capacity_index < 0) {
        return;
    }
    // Create a temporary new hash table to insert items into
    ht_hash_table* new_ht = ht_new_size(new_capacity_index);
    
	// Iterate through existing hash table, add all items to new
    for (int i = 0; i < ht->capacity; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM) {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    // Pass new_ht and ht's properties and deletes the new_ht
    ht->capacity_index = new_ht->capacity_index;
    ht->size = new_ht->size;

    // To delete new_ht, we give it ht's size and items 
    const int tmp_capacity = ht->capacity;
    ht->capacity = new_ht->capacity;
    new_ht->capacity = tmp_capacity;

    ht_item** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    ht_deconstruct(new_ht);
}


/**
 * Returns a hash
 */
static int ht_generic_hash(const int key, const int buckets) {
	return key % buckets;
}


/**
 * Gets the index of a free position of the ht_item array
 */
static int ht_hash(const int key, const int num_buckets, const int attempt) {
	return (ht_generic_hash(key, num_buckets) + attempt) % num_buckets;
}


/**
 * Inserts the key-value pair into the hash table
 */
void ht_insert(ht_hash_table* ht, const int key, const int value) {
	if (key == -1) {
		return;
	}
    // Resize if load > 0.7
    const int load = ht->size * 100 / ht->capacity;
    if (load > MAX_LOAD) {
        ht_resize(ht, 1);
    }
    ht_item* item = ht_new_item(key, value);

    // Cycle though filled buckets until we hit an empty or deleted one
    int index = ht_hash(item->key, ht->capacity, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL && cur_item != &HT_DELETED_ITEM) {
        if (cur_item->key == key) {
            ht_del_item(cur_item);
            ht->items[index] = item;
            return;
        }
        index = ht_hash(item->key, ht->capacity, i);
        cur_item = ht->items[index];
        i++;
    } 

    // index points to a free bucket
    ht->items[index] = item;
    ht->size++;
}


/**
 * Returns the value associated with 'key', or -1 if the key doesn't exist
 */
int ht_search(ht_hash_table* ht, const int key) {
	if (key == -1) {
		return -1;
	}
    int index = ht_hash(key, ht->capacity, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL && item != &HT_DELETED_ITEM) {
        if (item->key == key) {
            return item->value;
        }
        index = ht_hash(key, ht->capacity, i);
        item = ht->items[index];
        i++;
    } 
    return -1;
}


/**
 * Deletes key's item from the hash table. Does nothing if 'key' doesn't exist
 */
void ht_delete(ht_hash_table* ht, const int key) {
	if ( key == -1 || ht_search(ht, key) == -1 ) {
		return;
	}
    // Resize if load < 0.1
    const int load = ht->size * 100 / ht->capacity;
    if (load < MIN_LOAD) {
        ht_resize(ht, -1);
    }

    int index = ht_hash(key, ht->capacity, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL && item != &HT_DELETED_ITEM) {
        if (item->key == key) {
            ht_del_item(item);
            ht->items[index] = &HT_DELETED_ITEM;
        }
        index = ht_hash(key, ht->capacity, i);
        item = ht->items[index];
        i++;
    } 
    ht->size--;
}


/**
 * Gets the size of the hash table
 */
int ht_size(ht_hash_table* ht) {
	return ht->size;
}
