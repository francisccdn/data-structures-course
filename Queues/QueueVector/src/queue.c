#include <stdlib.h>
#include <string.h>

#include "../include/queue.h"
#include "../include/vector.h"

#ifndef _QUEUE_C_
#define _QUEUE_C_

// Struct da fila
struct queue
{
    // Vetor que armazena a fila
    DynVector *vec;
    // Indice do começo da fila
    int front;
    // Indice do final da fila
    int back;
    // Dimensão do vetor que armazena a fila
    int dim;
    // Quantidade de elementos na fila
    int n;
};

// Cria uma nova fila, retornando seu endereço de memória
// O(1)
Queue *q_create()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    // Se a memória não foi alocada, retorna nulo
    if (!q)
        return NULL;

    // Cria um novo vetor. Caso falhe, retorna nulo
    q->vec = dv_create(2);
    if (!q->vec)
        return NULL;

    q->front = 0;
    q->back = 0;
    q->dim = 2;
    q->n = 0;

    return q;
}

// Insere um elemento no fim da fila, retornando 0 em caso de erro
// O(n) -- Realloc no pior caso
int q_enqueue(Queue *q, float data)
{
    // Insere o novo elemento no final da fila
    dv_set(q->vec, q->back, data);

    // Incrementa a quantidade de elementos da fila
    q->n++;

    // Define novo final da fila
    q->back = (q->back + 1) % q->dim;

    // Se a fila está lotada, redimensiona
    if (q->back == q->front)
    {
        // Redimensiona o vetor
        dv_push_back(q->vec, 0);

        // Se o inicio não é o primeiro indice, é necessário reorganizar a fila
        if (q->front != 0)
        {
            // Ponteiro para o primeiro elemento do vetor
            float *vec = dv_get_vector(q->vec);

            memmove(&vec[q->dim],              // Destino: Espaço recém aberto pelo redimensionamento
                    &vec[0],                   // Origem: Inidice 0, queremos mover tudo que está entre começo do vetor e o inicio da fila
                    q->front * sizeof(float)); // Quantidade: O número de elementos é igual ao indíce do começo da fila
        }

        // Novo final da fila passa a ser a dimensão anterior + o número de elementos realocados
        q->back = q->dim + q->front;

        // Atualiza a dimensão
        q->dim *= 2;
    }

    return 1;
}

// Remove um elemento do começo da fila, e a retorna pelo parametro de saída
// O(1)
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
// O(1)
int q_peek(Queue *q, float *data)
{
    // Falha caso a fila esteja vazia
    if (q_is_empty(q))
        return 0;

    // Ponteiro para o primeiro elemento do vetor
    float *vec = dv_get_vector(q->vec);

    *data = vec[q->front];

    return 1;
}

// Checa se a fila está vazia
// O(1)
int q_is_empty(Queue *q)
{
    return q->n == 0;
}

// Libera a memória alocada para a fila
// O(1)
void q_free(Queue *q)
{
    dv_free(q->vec);
    free(q);
}

#endif