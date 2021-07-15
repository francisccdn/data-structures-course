#include <stdlib.h>

#include "../include/queue.h"
#include "../include/linkedlist.h"

#ifndef _QUEUE_C_
#define _QUEUE_C_

// Struct da fila
struct queue
{
    // Lista que amazena a fila -- Começo da fila é a cabeça da lista
    LinkedList *list;
    // Referencia para o fim da fila
    ListNode *back;
};

// Cria uma nova fila, retornando seu endereço de memória
// O(1)
Queue *q_create()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    // Se a memória não foi alocada, retorna nulo
    if (!q)
        return NULL;

    // Cria uma nova lista. Caso falhe, retorna nulo
    q->list = ll_create_list();
    if (!q->list)
        return NULL;

    // Define o fim da fila como nulo, já que ela começa vazia
    q->back = NULL;

    return q;
}

// Insere um elemento no fim da fila, retornando 0 em caso de erro
// O(1)
int q_enqueue(Queue *q, int data)
{
    // Se a fila está vazia, insere o elemento como primeiro da lista
    if (q_is_empty(q))
    {
        if(!ll_insert_first(q->list, data))
            return 0;

        // Novo elemento é a cabeça da lista
        q->back = ll_head(q->list);
        
        return 1;
    }

    //Cria novo nó da lista
    ListNode *new_back = ll_create_node(data);

    // Define novo nó como vindo após o fim da fila
    if (!ll_set_next_node(q->back, new_back))
        return 0;
    // Define fim da fila como o novo nó
    q->back = new_back;

    return 1;
}

// Remove um elemento do começo da fila, e a retorna pelo parametro de saída
// O(1)
int q_dequeue(Queue *q, int *data)
{
    if (!q_peek(q, data))
        return 0;
        
    ll_remove_first(q->list);
    return 1;
}

// Retorna o elemento no começo da fila, sem remove-lo
// O(1)
int q_peek(Queue *q, int *data)
{
    // Falha caso a fila esteja vazia
    if (q_is_empty(q))
        return 0;
    
    *data = ll_first(q->list);
    return 1;
}

// Checa se a fila está vazia
// O(1)
int q_is_empty(Queue *q)
{
    return ll_is_empty(q->list);
}

// Libera a memória alocada para a fila
// O(n) -- Precisa liberar a memória de cada nó da lista
void q_free(Queue *q)
{
    ll_free(q->list);
    free(q);
}

#endif