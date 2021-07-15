#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct linkedlist LinkedList;
typedef struct listnode ListNode;

LinkedList *ll_create_list();
ListNode *ll_create_node(float data);
int ll_is_empty(LinkedList *list);
int ll_size(LinkedList *list);
int ll_insert_first(LinkedList *list, float data);
int ll_insert_last(LinkedList *list, float data);
int ll_exists(LinkedList *list, float data);
void ll_print(LinkedList *list, char *message);
void ll_clear(LinkedList *list);
void ll_free(LinkedList *list);
int ll_remove(LinkedList *list, float data);
int ll_insert_sorted(LinkedList *list, float data);
float ll_first(LinkedList *list);
int ll_remove_first(LinkedList *list);
float ll_get(LinkedList *list, int pos);

#endif