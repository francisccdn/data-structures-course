#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

typedef struct doublylinkedlist DLinkedList;
typedef struct listnode ListNode;

DLinkedList *dll_create_list();
ListNode *dll_create_node(int data);
int dll_is_empty(DLinkedList *list);
int dll_size(DLinkedList *list);
int dll_insert(DLinkedList *list, int pos, int data);
int dll_insert_first(DLinkedList *list, int data);
int dll_insert_last(DLinkedList *list, int data);
int dll_exists(DLinkedList *list, int data);
void dll_print(DLinkedList *list, char *message);
void dll_clear(DLinkedList *list);
void dll_free(DLinkedList *list);
int dll_erase(DLinkedList *list, int data);
int dll_remove(DLinkedList *list, int pos);
int dll_remove_first(DLinkedList *list);
int dll_remove_last(DLinkedList *list);

#endif