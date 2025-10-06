#include <stdlib.h>
#include "LinkedList.h"

typedef struct node {
    int data;
    struct node *next;
} Node;

struct linked_list {
    Node *head;
    int size;
};

LinkedList *create_linked_list() {
    LinkedList *l = malloc(sizeof(LinkedList));
    if (l == NULL) return l;

    l->head = NULL;
    l->size = 0;

    return l;
}

int insert_node(LinkedList *l, int pos, int value) {
    if (l == NULL) return -1;
    if ((pos < 0) || (pos > l->size)) return 0;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return -1;

    new_node->data = value;
    new_node->next = NULL;

    if (pos == 0) {
        new_node->next = l->head;
        l->head = new_node;
    } else {
        Node *temp = l->head;

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    l->size++;

    return 1;
}

int remove_node(LinkedList *l, int pos, int *value) {
    if (l == NULL) return -1;
    if ((pos < 0) || (pos >= l->size)) return 0;

    Node *rem;

    if (pos == 0) {
        rem = l->head;
        l->head = rem->next;
    } else {
        Node *temp = l->head;

        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        rem = temp->next;
        temp->next = rem->next;
    }

    if (value != NULL) {
        *value = rem->data;
    }

    free(rem);
    l->size--;

    return 1;
}

int get_node(const LinkedList *l, int pos, int *value) {
    if (l == NULL) return -1;
    if ((pos < 0) || (pos >= l->size)) return 0;

    Node *temp = l->head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    *value = temp->data;

    return 1;
}

int is_empty_list(const LinkedList *l) {
    if (l == NULL) return -1;

    if (l->head == NULL) return 1;

    return 0;
}

int size_list(const LinkedList *l) {
    if (l == NULL) return -1;

    return l->size;
}

void free_linked_list(LinkedList **l) {
    if (l == NULL || *l == NULL) return;

    Node *temp = (*l)->head;
}

// TERMINAR O FREE