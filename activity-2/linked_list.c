#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct LinkedList {
    int size;
    Node *head;
};

LinkedList* linked_list_create(void) {
    LinkedList* l = malloc(sizeof(LinkedList));

    if (l == NULL)
        return NULL;

    l->head = NULL;
    l->size = 0;

    return l;
}

int linked_list_insert_node(LinkedList *l, int pos, int value) {
    if (l == NULL)
        return -1;

    if ((pos < 0) || (pos > l->size))
        return -1;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return -1;

    new_node->data = value;
    new_node->next = NULL;

    Node *temp = l->head;
    if (pos == 0) {
        l->head = new_node;
        new_node->next = temp;
    } else {
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        new_node->next = temp->next;
        temp->next = new_node;
    }
    
    l->size++;
    return 1;
}

int linked_list_remove_node(LinkedList *l, int pos, int *value) {
    if (l == NULL)
        return -1;

    if ((pos < 0) || (pos >= l->size))
        return -1;

    Node *temp = l->head;
    Node *rem;
    if (pos == 0) {
        l->head = temp->next;
        rem = temp;
    } else {
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        rem = temp->next;
        temp->next = rem->next;
    }

    if (value != NULL)
        *value = rem->data;

    free(rem);

    l->size--;
    return 1;
}

int linked_list_get_node(const LinkedList *l, int pos, int *value) {
    if (l == NULL)
        return -1;

    if ((pos < 0) || (pos >= l->size))
        return -1;

    if (value == NULL)
        return -1;

    Node *temp = l->head;
    if (pos > 0)
        for (int i = 0; i < pos; i++)
            temp = temp->next;
    
    *value = temp->data;

    return 1;
}

int linked_list_is_empty(const LinkedList *l) {
    if (l == NULL)
        return -1;

    if (l->size == 0)
        return 1;
    else
        return 0;
}

int linked_list_size(const LinkedList *l) {
    if (l == NULL)
        return -1;

    return l->size;
}

void linked_list_free(LinkedList **l) {
    if (l == NULL || *l == NULL)
        return;

    Node *current = (*l)->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(*l);
    *l = NULL;
}