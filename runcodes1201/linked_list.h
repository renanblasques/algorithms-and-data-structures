#ifndef linked_list_h
#define linked_list_h

typedef struct LinkedList LinkedList;
typedef int linked_list_type;

LinkedList *linked_list_create(void);
int linked_list_insert_node(LinkedList *list, int position, linked_list_type value);
int linked_list_remove_node(LinkedList *list, int position, linked_list_type *value);
int linked_list_get_node(const LinkedList *list, int position, linked_list_type *value);
int linked_list_is_empty(const LinkedList *list);
int linked_list_size(const LinkedList *list);
void linked_list_free(LinkedList **list);

#endif