#include <stdlib.h>
#include <string.h>

#include "../include/queue.h"

#ifndef _QUEUE_C_
#define _QUEUE_C_

// Struct da fila
struct queue
{
    // Array que armazena a fila
    float *ar;
    // Indice do começo da fila
    int front;
    // Indice do final da fila
    int back;
    // Tamanho do array que armazena a fila
    int dim;
    // Quantidade de elementos na fila
    int n;
};

// Cria uma nova fila, retornando seu endereço de memória
Queue *q_create(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    // Se a memória não foi alocada, retorna nulo
    if (!q)
        return NULL;

    q->dim = size;
    q->front = 0;
    q->back = 0;
    q->n = 0;

    // Cria um novo array. Caso falhe, retorna nulo
    q->ar = (float *)malloc(sizeof(float) * size);
    if (!q->ar)
        return NULL;

    return q;
}

// Insere um elemento no fim da fila, retornando 0 em caso de erro
int q_enqueue(Queue *q, float data)
{
    // Se a fila está cheia, retorna 0
    if (q->n >= q->dim)
        return 0;
    
    // Insere o novo elemento no final da fila
    q->ar[q->back] = data;

    // Incrementa a quantidade de elementos da fila
    q->n++;

    // Define novo final da fila
    q->back = (q->back + 1) % q->dim;

    return 1;
}

// Remove um elemento do começo da fila, e a retorna pelo parametro de saída
int q_dequeue(Queue *q, float *data)
{
    if (!q_peek(q, data))
        return 0;

    // Define novo inicio da fila
    q->front = (q->front + 1) % q->dim;

    // Decrementa a quantidade de elementos da fila
    q->n--;

    return 1;
}

// Retorna o elemento no começo da fila, sem remove-lo
int q_peek(Queue *q, float *data)
{
    // Falha caso a fila esteja vazia
    if (q_is_empty(q))
        return 0;

    *data = q->ar[q->front];

    return 1;
}

// Checa se a fila está vazia
int q_is_empty(Queue *q)
{
    return q->n == 0;
}

// Libera a memória alocada para a fila
void q_free(Queue *q)
{
    free(q->ar);
    free(q);
}

#endif