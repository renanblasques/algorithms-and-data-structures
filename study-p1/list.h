#ifndef list_h
#define list_h
/*
   Convenções de retorno:

   -1 → Erro
        - Ponteiro NULL
        - Posição inválida
        - Lista cheia/vazia quando não deveria
        - Falha de alocação
        - Parâmetro de saída NULL (ex: ponteiro para receber elemento ou posição)

    1 → Sucesso ou condição verdadeira
        - Operação realizada com êxito (inserção, remoção, criação, destruição, etc.)
        - Condição satisfeita (ex: lista está vazia, lista está cheia, elemento encontrado)

    0 → Sucesso com condição falsa
        - Condição verificada não se aplica (ex: lista **não** está vazia, elemento **não** encontrado)
        - Retornos intermediários que não configuram erro, mas sinalizam ausência de ocorrência esperada

    >1 → Retornos bem-sucedidos com valor informativo
        - Ex: quantidade de elementos, posição encontrada, etc. (quando for o caso)

    Obs: O padrão evita misturar valores negativos com positivos para distinguir claramente erros de sucesso.
*/

/* Capacidade máxima da lista */
#define LIST_MAX 100
#define LIST_TYPE_FORMAT "%d"

/* Tipo dos elementos armazenados na lista */
typedef int list_type;

/* Estrutura da lista sequencial estática */
typedef struct List List;

/* ==== Criação e Destruição ==== */

// Cria uma nova lista e retorna o ponteiro para ela.
// Retorna NULL em caso de erro de alocação.
List *list_create(void);

// Libera a memória da lista e define o ponteiro como NULL.
// Retorna 1 em caso de sucesso, -1 se ponteiro inválido.
int list_destroy(List **l);

/* ==== Estado da Lista ==== */

// Retorna 1 se a lista está vazia, 0 se não está, -1 se ponteiro inválido.
int list_is_empty(const List *l);

// Retorna 1 se a lista está cheia, 0 se não está, -1 se ponteiro inválido.
int list_is_full(const List *l);

// Retorna a quantidade de elementos na lista, -1 se ponteiro inválido.
int list_size(const List *l);

/* ==== Inserção e Remoção ==== */

// Insere um elemento no final da lista.
// Retorna 1 em caso de sucesso, -1 em caso de erro.
int list_insert_at_end(List *l, list_type value);

// Insere um elemento na posição especificada (0 ≤ pos ≤ qtd).
// Retorna 1 em caso de sucesso, -1 em caso de erro.
int list_insert_at(List *l, int position, list_type value);

// Remove o elemento da posição especificada (0 ≤ pos < qtd) e armazena em 'removido'.
// Retorna 1 em caso de sucesso, -1 em caso de erro.
int list_remove_at(List *l, int position, list_type *removed);

/* ==== Consulta e Busca ==== */

// Consulta o elemento da posição especificada e armazena em 'elem'.
// Retorna 1 em caso de sucesso, -1 em caso de erro.
int list_get_at(const List *l, int position, list_type *value);

// Busca um elemento na lista. Se encontrar, armazena a posição em 'pos'.
// Retorna 1 se encontrar, 0 se não encontrar, -1 em caso de erro.
int list_search(const List *l, list_type value, int *position);

/* ==== Utilitários ==== */

// Limpa a lista, zerando a quantidade de elementos.
// Retorna 1 em caso de sucesso, -1 se ponteiro inválido.
int list_clean(List *l);

// Imprime os elementos da lista (formato livre).
// Retorna 1 em caso de sucesso, -1 se ponteiro inválido.
int list_print(const List *l);

#endif