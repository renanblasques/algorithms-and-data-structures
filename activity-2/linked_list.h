/*  ===========================================================================
    |    TRABALHO 2 -ALGORTIMOS E ESTRUTURAS DE DADOS - NÚMEROS ASTRONÔMICOS  |
    |       Renan Silva Blasques                - NUSP:  9784057              |
    |       Rodrigo De Jesus Ferreira Gonçalves - NUSP: 16899823              |
    ===========================================================================   */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;

LinkedList* linked_list_create(void);
int linked_list_insert_node(LinkedList *l, int pos, int value);
int linked_list_remove_node(LinkedList *l, int pos, int *value);
int linked_list_get_node(const LinkedList *l, int pos, int *value);
int linked_list_is_empty(const LinkedList *l);
int linked_list_size(const LinkedList *l);
void linked_list_free(LinkedList **l);

#endif