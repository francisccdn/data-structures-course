#include <stdio.h>
#include "../include/circularlist.h"

int main(void)
{
    CircularList *mylist = cl_create_list();

    cl_insert(mylist, 0, 3);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 1, 1);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 0, 10);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 0, 7);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 2, 11);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 3, 13);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 0, 0);
    cl_print(mylist, "list: ");
    cl_insert(mylist, 4, 51);
    cl_print(mylist, "list: ");
    cl_remove(mylist, 4);
    cl_print(mylist, "list: ");
    cl_remove_first(mylist);
    cl_print(mylist, "list: ");
    cl_erase(mylist, 7);
    cl_print(mylist, "list: ");

    cl_clear(mylist); 

    printf("Is empty? %d\n", cl_is_empty(mylist));

    cl_insert_first(mylist, -3);
    cl_print(mylist, "list: ");
    cl_insert_first(mylist, 8);
    cl_print(mylist, "list: ");
    cl_insert_first(mylist, 0);
    cl_print(mylist, "list: ");

    printf("-3 exists? %d\n", cl_exists(mylist, -3));
    cl_erase(mylist, -3);
    cl_print(mylist, "list: ");
    printf("-3 exists? %d\n", cl_exists(mylist, -3));

    printf("list size: %d\n", cl_size(mylist));
    cl_free(mylist);

    return 0;
}