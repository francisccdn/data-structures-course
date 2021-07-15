#include <stdio.h>
#include "../include/seti.h"

int main(void)
{
    SetI *set_a = seti_create();

    seti_insert(set_a, 3);
    seti_print(set_a, "Conjunto a: ");
    seti_insert(set_a, 6);
    seti_print(set_a, "Conjunto a: ");
    seti_insert(set_a, -2);
    seti_print(set_a, "Conjunto a: ");
    seti_insert(set_a, 14);
    seti_print(set_a, "Conjunto a: ");
    seti_insert(set_a, 3);
    seti_print(set_a, "Conjunto a: ");

    seti_remove(set_a, 6);
    seti_print(set_a, "Conjunto a: ");

    SetI *set_b = seti_create();

    seti_insert(set_b, 8);
    seti_print(set_b, "Conjunto b: ");
    seti_insert(set_b, 6);
    seti_print(set_b, "Conjunto b: ");
    seti_insert(set_b, 29);
    seti_print(set_b, "Conjunto b: ");
    seti_insert(set_b, 3);
    seti_print(set_b, "Conjunto b: ");

    SetI *a_union_b = seti_union(set_a, set_b);
    SetI *a_intersection_b = seti_intersection(set_a, set_b);

    seti_print(set_a, "\nConjunto a: ");
    seti_print(set_b, "Conjunto b: ");
    seti_print(a_union_b, "a união b: ");
    seti_print(a_intersection_b, "a interseção b: ");

    printf("14 existe em a? %d\n", seti_exists(set_a, 14));
    printf("14 existe em b? %d\n", seti_exists(set_b, 14));

    printf("a é igual a b? %d\n", seti_equals(set_a, set_b));

    SetI *set_c = seti_create();

    seti_insert(set_c, 3);
    seti_print(set_c, "Conjunto c: ");

    printf("c é igual a a interseção b? %d\n", seti_equals(set_c, a_intersection_b));

    seti_print(set_a, "Conjunto a: ");
    printf("Tamanho de a: %d\n", seti_size(set_a));

    seti_print(set_c, "Conjunto c: ");
    printf("Tamanho de c: %d\n", seti_size(set_c));

    printf("c é vazio? %d\n", seti_is_empty(set_c));
    seti_remove(set_c, 3);
    seti_print(set_c, "Conjunto c: ");
    printf("c é vazio? %d\n", seti_is_empty(set_c));

    seti_free(set_a);
    seti_free(set_b);
    seti_free(set_c);
    seti_free(a_union_b);
    seti_free(a_intersection_b);

    return 0;
}