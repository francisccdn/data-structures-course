#ifndef _SET_I_H_
#define _SET_I_H_

typedef struct seti SetI;

SetI *seti_create();

SetI *seti_union(SetI *a, SetI *b);
int seti_insert(SetI *set, int value);
int seti_remove(SetI *set, int value);
SetI *seti_intersection(SetI *a, SetI *b);
int seti_exists(SetI *set, int value);
int seti_equals(SetI *a, SetI *b);
int seti_size(SetI *set);
int seti_is_empty(SetI *set);
void seti_free(SetI *set);
void seti_print(SetI *set, char* message);

#endif