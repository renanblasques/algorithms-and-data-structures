#include <stdlib.h>
#include "linked_list.h"

typedef struct node {
    linked_list_type data;
    struct node *next;
} Node;

struct LinkedList {
    Node *head;
    int size;
};

LinkedList *linked_list_create(void) {
    LinkedList *list = malloc(sizeof(LinkedList));

    if (list == NULL) return NULL;

    list->head = NULL;
    list->size = 0;

    return list;
}

int linked_list_insert_node(LinkedList *list, int position, linked_list_type value) {
    if (list == NULL) return -1;

    if (position < 0 || position > list->size) return -1;

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) return -1;

    new_node->data = value;
    new_node->next = NULL;

    if (position == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    list->size++;

    return 1;
}

int linked_list_remove_node(LinkedList *list, int position, linked_list_type *value) {
    if (list == NULL) return -1;

    if (position < 0 || position >= list->size) return -1;

    Node *rem = list->head;

    if (position == 0) {
        list->head = rem->next;
    } else {
		Node *temp = list->head;
		for (int i = 0; i < position - 1; i++) {
			temp = temp->next;
		}
		rem = temp->next;
		temp->next = rem->next;
    }

    if (value != NULL) {
        *value = rem->data;
    }

    free(rem);
    list->size--;

    return 1;
}

int linked_list_get_node(const LinkedList *list, int position, linked_list_type *value) {
    if (list == NULL) return -1;

    if (value == NULL) return -1;

    if (position < 0 || position >= list->size) return -1;

    Node *temp = list->head;

    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }

    *value = temp->data;

    return 1;
}

int linked_list_is_empty(const LinkedList *list) {
    if (list == NULL) return -1;

    if (list->size == 0) return 1;

    return 0;
}

int linked_list_size(const LinkedList *list) {
    if (list == NULL) return -1;

    return list->size;
}

void linked_list_free(LinkedList **list) {
    if (list == NULL || *list == NULL) return;

	Node *temp = (*list)->head;
	while (temp != NULL) {
		Node *rem = temp;
		temp = temp->next;
		free(rem);
	}

	free(*list);
	*list = NULL;
}