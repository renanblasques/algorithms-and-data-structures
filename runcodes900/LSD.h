#ifndef LSD_H
#define LSD_H

typedef int ListType;

typedef struct {
    ListType *data;
    int size;
    int capacity;
} DynamicList;

// Creates a new dynamic list
// Returns NULL if memory allocation fails
DynamicList *list_create(void);

// Destroys a dynamic list
// Returns 1 if destroyed successfully, 0 if the list was already NULL, -1 if pointer is invalid
int list_destroy(DynamicList **list);

// Checks if the list is empty
// Returns 1 if empty, 0 if not empty, -1 if pointer is invalid
int list_is_empty(const DynamicList *list);

// Returns the number of elements in the list, or -1 if pointer is invalid
int list_size(const DynamicList *list);

// Returns the capacity of the list, or -1 if pointer is invalid
int list_capacity(const DynamicList *list);

// Inserts an element at the end of the list
// Returns 1 if success, -1 if pointer is invalid
int list_insert_end(DynamicList *list, ListType elem);

// Inserts an element at a given position
// Returns 1 if success, 0 if position is invalid, -1 if pointer is invalid
int list_insert_at(DynamicList *list, int pos, ListType elem);

// Removes an element at a given position
// Returns 1 if success, 0 if position is invalid, -1 if pointer is invalid
int list_remove_at(DynamicList *list, int pos, ListType *removed);

// Retrieves the element at a given position
// Returns 1 if success, 0 if position is invalid, -1 if pointer is invalid
int list_get_at(const DynamicList *list, int pos, ListType *elem);

// Finds the first occurrence of an element in the list
// Returns 1 if found, 0 if not found, -1 if pointer is invalid
// If not found, *pos is set to -1
int list_find(const DynamicList *list, ListType elem, int *pos);

// Clears all elements from the list
// Returns 1 if cleared successfully, 0 if already empty, -1 if pointer is invalid
int list_clear(DynamicList *list);

// Prints the list to stdout
// Returns 1 if success, -1 if pointer is invalid, 0 if list is empty
int list_print(const DynamicList *list);

// Helper function to ensure the list has enough capacity
// If the list is full, reallocates the internal array and doubles its capacity
// Returns 1 if success, -1 if pointer is invalid or realloc fails
int list_ensure_capacity(DynamicList *list);

#endif