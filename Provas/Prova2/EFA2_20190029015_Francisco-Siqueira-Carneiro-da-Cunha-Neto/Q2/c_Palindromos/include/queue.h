#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue Queue;

Queue *q_create();
int q_enqueue(Queue *q, char data);
int q_dequeue(Queue *q, char *data);
int q_peek(Queue *q, char *data);
int q_is_empty(Queue *q);
void q_free(Queue *q);

#endif