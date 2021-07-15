#include <stdio.h>
#include "../include/doublylinkedlist.h"

int main(void)
{
    DLinkedList *mylist = dll_create_list();

    dll_insert(mylist, 0, 3);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 1, 1);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 0, 10);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 0, 7);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 2, 11);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 3, 13);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 0, 0);
    dll_print(mylist, "list: ");
    dll_insert(mylist, 4, 51);
    dll_print(mylist, "list: ");
    dll_remove(mylist, 4);
    dll_print(mylist, "list: ");
    dll_remove_first(mylist);
    dll_print(mylist, "list: ");
    dll_remove_last(mylist);
    dll_print(mylist, "list: ");
    
    dll_erase(mylist, 7);
    dll_print(mylist, "list: ");
    dll_remove(mylist, 0);
    dll_print(mylist, "list: ");

    dll_clear(mylist); 

    printf("Is empty? %d\n", dll_is_empty(mylist));

    dll_insert_first(mylist, -3);
    dll_print(mylist, "list: ");
    dll_insert_first(mylist, 8);
    dll_print(mylist, "list: ");
    dll_insert_first(mylist, 0);
    dll_print(mylist, "list: ");
    dll_insert_last(mylist, -2);
    dll_print(mylist, "list: ");
    dll_insert_last(mylist, -18);
    dll_print(mylist, "list: ");

    printf("-2 exists? %d\n", dll_exists(mylist, -2));
    dll_erase(mylist, -2);
    dll_print(mylist, "list: ");
    printf("-2 exists? %d\n", dll_exists(mylist, -2));

    printf("list size: %d\n", dll_size(mylist));
    dll_free(mylist);

    return 0;
}