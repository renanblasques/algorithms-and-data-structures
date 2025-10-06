#ifndef d_list_h
#define d_list_h

#define D_LIST_TYPE_FORMAT "%d"

typedef int d_list_type;

typedef struct DList DList;

DList *d_list_create(void);
int d_list_destroy(DList **l);

int d_list_is_empty(const DList *l);
int d_list_size(const DList *l);
int d_list_capacity(const DList *l);

int d_list_insert_at_end(DList *l, d_list_type value);
int d_list_insert_at(DList *l, int position, d_list_type value);
int d_list_remove_at(DList *l, int position, d_list_type *removed);

int d_list_get_at(const DList *l, int pos, d_list_type *value);
int d_list_search(const DList *l, d_list_type value, int *position);

int d_list_clean(DList *l);
int d_list_print(const DList *l);

/* 
   Função auxiliar que garante espaço para novas inserções.
   Se a lista estiver cheia, realoca o vetor interno dobrando a capacidade.
*/
int d_list_ensure_capacity(DList *l);

#endif