#ifndef _CIRCULAR_LIST_H_
#define _CIRCULAR_LIST_H_

typedef struct circularlist CircularList;
typedef struct listnode ListNode;

CircularList *cl_create_list();
ListNode *cl_create_node(int data);
int cl_is_empty(CircularList *list);
int cl_size(CircularList *list);
int cl_insert(CircularList *list, int pos, int data);
int cl_insert_first(CircularList *list, int data);
int cl_exists(CircularList *list, int data);
void cl_print(CircularList *list, char *message);
void cl_clear(CircularList *list);
void cl_free(CircularList *list);
int cl_erase(CircularList *list, int data);
int cl_remove(CircularList *list, int pos);
int cl_remove_first(CircularList *list);

#endif