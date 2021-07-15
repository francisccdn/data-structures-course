#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct bintree Heap;

Heap *heap_create(int max_h, int data);
void heap_print_bars(Heap *heap);
void heap_print_parenthesis(Heap *heap);
void heap_free(Heap *heap);
int heap_exists(Heap *heap, int data);
int heap_find(Heap *heap, int data);
int heap_height(Heap *heap);
int heap_insert(Heap *heap, int data);

#endif