#include <stdio.h>
#include "../include/linkedlist.h"

int main(void)
{
    LinkedList *mylist = ll_create_list();

    printf("sorted:\n");

    ll_insert_sorted(mylist, 3);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 1);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 10);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 7);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 11);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 13);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 0);
    ll_print(mylist, "list: ");
    ll_insert_sorted(mylist, 51);
    ll_print(mylist, "list: ");

    ll_clear(mylist);

    printf("Is empty? %d\n", ll_is_empty(mylist));

    ll_insert_first(mylist, -3);
    ll_print(mylist, "list: ");
    ll_insert_first(mylist, 8);
    ll_print(mylist, "list: ");
    ll_insert_first(mylist, 0);
    ll_print(mylist, "list: ");
    ll_insert_last(mylist, -2);
    ll_print(mylist, "list: ");
    ll_insert_last(mylist, -18);
    ll_print(mylist, "list: ");

    printf("First element: %d\n", ll_first(mylist));
    ll_remove_first(mylist);
    ll_print(mylist, "list: ");
    printf("First element: %d\n", ll_first(mylist));

    printf("-2 exists? %d\n", ll_exists(mylist, -2));
    ll_remove(mylist, -2);
    ll_print(mylist, "list: ");
    printf("-2 exists? %d\n", ll_exists(mylist, -2));

    printf("list size: %d\n", ll_size(mylist));
    ll_free(mylist);

    return 0;
}