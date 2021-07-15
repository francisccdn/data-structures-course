#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue Queue;

Queue *q_create(int size);
int q_enqueue(Queue *q, float data);
int q_dequeue(Queue *q, float *data);
int q_peek(Queue *q, float *data);
int q_is_empty(Queue *q);
void q_free(Queue *q);

#endif